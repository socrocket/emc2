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

#ifndef MICROBLAZE_CORE_FUNC_LT_ISATESTS2_HPP
#define MICROBLAZE_CORE_FUNC_LT_ISATESTS2_HPP

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


void MUL_0();
void MUL_1();
void MUL_2();
void MUL_3();
void MUL_4();
void MUL_5();
void MUL_6();
void BLEI_0();
void BLEI_1();
void BLEI_2();
void ANDN_0();
void ANDI_0();
void ANDI_1();
void ADDKC_0();
void ADDKC_1();
void ADDKC_2();
void ADDKC_3();
void ADDKC_4();
void ADDKC_5();
void ADDKC_6();
void ADDKC_7();
void MSRCLR_0();
void MSRCLR_1();
void MSRCLR_2();
void BSLLI_0();
void BSLLI_1();
void BGEI_0();
void BGEI_1();
void BGEI_2();
void SRC_0();
void SRC_1();
void SRC_2();
void SRC_3();
void SRC_4();
void SRC_5();
void SRC_6();
void SRC_7();
void SRC_8();
void SRC_9();
void SRA_0();
void SRA_1();
void SRA_2();
void SRA_3();
void SRA_4();
void SRA_5();
void IMM_0();
void IMM_1();
void SRL_0();
void SRL_1();
void SRL_2();
void SRL_3();
void SRL_4();
void SRL_5();
void FLT_0();
void MULHSU_0();
void MULHSU_1();
void MULHSU_2();
void MULHSU_3();
void MULHSU_4();
void MULHSU_5();
void ADD_0();
void ADD_1();
void ADD_2();
void ADD_3();
void ADD_4();
void ADD_5();
void ADD_6();
void ADD_7();
void ADD_8();
void ADD_9();
void ADD_10();
void ADD_11();
void ADD_12();
void XORI_0();
void XORI_1();
void XORI_2();
void PCMPNE_0();
void PCMPNE_1();
void BSRAI_0();
void BSRAI_1();
void BRAID_0();
void RSUBKC_0();
void RSUBKC_1();
void RSUBKC_2();
void RSUBKC_3();
void RSUBKC_4();
void SW_0();
void SW_1();
void SW_2();
void SW_3();
void SW_4();
void SH_0();
void SH_1();
void SH_2();
void SH_3();
void SH_4();
void BRK_0();
void BRK_1();
void BRI_0();
void ORI_0();


#endif
