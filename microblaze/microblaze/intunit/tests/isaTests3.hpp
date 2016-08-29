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

#ifndef MICROBLAZE_CORE_FUNC_LT_ISATESTS3_HPP
#define MICROBLAZE_CORE_FUNC_LT_ISATESTS3_HPP

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


void ORI_1();
void ORI_2();
void ORI_3();
void ANDNI_0();
void BRD_0();
void LHUI_0();
void LHUI_1();
void LHUI_2();
void LHUI_3();
void LHUI_4();
void RSUBIKC_0();
void RSUBIKC_1();
void RSUBIKC_2();
void RSUBIKC_3();
void RSUBIKC_4();
void RSUBIKC_5();
void MULH_0();
void MULH_1();
void MULH_2();
void MULH_3();
void MULH_4();
void MULH_5();
void FRSUB_0();
void BEQI_0();
void BEQI_1();
void BEQI_2();
void BEQD_0();
void BEQD_1();
void RTID_0();
void RTID_1();
void RTID_2();
void RTID_3();
void RTID_4();
void FMUL_0();
void LWI_0();
void LWI_1();
void LWI_2();
void LWI_3();
void LWI_4();
void BNEID_0();
void BNEID_1();
void ADDIK_0();
void ADDIK_1();
void ADDIK_2();
void ADDIK_3();
void ADDIK_4();
void BGTID_0();
void BGTID_1();
void ADDIC_0();
void ADDIC_1();
void ADDIC_2();
void ADDIC_3();
void ADDIC_4();
void LW_0();
void LW_1();
void LW_2();
void LW_3();
void LW_4();
void RSUBC_0();
void RSUBC_1();
void RSUBC_2();
void RSUBC_3();
void RSUBC_4();
void BLTID_0();
void BLTID_1();
void RSUBI_0();
void RSUBI_1();
void RSUBI_2();
void RSUBI_3();
void RSUBI_4();
void RSUBI_5();
void MTS_0();
void MTS_1();
void RSUBK_0();
void RSUBK_1();
void RSUBK_2();
void RSUBK_3();
void RSUBK_4();
void BGED_0();
void BGED_1();
void BRID_0();
void PCMPBF_0();
void PCMPBF_1();
void PCMPBF_2();
void PCMPBF_3();
void PCMPBF_4();
void PCMPBF_5();
void IDIVU_0();
void IDIVU_1();
void IDIVU_2();
void BRAD_0();
void BRAI_0();


#endif
