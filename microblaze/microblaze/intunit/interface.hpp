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

#include <ABIIf.hpp>
#include <instructionBase.hpp>
#include <utils/trap_utils.hpp>

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
    bool isLittleEndian() const throw();
    bool isInstrExecuting() const throw();
    void waitInstrEnd() const throw();
    void returnFromCall() throw();
    bool isRoutineEntry(const InstructionBase * instr) throw();
    bool isRoutineExit(const InstructionBase * instr) throw();
    unsigned char * getState() const throw();
    void setState(unsigned char * state) throw();
    void setExitValue(unsigned int value) throw();
    unsigned int getExitValue() throw();
    unsigned int getCodeLimit();
    unsigned int readLR() const throw();
    void setLR(const unsigned int & newValue) throw();
    unsigned int readPC() const throw();
    void setPC(const unsigned int & newValue) throw();
    unsigned int readSP() const throw();
    void setSP(const unsigned int & newValue) throw();
    unsigned int readRetVal() const throw();
    void setRetVal(const unsigned int & newValue) throw();
    std::vector<unsigned int> readArgs() const throw();
    void setArgs(const std::vector<unsigned int> & args) throw();
    unsigned int readGDBReg(const unsigned int & gdbId) const throw();
    unsigned int nGDBRegs() const throw();
    void setGDBReg(
        const unsigned int & newValue, const unsigned int & gdbId) throw();
    unsigned int readMem(const unsigned int & address);
    unsigned char readCharMem(const unsigned int & address);
    void writeMem(
        const unsigned int & address, unsigned int datum);
    void writeCharMem(
        const unsigned int & address, unsigned char datum);
    boost::circular_buffer<HistoryInstrType> & getInstructionHistory();
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
