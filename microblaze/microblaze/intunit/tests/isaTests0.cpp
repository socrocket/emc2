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


#include "microblaze/intunit/isaTests0.hpp"
#include "microblaze/intunit/alias.hpp"

#include <utils/customExceptions.hpp>

#include <boost/test/test_tools.hpp>

#ifdef _WIN32
#pragma warning(disable : 4101
#endif

#define private public
#define protected public
#include "microblaze/intunit/instructions.hpp"
#include "microblaze/intunit/registers.hpp"
#include "microblaze/intunit/memory.hpp"
#undef private
#undef protected


using namespace core_microblaze_lt;
using namespace trap;
void BGE_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGE_0()

void BGE_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffffff0);
  GPR[1].immediateWrite(0x0);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4ffff0);

  delete [] GPR;
  delete [] PVR;
} // BGE_1()

void BGE_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BGE_2()

void BGEID_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGEID_0()

void BGEID_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(-0x1);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BGEID_1()

void BSLL_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSLL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x7);
  GPR[1].immediateWrite(0x151fbb18);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x8fdd8c00);

  delete [] GPR;
  delete [] PVR;
} // BSLL_0()

void BSLL_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSLL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xf5489fe7);
  GPR[1].immediateWrite(0x151fbb18);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x8fdd8c00);

  delete [] GPR;
  delete [] PVR;
} // BSLL_1()

void BSLL_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSLL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x7);
  GPR[1].immediateWrite(0xff1fbb18);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x8fdd8c00);

  delete [] GPR;
  delete [] PVR;
} // BSLL_2()

void BGT_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGT_0()

void BGT_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffffff0);
  GPR[1].immediateWrite(0x0);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BGT_1()

void BGT_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BGT_2()

void BR_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  toTest.setParams(0x800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500050);

  delete [] GPR;
  delete [] PVR;
} // BR_0()

void BNED_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNED_0()

void BNED_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BNED_1()

void BNEI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x5);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNEI_0()

void BNEI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x1fff0);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BNEI_1()

void BNEI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(-0x5);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNEI_2()

void LBU_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x20);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff);

  delete [] GPR;
  delete [] PVR;
} // LBU_0()

void LBU_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x44);

  delete [] GPR;
  delete [] PVR;
} // LBU_1()

void LBU_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456cd);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff);

  delete [] GPR;
  delete [] PVR;
} // LBU_2()

void RSUB_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUB_0()

void RSUB_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x5);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x3);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffe);

  delete [] GPR;
  delete [] PVR;
} // RSUB_1()

void RSUB_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x3);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x5);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // RSUB_2()

void RSUB_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0xfffffffe);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffd);

  delete [] GPR;
  delete [] PVR;
} // RSUB_3()

void RSUB_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xfffffffe);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x1);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // RSUB_4()

void BSRLI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSRLI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x151fbb18);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610007);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2a3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRLI_0()

void BSRLI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSRLI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xff1fbb18);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610007);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1fe3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRLI_1()

void FDIV_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  FDIV toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xc0000000);
  GPR[1].immediateWrite(0xc07a1cac);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3f030368);

  delete [] GPR;
  delete [] PVR;
} // FDIV_0()

void FADD_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  FADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xc0800000);
  GPR[1].immediateWrite(0xc073c6a8);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xc0f9e354);

  delete [] GPR;
  delete [] PVR;
} // FADD_0()

void MULHU_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x6);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MULHU_0()

void MULHU_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x6);
  GPR[1].immediateWrite(0xfffffffc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x5);

  delete [] GPR;
  delete [] PVR;
} // MULHU_1()

void MULHU_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x10000001);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // MULHU_2()

void MULHU_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x100);
  GPR[1].immediateWrite(0xefffffff);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xef);

  delete [] GPR;
  delete [] PVR;
} // MULHU_3()

void BGTD_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGTD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGTD_0()

void BGTD_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGTD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BGTD_1()

void BGTI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x5);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGTI_0()

void BGTI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x1fff0);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BGTI_1()

void BGTI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(-0x5);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BGTI_2()

void SEXT8_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SEXT8 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x6666);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x66);

  delete [] GPR;
  delete [] PVR;
} // SEXT8_0()

void SEXT8_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SEXT8 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xabcd7777);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x77);

  delete [] GPR;
  delete [] PVR;
} // SEXT8_1()

void SEXT8_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SEXT8 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xabcd7787);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffff87);

  delete [] GPR;
  delete [] PVR;
} // SEXT8_2()

void LHU_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[2].immediateWrite(0x20);
  GPR[3].immediateWrite(0x1111);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHU_0()

void LHU_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x1111);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8c00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LHU_1()

void LHU_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[2].immediateWrite(0x22);
  GPR[3].immediateWrite(0x1111);
  dataMem.write_word_dbg(0x32, 0xff445566);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHU_2()

void LHU_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x1111);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHU_3()

void LHU_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LHU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x1111);
  TARGET.immediateWrite(0x500000);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8c80000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  delete [] GPR;
  delete [] PVR;
} // LHU_4()

void BNE_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNE_0()

void BNE_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffffff0);
  GPR[1].immediateWrite(0x0);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BNE_1()

void BNE_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BNE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x5);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNE_2()

void BRLD_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRLD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffff);
  GPR[1].immediateWrite(0x50);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x400800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(GPR[2].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500050);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BRLD_0()

void BRKI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRKI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x0);
  toTest.setParams(0x208bcd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0xffff8bcd);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x10000000);

  delete [] GPR;
  delete [] PVR;
} // BRKI_0()

void BRKI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRKI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x0);
  toTest.setParams(0x200008);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x8);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x10000000);

  delete [] GPR;
  delete [] PVR;
} // BRKI_1()

void BRKI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRKI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x40000);
  toTest.setParams(0x200008);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x8);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x10020000);

  delete [] GPR;
  delete [] PVR;
} // BRKI_2()

void BRKI_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRKI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x100000);
  toTest.setParams(0x200008);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x8);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x10080000);

  delete [] GPR;
  delete [] PVR;
} // BRKI_3()

void BRKI_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRKI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x100000);
  toTest.setParams(0x200040);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xffff);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // BRKI_4()

void ADDIKC_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610006);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDIKC_0()

void ADDIKC_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610006);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xb);

  delete [] GPR;
  delete [] PVR;
} // ADDIKC_1()

void ADDIKC_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x7fffffff);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610002);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDIKC_2()

void ADDIKC_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xff0000);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x618000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDIKC_3()

void ADDIKC_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xff0000);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x618000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8001);

  delete [] GPR;
  delete [] PVR;
} // ADDIKC_4()

void IDIV_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  IDIV toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x20);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // IDIV_0()

void IDIV_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  IDIV toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x2);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0xfffffffe);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // IDIV_1()

void IDIV_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  IDIV toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x20);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x2000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xa0000000);

  delete [] GPR;
  delete [] PVR;
} // IDIV_2()

void ADDC_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x6);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDC_0()

void ADDC_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x6);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xb);

  delete [] GPR;
  delete [] PVR;
} // ADDC_1()

void ADDC_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x7fffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x2);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDC_2()

void ADDC_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x4);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // ADDC_3()

void ADDC_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff000000);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x80000000);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7f000000);

  delete [] GPR;
  delete [] PVR;
} // ADDC_4()

void ADDC_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x7fffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x2);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000002);

  delete [] GPR;
  delete [] PVR;
} // ADDC_5()

void ADDC_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x4);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // ADDC_6()

void ADDC_7() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff000000);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x80000000);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7f000001);

  delete [] GPR;
  delete [] PVR;
} // ADDC_7()

void ADDC_8() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xfffffffe);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x1);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADDC_8()

void ADDC_9() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x8);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADDC_9()

void ADDC_10() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x9);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADDC_10()

void ADDC_11() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x7fffffff);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xffffffff);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADDC_11()

void ADDC_12() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xfffffffe);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // ADDC_12()

void ADDC_13() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xff000000);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xfe000001);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // ADDC_13()

void ADDC_14() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xfffffffe);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xfffffffc);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // ADDC_14()

void LBUI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x10);
  dataMem.write_word_dbg(0x30, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff);

  delete [] GPR;
  delete [] PVR;
} // LBUI_0()

void LBUI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x10);
  dataMem.write_word_dbg(0x30, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x44);

  delete [] GPR;
  delete [] PVR;
} // LBUI_1()

void LBUI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  LBUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0x123456cd);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff);

  delete [] GPR;
  delete [] PVR;
} // LBUI_2()

void ADDK_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x6);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDK_0()

void ADDK_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x6);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDK_1()

void ADDK_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x7fffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x2);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDK_2()

void ADDK_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x4);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // ADDK_3()

void ADDK_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff000000);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x80000000);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7f000000);

  delete [] GPR;
  delete [] PVR;
} // ADDK_4()

void ADDK_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x7fffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x2);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDK_5()

void ADDK_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x4);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // ADDK_6()

void ADDK_7() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff000000);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x80000000);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7f000000);

  delete [] GPR;
  delete [] PVR;
} // ADDK_7()

void OR_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  OR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x0);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // OR_0()

void OR_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  OR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x0);
  GPR[1].immediateWrite(0x2);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // OR_1()

void ADDI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x0);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610006);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDI_0()

void ADDI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x0);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610006);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDI_1()

void ADDI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x7fffffff);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x0);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610002);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDI_2()

void ADDI_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff0000);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x0);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x618000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDI_3()

void ADDI_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xff0000);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x0);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x618000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDI_4()

void ADDI_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x80001234);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610006);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x12340006);

  delete [] GPR;
  delete [] PVR;
} // ADDI_5()

void BEQID_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BEQID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BEQID_0()

void BEQID_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BEQID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BEQID_1()

void CMPU_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  CMPU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xd6cc);
  GPR[1].immediateWrite(0xfd33);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffd999);

  delete [] GPR;
  delete [] PVR;
} // CMPU_0()


