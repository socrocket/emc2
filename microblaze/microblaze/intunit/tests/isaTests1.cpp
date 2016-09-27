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


#include "microblaze/intunit/isaTests1.hpp"
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
void CMPU_1() {
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
  GPR[2].immediateWrite(0xfffea385);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7ffda652);

  delete [] GPR;
  delete [] PVR;
} // CMPU_1()

void CMPU_2() {
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
  GPR[2].immediateWrite(0xffff02cd);
  GPR[1].immediateWrite(0x15c7b);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7ffda652);

  delete [] GPR;
  delete [] PVR;
} // CMPU_2()

void CMPU_3() {
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
  GPR[2].immediateWrite(0x3);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x1);

  delete [] GPR;
  delete [] PVR;
} // CMPU_3()

void CMPU_4() {
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
  GPR[2].immediateWrite(0x4);
  GPR[1].immediateWrite(0x3);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // CMPU_4()

void CMPU_5() {
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
  GPR[2].immediateWrite(0x3);
  GPR[1].immediateWrite(0x3);
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
} // CMPU_5()

void CMPU_6() {
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
  GPR[2].immediateWrite(-0x3);
  GPR[1].immediateWrite(-0x4);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // CMPU_6()

void CMPU_7() {
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
  GPR[2].immediateWrite(-0x5);
  GPR[1].immediateWrite(-0x4);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // CMPU_7()

void CMPU_8() {
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
  GPR[2].immediateWrite(-0x5);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7ffffff7);

  delete [] GPR;
  delete [] PVR;
} // CMPU_8()

void BSRL_0() {
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


  BSRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2a3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRL_0()

void BSRL_1() {
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


  BSRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2a3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRL_1()

void BSRL_2() {
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


  BSRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1fe3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRL_2()

void BLTI_0() {
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


  BLTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x5);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BLTI_0()

void BLTI_1() {
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


  BLTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLTI_1()

void BLTI_2() {
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


  BLTI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLTI_2()

void PCMPEQ_0() {
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


  PCMPEQ toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x1234fedc);
  GPR[1].immediateWrite(0x1234fedc);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // PCMPEQ_0()

void PCMPEQ_1() {
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


  PCMPEQ toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x1234fedc);
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
} // PCMPEQ_1()

void XOR_0() {
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


  XOR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // XOR_0()

void XOR_1() {
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


  XOR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x5);
  GPR[1].immediateWrite(0x5);
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
} // XOR_1()

void XOR_2() {
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


  XOR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0xffff);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffff0000);

  delete [] GPR;
  delete [] PVR;
} // XOR_2()

void BEQ_0() {
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


  BEQ toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x0);
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
} // BEQ_0()

void BEQ_1() {
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


  BEQ toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BEQ_1()

void BEQ_2() {
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


  BEQ toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x1);
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
} // BEQ_2()

void BLTD_0() {
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


  BLTD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x1);
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
} // BLTD_0()

void BLTD_1() {
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


  BLTD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLTD_1()

void CMP_0() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // CMP_0()

void CMP_1() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffea385);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffda652);

  delete [] GPR;
  delete [] PVR;
} // CMP_1()

void CMP_2() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffff02cd);
  GPR[1].immediateWrite(0x15c7b);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffda652);

  delete [] GPR;
  delete [] PVR;
} // CMP_2()

void CMP_3() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x3);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x1);

  delete [] GPR;
  delete [] PVR;
} // CMP_3()

void CMP_4() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x4);
  GPR[1].immediateWrite(0x3);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // CMP_4()

void CMP_5() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x3);
  GPR[1].immediateWrite(0x3);
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
} // CMP_5()

void CMP_6() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(-0x3);
  GPR[1].immediateWrite(-0x4);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // CMP_6()

void CMP_7() {
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


  CMP toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(-0x5);
  GPR[1].immediateWrite(-0x4);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x1);

  delete [] GPR;
  delete [] PVR;
} // CMP_7()

void BRALID_0() {
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


  BRALID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  toTest.setParams(0x200050);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x50);

  delete [] GPR;
  delete [] PVR;
} // BRALID_0()

void RTBD_0() {
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


  RTBD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RTBD_0()

void RTBD_1() {
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


  RTBD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x20000);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x60000);

  delete [] GPR;
  delete [] PVR;
} // RTBD_1()

void RTBD_2() {
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


  RTBD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x100000);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x480000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // RTBD_2()

void MFS_0() {
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


  MFS toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xabcd);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x200001);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xabcd);

  delete [] GPR;
  delete [] PVR;
} // MFS_0()

void MFS_1() {
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


  MFS toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  PVR[1].immediateWrite(0xabcd);
  GPR[1].immediateWrite(0x13);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x202001);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xabcd);

  delete [] GPR;
  delete [] PVR;
} // MFS_1()

void BLT_0() {
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


  BLT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BLT_0()

void BLT_1() {
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


  BLT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLT_1()

void BLT_2() {
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


  BLT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLT_2()

void BRLID_0() {
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


  BRLID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0xffff);
  toTest.setParams(0x200050);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500050);

  delete [] GPR;
  delete [] PVR;
} // BRLID_0()

void SB_0() {
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


  SB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0xab445566);

  delete [] GPR;
  delete [] PVR;
} // SB_0()

void SB_1() {
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


  SB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0xffab5566);

  delete [] GPR;
  delete [] PVR;
} // SB_1()

void SB_2() {
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


  SB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x31), (unsigned int)0xab445566);

  delete [] GPR;
  delete [] PVR;
} // SB_2()

void BLE_0() {
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


  BLE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BLE_0()

void BLE_1() {
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


  BLE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLE_1()

void BLE_2() {
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


  BLE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLE_2()

void SHI_0() {
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


  SHI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x610020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0x56ab5566);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SHI_0()

void SHI_1() {
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


  SHI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x31), (unsigned int)0xff445566);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8e00000);

  delete [] GPR;
  delete [] PVR;
} // SHI_1()

void SHI_2() {
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


  SHI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x32, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610022);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x32), (unsigned int)0x56ab5566);

  delete [] GPR;
  delete [] PVR;
} // SHI_2()

void SHI_3() {
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


  SHI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x34), (unsigned int)0x56ab5566);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // SHI_3()

void SHI_4() {
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


  SHI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0x500000);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x31), (unsigned int)0xff445566);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8e80000);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  delete [] GPR;
  delete [] PVR;
} // SHI_4()

void AND_0() {
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


  AND toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x66666666);
  GPR[1].immediateWrite(0xffcc8844);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x66440044);

  delete [] GPR;
  delete [] PVR;
} // AND_0()

void AND_1() {
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


  AND toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x158aad87);
  GPR[1].immediateWrite(0xafb548ae);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x5800886);

  delete [] GPR;
  delete [] PVR;
} // AND_1()

void AND_2() {
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


  AND toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xab88cd77);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xab88cd77);

  delete [] GPR;
  delete [] PVR;
} // AND_2()

void RSUBIC_0() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610003);
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
} // RSUBIC_0()

void RSUBIC_1() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x61fffd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x7);

  delete [] GPR;
  delete [] PVR;
} // RSUBIC_1()

void RSUBIC_2() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x61fffd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBIC_2()

void RSUBIC_3() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x88888888);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000abcd);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611234);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x234489ab);

  delete [] GPR;
  delete [] PVR;
} // RSUBIC_3()

void RSUBIC_4() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000ffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBIC_4()

void RSUBIC_5() {
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


  RSUBIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000ffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x61ffff);
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
} // RSUBIC_5()

void SBI_0() {
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


  SBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0xab445566);

  delete [] GPR;
  delete [] PVR;
} // SBI_0()

void SBI_1() {
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


  SBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0xffab5566);

  delete [] GPR;
  delete [] PVR;
} // SBI_1()

void SBI_2() {
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


  SBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0x123456ab);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x31), (unsigned int)0xab445566);

  delete [] GPR;
  delete [] PVR;
} // SBI_2()

void RTED_0() {
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


  RTED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x800000);

  delete [] GPR;
  delete [] PVR;
} // RTED_0()

void RTED_1() {
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


  RTED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x20000);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x860000);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  delete [] GPR;
  delete [] PVR;
} // RTED_1()

void RTED_2() {
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


  RTED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  BTR.immediateWrite(0x7777);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x0);
  ESR.immediateWrite(0x80000);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x800000);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x7777);

  delete [] GPR;
  delete [] PVR;
} // RTED_2()

void RTED_3() {
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


  RTED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x100000);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x480000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // RTED_3()

void RSUBIK_0() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610003);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBIK_0()

void RSUBIK_1() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x61fffd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBIK_1()

void RSUBIK_2() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xfffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x61fffd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBIK_2()

void RSUBIK_3() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x88888888);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000abcd);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611234);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x234489ac);

  delete [] GPR;
  delete [] PVR;
} // RSUBIK_3()

void RSUBIK_4() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000ffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUBIK_4()

void RSUBIK_5() {
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


  RSUBIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  IMMREG.immediateWrite(0x8000ffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x61ffff);
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
} // RSUBIK_5()

void BRALD_0() {
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


  BRALD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x50);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BRALD_0()

void BRA_0() {
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


  BRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  toTest.setParams(0x800);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x50);

  delete [] GPR;
  delete [] PVR;
} // BRA_0()

void SEXT16_0() {
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


  SEXT16 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x6666);

  delete [] GPR;
  delete [] PVR;
} // SEXT16_0()

void SEXT16_1() {
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


  SEXT16 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7777);

  delete [] GPR;
  delete [] PVR;
} // SEXT16_1()

void SEXT16_2() {
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


  SEXT16 toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xabcd8777);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffff8777);

  delete [] GPR;
  delete [] PVR;
} // SEXT16_2()

void SWI_0() {
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


  SWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x610020);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0x123456ab);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SWI_0()

void SWI_1() {
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


  SWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x31), (unsigned int)0xff445566);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8f00000);

  delete [] GPR;
  delete [] PVR;
} // SWI_1()

void SWI_2() {
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


  SWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x32, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610022);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x32);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8f00000);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x32), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // SWI_2()

void SWI_3() {
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


  SWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x34), (unsigned int)0x123456ab);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // SWI_3()

void SWI_4() {
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


  SWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0x500000);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x32, 0xff445566);
  GPR[3].immediateWrite(0x123456ab);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610022);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8f80000);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x32);

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x32), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // SWI_4()

void BLEID_0() {
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


  BLEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLEID_0()

void BLEID_1() {
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


  BLEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLEID_1()

void BSRA_0() {
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


  BSRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2a3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRA_0()

void BSRA_1() {
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


  BSRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2a3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRA_1()

void BSRA_2() {
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


  BSRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffe3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRA_2()

void BLED_0() {
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


  BLED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x1);
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
} // BLED_0()

void BLED_1() {
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


  BLED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BLED_1()

void MULI_0() {
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


  MULI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MULI_0()

void MULI_1() {
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


  MULI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xfffffffc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x610001);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffc);

  delete [] GPR;
  delete [] PVR;
} // MULI_1()

void MULI_2() {
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


  MULI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffc);

  delete [] GPR;
  delete [] PVR;
} // MULI_2()

void MULI_3() {
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


  MULI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xfffffffc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // MULI_3()

void MULI_4() {
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


  MULI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x7530);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x610005);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x249f0);

  delete [] GPR;
  delete [] PVR;
} // MULI_4()

void MSRSET_0() {
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


  MSRSET toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xffffffff);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x200005);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x13);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0xffffffff);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // MSRSET_0()

void MSRSET_1() {
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


  MSRSET toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x200004);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MSRSET_1()

void MSRSET_2() {
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


  MSRSET toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xf0000000);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x204001);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xf0000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0xf0020000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MSRSET_2()


