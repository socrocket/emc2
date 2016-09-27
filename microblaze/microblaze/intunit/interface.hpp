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

#ifndef MICROBLAZE_CORE_FUNC_LT_INTERFACE_HPP
#define MICROBLAZE_CORE_FUNC_LT_INTERFACE_HPP

#include "microblaze/intunit/memory.hpp"
#include "microblaze/intunit/registers.hpp"

#include <common/report.hpp>
#include <modules/abi_if.hpp>
#include <modules/instruction.hpp>

#include <boost/circular_buffer.hpp>
#include <vector>
#include <string>


#define FUNC_MODEL
#define LT_IF
using namespace trap;
namespace core_microblaze_lt {

  /** @brief    Interface Class
  *   @details
  *   Creates the interface used by TRAP-Gen tools to access the processor core.
  */
  class MICROBLAZE_ABIIf : public ABIIf<unsigned int> {
    public:
    MICROBLAZE_ABIIf(
        unsigned int & PROGRAM_LIMIT, MemoryInterface & dataMem, Reg32_0 & PC,
        Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR, Reg32_3 &
        FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
        Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG,
        Reg32_0 & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, bool &
        instrExecuting, boost::circular_buffer<HistoryInstrType> & instHistoryQueue);
    bool is_little_endian() const throw();
    bool is_executing_instr() const throw();
    void wait_instr_end() const throw();
    void return_from_call() throw();
    bool is_routine_entry(const InstructionBase * instr) throw();
    bool is_routine_exit(const InstructionBase * instr) throw();
    unsigned char * get_state() const throw();
    void set_state(unsigned char * state) throw();
    void set_exit_value(unsigned int value) throw();
    unsigned int get_exit_value() throw();
    unsigned int get_code_limit();
    unsigned int read_LR() const throw();
    void set_LR(const unsigned int & newValue) throw();
    unsigned int read_PC() const throw();
    void set_PC(const unsigned int & newValue) throw();
    unsigned int read_SP() const throw();
    void set_SP(const unsigned int & newValue) throw();
    unsigned int read_return_value() const throw();
    void set_return_value(const unsigned int & newValue) throw();
    std::vector<unsigned int> read_args() const throw();
    void set_args(const std::vector<unsigned int> & args) throw();
    unsigned int read_gdb_reg(const unsigned int & gdbId) const throw();
    unsigned int num_gdb_regs() const throw();
    void set_gdb_reg(
        const unsigned int & newValue, const unsigned int & gdbId) throw();
    unsigned int read_mem(const unsigned int & address);
    unsigned char read_char_mem(const unsigned int & address);
    void write_mem(
        const unsigned int & address, unsigned int datum);
    void write_char_mem(
        const unsigned int & address, unsigned char datum);
    boost::circular_buffer<HistoryInstrType> & get_history();
    virtual ~MICROBLAZE_ABIIf();

    private:
    unsigned int & PROGRAM_LIMIT;
    MemoryInterface & dataMem;
    Reg32_0 & PC;
    Reg32_1 & MSR;
    Reg32_0 & EAR;
    Reg32_2 & ESR;
    Reg32_0 & BTR;
    Reg32_3 & FSR;
    Reg32_0 & EDR;
    Reg32_0 & PID;
    Reg32_0 & ZPR;
    Reg32_0 & TLBLO;
    Reg32_0 & TLBHI;
    Reg32_0 & TLBX;
    Reg32_0 & TLBSX;
    Reg32_0 & IMMREG;
    Reg32_0 & TARGET;
    Reg1_0 & DSFLAG;
    Reg32_0 * GPR;
    Reg32_0 * PVR;
    bool & instrExecuting;
    boost::circular_buffer<HistoryInstrType> & instHistoryQueue;
    int routineEntryState;
    int routineExitState;
    unsigned int exitValue;
    std::vector<std::vector<std::string> > routineEntrySequence;
    std::vector<std::vector<std::string> > routineExitSequence;

  }; // class MICROBLAZE_ABIIf

} // namespace core_microblaze_lt



#endif
