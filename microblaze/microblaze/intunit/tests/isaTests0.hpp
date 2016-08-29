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

#ifndef MICROBLAZE_CORE_FUNC_LT_ISATESTS0_HPP
#define MICROBLAZE_CORE_FUNC_LT_ISATESTS0_HPP

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


void BGE_0();
void BGE_1();
void BGE_2();
void BGEID_0();
void BGEID_1();
void BSLL_0();
void BSLL_1();
void BSLL_2();
void BGT_0();
void BGT_1();
void BGT_2();
void BR_0();
void BNED_0();
void BNED_1();
void BNEI_0();
void BNEI_1();
void BNEI_2();
void LBU_0();
void LBU_1();
void LBU_2();
void RSUB_0();
void RSUB_1();
void RSUB_2();
void RSUB_3();
void RSUB_4();
void BSRLI_0();
void BSRLI_1();
void FDIV_0();
void FADD_0();
void MULHU_0();
void MULHU_1();
void MULHU_2();
void MULHU_3();
void BGTD_0();
void BGTD_1();
void BGTI_0();
void BGTI_1();
void BGTI_2();
void SEXT8_0();
void SEXT8_1();
void SEXT8_2();
void LHU_0();
void LHU_1();
void LHU_2();
void LHU_3();
void LHU_4();
void BNE_0();
void BNE_1();
void BNE_2();
void BRLD_0();
void BRKI_0();
void BRKI_1();
void BRKI_2();
void BRKI_3();
void BRKI_4();
void ADDIKC_0();
void ADDIKC_1();
void ADDIKC_2();
void ADDIKC_3();
void ADDIKC_4();
void IDIV_0();
void IDIV_1();
void IDIV_2();
void ADDC_0();
void ADDC_1();
void ADDC_2();
void ADDC_3();
void ADDC_4();
void ADDC_5();
void ADDC_6();
void ADDC_7();
void ADDC_8();
void ADDC_9();
void ADDC_10();
void ADDC_11();
void ADDC_12();
void ADDC_13();
void ADDC_14();
void LBUI_0();
void LBUI_1();
void LBUI_2();
void ADDK_0();
void ADDK_1();
void ADDK_2();
void ADDK_3();
void ADDK_4();
void ADDK_5();
void ADDK_6();
void ADDK_7();
void OR_0();
void OR_1();
void ADDI_0();
void ADDI_1();
void ADDI_2();
void ADDI_3();
void ADDI_4();
void ADDI_5();
void BEQID_0();
void BEQID_1();
void CMPU_0();


#endif
