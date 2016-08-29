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


#include "microblaze/intunit/isaTests3.hpp"
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
void ORI_1() {
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


  ORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x2);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // ORI_1()

void ORI_2() {
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


  ORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x61f000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffff000);

  delete [] GPR;
  delete [] PVR;
} // ORI_2()

void ORI_3() {
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


  ORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // ORI_3()

void ANDNI_0() {
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


  ANDNI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xffcc8844);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x616666);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffcc8800);

  delete [] GPR;
  delete [] PVR;
} // ANDNI_0()

void BRD_0() {
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


  BRD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  toTest.setParams(0x800);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500050);

  delete [] GPR;
  delete [] PVR;
} // BRD_0()

void LHUI_0() {
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


  LHUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  GPR[3].immediateWrite(0x1111);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x610020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHUI_0()

void LHUI_1() {
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


  LHUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0x1111);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8c00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LHUI_1()

void LHUI_2() {
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


  LHUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x32, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610022);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHUI_2()

void LHUI_3() {
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


  LHUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff44);

  delete [] GPR;
  delete [] PVR;
} // LHUI_3()

void LHUI_4() {
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


  LHUI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0x500000);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8c80000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  delete [] GPR;
  delete [] PVR;
} // LHUI_4()

void RSUBIKC_0() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffe);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_0()

void RSUBIKC_1() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x7);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_1()

void RSUBIKC_2() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_2()

void RSUBIKC_3() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x234489ab);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_3()

void RSUBIKC_4() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_4()

void RSUBIKC_5() {
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


  RSUBIKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUBIKC_5()

void MULH_0() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MULH_0()

void MULH_1() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // MULH_1()

void MULH_2() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // MULH_2()

void MULH_3() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffef);

  delete [] GPR;
  delete [] PVR;
} // MULH_3()

void MULH_4() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffff00);
  GPR[1].immediateWrite(0xefffffff);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x10);

  delete [] GPR;
  delete [] PVR;
} // MULH_4()

void MULH_5() {
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


  MULH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x38ff0ccc);
  GPR[1].immediateWrite(0x5faadada);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x154cafd7);

  delete [] GPR;
  delete [] PVR;
} // MULH_5()

void FRSUB_0() {
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


  FRSUB toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xc0f9e354);
  GPR[1].immediateWrite(0xc073c6a8);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xc0800000);

  delete [] GPR;
  delete [] PVR;
} // FRSUB_0()

void BEQI_0() {
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


  BEQI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BEQI_0()

void BEQI_1() {
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


  BEQI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x1fff0);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4ffff0);

  delete [] GPR;
  delete [] PVR;
} // BEQI_1()

void BEQI_2() {
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


  BEQI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x1);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  delete [] GPR;
  delete [] PVR;
} // BEQI_2()

void BEQD_0() {
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


  BEQD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BEQD_0()

void BEQD_1() {
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


  BEQD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BEQD_1()

void RTID_0() {
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


  RTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x40000000);

  delete [] GPR;
  delete [] PVR;
} // RTID_0()

void RTID_1() {
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


  RTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x20000);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x40060000);

  delete [] GPR;
  delete [] PVR;
} // RTID_1()

void RTID_2() {
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


  RTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x100000);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x480000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // RTID_2()

void RTID_3() {
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


  RTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x40000000);

  delete [] GPR;
  delete [] PVR;
} // RTID_3()

void RTID_4() {
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


  RTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  MSR.immediateWrite(0x20000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x70);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x40060000);

  delete [] GPR;
  delete [] PVR;
} // RTID_4()

void FMUL_0() {
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


  FMUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x4173c6a8);

  delete [] GPR;
  delete [] PVR;
} // FMUL_0()

void LWI_0() {
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


  LWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  ESR.immediateWrite(0x0);
  GPR[3].immediateWrite(0x1111);
  dataMem.write_word_dbg(0x30, 0xff445566);
  toTest.setParams(0x610020);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // LWI_0()

void LWI_1() {
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


  LWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[3].immediateWrite(0x1111);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LWI_1()

void LWI_2() {
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


  LWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x32, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610022);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x32);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LWI_2()

void LWI_3() {
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


  LWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // LWI_3()

void LWI_4() {
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


  LWI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  TARGET.immediateWrite(0x500000);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[3].immediateWrite(0x1111);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x610021);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d80000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  delete [] GPR;
  delete [] PVR;
} // LWI_4()

void BNEID_0() {
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


  BNEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BNEID_0()

void BNEID_1() {
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


  BNEID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BNEID_1()

void ADDIK_0() {
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


  ADDIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDIK_0()

void ADDIK_1() {
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


  ADDIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDIK_1()

void ADDIK_2() {
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


  ADDIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDIK_2()

void ADDIK_3() {
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


  ADDIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDIK_3()

void ADDIK_4() {
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


  ADDIK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDIK_4()

void BGTID_0() {
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


  BGTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGTID_0()

void BGTID_1() {
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


  BGTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BGTID_1()

void ADDIC_0() {
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


  ADDIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADDIC_0()

void ADDIC_1() {
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


  ADDIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xb);

  delete [] GPR;
  delete [] PVR;
} // ADDIC_1()

void ADDIC_2() {
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


  ADDIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000001);

  delete [] GPR;
  delete [] PVR;
} // ADDIC_2()

void ADDIC_3() {
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


  ADDIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8000);

  delete [] GPR;
  delete [] PVR;
} // ADDIC_3()

void ADDIC_4() {
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


  ADDIC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfe8001);

  delete [] GPR;
  delete [] PVR;
} // ADDIC_4()

void LW_0() {
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


  LW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // LW_0()

void LW_1() {
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


  LW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LW_1()

void LW_2() {
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


  LW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x32);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d00000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  delete [] GPR;
  delete [] PVR;
} // LW_2()

void LW_3() {
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


  LW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xff445566);

  delete [] GPR;
  delete [] PVR;
} // LW_3()

void LW_4() {
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


  LW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x20);

  BOOST_CHECK_EQUAL(EAR.readNewValue(), (unsigned int)0x31);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x8d80000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1111);

  BOOST_CHECK_EQUAL(BTR.readNewValue(), (unsigned int)0x500000);

  delete [] GPR;
  delete [] PVR;
} // LW_4()

void RSUBC_0() {
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


  RSUBC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBC_0()

void RSUBC_1() {
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


  RSUBC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffe);

  delete [] GPR;
  delete [] PVR;
} // RSUBC_1()

void RSUBC_2() {
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


  RSUBC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // RSUBC_2()

void RSUBC_3() {
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


  RSUBC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x20000000);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0xfffffffe);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffd);

  delete [] GPR;
  delete [] PVR;
} // RSUBC_3()

void RSUBC_4() {
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


  RSUBC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0xfffffffe);
  TARGET.immediateWrite(0xffffffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x1);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // RSUBC_4()

void BLTID_0() {
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


  BLTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(-0x1);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BLTID_0()

void BLTID_1() {
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


  BLTID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10010);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BLTID_1()

void RSUBI_0() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_0()

void RSUBI_1() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_1()

void RSUBI_2() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)-0x6);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_2()

void RSUBI_3() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x234489ac);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_3()

void RSUBI_4() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_4()

void RSUBI_5() {
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


  RSUBI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUBI_5()

void MTS_0() {
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


  MTS toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x10001);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x13);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x13);

  delete [] GPR;
  delete [] PVR;
} // MTS_0()

void MTS_1() {
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


  MTS toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xffffffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x11001);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x13);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // MTS_1()

void RSUBK_0() {
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


  RSUBK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // RSUBK_0()

void RSUBK_1() {
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


  RSUBK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffe);

  delete [] GPR;
  delete [] PVR;
} // RSUBK_1()

void RSUBK_2() {
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


  RSUBK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // RSUBK_2()

void RSUBK_3() {
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


  RSUBK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffd);

  delete [] GPR;
  delete [] PVR;
} // RSUBK_3()

void RSUBK_4() {
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


  RSUBK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // RSUBK_4()

void BGED_0() {
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


  BGED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x1);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500010);

  delete [] GPR;
  delete [] PVR;
} // BGED_0()

void BGED_1() {
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


  BGED toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(-0x1);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x11000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500008);

  delete [] GPR;
  delete [] PVR;
} // BGED_1()

void BRID_0() {
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


  BRID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x50);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x500050);

  delete [] GPR;
  delete [] PVR;
} // BRID_0()

void PCMPBF_0() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_0()

void PCMPBF_1() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x12ffffff);
  GPR[1].immediateWrite(0x1234fedc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_1()

void PCMPBF_2() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xff34ffff);
  GPR[1].immediateWrite(0x1234fedc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_2()

void PCMPBF_3() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffffeff);
  GPR[1].immediateWrite(0x1234fedc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_3()

void PCMPBF_4() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffffdc);
  GPR[1].immediateWrite(0x1234fedc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_4()

void PCMPBF_5() {
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


  PCMPBF toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xff34ffdc);
  GPR[1].immediateWrite(0x1234fedc);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x611000);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // PCMPBF_5()

void IDIVU_0() {
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


  IDIVU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // IDIVU_0()

void IDIVU_1() {
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


  IDIVU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x7fffffff);

  delete [] GPR;
  delete [] PVR;
} // IDIVU_1()

void IDIVU_2() {
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


  IDIVU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x2000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x28000000);

  delete [] GPR;
  delete [] PVR;
} // IDIVU_2()

void BRAD_0() {
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


  BRAD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x50);
  toTest.setParams(0x800);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x50);

  delete [] GPR;
  delete [] PVR;
} // BRAD_0()

void BRAI_0() {
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


  BRAI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x50);
  try {
    toTest.behavior();
  }
  catch(annull_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x50);

  delete [] GPR;
  delete [] PVR;
} // BRAI_0()


