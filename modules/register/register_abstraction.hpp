/***************************************************************************//**
*
*  _/_/_/_/_/  _/_/_/           _/        _/_/_/
*     _/      _/    _/        _/_/       _/    _/
*    _/      _/    _/       _/  _/      _/    _/
*   _/      _/_/_/        _/_/_/_/     _/_/_/
*  _/      _/    _/     _/      _/    _/
* _/      _/      _/  _/        _/   _/
*
* @file     register_abstraction.hpp
* @brief    This file is part of the TRAP runtime library.
* @details  @see RegisterAbstraction
* @author   Lillian Tadros (Technische Universitaet Dortmund)
* @date     2016 Technische Universitaet Dortmund
* @copyright
*
* This file is part of TRAP.
*
* TRAP is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation; either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/
#ifndef TRAP_REGISTER_ABSTRACTION_H_
#define TRAP_REGISTER_ABSTRACTION_H_

#include "common/report.hpp"

//#include <amba_parameters.h>

#include <assert.h>

namespace trap {

/// Types

// TODO: Is it worth an amba dependency?
enum amba_layer_ids {
  amba_CT = 0x01,   // cycle-timed or cycle-accurate
  amba_AT = 0x04,   // approximately-timed
  amba_LT = 0x08,   // loosely-timed
  amba_pv = 0x10    // programmer's view
};

/// ****************************************************************************

/**
 * @brief RegisterAbstraction
 *
 * Serves two purposes:
 * 1.The register classes can be used for multiple levels of abstraction (cycle-
 *   accurate, etc), if the effect of the abstraction can be reduced down to a
 *   few operations. Since all access operations of RegisterField, RegisterBank
 *   as well as Register delegate to Register::read/write, it suffices to.name
 *   encapsulate these operations away from Register and into a strategy
 *   appropriate for the chosen abstraction level. The heavy-weight Register
 *   class can thus be used for all abstractions by only varying the strategy.
 *   Abstraction could be provided as a compile-time choice, but we use run-time
 *   delegation instead for more flexibility.
 *
 * 2.The same logic is used for delegating the behavior of special Registers. In
 *   particular, constant-value registers, registers with an offset and
 *   registers with a delay (only TLM) again have slightly different read/write
 *   behavior from the regular case. This makes for a second level of
 *   delegation: RegisterAbstraction->RegisterAbstraction<Behavior>. Since a
 *   const/offset/delay completely changes the read/write behavior, inheritance
 *   seems like the correct implementaion choice. The base abstraction is
 *   intentionally not an abstract class and should be used for the general
 *   case.
 *
 * 3.A cleaner solution would be layering RegisterAbstraction<Behavior> as
 *   decorators, i.e. enabling things like RegisterTLMDelay ->
 *   RegisterTLMOffset. We would change the variable references to a
 *   RegisterAbstraction&, and initialize the outer layer with a reference to
 *   an inner layer, so RegisterTLMDelay(RegisterTLMOffset(RegisterTLM)). The
 *   outer layers would then need to derive from RegisterAbstraction only, not
 *   RegisterTLM. I found the additional complexity too much for the one case
 *   where this is allowed (TLMDelay + TLMOffset), so I created an extra
 *   combination class instead. It saves us one level of delegation in that case.
 */
template <typename DATATYPE>
class RegisterAbstraction {
  /// @name Constructors and Destructors
  /// @{

  public:
  virtual ~RegisterAbstraction()
  {}

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  virtual const DATATYPE read_dbg() const = 0;

  // Reads last written value.
  virtual const DATATYPE read_force() const { return this->read_dbg(); }

  virtual bool write_dbg(const DATATYPE& data) = 0;

  // Writes value immediately discarding delay.
  virtual bool write_force(const DATATYPE& data) { return this->write_dbg(data); }

  virtual void clock_cycle() {}
  /// @} Access and Modification Methods
}; // class RegisterAbstraction

/// ****************************************************************************

template <typename DATATYPE>
class RegisterTLM : public RegisterAbstraction<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterTLM(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask)
    : m_value(value),
      m_used_mask(used_mask),
      m_read_mask(read_mask),
      m_write_mask(write_mask)
  {}

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  const DATATYPE read_dbg() const {
    return this->m_value & this->m_read_mask;
  }

  bool write_dbg(const DATATYPE& data) {
    this->m_value = data & this->m_write_mask;
    return true;
  }

  /// @} Access and Modification Methods
  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  DATATYPE& m_value;
  DATATYPE& m_used_mask;
  DATATYPE& m_read_mask;
  DATATYPE& m_write_mask;

  /// @} Data
}; // class RegisterTLM

/// ****************************************************************************

template <typename DATATYPE>
class RegisterTLMConst : public RegisterTLM<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterTLMConst(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask, DATATYPE& reset_value)
    : RegisterTLM<DATATYPE>(value, used_mask, read_mask, write_mask),
      m_reset_value(reset_value)
  {}

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  bool write_dbg(const DATATYPE&) {
    THROW_WARNING("Cannot write a const register.");
    return false;
  }

  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  DATATYPE& m_reset_value;

  /// @} Data

  /// @} Access and Modification Methods
}; // class RegisterTLMConst

/// ****************************************************************************

template <typename DATATYPE>
class RegisterTLMOffset : public RegisterTLM<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterTLMOffset(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask, const unsigned& offset)
    : RegisterTLM<DATATYPE>(value, used_mask, read_mask, write_mask),
      m_offset(offset) {
    // Offsets cannot be used with masks since it is not obviuos whether the
    // initial or the offset value should be masked.
    assert(read_mask == ((unsigned long)1 << (sizeof(DATATYPE) * 8) - 1)
    && read_mask == write_mask);
  }

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  const DATATYPE read_dbg() const {
    assert(this->m_value+this->m_offset < ((unsigned long)1 << (sizeof(DATATYPE) * 8)));
    return this->m_value + this->m_offset;
  }

  /// @} Access and Modification Methods
  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  const DATATYPE& m_offset;

  /// @} Data
}; // class RegisterTLMOffset

/// ****************************************************************************

template <typename DATATYPE>
class RegisterTLMDelay : public RegisterTLM<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterTLMDelay(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask, const unsigned& delay)
    : RegisterTLM<DATATYPE>(value, used_mask, read_mask, write_mask),
      m_delay(delay) {
    this->m_values = new DATATYPE[this->m_delay];
    this->m_update_slots = new bool[this->m_delay];
    for (unsigned i = 0; i < this->m_delay; ++i) {
      this->m_values[i] = 0;
      this->m_update_slots[i] = false;
    }
  }

  ~RegisterTLMDelay() {
    delete [] this->m_values;
    delete [] this->m_update_slots;
  }

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  const DATATYPE read_force() {
    for (unsigned i = this->m_delay-1; i >= 0; --i) {
      if (this->m_update_slots[i]) {
        return this->m_values[i] & this->m_read_mask;
      }
    }
    return this->m_value;
  }

  bool write_dbg(const DATATYPE& data) {
    this->m_values[this->m_delay-1] = data & this->m_write_mask;
    this->m_update_slots[this->m_delay-1] = true;
    return true;
  }

  bool write_force(const DATATYPE& data) {
    this->m_value = data;
    for (unsigned i = 0; i < this->m_delay; ++i) {
      this->m_update_slots[i] = false;
    }
    return true;
  }

  void clock_cycle() {
    if (this->m_update_slots[0]) {
      this->m_value = this->m_values[0];
      this->m_update_slots[0] = false;
    }
    for (unsigned i = 1; i < this->m_delay; ++i) {
      if (this->m_update_slots[i]) {
        this->m_values[i-1] = this->m_values[i];
        this->m_update_slots[i] = false;
        this->m_update_slots[i-1] = true;
      }
    }
  }

  /// @} Access and Modification Methods
  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  DATATYPE* m_values;
  bool* m_update_slots;
  const unsigned& m_delay;

  /// @} Data
}; // class RegisterTLMDelay

/// ****************************************************************************


template <typename DATATYPE>
class RegisterTLMDelayOffset : public RegisterTLM<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterTLMDelayOffset(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask, const unsigned& delay, const unsigned& offset)
    : RegisterTLM<DATATYPE>(value, used_mask, read_mask, write_mask),
      m_offset(offset),
      m_delay(delay) {
    // Offsets cannot be used with masks since it is not obviuos whether the
    // initial or the offset value should be masked.
    assert(read_mask == ((unsigned long)1 << (sizeof(DATATYPE) * 8) - 1)
    && read_mask == write_mask);

    this->m_update_slots = new bool[this->m_delay];
    this->m_values = new DATATYPE[this->m_delay];
    for (unsigned i = 0; i < this->m_delay; ++i) {
      this->m_values[i] = 0;
      this->m_update_slots[i] = false;
    }
  }

  ~RegisterTLMDelayOffset() {
    delete [] this->m_values;
    delete [] this->m_update_slots;
  }

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  const DATATYPE read_dbg() const {
    assert(this->m_value+this->m_offset < ((unsigned long)1 << (sizeof(DATATYPE) * 8)));
    return this->m_value + this->m_offset;
  }

  const DATATYPE read_force() {
    for (unsigned i = this->m_delay-1; i >= 0; --i) {
      if (this->m_update_slots[i]) {
        return this->m_values[i] + this->m_offset;
      }
    }
    return this->m_value + this->m_offset;
  }

  bool write_dbg(const DATATYPE& data) {
    this->m_values[this->m_delay-1] = data;
    this->m_update_slots[this->m_delay-1] = true;
    return true;
  }

  bool write_force(const DATATYPE& data) {
    this->m_value = data;
    for (unsigned i = 0; i < this->m_delay; ++i) {
      this->m_update_slots[i] = false;
    }
    return true;
  }

  void clock_cycle() {
    if (this->m_update_slots[0]) {
      this->m_value = this->m_values[0];
      this->m_update_slots[0] = false;
    }
    for (unsigned i = 1; i < this->m_delay; ++i) {
      if (this->m_update_slots[i]) {
        this->m_values[i-1] = this->m_values[i];
        this->m_update_slots[i] = false;
        this->m_update_slots[i-1] = true;
      }
    }
  }

  /// @} Access and Modification Methods
  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  DATATYPE* m_values;
  bool* m_update_slots;
  const unsigned& m_offset;
  const unsigned& m_delay;

  /// @} Data
}; // class RegisterTLMDelayOffset

/// ****************************************************************************

/*TODO: Unimplemented
template <typename DATATYPE>
class RegisterCA : public RegisterAbstraction<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  RegisterCA(DATATYPE& value, DATATYPE& used_mask, DATATYPE& read_mask, DATATYPE& write_mask)
    : m_value(value),
      m_used_mask(used_mask),
      m_read_mask(read_mask),
      m_write_mask(write_mask),
      m_num_locked(0),
      m_locked_latency(-1),
      m_has_to_propagate(NULL),
      m_time_stamp(SC_ZERO_TIME)
  {}

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  const DATATYPE read_dbg() const {
    return this->m_value & this->m_read_mask;
  }

  bool write_dbg(const DATATYPE& data) {
    this->m_value = data & this->m_write_mask;
    this->m_has_to_propagate = true;
    this->m_time_stamp = sc_time_stamp();
    return true;
  }

  void lock() {
    this->m_locked_latency = -1;
    this->m_num_locked++;
  }

  void unlock() {
    this->m_locked_latency = -1;
    if (this->m_num_locked > 0) {
      this->m_num_locked--;
    }
  }

  void unlock(int wb_latency) {
    if (wb_latency > 0) {
      this->m_locked_latency = wb_latency;
    } else {
      this->m_locked_latency = -1;
      if (this->m_num_locked > 0) {
        this->m_num_locked--;
      }
    }
  }

  bool is_locked() {
    if (this->m_locked_latency > 0) {
      this->m_locked_latency--;
      if (this->m_locked_latency == 0) {
        this->m_num_locked--;
      }
    }
    if (this->m_num_locked > 0) {
      return true;
    } else {
      this->m_num_locked = 0;
      return false;
    }
  }

  /// @} Access and Modification Methods
  /// --------------------------------------------------------------------------
  /// @name Data
  /// @{

  protected:
  DATATYPE& m_value;
  DATATYPE& m_reset_value;
  DATATYPE& m_used_mask;
  DATATYPE& m_read_mask;
  DATATYPE& m_write_mask;

  int m_locked_latency;
  int m_num_locked;
  bool* m_has_to_propagate;
  sc_time m_time_stamp;

  /// @} Data
} // class RegisterCA

/// ****************************************************************************

template <typename DATATYPE>
class RegisterCAConst : public RegisterCA<DATATYPE> {
  /// @name Constructors and Destructors
  /// @{

  public:
  using RegisterCA<DATATYPE>::RegisterCA;

  /// @} Constructors and Destructors
  /// --------------------------------------------------------------------------
  /// @name Access and Modification Methods
  /// @{

  public:
  bool write_dbg(const DATATYPE& data) {
    THROW_WARNING("Cannot write a const register.");
    return false;
  }

  /// @} Access and Modification Methods
} // class RegisterCAConst
*/

} // namespace trap

/// ****************************************************************************
#endif
