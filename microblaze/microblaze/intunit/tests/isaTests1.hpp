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

#ifndef MICROBLAZE_CORE_FUNC_LT_ISATESTS1_HPP
#define MICROBLAZE_CORE_FUNC_LT_ISATESTS1_HPP

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


void CMPU_1();
void CMPU_2();
void CMPU_3();
void CMPU_4();
void CMPU_5();
void CMPU_6();
void CMPU_7();
void CMPU_8();
void BSRL_0();
void BSRL_1();
void BSRL_2();
void BLTI_0();
void BLTI_1();
void BLTI_2();
void PCMPEQ_0();
void PCMPEQ_1();
void XOR_0();
void XOR_1();
void XOR_2();
void BEQ_0();
void BEQ_1();
void BEQ_2();
void BLTD_0();
void BLTD_1();
void CMP_0();
void CMP_1();
void CMP_2();
void CMP_3();
void CMP_4();
void CMP_5();
void CMP_6();
void CMP_7();
void BRALID_0();
void RTBD_0();
void RTBD_1();
void RTBD_2();
void MFS_0();
void MFS_1();
void BLT_0();
void BLT_1();
void BLT_2();
void BRLID_0();
void SB_0();
void SB_1();
void SB_2();
void BLE_0();
void BLE_1();
void BLE_2();
void SHI_0();
void SHI_1();
void SHI_2();
void SHI_3();
void SHI_4();
void AND_0();
void AND_1();
void AND_2();
void RSUBIC_0();
void RSUBIC_1();
void RSUBIC_2();
void RSUBIC_3();
void RSUBIC_4();
void RSUBIC_5();
void SBI_0();
void SBI_1();
void SBI_2();
void RTED_0();
void RTED_1();
void RTED_2();
void RTED_3();
void RSUBIK_0();
void RSUBIK_1();
void RSUBIK_2();
void RSUBIK_3();
void RSUBIK_4();
void RSUBIK_5();
void BRALD_0();
void BRA_0();
void SEXT16_0();
void SEXT16_1();
void SEXT16_2();
void SWI_0();
void SWI_1();
void SWI_2();
void SWI_3();
void SWI_4();
void BLEID_0();
void BLEID_1();
void BSRA_0();
void BSRA_1();
void BSRA_2();
void BLED_0();
void BLED_1();
void MULI_0();
void MULI_1();
void MULI_2();
void MULI_3();
void MULI_4();
void MSRSET_0();
void MSRSET_1();
void MSRSET_2();


#endif
