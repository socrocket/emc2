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


#include "microblaze/intunit/interface.hpp"
#include "microblaze/intunit/memory.hpp"
#include "microblaze/intunit/registers.hpp"

#include <modules/abi_if.hpp>
#include <modules/instruction.hpp>

#include <boost/circular_buffer.hpp>
#include <vector>
#include <string>


using namespace core_microblaze_lt;
using namespace trap;
bool core_microblaze_lt::MICROBLAZE_ABIIf::is_little_endian() const throw() {
  return false;
} // isLittleEndian()

bool core_microblaze_lt::MICROBLAZE_ABIIf::is_executing_instr() const throw() {
  return this->instrExecuting;
} // isInstrExecuting()

void core_microblaze_lt::MICROBLAZE_ABIIf::wait_instr_end() const throw() {
  while(this->instrExecuting) {
    ;
  }
} // waitInstrEnd()

void core_microblaze_lt::MICROBLAZE_ABIIf::return_from_call() throw() {
  PC.immediateWrite(GPR[15] + 8);
} // returnFromCall()

bool core_microblaze_lt::MICROBLAZE_ABIIf::is_routine_entry(const InstructionBase
  * instr) throw() {
  std::vector<std::string> nextNames = this->routineEntrySequence[this->routineEntryState];
  std::vector<std::string>::const_iterator namesIter, namesEnd;
  std::string curName = instr->get_name();
  for (namesIter = nextNames.begin(), namesEnd = nextNames.end(); namesIter !=
    namesEnd; namesIter++) {
    if (curName == *namesIter || *namesIter == "") {
      if (this->routineEntryState == -1) {
        this->routineEntryState = 0;
        return true;
      }
      this->routineEntryState++;
      return false;
    }
  }
  this->routineEntryState = 0;
  return false;
} // isRoutineEntry()

bool core_microblaze_lt::MICROBLAZE_ABIIf::is_routine_exit(const InstructionBase *
  instr) throw() {
  std::vector<std::string> nextNames = this->routineExitSequence[this->routineExitState];
  std::vector<std::string>::const_iterator namesIter, namesEnd;
  std::string curName = instr->get_name();
  for (namesIter = nextNames.begin(), namesEnd = nextNames.end(); namesIter !=
    namesEnd; namesIter++) {
    if (curName == *namesIter || *namesIter == "") {
      if (this->routineExitState == -1) {
        this->routineExitState = 0;
        return true;
      }
      this->routineExitState++;
      return false;
    }
  }
  this->routineExitState = 0;
  return false;
} // isRoutineExit()

unsigned char * core_microblaze_lt::MICROBLAZE_ABIIf::get_state() const throw() {
  unsigned char * curState = new unsigned char[236];
  unsigned char * curStateTemp = curState;
  *((unsigned int *)curStateTemp) = this->PC.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->MSR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->EAR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->ESR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->BTR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->FSR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->EDR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PID.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->ZPR.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->TLBLO.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->TLBHI.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->TLBX.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->TLBSX.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->IMMREG.readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->TARGET.readNewValue();
  curStateTemp += 4;
  *((bool *)curStateTemp) = this->DSFLAG.readNewValue();
  curStateTemp += 0;
  *((unsigned int *)curStateTemp) = this->GPR[0].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[1].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[2].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[3].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[4].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[5].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[6].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[7].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[8].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[9].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[10].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[11].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[12].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[13].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[14].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[15].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[16].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[17].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[18].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[19].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[20].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[21].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[22].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[23].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[24].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[25].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[26].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[27].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[28].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[29].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[30].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->GPR[31].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[0].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[1].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[2].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[3].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[4].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[5].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[6].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[7].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[8].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[9].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[10].readNewValue();
  curStateTemp += 4;
  *((unsigned int *)curStateTemp) = this->PVR[11].readNewValue();
  curStateTemp += 4;
  return curState;
} // getState()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_state(unsigned char * state) throw() {
  unsigned char * curStateTemp = state;
  this->PC.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->MSR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->EAR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->ESR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->BTR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->FSR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->EDR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PID.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->ZPR.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->TLBLO.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->TLBHI.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->TLBX.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->TLBSX.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->IMMREG.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->TARGET.immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->DSFLAG.immediateWrite(*((bool *)curStateTemp));
  curStateTemp += 0;
  this->GPR[0].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[1].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[2].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[3].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[4].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[5].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[6].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[7].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[8].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[9].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[10].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[11].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[12].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[13].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[14].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[15].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[16].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[17].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[18].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[19].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[20].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[21].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[22].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[23].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[24].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[25].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[26].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[27].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[28].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[29].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[30].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->GPR[31].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[0].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[1].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[2].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[3].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[4].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[5].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[6].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[7].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[8].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[9].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[10].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
  this->PVR[11].immediateWrite(*((unsigned int *)curStateTemp));
  curStateTemp += 4;
} // setState()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_exit_value(unsigned int value) throw() {
  this->exitValue = value;
} // setExitValue()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::get_exit_value() throw() {
  return this->exitValue;
} // getExitValue()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::get_code_limit() {
  return this->PROGRAM_LIMIT;
} // getCodeLimit()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_LR() const throw() {
  return this->GPR[15];
} // readLR()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_LR(const unsigned int & newValue)
  throw() {
  this->GPR[15].immediateWrite(newValue);
} // setLR()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_PC() const throw() {
  return this->PC + 0;
} // readPC()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_PC(const unsigned int & newValue)
  throw() {
  this->PC.immediateWrite(newValue);
} // setPC()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_SP() const throw() {
  return this->GPR[1];
} // readSP()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_SP(const unsigned int & newValue)
  throw() {
  this->GPR[1].immediateWrite(newValue);
} // setSP()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_return_value() const throw() {
  return this->GPR[3];
} // readRetVal()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_return_value(const unsigned int &
  newValue) throw() {
  this->GPR[3].immediateWrite(newValue);
} // setRetVal()

std::vector<unsigned int> core_microblaze_lt::MICROBLAZE_ABIIf::read_args() const
  throw() {
  std::vector<unsigned int > args;
  args.push_back(this->GPR[5]);
  args.push_back(this->GPR[6]);
  args.push_back(this->GPR[7]);
  args.push_back(this->GPR[8]);
  args.push_back(this->GPR[9]);
  args.push_back(this->GPR[10]);
  return args;
} // readArgs()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_args(const std::vector<unsigned
  int> & args) throw() {
  if (args.size() > 6) {
    THROW_EXCEPTION("ABI of processor supports up to 6 arguments: " << args.size()
      << " given");
  }
  std::vector<unsigned int >::const_iterator argIter = args.begin(), argEnd =
    args.end();
  if (argIter != argEnd) {
    this->GPR[5].immediateWrite(*argIter);
    argIter++;
  }
  if (argIter != argEnd) {
    this->GPR[6].immediateWrite(*argIter);
    argIter++;
  }
  if (argIter != argEnd) {
    this->GPR[7].immediateWrite(*argIter);
    argIter++;
  }
  if (argIter != argEnd) {
    this->GPR[8].immediateWrite(*argIter);
    argIter++;
  }
  if (argIter != argEnd) {
    this->GPR[9].immediateWrite(*argIter);
    argIter++;
  }
  if (argIter != argEnd) {
    this->GPR[10].immediateWrite(*argIter);
    argIter++;
  }
} // setArgs()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_gdb_reg(const unsigned int
  & gdbId) const throw() {
  switch(gdbId) {
    case 0: {
      return GPR[0];
    break;}
    case 1: {
      return GPR[1];
    break;}
    case 2: {
      return GPR[2];
    break;}
    case 3: {
      return GPR[3];
    break;}
    case 4: {
      return GPR[4];
    break;}
    case 5: {
      return GPR[5];
    break;}
    case 6: {
      return GPR[6];
    break;}
    case 7: {
      return GPR[7];
    break;}
    case 8: {
      return GPR[8];
    break;}
    case 9: {
      return GPR[9];
    break;}
    case 10: {
      return GPR[10];
    break;}
    case 11: {
      return GPR[11];
    break;}
    case 12: {
      return GPR[12];
    break;}
    case 13: {
      return GPR[13];
    break;}
    case 14: {
      return GPR[14];
    break;}
    case 15: {
      return GPR[15];
    break;}
    case 16: {
      return GPR[16];
    break;}
    case 17: {
      return GPR[17];
    break;}
    case 18: {
      return GPR[18];
    break;}
    case 19: {
      return GPR[19];
    break;}
    case 20: {
      return GPR[20];
    break;}
    case 21: {
      return GPR[21];
    break;}
    case 22: {
      return GPR[22];
    break;}
    case 23: {
      return GPR[23];
    break;}
    case 24: {
      return GPR[24];
    break;}
    case 25: {
      return GPR[25];
    break;}
    case 26: {
      return GPR[26];
    break;}
    case 27: {
      return GPR[27];
    break;}
    case 28: {
      return GPR[28];
    break;}
    case 29: {
      return GPR[29];
    break;}
    case 30: {
      return GPR[30];
    break;}
    case 31: {
      return GPR[31];
    break;}
    case 32: {
      return PC + 0;
    break;}
    case 33: {
      return MSR;
    break;}
    case 34: {
      return EAR;
    break;}
    case 35: {
      return ESR;
    break;}
    case 36: {
      return FSR;
    break;}
    default: {
      return 0;
    }
  }
} // readGDBReg()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::num_gdb_regs() const throw() {
  return 37;
} // nGDBRegs()

void core_microblaze_lt::MICROBLAZE_ABIIf::set_gdb_reg(
    const unsigned int & newValue,
    const unsigned int & gdbId) throw() {
  switch(gdbId) {
    case 0: {
      GPR[0].immediateWrite(newValue);
    break;}
    case 1: {
      GPR[1].immediateWrite(newValue);
    break;}
    case 2: {
      GPR[2].immediateWrite(newValue);
    break;}
    case 3: {
      GPR[3].immediateWrite(newValue);
    break;}
    case 4: {
      GPR[4].immediateWrite(newValue);
    break;}
    case 5: {
      GPR[5].immediateWrite(newValue);
    break;}
    case 6: {
      GPR[6].immediateWrite(newValue);
    break;}
    case 7: {
      GPR[7].immediateWrite(newValue);
    break;}
    case 8: {
      GPR[8].immediateWrite(newValue);
    break;}
    case 9: {
      GPR[9].immediateWrite(newValue);
    break;}
    case 10: {
      GPR[10].immediateWrite(newValue);
    break;}
    case 11: {
      GPR[11].immediateWrite(newValue);
    break;}
    case 12: {
      GPR[12].immediateWrite(newValue);
    break;}
    case 13: {
      GPR[13].immediateWrite(newValue);
    break;}
    case 14: {
      GPR[14].immediateWrite(newValue);
    break;}
    case 15: {
      GPR[15].immediateWrite(newValue);
    break;}
    case 16: {
      GPR[16].immediateWrite(newValue);
    break;}
    case 17: {
      GPR[17].immediateWrite(newValue);
    break;}
    case 18: {
      GPR[18].immediateWrite(newValue);
    break;}
    case 19: {
      GPR[19].immediateWrite(newValue);
    break;}
    case 20: {
      GPR[20].immediateWrite(newValue);
    break;}
    case 21: {
      GPR[21].immediateWrite(newValue);
    break;}
    case 22: {
      GPR[22].immediateWrite(newValue);
    break;}
    case 23: {
      GPR[23].immediateWrite(newValue);
    break;}
    case 24: {
      GPR[24].immediateWrite(newValue);
    break;}
    case 25: {
      GPR[25].immediateWrite(newValue);
    break;}
    case 26: {
      GPR[26].immediateWrite(newValue);
    break;}
    case 27: {
      GPR[27].immediateWrite(newValue);
    break;}
    case 28: {
      GPR[28].immediateWrite(newValue);
    break;}
    case 29: {
      GPR[29].immediateWrite(newValue);
    break;}
    case 30: {
      GPR[30].immediateWrite(newValue);
    break;}
    case 31: {
      GPR[31].immediateWrite(newValue);
    break;}
    case 32: {
      PC.immediateWrite(newValue);
    break;}
    case 33: {
      MSR.immediateWrite(newValue);
    break;}
    case 34: {
      EAR.immediateWrite(newValue);
    break;}
    case 35: {
      ESR.immediateWrite(newValue);
    break;}
    case 36: {
      FSR.immediateWrite(newValue);
    break;}
    default: {
      THROW_EXCEPTION("No register corresponding to GDB id " << gdbId);
    }
  }
} // setGDBReg()

unsigned int core_microblaze_lt::MICROBLAZE_ABIIf::read_mem(const unsigned int &
  address) {
  return this->dataMem.read_word_dbg(address);
} // readMem()

unsigned char core_microblaze_lt::MICROBLAZE_ABIIf::read_char_mem(const unsigned
  int & address) {
  return this->dataMem.read_byte_dbg(address);
} // readCharMem()

void core_microblaze_lt::MICROBLAZE_ABIIf::write_mem(
    const unsigned int & address,
    unsigned int datum) {
  this->dataMem.write_word_dbg(address, datum);
} // writeMem()

void core_microblaze_lt::MICROBLAZE_ABIIf::write_char_mem(
    const unsigned int & address,
    unsigned char datum) {
  this->dataMem.write_byte_dbg(address, datum);
} // writeCharMem()

boost::circular_buffer<HistoryInstrType> & core_microblaze_lt::MICROBLAZE_ABIIf::getInstructionHistory()
  {
  return this->instHistoryQueue;
} // getInstructionHistory()

core_microblaze_lt::MICROBLAZE_ABIIf::~MICROBLAZE_ABIIf() {

} // ~MICROBLAZE_ABIIf()

core_microblaze_lt::MICROBLAZE_ABIIf::MICROBLAZE_ABIIf(
    unsigned int & PROGRAM_LIMIT, MemoryInterface & dataMem, Reg32_0 & PC,
    Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR, Reg32_3 & FSR,
    Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO, Reg32_0 &
    TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0 & TARGET,
    Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, bool & instrExecuting,
    boost::circular_buffer<HistoryInstrType> & instHistoryQueue) :
  PROGRAM_LIMIT(PROGRAM_LIMIT), dataMem(dataMem), PC(PC), MSR(MSR), EAR(EAR),
  ESR(ESR), BTR(BTR), FSR(FSR), EDR(EDR), PID(PID), ZPR(ZPR), TLBLO(TLBLO),
  TLBHI(TLBHI), TLBX(TLBX), TLBSX(TLBSX), IMMREG(IMMREG), TARGET(TARGET),
  DSFLAG(DSFLAG), GPR(GPR), PVR(PVR), instrExecuting(instrExecuting), instHistoryQueue(instHistoryQueue)
  {
  this->routineExitState = 0;
  this->routineEntryState = 0;
  std::vector<std::string> tempVec;
} // MICROBLAZE_ABIIf()


