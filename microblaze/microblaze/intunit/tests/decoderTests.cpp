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


#include "microblaze/intunit/decoderTests.hpp"


#include <boost/test/test_tools.hpp>
#include <decoder.hpp>


void ADD_0_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADD
  BOOST_CHECK_EQUAL(dec.decode( 0x1f56000 ), 0);
} // ADD_0_decode()

void ADDC_1_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDC
  BOOST_CHECK_EQUAL(dec.decode( 0x9b3f000 ), 1);
} // ADDC_1_decode()

void ADDK_2_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDK
  BOOST_CHECK_EQUAL(dec.decode( 0x10316800 ), 2);
} // ADDK_2_decode()

void ADDKC_3_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDKC
  BOOST_CHECK_EQUAL(dec.decode( 0x19a3b000 ), 3);
} // ADDKC_3_decode()

void ADDI_4_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDI
  BOOST_CHECK_EQUAL(dec.decode( 0x208a8225 ), 4);
} // ADDI_4_decode()

void ADDIC_5_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDIC
  BOOST_CHECK_EQUAL(dec.decode( 0x2a4790a7 ), 5);
} // ADDIC_5_decode()

void ADDIK_6_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDIK
  BOOST_CHECK_EQUAL(dec.decode( 0x321954e7 ), 6);
} // ADDIK_6_decode()

void ADDIKC_7_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ADDIKC
  BOOST_CHECK_EQUAL(dec.decode( 0x3bec30fa ), 7);
} // ADDIKC_7_decode()

void AND_8_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction AND
  BOOST_CHECK_EQUAL(dec.decode( 0x854be000 ), 8);
} // AND_8_decode()

void ANDI_9_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ANDI
  BOOST_CHECK_EQUAL(dec.decode( 0xa47c6293 ), 9);
} // ANDI_9_decode()

void ANDN_10_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ANDN
  BOOST_CHECK_EQUAL(dec.decode( 0x8e1ba000 ), 10);
} // ANDN_10_decode()

void ANDNI_11_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ANDNI
  BOOST_CHECK_EQUAL(dec.decode( 0xad20d51f ), 11);
} // ANDNI_11_decode()

void BEQ_12_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BEQ
  BOOST_CHECK_EQUAL(dec.decode( 0x9c12f000 ), 12);
} // BEQ_12_decode()

void BEQD_13_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BEQD
  BOOST_CHECK_EQUAL(dec.decode( 0x9e00a800 ), 13);
} // BEQD_13_decode()

void BEQI_14_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BEQI
  BOOST_CHECK_EQUAL(dec.decode( 0xbc0ee099 ), 14);
} // BEQI_14_decode()

void BEQID_15_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BEQID
  BOOST_CHECK_EQUAL(dec.decode( 0xbe070546 ), 15);
} // BEQID_15_decode()

void BGE_16_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGE
  BOOST_CHECK_EQUAL(dec.decode( 0x9ca51800 ), 16);
} // BGE_16_decode()

void BGED_17_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGED
  BOOST_CHECK_EQUAL(dec.decode( 0x9ebce800 ), 17);
} // BGED_17_decode()

void BGEI_18_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGEI
  BOOST_CHECK_EQUAL(dec.decode( 0xbca91e57 ), 18);
} // BGEI_18_decode()

void BGEID_19_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGEID
  BOOST_CHECK_EQUAL(dec.decode( 0xbeac3ff2 ), 19);
} // BGEID_19_decode()

void BGT_20_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGT
  BOOST_CHECK_EQUAL(dec.decode( 0x9c854800 ), 20);
} // BGT_20_decode()

void BGTD_21_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGTD
  BOOST_CHECK_EQUAL(dec.decode( 0x9e8c7000 ), 21);
} // BGTD_21_decode()

void BGTI_22_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGTI
  BOOST_CHECK_EQUAL(dec.decode( 0xbc9dc3a1 ), 22);
} // BGTI_22_decode()

void BGTID_23_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BGTID
  BOOST_CHECK_EQUAL(dec.decode( 0xbe9da536 ), 23);
} // BGTID_23_decode()

void BLE_24_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLE
  BOOST_CHECK_EQUAL(dec.decode( 0x9c72e800 ), 24);
} // BLE_24_decode()

void BLED_25_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLED
  BOOST_CHECK_EQUAL(dec.decode( 0x9e717000 ), 25);
} // BLED_25_decode()

void BLEI_26_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLEI
  BOOST_CHECK_EQUAL(dec.decode( 0xbc6cce8b ), 26);
} // BLEI_26_decode()

void BLEID_27_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLEID
  BOOST_CHECK_EQUAL(dec.decode( 0xbe643691 ), 27);
} // BLEID_27_decode()

void BLT_28_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLT
  BOOST_CHECK_EQUAL(dec.decode( 0x9c470800 ), 28);
} // BLT_28_decode()

void BLTD_29_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLTD
  BOOST_CHECK_EQUAL(dec.decode( 0x9e43e000 ), 29);
} // BLTD_29_decode()

void BLTI_30_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLTI
  BOOST_CHECK_EQUAL(dec.decode( 0xbc42765a ), 30);
} // BLTI_30_decode()

void BLTID_31_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BLTID
  BOOST_CHECK_EQUAL(dec.decode( 0xbe5bd68b ), 31);
} // BLTID_31_decode()

void BNE_32_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BNE
  BOOST_CHECK_EQUAL(dec.decode( 0x9c2b7800 ), 32);
} // BNE_32_decode()

void BNED_33_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BNED
  BOOST_CHECK_EQUAL(dec.decode( 0x9e3f8000 ), 33);
} // BNED_33_decode()

void BNEI_34_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BNEI
  BOOST_CHECK_EQUAL(dec.decode( 0xbc312b42 ), 34);
} // BNEI_34_decode()

void BNEID_35_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BNEID
  BOOST_CHECK_EQUAL(dec.decode( 0xbe29c56d ), 35);
} // BNEID_35_decode()

void BR_36_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BR
  BOOST_CHECK_EQUAL(dec.decode( 0x98e07800 ), 36);
} // BR_36_decode()

void BRA_37_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRA
  BOOST_CHECK_EQUAL(dec.decode( 0x98083800 ), 37);
} // BRA_37_decode()

void BRD_38_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRD
  BOOST_CHECK_EQUAL(dec.decode( 0x9a306000 ), 38);
} // BRD_38_decode()

void BRAD_39_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRAD
  BOOST_CHECK_EQUAL(dec.decode( 0x9bd8c800 ), 39);
} // BRAD_39_decode()

void BRLD_40_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRLD
  BOOST_CHECK_EQUAL(dec.decode( 0x9a744800 ), 40);
} // BRLD_40_decode()

void BRALD_41_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRALD
  BOOST_CHECK_EQUAL(dec.decode( 0x98bca800 ), 41);
} // BRALD_41_decode()

void BRI_42_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRI
  BOOST_CHECK_EQUAL(dec.decode( 0xb84081ba ), 42);
} // BRI_42_decode()

void BRAI_43_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRAI
  BOOST_CHECK_EQUAL(dec.decode( 0xbb0823fa ), 43);
} // BRAI_43_decode()

void BRID_44_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRID
  BOOST_CHECK_EQUAL(dec.decode( 0xb8105547 ), 44);
} // BRID_44_decode()

void BRAID_45_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRAID
  BOOST_CHECK_EQUAL(dec.decode( 0xb978711f ), 45);
} // BRAID_45_decode()

void BRLID_46_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRLID
  BOOST_CHECK_EQUAL(dec.decode( 0xb974cd9c ), 46);
} // BRLID_46_decode()

void BRALID_47_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRALID
  BOOST_CHECK_EQUAL(dec.decode( 0xb83cd913 ), 47);
} // BRALID_47_decode()

void BRK_48_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRK
  BOOST_CHECK_EQUAL(dec.decode( 0x9accd800 ), 48);
} // BRK_48_decode()

void BRKI_49_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BRKI
  BOOST_CHECK_EQUAL(dec.decode( 0xbbec0c70 ), 49);
} // BRKI_49_decode()

void BSRL_50_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSRL
  BOOST_CHECK_EQUAL(dec.decode( 0x440e0800 ), 50);
} // BSRL_50_decode()

void BSRA_51_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSRA
  BOOST_CHECK_EQUAL(dec.decode( 0x45c8ca00 ), 51);
} // BSRA_51_decode()

void BSLL_52_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSLL
  BOOST_CHECK_EQUAL(dec.decode( 0x4548bc00 ), 52);
} // BSLL_52_decode()

void BSRLI_53_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSRLI
  BOOST_CHECK_EQUAL(dec.decode( 0x64900014 ), 53);
} // BSRLI_53_decode()

void BSRAI_54_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSRAI
  BOOST_CHECK_EQUAL(dec.decode( 0x64ec021f ), 54);
} // BSRAI_54_decode()

void BSLLI_55_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction BSLLI
  BOOST_CHECK_EQUAL(dec.decode( 0x65210402 ), 55);
} // BSLLI_55_decode()

void CMP_56_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction CMP
  BOOST_CHECK_EQUAL(dec.decode( 0x16a59801 ), 56);
} // CMP_56_decode()

void CMPU_57_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction CMPU
  BOOST_CHECK_EQUAL(dec.decode( 0x16dd4803 ), 57);
} // CMPU_57_decode()

void FADD_58_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FADD
  BOOST_CHECK_EQUAL(dec.decode( 0x5a78b800 ), 58);
} // FADD_58_decode()

void FRSUB_59_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FRSUB
  BOOST_CHECK_EQUAL(dec.decode( 0x5827e080 ), 59);
} // FRSUB_59_decode()

void FMUL_60_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FMUL
  BOOST_CHECK_EQUAL(dec.decode( 0x59eba100 ), 60);
} // FMUL_60_decode()

void FDIV_61_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FDIV
  BOOST_CHECK_EQUAL(dec.decode( 0x5a733980 ), 61);
} // FDIV_61_decode()

void FCMP_62_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FCMP
  BOOST_CHECK_EQUAL(dec.decode( 0x58867200 ), 62);
} // FCMP_62_decode()

void FLT_63_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FLT
  BOOST_CHECK_EQUAL(dec.decode( 0x591f0280 ), 63);
} // FLT_63_decode()

void FINT_64_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FINT
  BOOST_CHECK_EQUAL(dec.decode( 0x59ba0300 ), 64);
} // FINT_64_decode()

void FSQRT_65_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction FSQRT
  BOOST_CHECK_EQUAL(dec.decode( 0x5b4d0380 ), 65);
} // FSQRT_65_decode()

void IDIV_66_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction IDIV
  BOOST_CHECK_EQUAL(dec.decode( 0x4a1d0800 ), 66);
} // IDIV_66_decode()

void IDIVU_67_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction IDIVU
  BOOST_CHECK_EQUAL(dec.decode( 0x4bc07802 ), 67);
} // IDIVU_67_decode()

void IMM_68_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction IMM
  BOOST_CHECK_EQUAL(dec.decode( 0xb0005d1a ), 68);
} // IMM_68_decode()

void LBU_69_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LBU
  BOOST_CHECK_EQUAL(dec.decode( 0xc3cbf000 ), 69);
} // LBU_69_decode()

void LBUI_70_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LBUI
  BOOST_CHECK_EQUAL(dec.decode( 0xe2c862e2 ), 70);
} // LBUI_70_decode()

void LHU_71_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LHU
  BOOST_CHECK_EQUAL(dec.decode( 0xc7d84000 ), 71);
} // LHU_71_decode()

void LHUI_72_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LHUI
  BOOST_CHECK_EQUAL(dec.decode( 0xe48b4ab5 ), 72);
} // LHUI_72_decode()

void LW_73_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LW
  BOOST_CHECK_EQUAL(dec.decode( 0xc9cfe000 ), 73);
} // LW_73_decode()

void LWI_74_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction LWI
  BOOST_CHECK_EQUAL(dec.decode( 0xe8da585a ), 74);
} // LWI_74_decode()

void MFS_75_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MFS
  BOOST_CHECK_EQUAL(dec.decode( 0x9660b20e ), 75);
} // MFS_75_decode()

void MSRCLR_76_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MSRCLR
  BOOST_CHECK_EQUAL(dec.decode( 0x9461600a ), 76);
} // MSRCLR_76_decode()

void MSRSET_77_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MSRSET
  BOOST_CHECK_EQUAL(dec.decode( 0x95203cb5 ), 77);
} // MSRSET_77_decode()

void MTS_78_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MTS
  BOOST_CHECK_EQUAL(dec.decode( 0x940dc77a ), 78);
} // MTS_78_decode()

void MUL_79_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MUL
  BOOST_CHECK_EQUAL(dec.decode( 0x43e05000 ), 79);
} // MUL_79_decode()

void MULH_80_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MULH
  BOOST_CHECK_EQUAL(dec.decode( 0x42fa9801 ), 80);
} // MULH_80_decode()

void MULHU_81_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MULHU
  BOOST_CHECK_EQUAL(dec.decode( 0x415e8003 ), 81);
} // MULHU_81_decode()

void MULHSU_82_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MULHSU
  BOOST_CHECK_EQUAL(dec.decode( 0x41a48802 ), 82);
} // MULHSU_82_decode()

void MULI_83_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction MULI
  BOOST_CHECK_EQUAL(dec.decode( 0x62cde0e4 ), 83);
} // MULI_83_decode()

void OR_84_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction OR
  BOOST_CHECK_EQUAL(dec.decode( 0x831bc800 ), 84);
} // OR_84_decode()

void ORI_85_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction ORI
  BOOST_CHECK_EQUAL(dec.decode( 0xa00944af ), 85);
} // ORI_85_decode()

void PCMPBF_86_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction PCMPBF
  BOOST_CHECK_EQUAL(dec.decode( 0x8366c400 ), 86);
} // PCMPBF_86_decode()

void PCMPEQ_87_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction PCMPEQ
  BOOST_CHECK_EQUAL(dec.decode( 0x89918c00 ), 87);
} // PCMPEQ_87_decode()

void PCMPNE_88_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction PCMPNE
  BOOST_CHECK_EQUAL(dec.decode( 0x8d16dc00 ), 88);
} // PCMPNE_88_decode()

void RSUB_89_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUB
  BOOST_CHECK_EQUAL(dec.decode( 0x49dd000 ), 89);
} // RSUB_89_decode()

void RSUBC_90_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBC
  BOOST_CHECK_EQUAL(dec.decode( 0xca57800 ), 90);
} // RSUBC_90_decode()

void RSUBK_91_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBK
  BOOST_CHECK_EQUAL(dec.decode( 0x15a04800 ), 91);
} // RSUBK_91_decode()

void RSUBKC_92_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBKC
  BOOST_CHECK_EQUAL(dec.decode( 0x1c243800 ), 92);
} // RSUBKC_92_decode()

void RSUBI_93_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBI
  BOOST_CHECK_EQUAL(dec.decode( 0x26ff5e4e ), 93);
} // RSUBI_93_decode()

void RSUBIC_94_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBIC
  BOOST_CHECK_EQUAL(dec.decode( 0x2d02d68d ), 94);
} // RSUBIC_94_decode()

void RSUBIK_95_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBIK
  BOOST_CHECK_EQUAL(dec.decode( 0x375d45fd ), 95);
} // RSUBIK_95_decode()

void RSUBIKC_96_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RSUBIKC
  BOOST_CHECK_EQUAL(dec.decode( 0x3c814d92 ), 96);
} // RSUBIKC_96_decode()

void RTBD_97_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RTBD
  BOOST_CHECK_EQUAL(dec.decode( 0xb65014f0 ), 97);
} // RTBD_97_decode()

void RTID_98_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RTID
  BOOST_CHECK_EQUAL(dec.decode( 0xb63b8980 ), 98);
} // RTID_98_decode()

void RTED_99_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RTED
  BOOST_CHECK_EQUAL(dec.decode( 0xb68afc85 ), 99);
} // RTED_99_decode()

void RTSD_100_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction RTSD
  BOOST_CHECK_EQUAL(dec.decode( 0xb601107d ), 100);
} // RTSD_100_decode()

void SB_101_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SB
  BOOST_CHECK_EQUAL(dec.decode( 0xd2127000 ), 101);
} // SB_101_decode()

void SBI_102_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SBI
  BOOST_CHECK_EQUAL(dec.decode( 0xf0e10e1f ), 102);
} // SBI_102_decode()

void SH_103_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SH
  BOOST_CHECK_EQUAL(dec.decode( 0xd58b8000 ), 103);
} // SH_103_decode()

void SHI_104_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SHI
  BOOST_CHECK_EQUAL(dec.decode( 0xf6977b1c ), 104);
} // SHI_104_decode()

void SW_105_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SW
  BOOST_CHECK_EQUAL(dec.decode( 0xdbec1800 ), 105);
} // SW_105_decode()

void SWI_106_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SWI
  BOOST_CHECK_EQUAL(dec.decode( 0xf92b3dcd ), 106);
} // SWI_106_decode()

void SEXT16_107_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SEXT16
  BOOST_CHECK_EQUAL(dec.decode( 0x91230061 ), 107);
} // SEXT16_107_decode()

void SEXT8_108_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SEXT8
  BOOST_CHECK_EQUAL(dec.decode( 0x90f70060 ), 108);
} // SEXT8_108_decode()

void SRA_109_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SRA
  BOOST_CHECK_EQUAL(dec.decode( 0x91ad0001 ), 109);
} // SRA_109_decode()

void SRC_110_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SRC
  BOOST_CHECK_EQUAL(dec.decode( 0x92750021 ), 110);
} // SRC_110_decode()

void SRL_111_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction SRL
  BOOST_CHECK_EQUAL(dec.decode( 0x93100041 ), 111);
} // SRL_111_decode()

void WDC_112_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction WDC
  BOOST_CHECK_EQUAL(dec.decode( 0x900fc864 ), 112);
} // WDC_112_decode()

void WIC_113_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction WIC
  BOOST_CHECK_EQUAL(dec.decode( 0x9015a868 ), 113);
} // WIC_113_decode()

void XOR_114_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction XOR
  BOOST_CHECK_EQUAL(dec.decode( 0x8a20c000 ), 114);
} // XOR_114_decode()

void XORI_115_decode() {
  core_microblaze_lt::Decoder dec;
  // Checking Instruction XORI
  BOOST_CHECK_EQUAL(dec.decode( 0xab879ace ), 115);
} // XORI_115_decode()


