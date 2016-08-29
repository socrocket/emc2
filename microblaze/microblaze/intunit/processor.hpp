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

#ifndef MICROBLAZE_CORE_FUNC_LT_PROCESSOR_HPP
#define MICROBLAZE_CORE_FUNC_LT_PROCESSOR_HPP

#include "microblaze/intunit/instructions.hpp"
#include "microblaze/intunit/decoder.hpp"
#include "microblaze/intunit/interface.hpp"
#include "microblaze/intunit/registers.hpp"
#include "microblaze/intunit/memory.hpp"

#include <utils/customExceptions.hpp>
#include "core/trapgen/ToolsIf.hpp"
#include <tlm_utils/tlm_quantumkeeper.h>
#include <instructionBase.hpp>
#include "core/common/sr_param.h"

#include <systemc.h>
#include <iostream>
#include <fstream>
#include <boost/circular_buffer.hpp>
#include <string>

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


#define FUNC_MODEL
#define LT_IF
using namespace trap;
namespace core_microblaze_lt {

  /** @brief    Processor Class
  *   @details
  *   The top-level processor class holding the pipeline, registers and ports.
  */
  class CoreMICROBLAZELT : public sc_module {
    public:
    SC_HAS_PROCESS(CoreMICROBLAZELT);
    CoreMICROBLAZELT(sc_module_name name, MemoryInterface *memory = NULL);
    void mainLoop();
    void resetOp();
    void end_of_elaboration();
    tlm_utils::tlm_quantumkeeper quantKeeper;
    Instruction * decode(unsigned int bitString);
    MICROBLAZE_ABIIf * abiIf;
    MICROBLAZE_ABIIf & getInterface();
    ToolsManager<unsigned int> toolManager;
    Reg32_0 PC;
    Reg32_1 MSR;
    Reg32_0 EAR;
    Reg32_2 ESR;
    Reg32_0 BTR;
    Reg32_3 FSR;
    Reg32_0 EDR;
    Reg32_0 PID;
    Reg32_0 ZPR;
    Reg32_0 TLBLO;
    Reg32_0 TLBHI;
    Reg32_0 TLBX;
    Reg32_0 TLBSX;
    Reg32_0 IMMREG;
    Reg32_0 TARGET;
    Reg1_0 DSFLAG;
    Reg32_0 GPR[32];
    Reg32_0 PVR[12];
    MemoryInterface *mem;
    MemoryInterface &dataMem;
    sc_time latency;
    unsigned int totalCycles;
    boost::circular_buffer<HistoryInstrType> instHistoryQueue;
    unsigned int undumpedHistElems;
    unsigned int numInstructions;
    unsigned int ENTRY_POINT;
    unsigned int MPROC_ID;
    unsigned int PROGRAM_LIMIT;
    unsigned int PROGRAM_START;
    void enableHistory(std::string fileName = "");
    ~CoreMICROBLAZELT();

    private:
    bool resetCalled;
    Decoder decoder;
    std::ofstream histFile;
    sr_param<bool> historyEnabled;
    bool instrExecuting;
    Instruction * * INSTRUCTIONS;
    template_map<unsigned int, CacheElem> instrCache;
    static int numInstances;

  }; // class CoreMICROBLAZELT

} // namespace core_microblaze_lt



#endif
