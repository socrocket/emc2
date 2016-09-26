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


#include "microblaze/intunit/isaTests2.hpp"
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
void MUL_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x18);

  delete [] GPR;
  delete [] PVR;
} // MUL_0()

void MUL_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x6);
  GPR[1].immediateWrite(0xfffffffc);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffe8);

  delete [] GPR;
  delete [] PVR;
} // MUL_1()

void MUL_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x10);
  GPR[1].immediateWrite(0x10000001);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x10);

  delete [] GPR;
  delete [] PVR;
} // MUL_2()

void MUL_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x100);
  GPR[1].immediateWrite(0xefffffff);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffff00);

  delete [] GPR;
  delete [] PVR;
} // MUL_3()

void MUL_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffff00);
  GPR[1].immediateWrite(0x10000001);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffff00);

  delete [] GPR;
  delete [] PVR;
} // MUL_4()

void MUL_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffff00);
  GPR[1].immediateWrite(0xefffffff);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x100);

  delete [] GPR;
  delete [] PVR;
} // MUL_5()

void MUL_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MUL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xed8e9db8);

  delete [] GPR;
  delete [] PVR;
} // MUL_6()

void BLEI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BLEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLEI_0()

void BLEI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BLEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x1fff0);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4ffff0);

  delete [] GPR;
  delete [] PVR;
} // BLEI_1()

void BLEI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BLEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BLEI_2()

void ANDN_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ANDN toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x99888800);

  delete [] GPR;
  delete [] PVR;
} // ANDN_0()

void ANDI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ANDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xffcc8844);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x616666);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x44);

  delete [] GPR;
  delete [] PVR;
} // ANDI_0()

void ANDI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ANDI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xffcc8844);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  IMMREG.immediateWrite(0x8000f0ff);
  toTest.setParams(0x616666);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xf0cc0044);

  delete [] GPR;
  delete [] PVR;
} // ANDI_1()

void ADDKC_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_0()

void ADDKC_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xb);

  delete [] GPR;
  delete [] PVR;
} // ADDKC_1()

void ADDKC_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_2()

void ADDKC_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_3()

void ADDKC_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_4()

void ADDKC_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x80000002);

  delete [] GPR;
  delete [] PVR;
} // ADDKC_5()

void ADDKC_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_6()

void ADDKC_7() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADDKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADDKC_7()

void MSRCLR_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MSRCLR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // MSRCLR_0()

void MSRCLR_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MSRCLR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xffffffff);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x200004);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xffffffff);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0xdfffffff);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MSRCLR_1()

void MSRCLR_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MSRCLR toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[1].immediateWrite(0x13);
  MSR.immediateWrite(0xf0000000);
  ESR.immediateWrite(0x0);
  toTest.setParams(0x200001);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xf0000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x70000000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // MSRCLR_2()

void BSLLI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSLLI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x8fdd8c00);

  delete [] GPR;
  delete [] PVR;
} // BSLLI_0()

void BSLLI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSLLI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x8fdd8c00);

  delete [] GPR;
  delete [] PVR;
} // BSLLI_1()

void BGEI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BGEI_0()

void BGEI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  GPR[1].immediateWrite(0x0);
  toTest.setParams(0x1fff0);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4ffff0);

  delete [] GPR;
  delete [] PVR;
} // BGEI_1()

void BGEI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BGEI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BGEI_2()

void SRC_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa0000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_0()

void SRC_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_1()

void SRC_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa0000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_2()

void SRC_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_3()

void SRC_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000001);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x60000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_4()

void SRC_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xa0000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRC_5()

void SRC_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRC_6()

void SRC_7() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xa0000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_7()

void SRC_8() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_8()

void SRC_9() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000001);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x60000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRC_9()

void SRA_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRA_0()

void SRA_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000000);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // SRA_1()

void SRA_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x70000000);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x38000000);

  delete [] GPR;
  delete [] PVR;
} // SRA_2()

void SRA_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000001);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRA_3()

void SRA_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000000);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xe0000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRA_4()

void SRA_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRA toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x70000000);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x38000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRA_5()

void IMM_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  IMM toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  IMMREG.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x8bcd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(IMMREG.readNewValue(), (unsigned int)0x80008bcd);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // IMM_0()

void IMM_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  IMM toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  IMMREG.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  PC.immediateWrite(0x0);
  toTest.setParams(0x7bcd);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(IMMREG.readNewValue(), (unsigned int)0x80007bcd);

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  delete [] GPR;
  delete [] PVR;
} // IMM_1()

void SRL_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRL_0()

void SRL_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x0);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRL_1()

void SRL_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000001);
  MSR.immediateWrite(0x20000000);
  GPR[3].immediateWrite(0xffff);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x60000000);

  delete [] GPR;
  delete [] PVR;
} // SRL_2()

void SRL_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRL_3()

void SRL_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x40000000);
  MSR.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SRL_4()

void SRL_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SRL toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xc0000001);
  MSR.immediateWrite(0x20000000);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x210000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x60000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // SRL_5()

void FLT_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  FLT toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xfffffffd);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xfffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xc0400000);

  delete [] GPR;
  delete [] PVR;
} // FLT_0()

void MULHSU_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // MULHSU_0()

void MULHSU_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // MULHSU_1()

void MULHSU_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xfffffffa);
  GPR[1].immediateWrite(0x4);
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
} // MULHSU_2()

void MULHSU_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // MULHSU_3()

void MULHSU_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffef);

  delete [] GPR;
  delete [] PVR;
} // MULHSU_4()

void MULHSU_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  MULHSU toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0xffffff00);
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffff0);

  delete [] GPR;
  delete [] PVR;
} // MULHSU_5()

void ADD_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_0()

void ADD_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  delete [] GPR;
  delete [] PVR;
} // ADD_1()

void ADD_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_2()

void ADD_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_3()

void ADD_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_4()

void ADD_5() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0x50);
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

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x50);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // ADD_5()

void ADD_6() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x4);
  TARGET.immediateWrite(0x50);
  IMMREG.immediateWrite(0x8000abcd);
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

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x50);

  BOOST_CHECK_EQUAL(IMMREG.readNewValue(), (unsigned int)0xabcd);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xa);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // ADD_6()

void ADD_7() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_7()

void ADD_8() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x8);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADD_8()

void ADD_9() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xfffffffe);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // ADD_9()

void ADD_10() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_10()

void ADD_11() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xfe000000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  delete [] GPR;
  delete [] PVR;
} // ADD_11()

void ADD_12() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  ADD toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // ADD_12()

void XORI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  XORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x3);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x610000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x3);

  delete [] GPR;
  delete [] PVR;
} // XORI_0()

void XORI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  XORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0x5);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x610005);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // XORI_1()

void XORI_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  XORI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x0);
  GPR[1].immediateWrite(0xffff0000);
  TARGET.immediateWrite(0xffffffff);
  GPR[3].immediateWrite(0xffffffff);
  toTest.setParams(0x61ffff);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffff);

  delete [] GPR;
  delete [] PVR;
} // XORI_2()

void PCMPNE_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  PCMPNE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // PCMPNE_0()

void PCMPNE_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  PCMPNE toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // PCMPNE_1()

void BSRAI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSRAI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
} // BSRAI_0()

void BSRAI_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BSRAI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffe3f76);

  delete [] GPR;
  delete [] PVR;
} // BSRAI_1()

void BRAID_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRAID toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x50);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500004);

  BOOST_CHECK_EQUAL(TARGET.readNewValue(), (unsigned int)0x50);

  delete [] GPR;
  delete [] PVR;
} // BRAID_0()

void RSUBKC_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUBKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xffffffff);

  delete [] GPR;
  delete [] PVR;
} // RSUBKC_0()

void RSUBKC_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUBKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffe);

  delete [] GPR;
  delete [] PVR;
} // RSUBKC_1()

void RSUBKC_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUBKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x1);

  delete [] GPR;
  delete [] PVR;
} // RSUBKC_2()

void RSUBKC_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUBKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x20000000);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0xfffffffd);

  delete [] GPR;
  delete [] PVR;
} // RSUBKC_3()

void RSUBKC_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  RSUBKC toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
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
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x4);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x0);

  BOOST_CHECK_EQUAL(GPR[3].readNewValue(), (unsigned int)0x2);

  delete [] GPR;
  delete [] PVR;
} // RSUBKC_4()

void SW_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0x123456ab);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SW_0()

void SW_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
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
} // SW_1()

void SW_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[2].immediateWrite(0x22);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x32, 0xff445566);
  toTest.setParams(0x611000);
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
} // SW_2()

void SW_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
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
} // SW_3()

void SW_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SW toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0x500000);
  GPR[2].immediateWrite(0x22);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x32, 0xff445566);
  toTest.setParams(0x611000);
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
} // SW_4()

void SH_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
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

  BOOST_CHECK_EQUAL(dataMem.read_word_dbg(0x30), (unsigned int)0x56ab5566);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0x0);

  delete [] GPR;
  delete [] PVR;
} // SH_0()

void SH_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
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
} // SH_1()

void SH_2() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  TARGET.immediateWrite(0xffffffff);
  GPR[2].immediateWrite(0x22);
  GPR[3].immediateWrite(0x123456ab);
  dataMem.write_word_dbg(0x32, 0xff445566);
  toTest.setParams(0x611000);
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
} // SH_2()

void SH_3() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[1].immediateWrite(0x13);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  dataMem.write_word_dbg(0x34, 0xff445566);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0xffffffff);
  toTest.setParams(0x611000);
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
} // SH_3()

void SH_4() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  SH toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  dataMem.write_word_dbg(0x31, 0xff445566);
  GPR[1].immediateWrite(0x10);
  ESR.immediateWrite(0x0);
  PC.immediateWrite(0x0);
  GPR[2].immediateWrite(0x21);
  GPR[3].immediateWrite(0x123456ab);
  TARGET.immediateWrite(0x500000);
  toTest.setParams(0x611000);
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
} // SH_4()

void BRK_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x50);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x0);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x201000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x50);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x10000000);

  delete [] GPR;
  delete [] PVR;
} // BRK_0()

void BRK_1() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRK toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  GPR[2].immediateWrite(0x50);
  GPR[1].immediateWrite(0xffff);
  MSR.immediateWrite(0x100000);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x201000);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500000);

  BOOST_CHECK_EQUAL(GPR[1].readNewValue(), (unsigned int)0xffff);

  BOOST_CHECK_EQUAL(MSR.readNewValue(), (unsigned int)0x100000);

  BOOST_CHECK_EQUAL(ESR.readNewValue(), (unsigned int)0xe0000000);

  delete [] GPR;
  delete [] PVR;
} // BRK_1()

void BRI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
  core_microblaze_lt::Reg32_0 TLBX;
  core_microblaze_lt::Reg32_0 TLBSX;
  core_microblaze_lt::Reg32_0 IMMREG;
  core_microblaze_lt::Reg32_0 TARGET;
  core_microblaze_lt::Reg1_0 DSFLAG;
  Reg32_0 * GPR = new Reg32_0[32];
  Reg32_0 * PVR = new Reg32_0[12];
  unsigned int totalCycles;
  core_microblaze_lt::MemoryInterface dataMem(5242880);


  BRI toTest(PC, MSR, EAR, ESR, BTR, FSR, EDR, PID, ZPR, TLBLO, TLBHI, TLBX,
    TLBSX, IMMREG, TARGET, DSFLAG, GPR, PVR, dataMem, totalCycles);
  PC.immediateWrite(0x500000);
  toTest.setParams(0x50);
  try {
    toTest.behavior();
  }
  catch(annul_exception &etc) {
  }

  BOOST_CHECK_EQUAL(PC.readNewValue(), (unsigned int)0x500050);

  delete [] GPR;
  delete [] PVR;
} // BRI_0()

void ORI_0() {
  core_microblaze_lt::Reg32_0 PC;
  core_microblaze_lt::Reg32_1 MSR;
  core_microblaze_lt::Reg32_0 EAR;
  core_microblaze_lt::Reg32_2 ESR;
  core_microblaze_lt::Reg32_0 BTR;
  core_microblaze_lt::Reg32_3 FSR;
  core_microblaze_lt::Reg32_0 EDR;
  core_microblaze_lt::Reg32_0 PID;
  core_microblaze_lt::Reg32_0 ZPR;
  core_microblaze_lt::Reg32_0 TLBLO;
  core_microblaze_lt::Reg32_0 TLBHI;
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
} // ORI_0()


