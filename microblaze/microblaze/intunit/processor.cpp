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


#include "microblaze/intunit/processor.hpp"
#include "microblaze/intunit/instructions.hpp"
#include "microblaze/intunit/decoder.hpp"
#include "microblaze/intunit/interface.hpp"
#include "microblaze/intunit/registers.hpp"
#include "microblaze/intunit/memory.hpp"

#include <utils/customExceptions.hpp>
#include <ToolsIf.hpp>
#include <instructionBase.hpp>

#include <systemc.h>
#include <iostream>
#include <fstream>
#include <boost/circular_buffer.hpp>
#include <string>
#include "core/base/verbose.h"

#ifdef __GNUC__
#ifdef __GNUC_MINOR__
#if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 3)
#include <tr1/unordered_map>
#define template_map std::tr1::unordered_map
#else
#include <ext/hash_map>
#define  template_map __gnu_cxx::hash_map
#endif
#else
#include <ext/hash_map>
#define  template_map __gnu_cxx::hash_map
#endif
#else
#ifdef _WIN32
#include <hash_map>
#define  template_map stdext::hash_map
#else
#include <map>
#define  template_map std::map
#endif
#endif


using namespace core_microblaze_lt;
using namespace trap;
void core_microblaze_lt::CoreMICROBLAZELT::mainLoop() {
  template_map< unsigned int, CacheElem >::iterator instrCacheEnd = this->instrCache.end();

  while(true) {
    unsigned int numCycles = 0;
    this->instrExecuting = true;
    unsigned int curPC = this->PC;
    template_map< unsigned int, CacheElem >::iterator cachedInstr = this->instrCache.find(curPC);
    if (cachedInstr != instrCacheEnd) {
      Instruction * curInstrPtr = cachedInstr->second.instr;
      // I can call the instruction, I have found it
      if (curInstrPtr != NULL) {
        if (this->historyEnabled) {
          srInfo()
            ("Address",curPC)
            ("Name",curInstrPtr->getInstructionName())
            ("Mnemonic",curInstrPtr->getMnemonic())
            ("Instruction History");
        }
        try {
#ifndef DISABLE_TOOLS
          if (!(this->toolManager.newIssue(curPC, curInstrPtr))) {
#endif
            numCycles = curInstrPtr->behavior();
//            curInstrPtr->printTrace();
#ifndef DISABLE_TOOLS
          }
          else {
            std::cerr << "Not executed Instruction because Tools anulled it" <<
              std::endl << std::endl;
          }
#endif
        }
        catch(annull_exception &etc) {
//          curInstrPtr->printTrace();
          std::cerr << "Skipped Instruction " << curInstrPtr->getInstructionName()
            << std::endl << std::endl;
          numCycles = 0;
        }
      } else {
        unsigned int bitString = this->dataMem.read_word(curPC);
        unsigned int & curCount = cachedInstr->second.count;
        int instrId = this->decoder.decode(bitString);
        Instruction * instr = this->INSTRUCTIONS[instrId];
        instr->setParams(bitString);
        if (this->historyEnabled) {
          srInfo()
            ("Address",curPC)
            ("Name",curInstrPtr->getInstructionName())
            ("Mnemonic",curInstrPtr->getMnemonic())
            ("Instruction History");
        }
        try {
#ifndef DISABLE_TOOLS
          if (!(this->toolManager.newIssue(curPC, instr))) {
#endif
            numCycles = instr->behavior();
//            instr->printTrace();
#ifndef DISABLE_TOOLS
          }
          else {
            std::cerr << "Not executed Instruction because Tools anulled it" <<
              std::endl << std::endl;
          }
#endif
        }
        catch(annull_exception &etc) {
//          instr->printTrace();
          std::cerr << "Skipped Instruction " << instr->getInstructionName() <<
            std::endl << std::endl;
          numCycles = 0;
        }
        if (curCount < 256) {
          curCount++;
        } else {
          // ... and then add the instruction to the cache
          cachedInstr->second.instr = instr;
          this->INSTRUCTIONS[instrId] = instr->replicate();
        }
      }
    } else {
      // The current instruction is not present in the cache:
      // I have to perform the normal decoding phase ...
      unsigned int bitString = this->dataMem.read_word(curPC);
      int instrId = this->decoder.decode(bitString);
      Instruction * instr = this->INSTRUCTIONS[instrId];
      instr->setParams(bitString);
      if (this->historyEnabled) {
        srInfo()
          ("Address",curPC)
          ("Name",instr->getInstructionName())
          ("Mnemonic",instr->getMnemonic())
          ("Instruction History");
      }
      try {
#ifndef DISABLE_TOOLS
        if (!(this->toolManager.newIssue(curPC, instr))) {
#endif
          numCycles = instr->behavior();
//          instr->printTrace();
#ifndef DISABLE_TOOLS
        }
        else {
          std::cerr << "Not executed Instruction because Tools anulled it" <<
            std::endl << std::endl;
        }
#endif
      }
      catch(annull_exception &etc) {
//        instr->printTrace();
        std::cerr << "Skipped Instruction " << instr->getInstructionName() <<
          std::endl << std::endl;
        numCycles = 0;
      }
      this->instrCache.insert(std::pair< unsigned int, CacheElem >(bitString,
        CacheElem()));
      instrCacheEnd = this->instrCache.end();
    }
    /*if (this->historyEnabled) {
      srInfo()
        ("Address",curPC)
        ("Name",curInstrPtr->getInstructionName())
        ("Mnemonic",curInstrPtr->getMnemonic())
        ("Instruction History");
    }*/
    this->totalCycles += (numCycles + 1);
    this->instrExecuting = false;
    this->numInstructions++;

  }
} // mainLoop()

void core_microblaze_lt::CoreMICROBLAZELT::resetOp() {
  GPR[0].immediateWrite(0x0);
  GPR[1].immediateWrite(0x4ffff0);
  GPR[2].immediateWrite(0x0);
  GPR[3].immediateWrite(0x0);
  GPR[4].immediateWrite(0x0);
  GPR[5].immediateWrite(0x0);
  GPR[6].immediateWrite(0x0);
  GPR[7].immediateWrite(0x0);
  GPR[8].immediateWrite(0x0);
  GPR[9].immediateWrite(0x0);
  GPR[10].immediateWrite(0x0);
  GPR[11].immediateWrite(0x0);
  GPR[12].immediateWrite(0x0);
  GPR[13].immediateWrite(0x0);
  GPR[14].immediateWrite(0x0);
  GPR[15].immediateWrite(0x0);
  GPR[16].immediateWrite(0x0);
  GPR[17].immediateWrite(0x0);
  GPR[18].immediateWrite(0x0);
  GPR[19].immediateWrite(0x0);
  GPR[20].immediateWrite(0x0);
  GPR[21].immediateWrite(0x0);
  GPR[22].immediateWrite(0x0);
  GPR[23].immediateWrite(0x0);
  GPR[24].immediateWrite(0x0);
  GPR[25].immediateWrite(0x0);
  GPR[26].immediateWrite(0x0);
  GPR[27].immediateWrite(0x0);
  GPR[28].immediateWrite(0x0);
  GPR[29].immediateWrite(0x0);
  GPR[30].immediateWrite(0x0);
  GPR[31].immediateWrite(0x0);
  for (int i = 0; i < 12; i++) {
    PVR[i] = 0;
  }
  PC.immediateWrite(ENTRY_POINT);
  MSR.immediateWrite(0x0);
  EAR.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  BTR.immediateWrite(0x0);
  FSR.immediateWrite(0x0);
  EDR.immediateWrite(0x0);
  PID.immediateWrite(0x0);
  ZPR.immediateWrite(0x0);
  TLBLO.immediateWrite(0x0);
  TLBHI.immediateWrite(0x0);
  TLBX.immediateWrite(0x0);
  TLBSX.immediateWrite(0x0);
  IMMREG.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  DSFLAG.immediateWrite(0x0);

  this->resetCalled = true;
} // resetOp()

void core_microblaze_lt::CoreMICROBLAZELT::end_of_elaboration() {
  if (!this->resetCalled) {
    this->resetOp();
  }
  this->resetCalled = false;
} // end_of_elaboration()

Instruction * core_microblaze_lt::CoreMICROBLAZELT::decode(unsigned int bitString) {
  int instrId = this->decoder.decode(bitString);
  if (instrId >= 0) {
    Instruction * instr = this->INSTRUCTIONS[instrId];
    instr->setParams(bitString);
    return instr;
  }
  return NULL;
} // decode()

MICROBLAZE_ABIIf & core_microblaze_lt::CoreMICROBLAZELT::getInterface() {
  return *this->abiIf;
} // getInterface()

int core_microblaze_lt::CoreMICROBLAZELT::numInstances = 0;
void core_microblaze_lt::CoreMICROBLAZELT::enableHistory(std::string fileName) {
  this->historyEnabled = true;
  this->histFile.open(fileName.c_str(), ios::out | ios::ate);
} // enableHistory()

core_microblaze_lt::CoreMICROBLAZELT::CoreMICROBLAZELT(sc_module_name name, MemoryInterface *memory) :
  sc_module(name),
  mem(memory),
  dataMem(*mem) {
  this->resetCalled = false;
  CoreMICROBLAZELT::numInstances++;
  // Initialization of the array holding the initial instance of the instructions
  this->INSTRUCTIONS = new Instruction *[117];
  this->INSTRUCTIONS[112] = new WDC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[16] = new BGE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[19] = new BGEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[52] = new BSLL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[20] = new BGT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[36] = new BR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[33] = new BNED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[34] = new BNEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[69] = new LBU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[89] = new RSUB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[53] = new BSRLI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[61] = new FDIV(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[58] = new FADD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[81] = new MULHU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[21] = new BGTD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[22] = new BGTI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[108] = new SEXT8(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[71] = new LHU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[32] = new BNE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[40] = new BRLD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[49] = new BRKI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[7] = new ADDIKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[66] = new IDIV(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[1] = new ADDC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[70] = new LBUI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[2] = new ADDK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[84] = new OR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[4] = new ADDI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[15] = new BEQID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[57] = new CMPU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[64] = new FINT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[50] = new BSRL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[30] = new BLTI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[87] = new PCMPEQ(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[114] = new XOR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[12] = new BEQ(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[29] = new BLTD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[56] = new CMP(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[47] = new BRALID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[97] = new RTBD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[75] = new MFS(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[28] = new BLT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[46] = new BRLID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[101] = new SB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[24] = new BLE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[104] = new SHI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[8] = new AND(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[94] = new RSUBIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[102] = new SBI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[99] = new RTED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[95] = new RSUBIK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[41] = new BRALD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[37] = new BRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[65] = new FSQRT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[107] = new SEXT16(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[106] = new SWI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[27] = new BLEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[51] = new BSRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[25] = new BLED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[83] = new MULI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[77] = new MSRSET(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[79] = new MUL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[26] = new BLEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[100] = new RTSD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[10] = new ANDN(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[9] = new ANDI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[3] = new ADDKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[76] = new MSRCLR(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[55] = new BSLLI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[18] = new BGEI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[110] = new SRC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[109] = new SRA(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[68] = new IMM(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[111] = new SRL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[63] = new FLT(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[82] = new MULHSU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[0] = new ADD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[115] = new XORI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[88] = new PCMPNE(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[54] = new BSRAI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[45] = new BRAID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[113] = new WIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[92] = new RSUBKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[105] = new SW(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[62] = new FCMP(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[103] = new SH(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[48] = new BRK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[42] = new BRI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[85] = new ORI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[11] = new ANDNI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[38] = new BRD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[72] = new LHUI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[96] = new RSUBIKC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[80] = new MULH(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[59] = new FRSUB(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[14] = new BEQI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[13] = new BEQD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[98] = new RTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[60] = new FMUL(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[74] = new LWI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[35] = new BNEID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[6] = new ADDIK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[23] = new BGTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[5] = new ADDIC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[73] = new LW(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[90] = new RSUBC(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[31] = new BLTID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[93] = new RSUBI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[78] = new MTS(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[91] = new RSUBK(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[17] = new BGED(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[44] = new BRID(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[86] = new PCMPBF(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID,
    ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem,
    totalCycles);
  this->INSTRUCTIONS[67] = new IDIVU(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[39] = new BRAD(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[43] = new BRAI(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR,
    TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  this->INSTRUCTIONS[116] = new InvalidInstr(PC, MSR, EAR, ESR, BTR, FSR, EDR,
    PID, ZPR, TLBLO, TLBHI, TLBX, TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR,
    dataMem, totalCycles);
  this->quantKeeper.set_global_quantum( this->latency*100);
  this->quantKeeper.reset();
  // Initialization of the standard registers
  // Initialization of the register banks
  // Initialization of the aliases (plain and banks)
  this->totalCycles = 0;
  this->historyEnabled = false;
  this->instHistoryQueue.set_capacity(1000);
  this->undumpedHistElems = 0;
  this->numInstructions = 0;
  this->ENTRY_POINT = 0;
  this->MPROC_ID = 0;
  this->PROGRAM_LIMIT = 0;
  this->PROGRAM_START = 0;
  this->abiIf = new MICROBLAZE_ABIIf(this->PROGRAM_LIMIT, this->dataMem, this->PC,
    this->MSR, this->EAR, this->ESR, this->BTR, this->FSR, this->EDR, this->PID,
    this->ZPR, this->TLBLO, this->TLBHI, this->TLBX, this->TLBSX, this->IMMREG,
    this->TARGET, this->DSFLAG, this->GPR, this->PVR, this->instrExecuting,
    this->instHistoryQueue);
  SC_THREAD(mainLoop);
  this->totalCycles = 0;
  end_module();
} // CoreMICROBLAZELT()

core_microblaze_lt::CoreMICROBLAZELT::~CoreMICROBLAZELT() {
  CoreMICROBLAZELT::numInstances--;
  for (int i = 0; i < 117; i++) {
    delete this->INSTRUCTIONS[i];
  }
  delete [] this->INSTRUCTIONS;
  template_map< unsigned int, CacheElem >::const_iterator cacheIter, cacheEnd;
  for (cacheIter = this->instrCache.begin(), cacheEnd = this->instrCache.end();
    cacheIter != cacheEnd; cacheIter++) {
    delete cacheIter->second.instr;
  }
  delete this->abiIf;
} // ~CoreMICROBLAZELT()


