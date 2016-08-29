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


#include "microblaze/intunit/registers.hpp"
#include "microblaze/intunit/memory.hpp"
#include "microblaze/intunit/instructions.hpp"
#include "microblaze/intunit/alias.hpp"

#include <instructionBase.hpp>
#include <utils/customExceptions.hpp>
#include <utils/trap_utils.hpp>

#include <string>
#include <sstream>


using namespace core_microblaze_lt;
void core_microblaze_lt::Instruction::printTrace() {
  std::cerr << "Simulated time " << std::dec << this->totalCycles << std::endl;
  std::cerr << "Instruction: " << this->getInstructionName() << std::endl;
  std::cerr << "Mnemonic: " << this->getMnemonic() << std::endl;
  std::cerr << "PC = " << std::hex << std::showbase << this->PC << std::endl;
  std::cerr << "MSR = " << std::hex << std::showbase << this->MSR << std::endl;
  std::cerr << "EAR = " << std::hex << std::showbase << this->EAR << std::endl;
  std::cerr << "ESR = " << std::hex << std::showbase << this->ESR << std::endl;
  std::cerr << "BTR = " << std::hex << std::showbase << this->BTR << std::endl;
  std::cerr << "FSR = " << std::hex << std::showbase << this->FSR << std::endl;
  std::cerr << "EDR = " << std::hex << std::showbase << this->EDR << std::endl;
  std::cerr << "PID = " << std::hex << std::showbase << this->PID << std::endl;
  std::cerr << "ZPR = " << std::hex << std::showbase << this->ZPR << std::endl;
  std::cerr << "TLBLO = " << std::hex << std::showbase << this->TLBLO << std::endl;
  std::cerr << "TLBHI = " << std::hex << std::showbase << this->TLBHI << std::endl;
  std::cerr << "TLBX = " << std::hex << std::showbase << this->TLBX << std::endl;
  std::cerr << "TLBSX = " << std::hex << std::showbase << this->TLBSX << std::endl;
  std::cerr << "IMMREG = " << std::hex << std::showbase << this->IMMREG << std::endl;
  std::cerr << "TARGET = " << std::hex << std::showbase << this->TARGET << std::endl;
  std::cerr << "DSFLAG = " << std::hex << std::showbase << this->DSFLAG << std::endl;
  for (int regNum = 0; regNum < 32; regNum++) {
    std::cerr << "GPR[" << std::dec << regNum << "] = " << std::hex << std::showbase
      << this->GPR[regNum] << std::endl;
  }
  for (int regNum = 0; regNum < 12; regNum++) {
    std::cerr << "PVR[" << std::dec << regNum << "] = " << std::hex << std::showbase
      << this->PVR[regNum] << std::endl;
  }
  std::cerr << std::endl;
} // printTrace()

unsigned int core_microblaze_lt::Instruction::SignExtend(
    unsigned int bitSeq,
    unsigned int bitSeq_length) {

  if((bitSeq & (1 << (bitSeq_length - 1))) != 0)
  bitSeq |= (((unsigned int)0xFFFFFFFF) << bitSeq_length);
  return bitSeq;
} // SignExtend()

void core_microblaze_lt::Instruction::handleMemoryException(
    unsigned int W_value,
    unsigned int S_value,
    unsigned int rd_bit_value,
    unsigned int addr) {

  ESR[key_DS] = DSFLAG ? 0x1 : 0x0;
  if ( ESR[key_DS] ) {
    BTR = PC; /* In this moment, TARGET value is in PC */
    GPR[17] = 0xffffffff;
  } else {
    GPR[17] = PC; /* In this moment, PC points to the NEXT instruction */
  }
  PC = 0x00000020;
  MSR[key_EE] = 0x0; MSR[key_EIP] = 0x1;
  MSR[key_UMS] = MSR[key_UM]; MSR[key_UM] = 0x0;
  MSR[key_VMS] = MSR[key_VMS]; MSR[key_VM] = 0x0;

  ESR[key_EC] = 0x1;
  ESR[key_W] = W_value;
  ESR[key_S] = S_value;
  ESR[key_Rx] = rd_bit_value; /* the value that identifies rd */
  EAR = addr;
} // handleMemoryException()

void core_microblaze_lt::Instruction::handleUserPermissionException() {

  ESR[key_DS] = DSFLAG ? 0x1 : 0x0;
  if ( ESR[key_DS] ) {
    BTR = PC; /* In this moment, TARGET value is in PC */
    GPR[17] = 0xffffffff;
  } else {
    GPR[17] = PC; /* In this moment, PC points to the NEXT instruction */
  }
  PC = 0x00000020;
  MSR[key_EE] = 0x0; MSR[key_EIP] = 0x1;
  MSR[key_UMS] = MSR[key_UM]; MSR[key_UM] = 0x0;
  MSR[key_VMS] = MSR[key_VMS]; MSR[key_VM] = 0x0;

  ESR[key_EC] = 0x1c;
} // handleUserPermissionException()

core_microblaze_lt::Instruction::Instruction(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  PC(PC), MSR(MSR), EAR(EAR), ESR(ESR), BTR(BTR), FSR(FSR), EDR(EDR), PID(PID),
  ZPR(ZPR), TLBLO(TLBLO), TLBHI(TLBHI), TLBX(TLBX), TLBSX(TLBSX), IMMREG(IMMREG),
  TARGET(TARGET), DSFLAG(DSFLAG), GPR(GPR), PVR(PVR), dataMem(dataMem), totalCycles(totalCycles)
  {
  this->totalInstrCycles = 0;
} // Instruction()

core_microblaze_lt::Instruction::~Instruction() {

} // ~Instruction()

core_microblaze_lt::IMM_reset_op::~IMM_reset_op() {

} // ~IMM_reset_op()

core_microblaze_lt::IMM_reset_op::IMM_reset_op(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // IMM_reset_op()

core_microblaze_lt::IMM_handler_op::~IMM_handler_op() {

} // ~IMM_handler_op()

core_microblaze_lt::IMM_handler_op::IMM_handler_op(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // IMM_handler_op()

unsigned int core_microblaze_lt::InvalidInstr::behavior() {
  THROW_EXCEPTION("Unknown Instruction at PC: " << std::hex << std::showbase <<
    this->PC);
  return 0;
} // behavior()

Instruction * core_microblaze_lt::InvalidInstr::replicate() const throw() {
  return new InvalidInstr(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO,
    TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

void core_microblaze_lt::InvalidInstr::setParams(const unsigned int & bitString)
  throw() {

} // setParams()

std::string core_microblaze_lt::InvalidInstr::getInstructionName() const throw() {
  return "InvalidInstruction";
} // getInstructionName()

std::string core_microblaze_lt::InvalidInstr::getMnemonic() const throw() {
  return "invalid";
} // getMnemonic()

unsigned int core_microblaze_lt::InvalidInstr::getId() const throw() {
  return 116;
} // getId()

core_microblaze_lt::InvalidInstr::InvalidInstr(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // InvalidInstr()

core_microblaze_lt::InvalidInstr::~InvalidInstr() {

} // ~InvalidInstr()

unsigned int core_microblaze_lt::WDC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  /* This instruction is related to the Cache. Since we don't have
  Cache in our model, we simply ignore the implementation of
  this instruction. */
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::WDC::replicate() const throw() {
  return new WDC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::WDC::getInstructionName() const throw() {
  return "WDC";
} // getInstructionName()

unsigned int core_microblaze_lt::WDC::getId() const throw() {
  return 112;
} // getId()

void core_microblaze_lt::WDC::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::WDC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "wdc r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::WDC::WDC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // WDC()

core_microblaze_lt::WDC::~WDC() {

} // ~WDC()

unsigned int core_microblaze_lt::BGE::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra>=0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGE::replicate() const throw() {
  return new BGE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGE::getInstructionName() const throw() {
  return "BGE";
} // getInstructionName()

unsigned int core_microblaze_lt::BGE::getId() const throw() {
  return 16;
} // getId()

void core_microblaze_lt::BGE::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BGE::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bge r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGE::BGE(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGE()

core_microblaze_lt::BGE::~BGE() {

} // ~BGE()

unsigned int core_microblaze_lt::BGEID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra >= 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGEID::replicate() const throw() {
  return new BGEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGEID::getInstructionName() const throw() {
  return "BGEID";
} // getInstructionName()

unsigned int core_microblaze_lt::BGEID::getId() const throw() {
  return 19;
} // getId()

void core_microblaze_lt::BGEID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BGEID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgeid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGEID::BGEID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGEID()

core_microblaze_lt::BGEID::~BGEID() {

} // ~BGEID()

unsigned int core_microblaze_lt::BSLL::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (unsigned int)ra << ((int)rb & 0x1f);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSLL::replicate() const throw() {
  return new BSLL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSLL::getInstructionName() const throw() {
  return "BSLL";
} // getInstructionName()

unsigned int core_microblaze_lt::BSLL::getId() const throw() {
  return 52;
} // getId()

void core_microblaze_lt::BSLL::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BSLL::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bsll r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSLL::BSLL(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSLL()

core_microblaze_lt::BSLL::~BSLL() {

} // ~BSLL()

unsigned int core_microblaze_lt::BGT::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra>0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGT::replicate() const throw() {
  return new BGT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGT::getInstructionName() const throw() {
  return "BGT";
} // getInstructionName()

unsigned int core_microblaze_lt::BGT::getId() const throw() {
  return 20;
} // getId()

void core_microblaze_lt::BGT::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BGT::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgt r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGT::BGT(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGT()

core_microblaze_lt::BGT::~BGT() {

} // ~BGT()

unsigned int core_microblaze_lt::BR::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  PC = PC + (int)rb;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BR::replicate() const throw() {
  return new BR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BR::getInstructionName() const throw() {
  return "BR";
} // getInstructionName()

unsigned int core_microblaze_lt::BR::getId() const throw() {
  return 36;
} // getId()

void core_microblaze_lt::BR::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BR::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "br r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BR::BR(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BR()

core_microblaze_lt::BR::~BR() {

} // ~BR()

unsigned int core_microblaze_lt::BNED::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra != 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BNED::replicate() const throw() {
  return new BNED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BNED::getInstructionName() const throw() {
  return "BNED";
} // getInstructionName()

unsigned int core_microblaze_lt::BNED::getId() const throw() {
  return 33;
} // getId()

void core_microblaze_lt::BNED::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BNED::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bned r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BNED::BNED(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BNED()

core_microblaze_lt::BNED::~BNED() {

} // ~BNED()

unsigned int core_microblaze_lt::BNEI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra!=0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BNEI::replicate() const throw() {
  return new BNEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BNEI::getInstructionName() const throw() {
  return "BNEI";
} // getInstructionName()

unsigned int core_microblaze_lt::BNEI::getId() const throw() {
  return 34;
} // getId()

void core_microblaze_lt::BNEI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BNEI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bnei r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BNEI::BNEI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BNEI()

core_microblaze_lt::BNEI::~BNEI() {

} // ~BNEI()

unsigned int core_microblaze_lt::LBU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  rd = dataMem.read_byte(addr);
  rd &= 0x000000ff;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LBU::replicate() const throw() {
  return new LBU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LBU::getInstructionName() const throw() {
  return "LBU";
} // getInstructionName()

unsigned int core_microblaze_lt::LBU::getId() const throw() {
  return 69;
} // getId()

void core_microblaze_lt::LBU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::LBU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lbu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LBU::LBU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LBU()

core_microblaze_lt::LBU::~LBU() {

} // ~LBU()

unsigned int core_microblaze_lt::RSUB::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int b = (int)rb;
  long long result = (long long)( (long long)b + ~((long long)a) + 1);
  MSR[key_C] = (( (~a + 1)^b^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd=(int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUB::replicate() const throw() {
  return new RSUB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUB::getInstructionName() const throw() {
  return "RSUB";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUB::getId() const throw() {
  return 89;
} // getId()

void core_microblaze_lt::RSUB::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::RSUB::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsub r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUB::RSUB(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUB()

core_microblaze_lt::RSUB::~RSUB() {

} // ~RSUB()

unsigned int core_microblaze_lt::BSRLI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (unsigned int)ra >> (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSRLI::replicate() const throw() {
  return new BSRLI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSRLI::getInstructionName() const throw() {
  return "BSRLI";
} // getInstructionName()

unsigned int core_microblaze_lt::BSRLI::getId() const throw() {
  return 53;
} // getId()

void core_microblaze_lt::BSRLI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0x1f);
} // setParams()

std::string core_microblaze_lt::BSRLI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bsrli r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSRLI::BSRLI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSRLI()

core_microblaze_lt::BSRLI::~BSRLI() {

} // ~BSRLI()

unsigned int core_microblaze_lt::FDIV::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  unsigned int ira=(unsigned int)ra;
  float fra=  *( (float*)( (void*)(&ira) ) );
  unsigned int irb=(unsigned int)rb;
  float frb= *( (float*)( (void*)(&irb) ) );
  float fres=frb / fra;
  unsigned int res= *( (int*)( (void*)(&fres) ) );
  //if isDnz(ra) or isDnz(rb):
  if ( (ira & 0x7f800000 == 0 && ira & 0x007fffff != 0) || ( irb & 0x7f800000 ==
    0 && irb & 0x007fffff != 0 )){
    rd=(unsigned int)0xffc00000;
    FSR[key_DO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isSigNan(ra) or isSigNaN(rb) or (isZero(ra) and isZero(rb)) or
  // (isInfinite(ra) and isInfinite(rb)):
  else if ( (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira &
    0x00400000 == 0) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 == 0) ||
  (
  (ira & 0x7f800000 == 0 && ira & 0x007fffff == 0) &&
  (irb & 0x7f800000 == 0 && irb & 0x007fffff == 0)

  ) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0)
  )
  ){
    rd=(unsigned int)0xffc00000;
    FSR[key_IO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isZero(ra) and not isInfinite(rb):
  else if (
  (ira & 0x7f800000 == 0 && ira & 0x007fffff == 0) &&
  ( ! ( irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0 )) ){
    rd =(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_DZ]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isQuietNaN(ra) or isQuietNaN(rb):
  else if (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira & 0x00400000 ==
    0x00400000) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 ==
    0x00400000)
  ){
    rd=(unsigned int)0xffc00000;
  }
  //else if isDnz (rb/ra):
  else if(res & 0x7f800000 == 0 && res & 0x007fffff != 0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_UF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isNaN(rb/ra):
  else if (res & 0x7f800000 == 0x7f800000 && res & 0x007fffff !=0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_OF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  else {
    rd=(unsigned int)res;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FDIV::replicate() const throw() {
  return new FDIV(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FDIV::getInstructionName() const throw() {
  return "FDIV";
} // getInstructionName()

unsigned int core_microblaze_lt::FDIV::getId() const throw() {
  return 61;
} // getId()

void core_microblaze_lt::FDIV::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::FDIV::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FDIV::FDIV(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FDIV()

core_microblaze_lt::FDIV::~FDIV() {

} // ~FDIV()

unsigned int core_microblaze_lt::FADD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  unsigned int ira=(unsigned int)ra;
  float fra=  *( (float*)( (void*)(&ira) ) );
  unsigned int irb=(unsigned int)rb;
  float frb= *( (float*)( (void*)(&irb) ) );
  float fres=fra+frb;
  unsigned int res= *( (int*)( (void*)(&fres) ) );
  //if isDnz(ra) or isDnz(rb):
  if ( (ira & 0x7f800000 == 0 && ira & 0x007fffff != 0) || ( irb & 0x7f800000 ==
    0 && irb & 0x007fffff != 0 )){
    rd=(unsigned int)0xffc00000;
    FSR[key_DO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isSigNan(ra) or isSigNaN(rb) or (isPosInfinite(ra) and isNegInfinite(rb))
  // or (isNegInfinite(ra) and isPosInfinite(rb)):
  else if ( (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira &
    0x00400000 == 0) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 == 0) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0 & ira & 0x80000000 ==
    0x80000000) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0 & irb & 0x80000000 == 0)
  ) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0 & ira & 0x80000000 == 0) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0 & irb & 0x80000000 ==
    0x80000000)
  )
  ){
    rd=(unsigned int)0xffc00000;
    FSR[key_IO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isQuietNaN(ra) or isQuietNaN(rb):
  else if (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira & 0x00400000 ==
    0x00400000) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 ==
    0x00400000)
  ){
    rd=(unsigned int)0xffc00000;
  }
  //else if isDnz (ra+rb):
  else if(res & 0x7f800000 == 0 && res & 0x007fffff != 0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_UF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isNaN(ra+rb):
  else if (res & 0x7f800000 == 0x7f800000 && res & 0x007fffff !=0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_OF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  else {
    rd=(unsigned int)res;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FADD::replicate() const throw() {
  return new FADD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FADD::getInstructionName() const throw() {
  return "FADD";
} // getInstructionName()

unsigned int core_microblaze_lt::FADD::getId() const throw() {
  return 58;
} // getId()

void core_microblaze_lt::FADD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::FADD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FADD::FADD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FADD()

core_microblaze_lt::FADD::~FADD() {

} // ~FADD()

unsigned int core_microblaze_lt::MULHU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  unsigned long long res = (  (unsigned long long)(unsigned int)ra *  (unsigned
    long long)(unsigned int)rb );
  res>>=32;
  rd = (unsigned int) res;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MULHU::replicate() const throw() {
  return new MULHU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MULHU::getInstructionName() const throw() {
  return "MULHU";
} // getInstructionName()

unsigned int core_microblaze_lt::MULHU::getId() const throw() {
  return 81;
} // getId()

void core_microblaze_lt::MULHU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::MULHU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "mulhu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MULHU::MULHU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MULHU()

core_microblaze_lt::MULHU::~MULHU() {

} // ~MULHU()

unsigned int core_microblaze_lt::BGTD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra > 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGTD::replicate() const throw() {
  return new BGTD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGTD::getInstructionName() const throw() {
  return "BGTD";
} // getInstructionName()

unsigned int core_microblaze_lt::BGTD::getId() const throw() {
  return 21;
} // getId()

void core_microblaze_lt::BGTD::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BGTD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgtd r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGTD::BGTD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGTD()

core_microblaze_lt::BGTD::~BGTD() {

} // ~BGTD()

unsigned int core_microblaze_lt::BGTI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra>0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGTI::replicate() const throw() {
  return new BGTI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGTI::getInstructionName() const throw() {
  return "BGTI";
} // getInstructionName()

unsigned int core_microblaze_lt::BGTI::getId() const throw() {
  return 22;
} // getId()

void core_microblaze_lt::BGTI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BGTI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgti r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGTI::BGTI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGTI()

core_microblaze_lt::BGTI::~BGTI() {

} // ~BGTI()

unsigned int core_microblaze_lt::SEXT8::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result;
  if ( ( (int)ra & 0x00000080 ) != 0) {
    result = (int)ra | 0xffffff00;
  } else {
    result = (int)ra & 0x000000ff;
  }
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SEXT8::replicate() const throw() {
  return new SEXT8(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SEXT8::getInstructionName() const throw() {
  return "SEXT8";
} // getInstructionName()

unsigned int core_microblaze_lt::SEXT8::getId() const throw() {
  return 108;
} // getId()

void core_microblaze_lt::SEXT8::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::SEXT8::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sext8 r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SEXT8::SEXT8(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SEXT8()

core_microblaze_lt::SEXT8::~SEXT8() {

} // ~SEXT8()

unsigned int core_microblaze_lt::LHU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  if ( (addr & 0x00000001) != 0 ) {
    handleMemoryException(0x0,0x0,rd_bit,addr);
  } else {
    rd = dataMem.read_half(addr);
    rd &= 0x0000ffff;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LHU::replicate() const throw() {
  return new LHU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LHU::getInstructionName() const throw() {
  return "LHU";
} // getInstructionName()

unsigned int core_microblaze_lt::LHU::getId() const throw() {
  return 71;
} // getId()

void core_microblaze_lt::LHU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::LHU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lhu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LHU::LHU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LHU()

core_microblaze_lt::LHU::~LHU() {

} // ~LHU()

unsigned int core_microblaze_lt::BNE::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra!=0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BNE::replicate() const throw() {
  return new BNE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BNE::getInstructionName() const throw() {
  return "BNE";
} // getInstructionName()

unsigned int core_microblaze_lt::BNE::getId() const throw() {
  return 32;
} // getId()

void core_microblaze_lt::BNE::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BNE::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bne r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BNE::BNE(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BNE()

core_microblaze_lt::BNE::~BNE() {

} // ~BNE()

unsigned int core_microblaze_lt::BRLD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  rd = PC;
  TARGET = PC + (int)rb;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRLD::replicate() const throw() {
  return new BRLD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRLD::getInstructionName() const throw() {
  return "BRLD";
} // getInstructionName()

unsigned int core_microblaze_lt::BRLD::getId() const throw() {
  return 40;
} // getId()

void core_microblaze_lt::BRLD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRLD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brld r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRLD::BRLD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRLD()

core_microblaze_lt::BRLD::~BRLD() {

} // ~BRLD()

unsigned int core_microblaze_lt::BRKI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((MSR[key_UM] == 1) && ((int)imm_value != 0x8) && ((int)imm_value != 0x18)) {
    ESR[key_EC] = 0x1c;
  } else {
    rd = PC;
    PC = (int)imm_value;
    MSR[key_BIP] = 0x1;
    if ( ((int)imm_value == 0x8) || ((int)imm_value == 0x18) ) {
      MSR[key_UMS] = MSR[key_UM];
      MSR[key_VMS] = MSR[key_VM];
      MSR[key_UM] = 0x0;
      MSR[key_VM] = 0x0;
    }
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRKI::replicate() const throw() {
  return new BRKI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRKI::getInstructionName() const throw() {
  return "BRKI";
} // getInstructionName()

unsigned int core_microblaze_lt::BRKI::getId() const throw() {
  return 49;
} // getId()

void core_microblaze_lt::BRKI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRKI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brki r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRKI::BRKI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRKI()

core_microblaze_lt::BRKI::~BRKI() {

} // ~BRKI()

unsigned int core_microblaze_lt::ADDIKC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra + (int)imm_value + (int)MSR[key_C];
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDIKC::replicate() const throw() {
  return new ADDIKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDIKC::getInstructionName() const throw() {
  return "ADDIKC";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDIKC::getId() const throw() {
  return 7;
} // getId()

void core_microblaze_lt::ADDIKC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ADDIKC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addikc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDIKC::ADDIKC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDIKC()

core_microblaze_lt::ADDIKC::~ADDIKC() {

} // ~ADDIKC()

unsigned int core_microblaze_lt::IDIV::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if (ra==0){
    rd=(int)0;
    MSR[key_DZ]=1;
    ESR[key_EC]=0x14; // 00101 ---> 10100
    //EXCEPTION
  }
  else{
    rd=(int) (((int)rb)/((int)ra));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::IDIV::replicate() const throw() {
  return new IDIV(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::IDIV::getInstructionName() const throw() {
  return "IDIV";
} // getInstructionName()

unsigned int core_microblaze_lt::IDIV::getId() const throw() {
  return 66;
} // getId()

void core_microblaze_lt::IDIV::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::IDIV::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "idiv r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::IDIV::IDIV(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // IDIV()

core_microblaze_lt::IDIV::~IDIV() {

} // ~IDIV()

unsigned int core_microblaze_lt::ADDC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long result = (long long)((int)ra) + (long long)((int)rb) + (long long)MSR[key_C];
  MSR[key_C] = ((ra^rb^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDC::replicate() const throw() {
  return new ADDC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDC::getInstructionName() const throw() {
  return "ADDC";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDC::getId() const throw() {
  return 1;
} // getId()

void core_microblaze_lt::ADDC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::ADDC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDC::ADDC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDC()

core_microblaze_lt::ADDC::~ADDC() {

} // ~ADDC()

unsigned int core_microblaze_lt::LBUI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  rd = dataMem.read_byte(addr);
  rd &= 0x000000ff;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LBUI::replicate() const throw() {
  return new LBUI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LBUI::getInstructionName() const throw() {
  return "LBUI";
} // getInstructionName()

unsigned int core_microblaze_lt::LBUI::getId() const throw() {
  return 70;
} // getId()

void core_microblaze_lt::LBUI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::LBUI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lbui r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LBUI::LBUI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LBUI()

core_microblaze_lt::LBUI::~LBUI() {

} // ~LBUI()

unsigned int core_microblaze_lt::ADDK::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)rb + (int)ra;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDK::replicate() const throw() {
  return new ADDK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDK::getInstructionName() const throw() {
  return "ADDK";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDK::getId() const throw() {
  return 2;
} // getId()

void core_microblaze_lt::ADDK::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::ADDK::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addk r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDK::ADDK(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDK()

core_microblaze_lt::ADDK::~ADDK() {

} // ~ADDK()

unsigned int core_microblaze_lt::OR::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd =  (int)ra | (int)rb;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::OR::replicate() const throw() {
  return new OR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::OR::getInstructionName() const throw() {
  return "OR";
} // getInstructionName()

unsigned int core_microblaze_lt::OR::getId() const throw() {
  return 84;
} // getId()

void core_microblaze_lt::OR::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::OR::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "or r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::OR::OR(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // OR()

core_microblaze_lt::OR::~OR() {

} // ~OR()

unsigned int core_microblaze_lt::ADDI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long result = (long long)((long long)((int)ra) + ((long long)(int)imm_value));
  MSR[key_C] = ((ra^imm_value^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDI::replicate() const throw() {
  return new ADDI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDI::getInstructionName() const throw() {
  return "ADDI";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDI::getId() const throw() {
  return 4;
} // getId()

void core_microblaze_lt::ADDI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ADDI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDI::ADDI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDI()

core_microblaze_lt::ADDI::~ADDI() {

} // ~ADDI()

unsigned int core_microblaze_lt::BEQID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra == 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BEQID::replicate() const throw() {
  return new BEQID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BEQID::getInstructionName() const throw() {
  return "BEQID";
} // getInstructionName()

unsigned int core_microblaze_lt::BEQID::getId() const throw() {
  return 15;
} // getId()

void core_microblaze_lt::BEQID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BEQID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "beqid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BEQID::BEQID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BEQID()

core_microblaze_lt::BEQID::~BEQID() {

} // ~BEQID()

unsigned int core_microblaze_lt::CMPU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result = (unsigned int)rb + ~((unsigned int)ra) + 1;
  if ((unsigned int)ra > (unsigned int) rb) {
    result |= 0x80000000;
  } else {
    result &= 0x7fffffff;
  }
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::CMPU::replicate() const throw() {
  return new CMPU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::CMPU::getInstructionName() const throw() {
  return "CMPU";
} // getInstructionName()

unsigned int core_microblaze_lt::CMPU::getId() const throw() {
  return 57;
} // getId()

void core_microblaze_lt::CMPU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::CMPU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "cmpu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::CMPU::CMPU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // CMPU()

core_microblaze_lt::CMPU::~CMPU() {

} // ~CMPU()

unsigned int core_microblaze_lt::FINT::behavior() {
  this->totalInstrCycles = 0;


  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FINT::replicate() const throw() {
  return new FINT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FINT::getInstructionName() const throw() {
  return "FINT";
} // getInstructionName()

unsigned int core_microblaze_lt::FINT::getId() const throw() {
  return 64;
} // getId()

void core_microblaze_lt::FINT::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::FINT::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FINT::FINT(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FINT()

core_microblaze_lt::FINT::~FINT() {

} // ~FINT()

unsigned int core_microblaze_lt::BSRL::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (unsigned int)ra >> ((int)rb & 0x1f); /* I consider only the five less
    significant bits */
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSRL::replicate() const throw() {
  return new BSRL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSRL::getInstructionName() const throw() {
  return "BSRL";
} // getInstructionName()

unsigned int core_microblaze_lt::BSRL::getId() const throw() {
  return 50;
} // getId()

void core_microblaze_lt::BSRL::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BSRL::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bsrl r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSRL::BSRL(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSRL()

core_microblaze_lt::BSRL::~BSRL() {

} // ~BSRL()

unsigned int core_microblaze_lt::BLTI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra<0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLTI::replicate() const throw() {
  return new BLTI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLTI::getInstructionName() const throw() {
  return "BLTI";
} // getInstructionName()

unsigned int core_microblaze_lt::BLTI::getId() const throw() {
  return 30;
} // getId()

void core_microblaze_lt::BLTI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BLTI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "blti r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLTI::BLTI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLTI()

core_microblaze_lt::BLTI::~BLTI() {

} // ~BLTI()

unsigned int core_microblaze_lt::PCMPEQ::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = ((int)rb == (int)ra);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::PCMPEQ::replicate() const throw() {
  return new PCMPEQ(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::PCMPEQ::getInstructionName() const throw() {
  return "PCMPEQ";
} // getInstructionName()

unsigned int core_microblaze_lt::PCMPEQ::getId() const throw() {
  return 87;
} // getId()

void core_microblaze_lt::PCMPEQ::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::PCMPEQ::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "pcmpeq r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::PCMPEQ::PCMPEQ(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // PCMPEQ()

core_microblaze_lt::PCMPEQ::~PCMPEQ() {

} // ~PCMPEQ()

unsigned int core_microblaze_lt::XOR::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra ^ (int)rb;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::XOR::replicate() const throw() {
  return new XOR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::XOR::getInstructionName() const throw() {
  return "XOR";
} // getInstructionName()

unsigned int core_microblaze_lt::XOR::getId() const throw() {
  return 114;
} // getId()

void core_microblaze_lt::XOR::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::XOR::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "xor r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::XOR::XOR(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // XOR()

core_microblaze_lt::XOR::~XOR() {

} // ~XOR()

unsigned int core_microblaze_lt::BEQ::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra==0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BEQ::replicate() const throw() {
  return new BEQ(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BEQ::getInstructionName() const throw() {
  return "BEQ";
} // getInstructionName()

unsigned int core_microblaze_lt::BEQ::getId() const throw() {
  return 12;
} // getId()

void core_microblaze_lt::BEQ::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BEQ::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "beq r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BEQ::BEQ(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BEQ()

core_microblaze_lt::BEQ::~BEQ() {

} // ~BEQ()

unsigned int core_microblaze_lt::BLTD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra < 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLTD::replicate() const throw() {
  return new BLTD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLTD::getInstructionName() const throw() {
  return "BLTD";
} // getInstructionName()

unsigned int core_microblaze_lt::BLTD::getId() const throw() {
  return 29;
} // getId()

void core_microblaze_lt::BLTD::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BLTD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bltd r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLTD::BLTD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLTD()

core_microblaze_lt::BLTD::~BLTD() {

} // ~BLTD()

unsigned int core_microblaze_lt::CMP::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result = (int)rb + ~((int)ra) + 1;
  if ((int)ra > (int) rb) {
    result |= 0x80000000;
  } else {
    result &= 0x7fffffff;
  }
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::CMP::replicate() const throw() {
  return new CMP(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::CMP::getInstructionName() const throw() {
  return "CMP";
} // getInstructionName()

unsigned int core_microblaze_lt::CMP::getId() const throw() {
  return 56;
} // getId()

void core_microblaze_lt::CMP::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::CMP::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "cmp r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::CMP::CMP(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // CMP()

core_microblaze_lt::CMP::~CMP() {

} // ~CMP()

unsigned int core_microblaze_lt::BRALID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  rd = PC;
  TARGET = (int)imm_value;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRALID::replicate() const throw() {
  return new BRALID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRALID::getInstructionName() const throw() {
  return "BRALID";
} // getInstructionName()

unsigned int core_microblaze_lt::BRALID::getId() const throw() {
  return 47;
} // getId()

void core_microblaze_lt::BRALID::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRALID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bralid r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRALID::BRALID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRALID()

core_microblaze_lt::BRALID::~BRALID() {

} // ~BRALID()

unsigned int core_microblaze_lt::RTBD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ( MSR[key_UM] == 1 ) {
    handleUserPermissionException();
  } else {
    TARGET = (int)ra + (int)imm_value;
    MSR[key_BIP] = 0x0;
    MSR[key_UM] = MSR[key_UMS];
    MSR[key_VM] = MSR[key_VMS];
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RTBD::replicate() const throw() {
  return new RTBD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RTBD::getInstructionName() const throw() {
  return "RTBD";
} // getInstructionName()

unsigned int core_microblaze_lt::RTBD::getId() const throw() {
  return 97;
} // getId()

void core_microblaze_lt::RTBD::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RTBD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rtbd r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RTBD::RTBD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RTBD()

core_microblaze_lt::RTBD::~RTBD() {

} // ~RTBD()

unsigned int core_microblaze_lt::MFS::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  switch (rs){
    case 0x0000:
    rd=PC;
    break;
    case 0x0001:
    rd=MSR;
    break;
    case 0x0003:
    rd=EAR;
    break;
    case 0x0005:
    rd=ESR;
    break;
    case 0x0007:
    rd=FSR;
    break;
    case 0x000b:
    rd=BTR;
    break;
    case 0x000d:
    rd=EDR;
    break;
    case 0x1000:
    rd=PID;
    break;
    case 0x1001:
    rd=ZPR;
    break;
    case 0x1002:
    rd=TLBX;
    break;
    case 0x1003:
    rd=TLBLO;
    break;
    case 0x1004:
    rd=TLBHI;
    break;
  };
  if (rs>=0x2000 && rs <=0x200b){
    rd=PVR[rs-0x2000];
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MFS::replicate() const throw() {
  return new MFS(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MFS::getInstructionName() const throw() {
  return "MFS";
} // getInstructionName()

unsigned int core_microblaze_lt::MFS::getId() const throw() {
  return 75;
} // getId()

void core_microblaze_lt::MFS::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rs = (bitString & 0x3fff);
} // setParams()

std::string core_microblaze_lt::MFS::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MFS::MFS(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MFS()

core_microblaze_lt::MFS::~MFS() {

} // ~MFS()

unsigned int core_microblaze_lt::BLT::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra<0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLT::replicate() const throw() {
  return new BLT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLT::getInstructionName() const throw() {
  return "BLT";
} // getInstructionName()

unsigned int core_microblaze_lt::BLT::getId() const throw() {
  return 28;
} // getId()

void core_microblaze_lt::BLT::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BLT::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "blt r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLT::BLT(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLT()

core_microblaze_lt::BLT::~BLT() {

} // ~BLT()

unsigned int core_microblaze_lt::BRLID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  rd = PC;
  TARGET = PC + (int)imm_value;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRLID::replicate() const throw() {
  return new BRLID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRLID::getInstructionName() const throw() {
  return "BRLID";
} // getInstructionName()

unsigned int core_microblaze_lt::BRLID::getId() const throw() {
  return 46;
} // getId()

void core_microblaze_lt::BRLID::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRLID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brlid r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRLID::BRLID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRLID()

core_microblaze_lt::BRLID::~BRLID() {

} // ~BRLID()

unsigned int core_microblaze_lt::SB::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  dataMem.write_byte(addr, (unsigned char)(rd & 0x000000ff));
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SB::replicate() const throw() {
  return new SB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SB::getInstructionName() const throw() {
  return "SB";
} // getInstructionName()

unsigned int core_microblaze_lt::SB::getId() const throw() {
  return 101;
} // getId()

void core_microblaze_lt::SB::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::SB::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sb r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SB::SB(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SB()

core_microblaze_lt::SB::~SB() {

} // ~SB()

unsigned int core_microblaze_lt::BLE::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra<=0) {
    PC = PC + (int)rb;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLE::replicate() const throw() {
  return new BLE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLE::getInstructionName() const throw() {
  return "BLE";
} // getInstructionName()

unsigned int core_microblaze_lt::BLE::getId() const throw() {
  return 24;
} // getId()

void core_microblaze_lt::BLE::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BLE::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "ble r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLE::BLE(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLE()

core_microblaze_lt::BLE::~BLE() {

} // ~BLE()

unsigned int core_microblaze_lt::SHI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  if ( ( addr & 0x00000001 ) != 0 ) {
    handleMemoryException(0x0,0x1,rd_bit,addr);
  } else {
    dataMem.write_half(addr, (unsigned int)(rd & 0x0000ffff));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SHI::replicate() const throw() {
  return new SHI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SHI::getInstructionName() const throw() {
  return "SHI";
} // getInstructionName()

unsigned int core_microblaze_lt::SHI::getId() const throw() {
  return 104;
} // getId()

void core_microblaze_lt::SHI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::SHI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "shi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SHI::SHI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SHI()

core_microblaze_lt::SHI::~SHI() {

} // ~SHI()

unsigned int core_microblaze_lt::AND::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra & (int)rb;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::AND::replicate() const throw() {
  return new AND(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::AND::getInstructionName() const throw() {
  return "AND";
} // getInstructionName()

unsigned int core_microblaze_lt::AND::getId() const throw() {
  return 8;
} // getId()

void core_microblaze_lt::AND::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::AND::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "and r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::AND::AND(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // AND()

core_microblaze_lt::AND::~AND() {

} // ~AND()

unsigned int core_microblaze_lt::RSUBIC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int imm = (int)imm_value;
  long long result = (long long) ( ((long long)imm) + ~((long long)a) + (int)MSR[key_C]);
  MSR[key_C] = ( ((~a + MSR[key_C])^imm^(unsigned int)(result >> 1)) & 0x80000000)
    != 0;
  rd=(int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBIC::replicate() const throw() {
  return new RSUBIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBIC::getInstructionName() const throw() {
  return "RSUBIC";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBIC::getId() const throw() {
  return 94;
} // getId()

void core_microblaze_lt::RSUBIC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RSUBIC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubic r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBIC::RSUBIC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBIC()

core_microblaze_lt::RSUBIC::~RSUBIC() {

} // ~RSUBIC()

unsigned int core_microblaze_lt::SBI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  dataMem.write_byte(addr, (unsigned char)(rd & 0x000000ff));
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SBI::replicate() const throw() {
  return new SBI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SBI::getInstructionName() const throw() {
  return "SBI";
} // getInstructionName()

unsigned int core_microblaze_lt::SBI::getId() const throw() {
  return 102;
} // getId()

void core_microblaze_lt::SBI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::SBI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sbi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SBI::SBI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SBI()

core_microblaze_lt::SBI::~SBI() {

} // ~SBI()

unsigned int core_microblaze_lt::RTED::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ( MSR[key_UM] == 1 ) {
    handleUserPermissionException();
  } else {
    if (ESR[key_DS] ) {
      TARGET = BTR;
    } else {
      TARGET = (int)ra + (int)imm_value;
    }
    MSR[key_EE] = 0x1;
    MSR[key_EIP] = 0x0;
    MSR[key_UM] = MSR[key_UMS];
    MSR[key_VM] = MSR[key_VMS];
    ESR = 0x0;
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RTED::replicate() const throw() {
  return new RTED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RTED::getInstructionName() const throw() {
  return "RTED";
} // getInstructionName()

unsigned int core_microblaze_lt::RTED::getId() const throw() {
  return 99;
} // getId()

void core_microblaze_lt::RTED::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RTED::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rted r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RTED::RTED(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RTED()

core_microblaze_lt::RTED::~RTED() {

} // ~RTED()

unsigned int core_microblaze_lt::RSUBIK::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int imm = (int)imm_value;
  rd=(int)(imm + ~a + 1);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBIK::replicate() const throw() {
  return new RSUBIK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBIK::getInstructionName() const throw() {
  return "RSUBIK";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBIK::getId() const throw() {
  return 95;
} // getId()

void core_microblaze_lt::RSUBIK::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RSUBIK::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubik r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBIK::RSUBIK(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBIK()

core_microblaze_lt::RSUBIK::~RSUBIK() {

} // ~RSUBIK()

unsigned int core_microblaze_lt::BRALD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  rd = PC;
  TARGET = (int)rb;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRALD::replicate() const throw() {
  return new BRALD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRALD::getInstructionName() const throw() {
  return "BRALD";
} // getInstructionName()

unsigned int core_microblaze_lt::BRALD::getId() const throw() {
  return 41;
} // getId()

void core_microblaze_lt::BRALD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRALD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brald r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRALD::BRALD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRALD()

core_microblaze_lt::BRALD::~BRALD() {

} // ~BRALD()

unsigned int core_microblaze_lt::BRA::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  PC = (int)rb;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRA::replicate() const throw() {
  return new BRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRA::getInstructionName() const throw() {
  return "BRA";
} // getInstructionName()

unsigned int core_microblaze_lt::BRA::getId() const throw() {
  return 37;
} // getId()

void core_microblaze_lt::BRA::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRA::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bra r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRA::BRA(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRA()

core_microblaze_lt::BRA::~BRA() {

} // ~BRA()

unsigned int core_microblaze_lt::FSQRT::behavior() {
  this->totalInstrCycles = 0;


  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FSQRT::replicate() const throw() {
  return new FSQRT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FSQRT::getInstructionName() const throw() {
  return "FSQRT";
} // getInstructionName()

unsigned int core_microblaze_lt::FSQRT::getId() const throw() {
  return 65;
} // getId()

void core_microblaze_lt::FSQRT::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::FSQRT::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FSQRT::FSQRT(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FSQRT()

core_microblaze_lt::FSQRT::~FSQRT() {

} // ~FSQRT()

unsigned int core_microblaze_lt::SEXT16::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result;
  if ( ( (int)ra & 0x00008000 ) != 0) {
    result = (int)ra | 0xffff0000;
  } else {
    result = (int)ra & 0x0000ffff;
  }
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SEXT16::replicate() const throw() {
  return new SEXT16(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SEXT16::getInstructionName() const throw() {
  return "SEXT16";
} // getInstructionName()

unsigned int core_microblaze_lt::SEXT16::getId() const throw() {
  return 107;
} // getId()

void core_microblaze_lt::SEXT16::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::SEXT16::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sext16 r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SEXT16::SEXT16(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SEXT16()

core_microblaze_lt::SEXT16::~SEXT16() {

} // ~SEXT16()

unsigned int core_microblaze_lt::SWI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  if ( ( addr & 0x00000003 ) != 0 ) {
    handleMemoryException(0x1,0x1,rd_bit,addr);
  } else {
    dataMem.write_word(addr, (unsigned int)(rd));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SWI::replicate() const throw() {
  return new SWI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SWI::getInstructionName() const throw() {
  return "SWI";
} // getInstructionName()

unsigned int core_microblaze_lt::SWI::getId() const throw() {
  return 106;
} // getId()

void core_microblaze_lt::SWI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::SWI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "swi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SWI::SWI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SWI()

core_microblaze_lt::SWI::~SWI() {

} // ~SWI()

unsigned int core_microblaze_lt::BLEID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra <= 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLEID::replicate() const throw() {
  return new BLEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLEID::getInstructionName() const throw() {
  return "BLEID";
} // getInstructionName()

unsigned int core_microblaze_lt::BLEID::getId() const throw() {
  return 27;
} // getId()

void core_microblaze_lt::BLEID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BLEID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bleid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLEID::BLEID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLEID()

core_microblaze_lt::BLEID::~BLEID() {

} // ~BLEID()

unsigned int core_microblaze_lt::BSRA::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra >> ((int)rb & 0x1f); /* the C shift is Arithmetical! */
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSRA::replicate() const throw() {
  return new BSRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSRA::getInstructionName() const throw() {
  return "BSRA";
} // getInstructionName()

unsigned int core_microblaze_lt::BSRA::getId() const throw() {
  return 51;
} // getId()

void core_microblaze_lt::BSRA::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BSRA::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bsra r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSRA::BSRA(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSRA()

core_microblaze_lt::BSRA::~BSRA() {

} // ~BSRA()

unsigned int core_microblaze_lt::BLED::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra <= 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLED::replicate() const throw() {
  return new BLED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLED::getInstructionName() const throw() {
  return "BLED";
} // getInstructionName()

unsigned int core_microblaze_lt::BLED::getId() const throw() {
  return 25;
} // getId()

void core_microblaze_lt::BLED::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BLED::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bled r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLED::BLED(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLED()

core_microblaze_lt::BLED::~BLED() {

} // ~BLED()

unsigned int core_microblaze_lt::MULI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long res = (int)ra * (int)imm_value;
  rd = (int) res;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MULI::replicate() const throw() {
  return new MULI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MULI::getInstructionName() const throw() {
  return "MULI";
} // getInstructionName()

unsigned int core_microblaze_lt::MULI::getId() const throw() {
  return 83;
} // getId()

void core_microblaze_lt::MULI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::MULI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "muli r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MULI::MULI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MULI()

core_microblaze_lt::MULI::~MULI() {

} // ~MULI()

unsigned int core_microblaze_lt::MSRSET::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if (MSR[key_UM] == 1 && ((unsigned int)imm15) != 0x4 ){
    ESR[key_EC]=0x1c; // 00111 -----> 11100
    //EXCEPTION
  }
  else{
    rd=MSR;
    unsigned int imm=0;
    for (int i=0;i<15;i++){
      imm+=((unsigned int)imm15)%2;
      imm15>>=1;
      imm<<=1;
    }
    imm<<=16;
    imm &= 0xfffe0000;
    MSR |= imm ;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MSRSET::replicate() const throw() {
  return new MSRSET(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MSRSET::getInstructionName() const throw() {
  return "MSRSET";
} // getInstructionName()

unsigned int core_microblaze_lt::MSRSET::getId() const throw() {
  return 77;
} // getId()

void core_microblaze_lt::MSRSET::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm15 = (bitString & 0x7fff);
} // setParams()

std::string core_microblaze_lt::MSRSET::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MSRSET::MSRSET(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MSRSET()

core_microblaze_lt::MSRSET::~MSRSET() {

} // ~MSRSET()

unsigned int core_microblaze_lt::MUL::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long res = ( (long long)(int)rb * (long long)(int)ra );
  rd = (int) res;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MUL::replicate() const throw() {
  return new MUL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MUL::getInstructionName() const throw() {
  return "MUL";
} // getInstructionName()

unsigned int core_microblaze_lt::MUL::getId() const throw() {
  return 79;
} // getId()

void core_microblaze_lt::MUL::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::MUL::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "mul r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MUL::MUL(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MUL()

core_microblaze_lt::MUL::~MUL() {

} // ~MUL()

unsigned int core_microblaze_lt::BLEI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra<=0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLEI::replicate() const throw() {
  return new BLEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLEI::getInstructionName() const throw() {
  return "BLEI";
} // getInstructionName()

unsigned int core_microblaze_lt::BLEI::getId() const throw() {
  return 26;
} // getId()

void core_microblaze_lt::BLEI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BLEI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "blei r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLEI::BLEI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLEI()

core_microblaze_lt::BLEI::~BLEI() {

} // ~BLEI()

unsigned int core_microblaze_lt::RTSD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  TARGET = (int)ra + (int)imm_value;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RTSD::replicate() const throw() {
  return new RTSD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RTSD::getInstructionName() const throw() {
  return "RTSD";
} // getInstructionName()

unsigned int core_microblaze_lt::RTSD::getId() const throw() {
  return 100;
} // getId()

void core_microblaze_lt::RTSD::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RTSD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rtsd r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RTSD::RTSD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RTSD()

core_microblaze_lt::RTSD::~RTSD() {

} // ~RTSD()

unsigned int core_microblaze_lt::ANDN::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra & ~((int)rb);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ANDN::replicate() const throw() {
  return new ANDN(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ANDN::getInstructionName() const throw() {
  return "ANDN";
} // getInstructionName()

unsigned int core_microblaze_lt::ANDN::getId() const throw() {
  return 10;
} // getId()

void core_microblaze_lt::ANDN::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::ANDN::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addn r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ANDN::ANDN(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ANDN()

core_microblaze_lt::ANDN::~ANDN() {

} // ~ANDN()

unsigned int core_microblaze_lt::ANDI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra & (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ANDI::replicate() const throw() {
  return new ANDI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ANDI::getInstructionName() const throw() {
  return "ANDI";
} // getInstructionName()

unsigned int core_microblaze_lt::ANDI::getId() const throw() {
  return 9;
} // getId()

void core_microblaze_lt::ANDI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ANDI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "andi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ANDI::ANDI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ANDI()

core_microblaze_lt::ANDI::~ANDI() {

} // ~ANDI()

unsigned int core_microblaze_lt::ADDKC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)rb + (int)ra +(int)MSR[key_C];
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDKC::replicate() const throw() {
  return new ADDKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDKC::getInstructionName() const throw() {
  return "ADDKC";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDKC::getId() const throw() {
  return 3;
} // getId()

void core_microblaze_lt::ADDKC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::ADDKC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addkc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDKC::ADDKC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDKC()

core_microblaze_lt::ADDKC::~ADDKC() {

} // ~ADDKC()

unsigned int core_microblaze_lt::MSRCLR::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if (MSR[key_UM] == 1 && ((unsigned int)imm15) != 0x4 ){
    ESR[key_EC]=0x1c; // 00111 -----> 11100
    //EXCEPTION
  }
  else{
    rd=MSR;
    unsigned int imm=0;
    for (int i=0;i<15;i++){
      imm+=(((unsigned int)imm15)%2)==0;
      imm15>>=1;
      imm<<=1;
    }
    imm<<=16;
    imm |= 0x0001ffff;
    MSR &= imm ;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MSRCLR::replicate() const throw() {
  return new MSRCLR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MSRCLR::getInstructionName() const throw() {
  return "MSRCLR";
} // getInstructionName()

unsigned int core_microblaze_lt::MSRCLR::getId() const throw() {
  return 76;
} // getId()

void core_microblaze_lt::MSRCLR::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm15 = (bitString & 0x7fff);
} // setParams()

std::string core_microblaze_lt::MSRCLR::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MSRCLR::MSRCLR(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MSRCLR()

core_microblaze_lt::MSRCLR::~MSRCLR() {

} // ~MSRCLR()

unsigned int core_microblaze_lt::BSLLI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (unsigned int)ra << (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSLLI::replicate() const throw() {
  return new BSLLI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSLLI::getInstructionName() const throw() {
  return "BSLLI";
} // getInstructionName()

unsigned int core_microblaze_lt::BSLLI::getId() const throw() {
  return 55;
} // getId()

void core_microblaze_lt::BSLLI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0x1f);
} // setParams()

std::string core_microblaze_lt::BSLLI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bslli r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSLLI::BSLLI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSLLI()

core_microblaze_lt::BSLLI::~BSLLI() {

} // ~BSLLI()

unsigned int core_microblaze_lt::BGEI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra>=0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGEI::replicate() const throw() {
  return new BGEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGEI::getInstructionName() const throw() {
  return "BGEI";
} // getInstructionName()

unsigned int core_microblaze_lt::BGEI::getId() const throw() {
  return 18;
} // getId()

void core_microblaze_lt::BGEI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BGEI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgei r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGEI::BGEI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGEI()

core_microblaze_lt::BGEI::~BGEI() {

} // ~BGEI()

unsigned int core_microblaze_lt::SRC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result = ((int)ra)>>1;
  if (MSR[key_C]) {
    result |= 0x80000000;
  } else {
    result &= 0x7fffffff;
  }
  MSR[key_C]= ((int)ra & 0x00000001) ? 0x1 : 0x0;
  rd = (int) result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SRC::replicate() const throw() {
  return new SRC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SRC::getInstructionName() const throw() {
  return "SRC";
} // getInstructionName()

unsigned int core_microblaze_lt::SRC::getId() const throw() {
  return 110;
} // getId()

void core_microblaze_lt::SRC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::SRC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "src r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SRC::SRC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SRC()

core_microblaze_lt::SRC::~SRC() {

} // ~SRC()

unsigned int core_microblaze_lt::SRA::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result = ((int)ra)>>1;
  if ((int)ra & 0x80000000) {
    result |= 0x80000000;
  } else {
    result &= 0x7fffffff;
  }
  MSR[key_C]= ((int)ra & 0x00000001) ? 0x1 : 0x0;
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SRA::replicate() const throw() {
  return new SRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SRA::getInstructionName() const throw() {
  return "SRA";
} // getInstructionName()

unsigned int core_microblaze_lt::SRA::getId() const throw() {
  return 109;
} // getId()

void core_microblaze_lt::SRA::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::SRA::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sra r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SRA::SRA(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SRA()

core_microblaze_lt::SRA::~SRA() {

} // ~SRA()

unsigned int core_microblaze_lt::IMM::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  IMMREG = (int)imm & 0x0000ffff;
  IMMREG |= 0x80000000;
  /* We set the MSB bit: this indicate that the register's content is valid */
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::IMM::replicate() const throw() {
  return new IMM(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::IMM::getInstructionName() const throw() {
  return "IMM";
} // getInstructionName()

unsigned int core_microblaze_lt::IMM::getId() const throw() {
  return 68;
} // getId()

void core_microblaze_lt::IMM::setParams(const unsigned int & bitString) throw() {
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::IMM::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "imm";
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::IMM::IMM(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // IMM()

core_microblaze_lt::IMM::~IMM() {

} // ~IMM()

unsigned int core_microblaze_lt::SRL::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int result = ((int)ra)>>1;
  result &= 0x7fffffff;
  MSR[key_C]= ((int)ra & 0x00000001) ? 0x1 : 0x0;
  rd = (int) result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SRL::replicate() const throw() {
  return new SRL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SRL::getInstructionName() const throw() {
  return "SRL";
} // getInstructionName()

unsigned int core_microblaze_lt::SRL::getId() const throw() {
  return 111;
} // getId()

void core_microblaze_lt::SRL::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::SRL::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "srl r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SRL::SRL(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SRL()

core_microblaze_lt::SRL::~SRL() {

} // ~SRL()

unsigned int core_microblaze_lt::FLT::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int ira=(int)ra;
  float frd=(float)ira;
  rd=*((int*) ((void*)(&frd)));
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FLT::replicate() const throw() {
  return new FLT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FLT::getInstructionName() const throw() {
  return "FLT";
} // getInstructionName()

unsigned int core_microblaze_lt::FLT::getId() const throw() {
  return 63;
} // getId()

void core_microblaze_lt::FLT::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
} // setParams()

std::string core_microblaze_lt::FLT::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FLT::FLT(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FLT()

core_microblaze_lt::FLT::~FLT() {

} // ~FLT()

unsigned int core_microblaze_lt::MULHSU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long res = (long long)(int)ra * (unsigned long long)(unsigned int) rb;
  res>>=32;
  rd = (unsigned int) res;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MULHSU::replicate() const throw() {
  return new MULHSU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MULHSU::getInstructionName() const throw() {
  return "MULHSU";
} // getInstructionName()

unsigned int core_microblaze_lt::MULHSU::getId() const throw() {
  return 82;
} // getId()

void core_microblaze_lt::MULHSU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::MULHSU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "mulhsu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MULHSU::MULHSU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MULHSU()

core_microblaze_lt::MULHSU::~MULHSU() {

} // ~MULHSU()

unsigned int core_microblaze_lt::ADD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long result = (long long)((int)rb) + (long long)((int)ra);
  MSR[key_C] = ((ra^rb^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADD::replicate() const throw() {
  return new ADD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADD::getInstructionName() const throw() {
  return "ADD";
} // getInstructionName()

unsigned int core_microblaze_lt::ADD::getId() const throw() {
  return 0;
} // getId()

void core_microblaze_lt::ADD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::ADD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "add r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADD::ADD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADD()

core_microblaze_lt::ADD::~ADD() {

} // ~ADD()

unsigned int core_microblaze_lt::XORI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra ^ (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::XORI::replicate() const throw() {
  return new XORI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::XORI::getInstructionName() const throw() {
  return "XORI";
} // getInstructionName()

unsigned int core_microblaze_lt::XORI::getId() const throw() {
  return 115;
} // getId()

void core_microblaze_lt::XORI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::XORI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "xori r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::XORI::XORI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // XORI()

core_microblaze_lt::XORI::~XORI() {

} // ~XORI()

unsigned int core_microblaze_lt::PCMPNE::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = ((int)rb != (int)ra);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::PCMPNE::replicate() const throw() {
  return new PCMPNE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::PCMPNE::getInstructionName() const throw() {
  return "PCMPNE";
} // getInstructionName()

unsigned int core_microblaze_lt::PCMPNE::getId() const throw() {
  return 88;
} // getId()

void core_microblaze_lt::PCMPNE::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::PCMPNE::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "pcmpne r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::PCMPNE::PCMPNE(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // PCMPNE()

core_microblaze_lt::PCMPNE::~PCMPNE() {

} // ~PCMPNE()

unsigned int core_microblaze_lt::BSRAI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra >> (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BSRAI::replicate() const throw() {
  return new BSRAI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BSRAI::getInstructionName() const throw() {
  return "BSRAI";
} // getInstructionName()

unsigned int core_microblaze_lt::BSRAI::getId() const throw() {
  return 54;
} // getId()

void core_microblaze_lt::BSRAI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0x1f);
} // setParams()

std::string core_microblaze_lt::BSRAI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bsrai r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BSRAI::BSRAI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BSRAI()

core_microblaze_lt::BSRAI::~BSRAI() {

} // ~BSRAI()

unsigned int core_microblaze_lt::BRAID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  TARGET = (int)imm_value;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRAID::replicate() const throw() {
  return new BRAID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRAID::getInstructionName() const throw() {
  return "BRAID";
} // getInstructionName()

unsigned int core_microblaze_lt::BRAID::getId() const throw() {
  return 45;
} // getId()

void core_microblaze_lt::BRAID::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRAID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "braid r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRAID::BRAID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRAID()

core_microblaze_lt::BRAID::~BRAID() {

} // ~BRAID()

unsigned int core_microblaze_lt::WIC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  /* This instruction is related to the Cache. Since we don't have
  Cache in our model, we simply ignore the implementation of
  this instruction. */
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::WIC::replicate() const throw() {
  return new WIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::WIC::getInstructionName() const throw() {
  return "WIC";
} // getInstructionName()

unsigned int core_microblaze_lt::WIC::getId() const throw() {
  return 113;
} // getId()

void core_microblaze_lt::WIC::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::WIC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "wic r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::WIC::WIC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // WIC()

core_microblaze_lt::WIC::~WIC() {

} // ~WIC()

unsigned int core_microblaze_lt::RSUBKC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int b = (int)rb;
  rd = (int)(b + ~a + MSR[key_C]);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBKC::replicate() const throw() {
  return new RSUBKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBKC::getInstructionName() const throw() {
  return "RSUBKC";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBKC::getId() const throw() {
  return 92;
} // getId()

void core_microblaze_lt::RSUBKC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::RSUBKC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubkc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBKC::RSUBKC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBKC()

core_microblaze_lt::RSUBKC::~RSUBKC() {

} // ~RSUBKC()

unsigned int core_microblaze_lt::SW::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  if ( ( addr & 0x00000003 ) != 0 ) {
    handleMemoryException(0x1,0x1,rd_bit,addr);
  } else {
    dataMem.write_word(addr, (unsigned int)(rd));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SW::replicate() const throw() {
  return new SW(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SW::getInstructionName() const throw() {
  return "SW";
} // getInstructionName()

unsigned int core_microblaze_lt::SW::getId() const throw() {
  return 105;
} // getId()

void core_microblaze_lt::SW::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::SW::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sw r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SW::SW(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SW()

core_microblaze_lt::SW::~SW() {

} // ~SW()

unsigned int core_microblaze_lt::FCMP::behavior() {
  this->totalInstrCycles = 0;


  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FCMP::replicate() const throw() {
  return new FCMP(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FCMP::getInstructionName() const throw() {
  return "FCMP";
} // getInstructionName()

unsigned int core_microblaze_lt::FCMP::getId() const throw() {
  return 62;
} // getId()

void core_microblaze_lt::FCMP::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
  this->opsel = (bitString & 0x70) >> 4;
} // setParams()

std::string core_microblaze_lt::FCMP::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FCMP::FCMP(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FCMP()

core_microblaze_lt::FCMP::~FCMP() {

} // ~FCMP()

unsigned int core_microblaze_lt::SH::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  if ( ( addr & 0x00000001 ) != 0 ) {
    handleMemoryException(0x0,0x1,rd_bit,addr);
  } else {
    dataMem.write_half(addr, (unsigned int)(rd & 0x0000ffff));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::SH::replicate() const throw() {
  return new SH(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::SH::getInstructionName() const throw() {
  return "SH";
} // getInstructionName()

unsigned int core_microblaze_lt::SH::getId() const throw() {
  return 103;
} // getId()

void core_microblaze_lt::SH::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::SH::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "sh r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::SH::SH(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // SH()

core_microblaze_lt::SH::~SH() {

} // ~SH()

unsigned int core_microblaze_lt::BRK::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ( MSR[key_UM] == 0x1 ) {
    ESR[key_EC] = 0x1c;
  } else {
    rd = PC;
    PC = (int)rb;
    MSR[key_BIP] = 0x1;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRK::replicate() const throw() {
  return new BRK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRK::getInstructionName() const throw() {
  return "BRK";
} // getInstructionName()

unsigned int core_microblaze_lt::BRK::getId() const throw() {
  return 48;
} // getId()

void core_microblaze_lt::BRK::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRK::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brk r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRK::BRK(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRK()

core_microblaze_lt::BRK::~BRK() {

} // ~BRK()

unsigned int core_microblaze_lt::BRI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  PC = PC + (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRI::replicate() const throw() {
  return new BRI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRI::getInstructionName() const throw() {
  return "BRI";
} // getInstructionName()

unsigned int core_microblaze_lt::BRI::getId() const throw() {
  return 42;
} // getId()

void core_microblaze_lt::BRI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bri r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRI::BRI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRI()

core_microblaze_lt::BRI::~BRI() {

} // ~BRI()

unsigned int core_microblaze_lt::ORI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra | (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ORI::replicate() const throw() {
  return new ORI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ORI::getInstructionName() const throw() {
  return "ORI";
} // getInstructionName()

unsigned int core_microblaze_lt::ORI::getId() const throw() {
  return 85;
} // getId()

void core_microblaze_lt::ORI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ORI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "ori r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ORI::ORI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ORI()

core_microblaze_lt::ORI::~ORI() {

} // ~ORI()

unsigned int core_microblaze_lt::ANDNI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra & ~((int)imm_value);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ANDNI::replicate() const throw() {
  return new ANDNI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ANDNI::getInstructionName() const throw() {
  return "ANDNI";
} // getInstructionName()

unsigned int core_microblaze_lt::ANDNI::getId() const throw() {
  return 11;
} // getId()

void core_microblaze_lt::ANDNI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ANDNI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "andi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ANDNI::ANDNI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ANDNI()

core_microblaze_lt::ANDNI::~ANDNI() {

} // ~ANDNI()

unsigned int core_microblaze_lt::BRD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  TARGET = PC + (int)rb;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRD::replicate() const throw() {
  return new BRD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRD::getInstructionName() const throw() {
  return "BRD";
} // getInstructionName()

unsigned int core_microblaze_lt::BRD::getId() const throw() {
  return 38;
} // getId()

void core_microblaze_lt::BRD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brd r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRD::BRD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRD()

core_microblaze_lt::BRD::~BRD() {

} // ~BRD()

unsigned int core_microblaze_lt::LHUI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  if ( (addr & 0x00000001) != 0 ) {
    handleMemoryException(0x0,0x0,rd_bit,addr);
  } else {
    rd = dataMem.read_half(addr);
    rd &= 0x0000ffff;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LHUI::replicate() const throw() {
  return new LHUI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LHUI::getInstructionName() const throw() {
  return "LHUI";
} // getInstructionName()

unsigned int core_microblaze_lt::LHUI::getId() const throw() {
  return 72;
} // getId()

void core_microblaze_lt::LHUI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::LHUI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lhui r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LHUI::LHUI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LHUI()

core_microblaze_lt::LHUI::~LHUI() {

} // ~LHUI()

unsigned int core_microblaze_lt::RSUBIKC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int imm = (int)imm_value;
  rd=(int)(imm + ~a + (int)MSR[key_C]);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBIKC::replicate() const throw() {
  return new RSUBIKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBIKC::getInstructionName() const throw() {
  return "RSUBIKC";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBIKC::getId() const throw() {
  return 96;
} // getId()

void core_microblaze_lt::RSUBIKC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RSUBIKC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubikc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBIKC::RSUBIKC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBIKC()

core_microblaze_lt::RSUBIKC::~RSUBIKC() {

} // ~RSUBIKC()

unsigned int core_microblaze_lt::MULH::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long res = (long long) ( ( (long long)(int)ra) * ( (long long)(int)rb )   );
  res>>=32;
  rd = (int) res;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MULH::replicate() const throw() {
  return new MULH(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MULH::getInstructionName() const throw() {
  return "MULH";
} // getInstructionName()

unsigned int core_microblaze_lt::MULH::getId() const throw() {
  return 80;
} // getId()

void core_microblaze_lt::MULH::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::MULH::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "mulh r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MULH::MULH(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MULH()

core_microblaze_lt::MULH::~MULH() {

} // ~MULH()

unsigned int core_microblaze_lt::FRSUB::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  unsigned int ira=(unsigned int)ra;
  float fra=  *( (float*)( (void*)(&ira) ) );
  unsigned int irb=(unsigned int)rb;
  float frb= *( (float*)( (void*)(&irb) ) );
  float fres=frb-fra;
  unsigned int res= *( (int*)( (void*)(&fres) ) );
  //if isDnz(ra) or isDnz(rb):
  if ( (ira & 0x7f800000 == 0 && ira & 0x007fffff != 0) || ( irb & 0x7f800000 ==
    0 && irb & 0x007fffff != 0 )){
    rd=(unsigned int)0xffc00000;
    FSR[key_DO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isSigNan(ra) or isSigNaN(rb) or (isPosInfinite(ra) and isPosInfinite(rb))
  // or (isNegInfinite(ra) and isNegInfinite(rb)):
  else if ( (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira &
    0x00400000 == 0) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 == 0) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0 & ira & 0x80000000 ==
    0x80000000) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0 & irb & 0x80000000 ==
    0x80000000)
  ) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0 & ira & 0x80000000 == 0) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0 & irb & 0x80000000 == 0)
  )
  ){
    rd=(unsigned int)0xffc00000;
    FSR[key_IO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isQuietNaN(ra) or isQuietNaN(rb):
  else if (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira & 0x00400000 ==
    0x00400000) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 ==
    0x00400000)
  ){
    rd=(unsigned int)0xffc00000;
  }
  //else if isDnz (rb-ra):
  else if(res & 0x7f800000 == 0 && res & 0x007fffff != 0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_UF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isNaN(rb-ra):
  else if (res & 0x7f800000 == 0x7f800000 && res & 0x007fffff !=0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_OF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  else {
    rd=(unsigned int)res;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FRSUB::replicate() const throw() {
  return new FRSUB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FRSUB::getInstructionName() const throw() {
  return "FRSUB";
} // getInstructionName()

unsigned int core_microblaze_lt::FRSUB::getId() const throw() {
  return 59;
} // getId()

void core_microblaze_lt::FRSUB::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::FRSUB::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FRSUB::FRSUB(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FRSUB()

core_microblaze_lt::FRSUB::~FRSUB() {

} // ~FRSUB()

unsigned int core_microblaze_lt::BEQI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra==0) {
    PC = PC + (int)imm_value;
  } else {
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BEQI::replicate() const throw() {
  return new BEQI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BEQI::getInstructionName() const throw() {
  return "BEQI";
} // getInstructionName()

unsigned int core_microblaze_lt::BEQI::getId() const throw() {
  return 14;
} // getId()

void core_microblaze_lt::BEQI::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BEQI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "beqi r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BEQI::BEQI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BEQI()

core_microblaze_lt::BEQI::~BEQI() {

} // ~BEQI()

unsigned int core_microblaze_lt::BEQD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra == 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BEQD::replicate() const throw() {
  return new BEQD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BEQD::getInstructionName() const throw() {
  return "BEQD";
} // getInstructionName()

unsigned int core_microblaze_lt::BEQD::getId() const throw() {
  return 13;
} // getId()

void core_microblaze_lt::BEQD::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BEQD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "beqd r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BEQD::BEQD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BEQD()

core_microblaze_lt::BEQD::~BEQD() {

} // ~BEQD()

unsigned int core_microblaze_lt::RTID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ( MSR[key_UM] == 1 ) {
    handleUserPermissionException();
  } else {
    TARGET = (int)ra + (int)imm_value;
    MSR[key_IE] = 0x1;
    MSR[key_UM] = MSR[key_UMS];
    MSR[key_VM] = MSR[key_VMS];
    PC = PC + 4;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RTID::replicate() const throw() {
  return new RTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RTID::getInstructionName() const throw() {
  return "RTID";
} // getInstructionName()

unsigned int core_microblaze_lt::RTID::getId() const throw() {
  return 98;
} // getId()

void core_microblaze_lt::RTID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RTID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rtid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RTID::RTID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RTID()

core_microblaze_lt::RTID::~RTID() {

} // ~RTID()

unsigned int core_microblaze_lt::FMUL::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  unsigned int ira=(unsigned int)ra;
  float fra=  *( (float*)( (void*)(&ira) ) );
  unsigned int irb=(unsigned int)rb;
  float frb= *( (float*)( (void*)(&irb) ) );
  float fres=frb * fra;
  unsigned int res= *( (int*)( (void*)(&fres) ) );
  //if isDnz(ra) or isDnz(rb):
  if ( (ira & 0x7f800000 == 0 && ira & 0x007fffff != 0) || ( irb & 0x7f800000 ==
    0 && irb & 0x007fffff != 0 )){
    rd=(unsigned int)0xffc00000;
    FSR[key_DO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isSigNan(ra) or isSigNaN(rb) or (isZero(ra) and isInfinite(rb)) or
  // (isInfinite(ra) and isZero(rb)):
  else if ( (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira &
    0x00400000 == 0) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 == 0) ||
  (
  (ira & 0x7f800000 == 0 && ira & 0x007fffff == 0) &&
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff == 0)
  ) ||
  (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff == 0) &&
  (irb & 0x7f800000 == 0 && irb & 0x007fffff == 0)
  )
  ){
    rd=(unsigned int)0xffc00000;
    FSR[key_IO]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isQuietNaN(ra) or isQuietNaN(rb):
  else if (
  (ira & 0x7f800000 == 0x7f800000 && ira & 0x007fffff !=0 && ira & 0x00400000 ==
    0x00400000) ||
  (irb & 0x7f800000 == 0x7f800000 && irb & 0x007fffff !=0 && irb & 0x00400000 ==
    0x00400000)
  ){
    rd=(unsigned int)0xffc00000;
  }
  //else if isDnz (rb*ra):
  else if(res & 0x7f800000 == 0 && res & 0x007fffff != 0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_UF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  //else if isNaN(rb*ra):
  else if (res & 0x7f800000 == 0x7f800000 && res & 0x007fffff !=0){
    rd=(unsigned int) res & 0x80000000 == 0x80000000;
    FSR[key_OF]=1;
    ESR[key_EC]=0x0c;
    //EXCEPTION
  }
  else {
    rd=(unsigned int)res;
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::FMUL::replicate() const throw() {
  return new FMUL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::FMUL::getInstructionName() const throw() {
  return "FMUL";
} // getInstructionName()

unsigned int core_microblaze_lt::FMUL::getId() const throw() {
  return 60;
} // getId()

void core_microblaze_lt::FMUL::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::FMUL::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::FMUL::FMUL(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // FMUL()

core_microblaze_lt::FMUL::~FMUL() {

} // ~FMUL()

unsigned int core_microblaze_lt::LWI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)imm_value;
  if ( (addr & 0x00000003) != 0 ) {
    handleMemoryException(0x1,0x0,rd_bit,addr);
  } else {
    rd = dataMem.read_word(addr);
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LWI::replicate() const throw() {
  return new LWI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LWI::getInstructionName() const throw() {
  return "LWI";
} // getInstructionName()

unsigned int core_microblaze_lt::LWI::getId() const throw() {
  return 74;
} // getId()

void core_microblaze_lt::LWI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::LWI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lwi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LWI::LWI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LWI()

core_microblaze_lt::LWI::~LWI() {

} // ~LWI()

unsigned int core_microblaze_lt::BNEID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra != 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BNEID::replicate() const throw() {
  return new BNEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BNEID::getInstructionName() const throw() {
  return "BNEID";
} // getInstructionName()

unsigned int core_microblaze_lt::BNEID::getId() const throw() {
  return 35;
} // getId()

void core_microblaze_lt::BNEID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BNEID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bneid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BNEID::BNEID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BNEID()

core_microblaze_lt::BNEID::~BNEID() {

} // ~BNEID()

unsigned int core_microblaze_lt::ADDIK::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  rd = (int)ra + (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDIK::replicate() const throw() {
  return new ADDIK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDIK::getInstructionName() const throw() {
  return "ADDIK";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDIK::getId() const throw() {
  return 6;
} // getId()

void core_microblaze_lt::ADDIK::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ADDIK::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addik r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDIK::ADDIK(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDIK()

core_microblaze_lt::ADDIK::~ADDIK() {

} // ~ADDIK()

unsigned int core_microblaze_lt::BGTID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra > 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGTID::replicate() const throw() {
  return new BGTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGTID::getInstructionName() const throw() {
  return "BGTID";
} // getInstructionName()

unsigned int core_microblaze_lt::BGTID::getId() const throw() {
  return 23;
} // getId()

void core_microblaze_lt::BGTID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BGTID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bgtid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGTID::BGTID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGTID()

core_microblaze_lt::BGTID::~BGTID() {

} // ~BGTID()

unsigned int core_microblaze_lt::ADDIC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  long long result = (long long)((long long)((int)ra) + ((long long)(int)imm_value)
    + (long long)MSR[key_C]);
  MSR[key_C] = ((ra^imm_value^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd = (int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::ADDIC::replicate() const throw() {
  return new ADDIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::ADDIC::getInstructionName() const throw() {
  return "ADDIC";
} // getInstructionName()

unsigned int core_microblaze_lt::ADDIC::getId() const throw() {
  return 5;
} // getId()

void core_microblaze_lt::ADDIC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::ADDIC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "addic r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::ADDIC::ADDIC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // ADDIC()

core_microblaze_lt::ADDIC::~ADDIC() {

} // ~ADDIC()

unsigned int core_microblaze_lt::LW::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int addr = (int)ra + (int)rb;
  if ( (addr & 0x00000003) != 0 ) {
    handleMemoryException(0x1,0x0,rd_bit,addr);
  } else {
    rd = dataMem.read_word(addr);
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::LW::replicate() const throw() {
  return new LW(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::LW::getInstructionName() const throw() {
  return "LW";
} // getInstructionName()

unsigned int core_microblaze_lt::LW::getId() const throw() {
  return 73;
} // getId()

void core_microblaze_lt::LW::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::LW::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "lw r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::LW::LW(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // LW()

core_microblaze_lt::LW::~LW() {

} // ~LW()

unsigned int core_microblaze_lt::RSUBC::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int b = (int)rb;
  long long result = (long long)( (long long)b + ~((long long)a) + (int)MSR[key_C]);
  MSR[key_C] = (( (~a + MSR[key_C])^b^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd=(int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBC::replicate() const throw() {
  return new RSUBC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBC::getInstructionName() const throw() {
  return "RSUBC";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBC::getId() const throw() {
  return 90;
} // getId()

void core_microblaze_lt::RSUBC::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::RSUBC::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubc r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBC::RSUBC(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBC()

core_microblaze_lt::RSUBC::~RSUBC() {

} // ~RSUBC()

unsigned int core_microblaze_lt::BLTID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  if ((int)ra < 0 ) {
    TARGET = PC + (int)imm_value;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BLTID::replicate() const throw() {
  return new BLTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BLTID::getInstructionName() const throw() {
  return "BLTID";
} // getInstructionName()

unsigned int core_microblaze_lt::BLTID::getId() const throw() {
  return 31;
} // getId()

void core_microblaze_lt::BLTID::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BLTID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bltid r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BLTID::BLTID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BLTID()

core_microblaze_lt::BLTID::~BLTID() {

} // ~BLTID()

unsigned int core_microblaze_lt::RSUBI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int imm = (int)imm_value;
  long long result = (long long) ( ((long long)imm) + ~((long long)a) + 1);
  MSR[key_C] = ( ((~a + 1)^imm^(unsigned int)(result >> 1)) & 0x80000000) != 0;
  rd=(int)result;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBI::replicate() const throw() {
  return new RSUBI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBI::getInstructionName() const throw() {
  return "RSUBI";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBI::getId() const throw() {
  return 93;
} // getId()

void core_microblaze_lt::RSUBI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::RSUBI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubi r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBI::RSUBI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBI()

core_microblaze_lt::RSUBI::~RSUBI() {

} // ~RSUBI()

unsigned int core_microblaze_lt::MTS::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if (MSR[key_UM] == 1){
    ESR[key_EC]=0x1c;
    //EXCEPTION;
  }
  else{
    switch (rs){
      case 0x0001:
      MSR=(int)ra;
      break;
      case 0x0007:
      FSR=(int)ra;
      break;
      case 0x1000:
      PID=(int)ra;
      break;
      case 0x1001:
      ZPR=(int)ra;
      break;
      case 0x1002:
      TLBX=(int)ra;
      break;
      case 0x1003:
      TLBLO=(int)ra;
      break;
      case 0x1004:
      TLBHI=(int)ra;
      break;
      case 0x1005:
      TLBSX=(int)ra;
      break;
    };
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::MTS::replicate() const throw() {
  return new MTS(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::MTS::getInstructionName() const throw() {
  return "MTS";
} // getInstructionName()

unsigned int core_microblaze_lt::MTS::getId() const throw() {
  return 78;
} // getId()

void core_microblaze_lt::MTS::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rs = (bitString & 0x3fff);
} // setParams()

std::string core_microblaze_lt::MTS::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "T";
  oss << "O";
  oss << "D";
  oss << "O";
  return oss.str();
} // getMnemonic()

core_microblaze_lt::MTS::MTS(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // MTS()

core_microblaze_lt::MTS::~MTS() {

} // ~MTS()

unsigned int core_microblaze_lt::RSUBK::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  int a = (int)ra;
  int b = (int)rb;
  rd = (int)(b + ~a + 1);
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::RSUBK::replicate() const throw() {
  return new RSUBK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::RSUBK::getInstructionName() const throw() {
  return "RSUBK";
} // getInstructionName()

unsigned int core_microblaze_lt::RSUBK::getId() const throw() {
  return 91;
} // getId()

void core_microblaze_lt::RSUBK::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::RSUBK::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "rsubk r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::RSUBK::RSUBK(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // RSUBK()

core_microblaze_lt::RSUBK::~RSUBK() {

} // ~RSUBK()

unsigned int core_microblaze_lt::BGED::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  if ((int)ra >= 0 ) {
    TARGET = PC + (int)rb;
  } else {
    TARGET = PC + 8; /* we have to jump to the instruction AFTER the delay slot. */
  }
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BGED::replicate() const throw() {
  return new BGED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BGED::getInstructionName() const throw() {
  return "BGED";
} // getInstructionName()

unsigned int core_microblaze_lt::BGED::getId() const throw() {
  return 17;
} // getId()

void core_microblaze_lt::BGED::setParams(const unsigned int & bitString) throw() {
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BGED::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "bged r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BGED::BGED(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BGED()

core_microblaze_lt::BGED::~BGED() {

} // ~BGED()

unsigned int core_microblaze_lt::BRID::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  TARGET = PC + (int)imm_value;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRID::replicate() const throw() {
  return new BRID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRID::getInstructionName() const throw() {
  return "BRID";
} // getInstructionName()

unsigned int core_microblaze_lt::BRID::getId() const throw() {
  return 44;
} // getId()

void core_microblaze_lt::BRID::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRID::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brid r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRID::BRID(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRID()

core_microblaze_lt::BRID::~BRID() {

} // ~BRID()

unsigned int core_microblaze_lt::PCMPBF::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if ( ((int)rb & 0xff000000) == ((int)ra & 0xff000000) )
  rd = 0x1;
  else if ( ((int)rb & 0x00ff0000) == ((int)ra & 0x00ff0000) )
  rd = 0x2;
  else if ( ((int)rb & 0x0000ff00) == ((int)ra & 0x0000ff00) )
  rd = 0x3;
  else if ( ((int)rb & 0x000000ff) == ((int)ra & 0x000000ff) )
  rd = 0x4;
  else
  rd = 0x0;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::PCMPBF::replicate() const throw() {
  return new PCMPBF(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::PCMPBF::getInstructionName() const throw() {
  return "PCMPBF";
} // getInstructionName()

unsigned int core_microblaze_lt::PCMPBF::getId() const throw() {
  return 86;
} // getId()

void core_microblaze_lt::PCMPBF::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::PCMPBF::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "pcmpbf r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::PCMPBF::PCMPBF(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // PCMPBF()

core_microblaze_lt::PCMPBF::~PCMPBF() {

} // ~PCMPBF()

unsigned int core_microblaze_lt::IDIVU::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();
  {


    if (TARGET == 0xffffffff) {
      PC = PC + 4;
      DSFLAG = 0x0;
    } else {
      PC = TARGET;
      TARGET = 0xffffffff;
      DSFLAG = 0x1;
    }
  }

  if (ra==0){
    rd=(unsigned int)0;
    MSR[key_DZ]=1;
    ESR[key_EC]=0x5;
    //EXCEPTION
  }
  else{
    rd=(unsigned int) (((unsigned int)rb)/((unsigned int)ra));
  }
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::IDIVU::replicate() const throw() {
  return new IDIVU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::IDIVU::getInstructionName() const throw() {
  return "IDIVU";
} // getInstructionName()

unsigned int core_microblaze_lt::IDIVU::getId() const throw() {
  return 67;
} // getId()

void core_microblaze_lt::IDIVU::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->ra_bit = (bitString & 0x1f0000) >> 16;
  this->ra.directSetAlias(this->GPR[this->ra_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::IDIVU::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "idivu r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->ra_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::IDIVU::IDIVU(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // IDIVU()

core_microblaze_lt::IDIVU::~IDIVU() {

} // ~IDIVU()

unsigned int core_microblaze_lt::BRAD::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_reset();

  TARGET = (int)rb;
  PC = PC + 4;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRAD::replicate() const throw() {
  return new BRAD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRAD::getInstructionName() const throw() {
  return "BRAD";
} // getInstructionName()

unsigned int core_microblaze_lt::BRAD::getId() const throw() {
  return 39;
} // getId()

void core_microblaze_lt::BRAD::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->rb_bit = (bitString & 0xf800) >> 11;
  this->rb.directSetAlias(this->GPR[this->rb_bit]);
} // setParams()

std::string core_microblaze_lt::BRAD::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brad r";
  oss << std::dec << this->rd_bit;
  oss << " r";
  oss << std::dec << this->rb_bit;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRAD::BRAD(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_reset_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRAD()

core_microblaze_lt::BRAD::~BRAD() {

} // ~BRAD()

unsigned int core_microblaze_lt::BRAI::behavior() {
  this->totalInstrCycles = 0;
  this->IMM_handler(this->imm, this->imm_value);

  PC = (int)imm_value;
  return this->totalInstrCycles;
} // behavior()

Instruction * core_microblaze_lt::BRAI::replicate() const throw() {
  return new BRAI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI,
    TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
} // replicate()

std::string core_microblaze_lt::BRAI::getInstructionName() const throw() {
  return "BRAI";
} // getInstructionName()

unsigned int core_microblaze_lt::BRAI::getId() const throw() {
  return 43;
} // getId()

void core_microblaze_lt::BRAI::setParams(const unsigned int & bitString) throw() {
  this->rd_bit = (bitString & 0x3e00000) >> 21;
  this->rd.directSetAlias(this->GPR[this->rd_bit]);
  this->imm = (bitString & 0xffff);
} // setParams()

std::string core_microblaze_lt::BRAI::getMnemonic() const throw() {
  std::ostringstream oss (std::ostringstream::out);
  oss << "brai r";
  oss << std::dec << this->rd_bit;
  oss << " ";
  oss << std::showbase << std::hex << this->imm;
  return oss.str();
} // getMnemonic()

core_microblaze_lt::BRAI::BRAI(
    Reg32_0 & PC, Reg32_1 & MSR, Reg32_0 & EAR, Reg32_2 & ESR, Reg32_0 & BTR,
    Reg32_3 & FSR, Reg32_0 & EDR, Reg32_0 & PID, Reg32_0 & ZPR, Reg32_0 & TLBLO,
    Reg32_0 & TLBHI, Reg32_0 & TLBX, Reg32_0 & TLBSX, Reg32_0 & IMMREG, Reg32_0
    & TARGET, Reg1_0 & DSFLAG, Reg32_0 * GPR, Reg32_0 * PVR, MemoryInterface &
    dataMem, unsigned int & totalCycles) :
  Instruction(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles),
  IMM_handler_op(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
  TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles) {

} // BRAI()

core_microblaze_lt::BRAI::~BRAI() {

} // ~BRAI()


