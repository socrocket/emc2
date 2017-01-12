/***************************************************************************//**
*
*           _/       _/_/_/      _/         _/
*         _/_/      _/    _/    _/_/      __/
*       _/  _/     _/    _/    _/ _/    _/_/
*     _/_/_/_/    _/_/_/      _/  _/  _/ _/
*   _/      _/   _/    _/    _/   _/_/  _/
* _/        _/  _/      _/  _/    _/   _/
*
* @brief    This file is part of the SoCRocket ARM ISS generated by TRAP.
* @details  This SystemC model was automatically generated by running
*           $ python ARMArch.py
*           Please refer to the ARM TRAP source files for documentation.
* @author   Lillian Tadros (Technische Universitaet Dortmund)
* @date     2015-2016 Technische Universitaet Dortmund
*
*
* (c) 2014-2016
* Technische Universitaet Dortmund
* Institut fuer Roboterforschung
* Project Embedded Multi-Core Systems for Mixed Criticality
* Applications in Dynamic and Changeable Real-time Environments (EMC2)
*
*
* This file is part of ARMCortexA9.
*
* ARMCortexA9 is free software; you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation; either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#include "processor.hpp"
#include "memory.hpp"
#include "instructions.hpp"
#include "interface.hpp"
#include "registers.hpp"
#include "irqPorts.hpp"
#include "decoder.hpp"

#include <systemc.h>
#include <common/report.hpp>
#include <string>
#include <tlm_utils/tlm_quantumkeeper.h>
#include <common/tools_if.hpp>
#include <boost/circular_buffer.hpp>
#include <modules/instruction.hpp>
#include <iostream>
#include <fstream>

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

using namespace core_armcortexa9_funclt;

using namespace trap;

core_armcortexa9_funclt::CoreARMCortexA9FuncLT::CoreARMCortexA9FuncLT(
    sc_module_name name,
    sc_time latency,
    MemoryInterface& instr_memory,
    MemoryInterface& data_memory) :
  sc_module(name),
  latency(latency),
  reset_called(false),
  R(MPROC_ID, ENTRY_POINT),
  instr_memory(instr_memory),
  data_memory(data_memory),
  IRQ_port("IRQ_port", IRQ),
  FIQ_port("FIQ_port", FIQ),
  num_instructions(0),
  profiler_time_start(SC_ZERO_TIME),
  profiler_time_end(SC_ZERO_TIME),
  profiler_start_addr((unsigned)-1),
  profiler_end_addr((unsigned)-1),
  history_en(false),
  history_undumped_elements(0),
  MPROC_ID(0),
  ENTRY_POINT(0),
  PROGRAM_START(0),
  PROGRAM_LIMIT(0) {

  CoreARMCortexA9FuncLT::num_instances++;
  this->quant_keeper.set_global_quantum(this->latency*100);
  this->quant_keeper.reset();
  SC_THREAD(main_loop);
  // Initialize the array containing the initial instance of the instructions.
  this->INSTRUCTIONS = new Instruction*[162];
  this->INSTRUCTIONS[0] = new ADD_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[1] = new ADD_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[2] = new ADD_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[3] = new ADC_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[4] = new ADC_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[5] = new ADC_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[6] = new SUB_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[7] = new SUB_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[8] = new SUB_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[9] = new SBC_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[10] = new SBC_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[11] = new SBC_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[12] = new RSB_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[13] = new RSB_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[14] = new RSB_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[15] = new RSC_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[16] = new RSC_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[17] = new RSC_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[18] = new USHQADD(R, instr_memory, data_memory);
  this->INSTRUCTIONS[19] = new USHQSUB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[20] = new USADA8(R, instr_memory, data_memory);
  this->INSTRUCTIONS[21] = new USXTAHB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[22] = new USHQASX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[23] = new USHQSAX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[24] = new USSAT(R, instr_memory, data_memory);
  this->INSTRUCTIONS[25] = new USSAT16(R, instr_memory, data_memory);
  this->INSTRUCTIONS[26] = new QDADDSUB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[27] = new MUL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[28] = new SMMUL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[29] = new MULL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[30] = new UMAAL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[31] = new SMULBW(R, instr_memory, data_memory);
  this->INSTRUCTIONS[32] = new SMMULD(R, instr_memory, data_memory);
  this->INSTRUCTIONS[33] = new DIV(R, instr_memory, data_memory);
  this->INSTRUCTIONS[34] = new AND_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[35] = new AND_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[36] = new AND_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[37] = new EOR_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[38] = new EOR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[39] = new EOR_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[40] = new MVN_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[41] = new MVN_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[42] = new MVN_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[43] = new ORR_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[44] = new ORR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[45] = new ORR_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[46] = new TEQ_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[47] = new TEQ_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[48] = new TEQ_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[49] = new TST_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[50] = new TST_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[51] = new TST_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[52] = new ASR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[53] = new ASR_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[54] = new LSR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[55] = new LSR_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[56] = new LSL_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[57] = new LSL_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[58] = new ROR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[59] = new ROR_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[60] = new BFCI(R, instr_memory, data_memory);
  this->INSTRUCTIONS[61] = new BIC_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[62] = new BIC_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[63] = new BIC_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[64] = new CLZ(R, instr_memory, data_memory);
  this->INSTRUCTIONS[65] = new PKH(R, instr_memory, data_memory);
  this->INSTRUCTIONS[66] = new RBIT(R, instr_memory, data_memory);
  this->INSTRUCTIONS[67] = new REV(R, instr_memory, data_memory);
  this->INSTRUCTIONS[68] = new REV16(R, instr_memory, data_memory);
  this->INSTRUCTIONS[69] = new REVSH(R, instr_memory, data_memory);
  this->INSTRUCTIONS[70] = new USBFX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[71] = new SEL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[72] = new CMN_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[73] = new CMN_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[74] = new CMN_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[75] = new CMP_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[76] = new CMP_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[77] = new CMP_sr(R, instr_memory, data_memory);
  this->INSTRUCTIONS[78] = new LDR_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[79] = new LDR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[80] = new LDREX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[81] = new LDRB_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[82] = new LDRB_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[83] = new LDREXB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[84] = new LDRSB_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[85] = new LDRSB_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[86] = new LDRH_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[87] = new LDRH_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[88] = new LDREXH(R, instr_memory, data_memory);
  this->INSTRUCTIONS[89] = new LDRSH_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[90] = new LDRSH_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[91] = new LDRD_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[92] = new LDRD_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[93] = new LDREXD(R, instr_memory, data_memory);
  this->INSTRUCTIONS[94] = new STR_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[95] = new STR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[96] = new STREX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[97] = new STRB_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[98] = new STRB_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[99] = new STREXB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[100] = new STRH_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[101] = new STRH_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[102] = new STREXH(R, instr_memory, data_memory);
  this->INSTRUCTIONS[103] = new STRD_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[104] = new STRD_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[105] = new STREXD(R, instr_memory, data_memory);
  this->INSTRUCTIONS[106] = new LDM(R, instr_memory, data_memory);
  this->INSTRUCTIONS[107] = new LDMIB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[108] = new LDMDA(R, instr_memory, data_memory);
  this->INSTRUCTIONS[109] = new LDMDB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[110] = new POP_single(R, instr_memory, data_memory);
  this->INSTRUCTIONS[111] = new POP_block(R, instr_memory, data_memory);
  this->INSTRUCTIONS[112] = new STM(R, instr_memory, data_memory);
  this->INSTRUCTIONS[113] = new STMIB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[114] = new STMDA(R, instr_memory, data_memory);
  this->INSTRUCTIONS[115] = new STMDB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[116] = new PUSH_single(R, instr_memory, data_memory);
  this->INSTRUCTIONS[117] = new PUSH_block(R, instr_memory, data_memory);
  this->INSTRUCTIONS[118] = new MOV_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[119] = new MOV_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[120] = new MOVW(R, instr_memory, data_memory);
  this->INSTRUCTIONS[121] = new MOVT(R, instr_memory, data_memory);
  this->INSTRUCTIONS[122] = new SWP(R, instr_memory, data_memory);
  this->INSTRUCTIONS[123] = new MRS(R, instr_memory, data_memory);
  this->INSTRUCTIONS[124] = new MSR_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[125] = new MSR_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[126] = new B(R, instr_memory, data_memory);
  this->INSTRUCTIONS[127] = new BL(R, instr_memory, data_memory);
  this->INSTRUCTIONS[128] = new BX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[129] = new BLX_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[130] = new BLX_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[131] = new BXJ(R, instr_memory, data_memory);
  this->INSTRUCTIONS[132] = new BKPT(R, instr_memory, data_memory);
  this->INSTRUCTIONS[133] = new CLREX(R, instr_memory, data_memory);
  this->INSTRUCTIONS[134] = new CPS(R, instr_memory, data_memory);
  this->INSTRUCTIONS[135] = new DBG(R, instr_memory, data_memory);
  this->INSTRUCTIONS[136] = new DMB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[137] = new DSB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[138] = new ISB(R, instr_memory, data_memory);
  this->INSTRUCTIONS[139] = new NOP(R, instr_memory, data_memory);
  this->INSTRUCTIONS[140] = new PLI_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[141] = new PLI_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[142] = new PLD_i(R, instr_memory, data_memory);
  this->INSTRUCTIONS[143] = new PLD_r(R, instr_memory, data_memory);
  this->INSTRUCTIONS[144] = new RFE(R, instr_memory, data_memory);
  this->INSTRUCTIONS[145] = new SETEND(R, instr_memory, data_memory);
  this->INSTRUCTIONS[146] = new SEV(R, instr_memory, data_memory);
  this->INSTRUCTIONS[147] = new SRS(R, instr_memory, data_memory);
  this->INSTRUCTIONS[148] = new SVC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[149] = new UDF(R, instr_memory, data_memory);
  this->INSTRUCTIONS[150] = new WFE(R, instr_memory, data_memory);
  this->INSTRUCTIONS[151] = new WFI(R, instr_memory, data_memory);
  this->INSTRUCTIONS[152] = new YIELD(R, instr_memory, data_memory);
  this->INSTRUCTIONS[153] = new SMC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[154] = new CDP(R, instr_memory, data_memory);
  this->INSTRUCTIONS[155] = new LDC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[156] = new STC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[157] = new MCR(R, instr_memory, data_memory);
  this->INSTRUCTIONS[158] = new MCRR(R, instr_memory, data_memory);
  this->INSTRUCTIONS[159] = new MRC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[160] = new MRRC(R, instr_memory, data_memory);
  this->INSTRUCTIONS[161] = new InvalidInstruction(R, instr_memory, data_memory);
  this->IRQ_instr = new IRQIntrInstruction(R, instr_memory, data_memory, this->IRQ);
  this->FIQ_instr = new FIQIntrInstruction(R, instr_memory, data_memory, this->FIQ);
  this->history_instr_queue.set_capacity(1000);
  this->ABIIf = new Interface(this->R, this->data_memory, this->instr_executing,
  this->instr_end_event, this->history_instr_queue, this->PROGRAM_LIMIT);
  end_module();
} // CoreARMCortexA9FuncLT()

// -----------------------------------------------------------------------------

core_armcortexa9_funclt::CoreARMCortexA9FuncLT::~CoreARMCortexA9FuncLT() {

  CoreARMCortexA9FuncLT::num_instances--;
  for (int i = 0; i < 162; i++) {
    delete this->INSTRUCTIONS[i];
  }
  delete [] this->INSTRUCTIONS;
  template_map<unsigned, CacheElem>::const_iterator cache_it, cache_end;
  for (cache_it = this->instr_cache.begin(), cache_end = this->instr_cache.end();
  cache_it != cache_end; cache_it++) {
    delete cache_it->second.instr;
  }
  delete this->IRQ_instr;
  delete this->FIQ_instr;
#ifdef ENABLE_HISTORY
  if (this->history_en) {
    // In case a queue dump file has been specified, check if it needs to be
    // saved.
    if (this->history_file) {
      if (this->history_undumped_elements > 0) {
        std::vector<std::string> history_vector;
        boost::circular_buffer<HistoryInstrType>::const_reverse_iterator history_it,
        history_end;
        unsigned history_read = 0;
        for (history_read = 0, history_it = this->history_instr_queue.rbegin(),
        history_end = this->history_instr_queue.rend(); history_it != history_end
        && history_read < this->history_undumped_elements; history_it++, history_read++)
        {
          history_vector.push_back(history_it->get_mnemonic());
        }
        std::vector<std::string>::const_reverse_iterator history_vector_it,
        history_vector_end;
        for (history_vector_it = history_vector.rbegin(), history_vector_end =
        history_vector.rend(); history_vector_it != history_vector_end; history_vector_it++)
        {
          this->history_file << *history_vector_it << std::endl;
        }
      }
      this->history_file.flush();
      this->history_file.close();
    }
  }
#endif
  delete this->ABIIf;
} // ~CoreARMCortexA9FuncLT()

// -----------------------------------------------------------------------------

void core_armcortexa9_funclt::CoreARMCortexA9FuncLT::main_loop() {

  // Wait for SystemC infrastructure, otherwise register callbacks will crash.
  wait(SC_ZERO_TIME);
  Instruction* cur_instr = NULL;
  template_map<unsigned, CacheElem >::iterator icache_end = this->instr_cache.end();

  while(true) {
    this->instr_executing = true;
    unsigned num_cycles = 0;
    if (FIQ) {
      this->FIQ_instr->set_interrupt_value(FIQ);
      try {
        num_cycles = this->FIQ_instr->behavior();
      }
      catch(annul_exception& etc) {
        num_cycles = 0;
      }

    }
    else if (IRQ) {
      this->IRQ_instr->set_interrupt_value(IRQ);
      try {
        num_cycles = this->IRQ_instr->behavior();
      }
      catch(annul_exception& etc) {
        num_cycles = 0;
      }

    }
    else /* !IRQ */ {
      unsigned cur_PC = this->RB[15];
      if (cur_PC == this->profiler_start_addr) {
        this->profiler_time_start = sc_time_stamp();
      }
      if (cur_PC == this->profiler_end_addr) {
        this->profiler_time_end = sc_time_stamp();
      }

      // Tools: Instruction History
#ifdef ENABLE_HISTORY
      HistoryInstrType instr_queue_elem;
      if (this->history_en) {
        instr_queue_elem.cycle = (unsigned)(this->quant_keeper.get_current_time()/this->latency);
        instr_queue_elem.address = cur_PC;
      }
#endif
      unsigned bitstring = this->instr_memory.read_instr(cur_PC);
      cur_instr = NULL;
      template_map< unsigned, CacheElem >::iterator cached_instr = this->instr_cache.find(bitstring);
      if (cached_instr != icache_end) {
        cur_instr = cached_instr->second.instr;
        // Instruction found, call it.
        if (cur_instr != NULL) {
#ifdef ENABLE_HISTORY
          if (this->history_en) {
            instr_queue_elem.name = cur_instr->get_name();
            instr_queue_elem.mnemonic = cur_instr->get_mnemonic();
          }
#endif
          try {
#ifndef DISABLE_TOOLS
            if (!(this->tool_manager.issue(cur_PC, cur_instr))) {
#endif
              num_cycles = cur_instr->behavior();
#ifndef DISABLE_TOOLS
            }
#endif
          }
          catch(annul_exception& etc) {
            num_cycles = 0;
          }
        } else {
          // Current instruction is indexed but not present in the cache.
          // Perform regular decoding.
          unsigned& cur_instr_count = cached_instr->second.count;
          int cur_instr_id = this->decoder.decode(bitstring);
          cur_instr = this->INSTRUCTIONS[cur_instr_id];
          cur_instr->set_params(bitstring);
#ifdef ENABLE_HISTORY
          if (this->history_en) {
            instr_queue_elem.name = cur_instr->get_name();
            instr_queue_elem.mnemonic = cur_instr->get_mnemonic();
          }
#endif
          try {
#ifndef DISABLE_TOOLS
            if (!(this->tool_manager.issue(cur_PC, cur_instr))) {
#endif
              num_cycles = cur_instr->behavior();
#ifndef DISABLE_TOOLS
            }
#endif
          }
          catch(annul_exception& etc) {
            num_cycles = 0;
          }
          if (cur_instr_count < 256) {
            cur_instr_count++;
          } else {
            // Add the instruction to the i-cache.
            cached_instr->second.instr = cur_instr;
            this->INSTRUCTIONS[cur_instr_id] = cur_instr->replicate();
          }
        }
      } else {
        // Current instruction is not present in the cache. Perform regular
        // decoding.
        int cur_instr_id = this->decoder.decode(bitstring);
        cur_instr = this->INSTRUCTIONS[cur_instr_id];
        cur_instr->set_params(bitstring);
#ifdef ENABLE_HISTORY
        if (this->history_en) {
          instr_queue_elem.name = cur_instr->get_name();
          instr_queue_elem.mnemonic = cur_instr->get_mnemonic();
        }
#endif
        try {
#ifndef DISABLE_TOOLS
          if (!(this->tool_manager.issue(cur_PC, cur_instr))) {
#endif
            num_cycles = cur_instr->behavior();
#ifndef DISABLE_TOOLS
          }
#endif
        }
        catch(annul_exception& etc) {
          num_cycles = 0;
        }
        this->instr_cache.insert(std::pair<unsigned, CacheElem>(bitstring,
        CacheElem()));
        icache_end = this->instr_cache.end();
      }

#ifdef FUNC_MODEL
      if (cur_PC == RB[15]) {
#endif
        // Check instruction set mode.
        // JT=00: ARM (32-bit); JT=01: Thumb (16-bit); JT=10: Jazelle (8-bit);
        // JT=11: ThumbEE (16-bit)
        if (CPSR[CPSR_T]) {
          PC += 2;
        } else if (CPSR[CPSR_J]) {
          PC += 1;
        } else {
          PC += 4;
        }
#ifdef FUNC_MODEL
      }
#endif

      // Tools: Instruction History
#ifdef ENABLE_HISTORY
      if (this->history_en) {
        // Add current instruction to history queue.
        this->history_instr_queue.push_back(instr_queue_elem);
        // In case a queue dump file has been specified, check if it needs to be
        // saved.
        if (this->history_file) {
          this->history_undumped_elements++;
          if (history_undumped_elements == this->history_instr_queue.capacity())
          {
            boost::circular_buffer<HistoryInstrType>::const_iterator history_it,
            history_end;
            for (history_it = this->history_instr_queue.begin(), history_end =
            this->history_instr_queue.end(); history_it != history_end; history_it++)
            {
              this->history_file << history_it->get_mnemonic() << std::endl;
            }
            this->history_undumped_elements = 0;
          }
        }
      }
#endif
    } // if (!IRQ)
    // Instruction-induced Latency
    this->quant_keeper.inc((num_cycles + 1)*this->latency);
    if (this->quant_keeper.need_sync()) {
      this->quant_keeper.sync();
    }
    this->instr_executing = false;
    this->instr_end_event.notify();
    this->num_instructions++;

  }
} // main_loop()

// -----------------------------------------------------------------------------

void core_armcortexa9_funclt::CoreARMCortexA9FuncLT::reset() {

  this->R.reset();
  this->RB[15].set_stage(0);
  this->RB[15] = this->ENTRY_POINT;
  this->RB[15].set_stage(1);
  this->RB[15] = this->ENTRY_POINT;
  this->RB[15].unset_stage();
  this->IRQ = 0;
  this->FIQ = 0;

  this->reset_called = true;
} // reset()

// -----------------------------------------------------------------------------

void core_armcortexa9_funclt::CoreARMCortexA9FuncLT::end_of_elaboration() {

  if (!this->reset_called) {
    this->reset();
  }
} // end_of_elaboration()

// -----------------------------------------------------------------------------

void core_armcortexa9_funclt::CoreARMCortexA9FuncLT::set_profiling_range(
    unsigned start_addr,
    unsigned end_addr) {

  this->profiler_start_addr = start_addr;
  this->profiler_end_addr = end_addr;
} // set_profiling_range()

// -----------------------------------------------------------------------------

void core_armcortexa9_funclt::CoreARMCortexA9FuncLT::enable_history(std::string
file_name) {

  this->history_en = true;
  this->history_file.open(file_name.c_str(), ios::out | ios::ate);
} // enable_history()

// -----------------------------------------------------------------------------

Instruction* core_armcortexa9_funclt::CoreARMCortexA9FuncLT::decode(unsigned
bitstring) {

  int instr_id = this->decoder.decode(bitstring);
  if (instr_id >= 0) {
    Instruction* instr = this->INSTRUCTIONS[instr_id];
    instr->set_params(bitstring);
    return instr;
  }
  return NULL;
} // decode()

// -----------------------------------------------------------------------------

Interface& core_armcortexa9_funclt::CoreARMCortexA9FuncLT::get_interface() {

  return *this->ABIIf;
} // get_interface()

// -----------------------------------------------------------------------------

int core_armcortexa9_funclt::CoreARMCortexA9FuncLT::num_instances = 0;

// *****************************************************************************

