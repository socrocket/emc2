/*******************************************************************************
*
*
*
*
*
* This file is part of MICROBLAZE.
*
* MICROBLAZE is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#ifndef MICROBLAZE_CORE_FUNC_LT_ALIAS_HPP
#define MICROBLAZE_CORE_FUNC_LT_ALIAS_HPP

#include "microblaze/intunit/registers.hpp"


#include <ostream>
#include <list>


#define FUNC_MODEL
#define LT_IF
namespace core_microblaze_lt {

  /** @brief    Register Alias Class
  *   @details
  *   An alias simply holds a pointer to a register. The operators are
  *   redefined in order to call the corresponding operators of the register.
  *   There is also an updateAlias() method which updates the register this
  *   alias points to (and possibly the offset).
  */
  class Alias {
    public:
    ~Alias();
    Alias(
        Alias * initAlias, unsigned int offset = 0);
    Alias();
    Alias(
        Register * reg, unsigned int offset = 0);
    inline InnerField & operator [](int bitField) throw() {
      return (*this->reg)[bitField];
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    inline Register * getReg() const throw() {
      return this->reg;
    } // getReg()

    unsigned int operator ~() throw();
    inline Alias & operator =(const unsigned int & other) throw() {
      *this->reg = other;
      return *this;
    } // operator =()

    inline Alias & operator +=(const unsigned int & other) throw() {
      *this->reg += other;
      return *this;
    } // operator +=()

    inline Alias & operator -=(const unsigned int & other) throw() {
      *this->reg -= other;
      return *this;
    } // operator -=()

    inline Alias & operator *=(const unsigned int & other) throw() {
      *this->reg *= other;
      return *this;
    } // operator *=()

    inline Alias & operator /=(const unsigned int & other) throw() {
      *this->reg /= other;
      return *this;
    } // operator /=()

    inline Alias & operator |=(const unsigned int & other) throw() {
      *this->reg |= other;
      return *this;
    } // operator |=()

    inline Alias & operator &=(const unsigned int & other) throw() {
      *this->reg &= other;
      return *this;
    } // operator &=()

    inline Alias & operator ^=(const unsigned int & other) throw() {
      *this->reg ^= other;
      return *this;
    } // operator ^=()

    inline Alias & operator <<=(const unsigned int & other) throw() {
      *this->reg <<= other;
      return *this;
    } // operator <<=()

    inline Alias & operator >>=(const unsigned int & other) throw() {
      *this->reg >>= other;
      return *this;
    } // operator >>=()

    unsigned int operator +(const Alias & other) const throw();
    unsigned int operator -(const Alias & other) const throw();
    unsigned int operator *(const Alias & other) const throw();
    unsigned int operator /(const Alias & other) const throw();
    unsigned int operator |(const Alias & other) const throw();
    unsigned int operator &(const Alias & other) const throw();
    unsigned int operator ^(const Alias & other) const throw();
    unsigned int operator <<(const Alias & other) const throw();
    unsigned int operator >>(const Alias & other) const throw();
    Alias & operator =(const Alias & other) throw();
    Alias & operator +=(const Alias & other) throw();
    Alias & operator -=(const Alias & other) throw();
    Alias & operator *=(const Alias & other) throw();
    Alias & operator /=(const Alias & other) throw();
    Alias & operator |=(const Alias & other) throw();
    Alias & operator &=(const Alias & other) throw();
    Alias & operator ^=(const Alias & other) throw();
    Alias & operator <<=(const Alias & other) throw();
    Alias & operator >>=(const Alias & other) throw();
    inline unsigned int operator +(const Register & other) const throw() {
      return ((*this->reg + this->offset) + other);
    } // operator +()

    inline unsigned int operator -(const Register & other) const throw() {
      return ((*this->reg + this->offset) - other);
    } // operator -()

    inline unsigned int operator *(const Register & other) const throw() {
      return ((*this->reg + this->offset) * other);
    } // operator *()

    inline unsigned int operator /(const Register & other) const throw() {
      return ((*this->reg + this->offset) / other);
    } // operator /()

    inline unsigned int operator |(const Register & other) const throw() {
      return ((*this->reg + this->offset) | other);
    } // operator |()

    inline unsigned int operator &(const Register & other) const throw() {
      return ((*this->reg + this->offset) & other);
    } // operator &()

    inline unsigned int operator ^(const Register & other) const throw() {
      return ((*this->reg + this->offset) ^ other);
    } // operator ^()

    inline unsigned int operator <<(const Register & other) const throw() {
      return ((*this->reg + this->offset) << other);
    } // operator <<()

    inline unsigned int operator >>(const Register & other) const throw() {
      return ((*this->reg + this->offset) >> other);
    } // operator >>()

    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Alias & operator =(const Register & other) throw();
    Alias & operator +=(const Register & other) throw();
    Alias & operator -=(const Register & other) throw();
    Alias & operator *=(const Register & other) throw();
    Alias & operator /=(const Register & other) throw();
    Alias & operator |=(const Register & other) throw();
    Alias & operator &=(const Register & other) throw();
    Alias & operator ^=(const Register & other) throw();
    Alias & operator <<=(const Register & other) throw();
    Alias & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return *this->reg + this->offset;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();
    inline void updateAlias(
        Alias & newAlias, unsigned int newOffset) throw() {
      this->reg = newAlias.reg;
      this->offset = newAlias.offset + newOffset;
      this->defaultOffset = newOffset;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(newAlias.reg, newAlias.offset + newOffset);
      }
      if (this->referringAliases != NULL) {
        this->referringAliases->referredAliases.remove(this);
      }
      this->referringAliases = &newAlias;
      newAlias.referredAliases.push_back(this);
    } // updateAlias()

    inline void updateAlias(Alias & newAlias) throw() {
      this->offset = newAlias.offset;
      this->defaultOffset = 0;
      this->reg = newAlias.reg;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(newAlias.reg, newAlias.offset);
      }
      if (this->referringAliases != NULL) {
        this->referringAliases->referredAliases.remove(this);
      }
      this->referringAliases = &newAlias;
      newAlias.referredAliases.push_back(this);
    } // updateAlias()

    inline void updateAlias(
        Register & newAlias, unsigned int newOffset) throw() {
      this->reg = &newAlias;
      this->offset = newOffset;
      this->defaultOffset = newOffset;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(&newAlias, newOffset);
      }
      if (this->referringAliases != NULL) {
        this->referringAliases->referredAliases.remove(this);
      }
      this->referringAliases = NULL;
    } // updateAlias()

    inline void updateAlias(Register & newAlias) throw() {
      this->offset = 0;
      this->defaultOffset = 0;
      this->reg = &newAlias;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(&newAlias);
      }
      if (this->referringAliases != NULL) {
        this->referringAliases->referredAliases.remove(this);
      }
      this->referringAliases = NULL;
    } // updateAlias()

    void directSetAlias(Alias & newAlias) throw();
    void directSetAlias(Register & newAlias) throw();
    inline void newReferredAlias(
        Register * newAlias, unsigned int newOffset) throw() {
      this->reg = newAlias;
      this->offset = newOffset + this->defaultOffset;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(newAlias, newOffset);
      }
    } // newReferredAlias()

    inline void newReferredAlias(Register * newAlias) throw() {
      this->offset = this->defaultOffset;
      this->reg = newAlias;
      std::list<Alias *>::iterator referredIter, referredEnd;
      for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
        referredIter != referredEnd; referredIter++) {
        (*referredIter)->newReferredAlias(newAlias);
      }
    } // newReferredAlias()


    private:
    Register * reg;
    unsigned int offset;
    unsigned int defaultOffset;
    std::list<Alias *> referredAliases;
    Alias * referringAliases;

  }; // class Alias

} // namespace core_microblaze_lt



#endif
