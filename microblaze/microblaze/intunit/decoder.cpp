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


#include "microblaze/intunit/decoder.hpp"
#include "microblaze/intunit/instructions.hpp"




using namespace core_microblaze_lt;
core_microblaze_lt::CacheElem::CacheElem(
    Instruction * instr,
    unsigned int count) :
  instr(instr),
  count(count) {

} // CacheElem()

core_microblaze_lt::CacheElem::CacheElem() :
  instr(NULL),
  count(1) {

} // CacheElem()

int core_microblaze_lt::Decoder::decode(unsigned int instrCode) const throw() {
  switch(instrCode & 0x7c000000) {
    case 0x3c000000: {
      switch(instrCode & 0xc0000000) {
        case 0x80000000: {
          switch(instrCode & 0x600000) {
            case 0x200000: {
              if((instrCode & 0x800000) != 0x0){
                if((instrCode & 0x2000000) != 0x0){
                  // Instruction BGEID
                  return 19;
                } else {
                  // Instruction BGEI
                  return 18;
                }
              } else {
                if((instrCode & 0x2000000) == 0x0){
                  // Instruction BNEI
                  return 34;
                } else {
                  // Instruction BNEID
                  return 35;
                }
              }
            break;}
            case 0x0: {
              if((instrCode & 0x800000) != 0x0){
                if((instrCode & 0x2000000) == 0x0){
                  // Instruction BGTI
                  return 22;
                } else {
                  // Instruction BGTID
                  return 23;
                }
              } else {
                if((instrCode & 0x2000000) != 0x0){
                  // Instruction BEQID
                  return 15;
                } else {
                  // Instruction BEQI
                  return 14;
                }
              }
            break;}
            case 0x600000: {
              if((instrCode & 0x2000000) != 0x0){
                // Instruction BLEID
                return 27;
              } else {
                // Instruction BLEI
                return 26;
              }
            break;}
            case 0x400000: {
              if((instrCode & 0x2000000) != 0x0){
                // Instruction BLTID
                return 31;
              } else {
                // Instruction BLTI
                return 30;
              }
            break;}
            default: {
              // Invalid pattern
              return 116;
            }
          }
        break;}
        case 0x0: {
          // Instruction RSUBIKC
          return 96;
        break;}
        default: {
          // Invalid pattern
          return 116;
        }
      }
    break;}
    case 0x1c000000: {
      switch(instrCode & 0xc0000000) {
        case 0x80000000: {
          switch(instrCode & 0x600000) {
            case 0x0: {
              if((instrCode & 0x800000) != 0x0){
                if((instrCode & 0x2000000) != 0x0){
                  // Instruction BGTD
                  return 21;
                } else {
                  // Instruction BGT
                  return 20;
                }
              } else {
                if((instrCode & 0x2000000) == 0x0){
                  // Instruction BEQ
                  return 12;
                } else {
                  // Instruction BEQD
                  return 13;
                }
              }
            break;}
            case 0x200000: {
              if((instrCode & 0x800000) != 0x0){
                if((instrCode & 0x2000000) == 0x0){
                  // Instruction BGE
                  return 16;
                } else {
                  // Instruction BGED
                  return 17;
                }
              } else {
                if((instrCode & 0x2000000) != 0x0){
                  // Instruction BNED
                  return 33;
                } else {
                  // Instruction BNE
                  return 32;
                }
              }
            break;}
            case 0x600000: {
              if((instrCode & 0x2000000) == 0x0){
                // Instruction BLE
                return 24;
              } else {
                // Instruction BLED
                return 25;
              }
            break;}
            case 0x400000: {
              if((instrCode & 0x2000000) != 0x0){
                // Instruction BLTD
                return 29;
              } else {
                // Instruction BLT
                return 28;
              }
            break;}
            default: {
              // Invalid pattern
              return 116;
            }
          }
        break;}
        case 0x0: {
          // Instruction RSUBKC
          return 92;
        break;}
        default: {
          // Invalid pattern
          return 116;
        }
      }
    break;}
    case 0x58000000: {
      switch(instrCode & 0x380) {
        case 0x0: {
          if((instrCode & 0x80000000) == 0x0){
            // Instruction FADD
            return 58;
          } else {
            // Instruction SW
            return 105;
          }
        break;}
        case 0x100: {
          // Instruction FMUL
          return 60;
        break;}
        case 0x180: {
          // Instruction FDIV
          return 61;
        break;}
        case 0x300: {
          // Instruction FINT
          return 64;
        break;}
        case 0x380: {
          // Instruction FSQRT
          return 65;
        break;}
        case 0x80: {
          // Instruction FRSUB
          return 59;
        break;}
        case 0x280: {
          // Instruction FLT
          return 63;
        break;}
        case 0x200: {
          // Instruction FCMP
          return 62;
        break;}
        default: {
          // Invalid pattern
          return 116;
        }
      }
    break;}
    case 0x38000000: {
      if((instrCode & 0x80000000) != 0x0){
        switch(instrCode & 0xc0000) {
          case 0x0: {
            if((instrCode & 0x100000) != 0x0){
              // Instruction BRID
              return 44;
            } else {
              // Instruction BRI
              return 42;
            }
          break;}
          case 0x80000: {
            if((instrCode & 0x100000) == 0x0){
              // Instruction BRAI
              return 43;
            } else {
              // Instruction BRAID
              return 45;
            }
          break;}
          case 0xc0000: {
            if((instrCode & 0x100000) == 0x0){
              // Instruction BRKI
              return 49;
            } else {
              // Instruction BRALID
              return 47;
            }
          break;}
          case 0x40000: {
            // Instruction BRLID
            return 46;
          break;}
          default: {
            // Invalid pattern
            return 116;
          }
        }
      } else {
        // Instruction ADDIKC
        return 7;
      }
    break;}
    case 0x18000000: {
      if((instrCode & 0x80000000) != 0x0){
        switch(instrCode & 0xc0000) {
          case 0xc0000: {
            if((instrCode & 0x100000) == 0x0){
              // Instruction BRK
              return 48;
            } else {
              // Instruction BRALD
              return 41;
            }
          break;}
          case 0x80000: {
            if((instrCode & 0x100000) != 0x0){
              // Instruction BRAD
              return 39;
            } else {
              // Instruction BRA
              return 37;
            }
          break;}
          case 0x0: {
            if((instrCode & 0x100000) != 0x0){
              // Instruction BRD
              return 38;
            } else {
              // Instruction BR
              return 36;
            }
          break;}
          case 0x40000: {
            // Instruction BRLD
            return 40;
          break;}
          default: {
            // Invalid pattern
            return 116;
          }
        }
      } else {
        // Instruction ADDKC
        return 3;
      }
    break;}
    case 0x10000000: {
      switch(instrCode & 0x60) {
        case 0x60: {
          if((instrCode & 0x5) == 0x0){
            if((instrCode & 0x8) != 0x0){
              // Instruction WIC
              return 113;
            } else {
              // Instruction SEXT8
              return 108;
            }
          } else {
            if((instrCode & 0x1) != 0x0){
              // Instruction SEXT16
              return 107;
            } else {
              // Instruction WDC
              return 112;
            }
          }
        break;}
        case 0x0: {
          if((instrCode & 0x1) != 0x0){
            // Instruction SRA
            return 109;
          } else {
            // Instruction ADDK
            return 2;
          }
        break;}
        case 0x20: {
          // Instruction SRC
          return 110;
        break;}
        case 0x40: {
          // Instruction SRL
          return 111;
        break;}
        default: {
          // Invalid pattern
          return 116;
        }
      }
    break;}
    case 0x14000000: {
      if((instrCode & 0x80000001) != 0x0){
        if((instrCode & 0x80000000) != 0x0){
          if((instrCode & 0x8000) != 0x0){
            if((instrCode & 0x4000) == 0x0){
              // Instruction MFS
              return 75;
            } else {
              // Instruction MTS
              return 78;
            }
          } else {
            if((instrCode & 0x10000) != 0x0){
              // Instruction MSRCLR
              return 76;
            } else {
              // Instruction MSRSET
              return 77;
            }
          }
        } else {
          if((instrCode & 0x2) != 0x0){
            // Instruction CMPU
            return 57;
          } else {
            // Instruction CMP
            return 56;
          }
        }
      } else {
        // Instruction RSUBK
        return 91;
      }
    break;}
    case 0x40000000: {
      if((instrCode & 0x80000000) == 0x0){
        if((instrCode & 0x1) == 0x0){
          if((instrCode & 0x2) != 0x0){
            // Instruction MULHSU
            return 82;
          } else {
            // Instruction MUL
            return 79;
          }
        } else {
          if((instrCode & 0x2) != 0x0){
            // Instruction MULHU
            return 81;
          } else {
            // Instruction MULH
            return 80;
          }
        }
      } else {
        // Instruction LBU
        return 69;
      }
    break;}
    case 0x34000000: {
      if((instrCode & 0x80000000) != 0x0){
        if((instrCode & 0x600000) == 0x0){
          if((instrCode & 0x800000) != 0x0){
            // Instruction RTED
            return 99;
          } else {
            // Instruction RTSD
            return 100;
          }
        } else {
          if((instrCode & 0x200000) == 0x0){
            // Instruction RTBD
            return 97;
          } else {
            // Instruction RTID
            return 98;
          }
        }
      } else {
        // Instruction RSUBIK
        return 95;
      }
    break;}
    case 0x44000000: {
      if((instrCode & 0x600) == 0x0){
        if((instrCode & 0x80000000) != 0x0){
          // Instruction LHU
          return 71;
        } else {
          // Instruction BSRL
          return 50;
        }
      } else {
        if((instrCode & 0x200) != 0x0){
          // Instruction BSRA
          return 51;
        } else {
          // Instruction BSLL
          return 52;
        }
      }
    break;}
    case 0x64000000: {
      if((instrCode & 0x80000200) != 0x0){
        if((instrCode & 0x80000000) != 0x0){
          // Instruction LHUI
          return 72;
        } else {
          // Instruction BSRAI
          return 54;
        }
      } else {
        if((instrCode & 0x400) != 0x0){
          // Instruction BSLLI
          return 55;
        } else {
          // Instruction BSRLI
          return 53;
        }
      }
    break;}
    case 0x0: {
      if((instrCode & 0x400) == 0x0){
        if((instrCode & 0x80000000) != 0x0){
          // Instruction OR
          return 84;
        } else {
          // Instruction ADD
          return 0;
        }
      } else {
        // Instruction PCMPBF
        return 86;
      }
    break;}
    case 0x48000000: {
      if((instrCode & 0x2) == 0x0){
        if((instrCode & 0x80000000) != 0x0){
          // Instruction LW
          return 73;
        } else {
          // Instruction IDIV
          return 66;
        }
      } else {
        // Instruction IDIVU
        return 67;
      }
    break;}
    case 0xc000000: {
      if((instrCode & 0x400) == 0x0){
        if((instrCode & 0x80000000) == 0x0){
          // Instruction RSUBC
          return 90;
        } else {
          // Instruction ANDN
          return 10;
        }
      } else {
        // Instruction PCMPNE
        return 88;
      }
    break;}
    case 0x8000000: {
      if((instrCode & 0x400) == 0x0){
        if((instrCode & 0x80000000) == 0x0){
          // Instruction ADDC
          return 1;
        } else {
          // Instruction XOR
          return 114;
        }
      } else {
        // Instruction PCMPEQ
        return 87;
      }
    break;}
    case 0x30000000: {
      if((instrCode & 0x80000000) == 0x0){
        // Instruction ADDIK
        return 6;
      } else {
        // Instruction IMM
        return 68;
      }
    break;}
    case 0x28000000: {
      if((instrCode & 0x80000000) != 0x0){
        // Instruction XORI
        return 115;
      } else {
        // Instruction ADDIC
        return 5;
      }
    break;}
    case 0x4000000: {
      if((instrCode & 0x80000000) != 0x0){
        // Instruction AND
        return 8;
      } else {
        // Instruction RSUB
        return 89;
      }
    break;}
    case 0x24000000: {
      if((instrCode & 0x80000000) == 0x0){
        // Instruction RSUBI
        return 93;
      } else {
        // Instruction ANDI
        return 9;
      }
    break;}
    case 0x20000000: {
      if((instrCode & 0x80000000) == 0x0){
        // Instruction ADDI
        return 4;
      } else {
        // Instruction ORI
        return 85;
      }
    break;}
    case 0x2c000000: {
      if((instrCode & 0x80000000) != 0x0){
        // Instruction ANDNI
        return 11;
      } else {
        // Instruction RSUBIC
        return 94;
      }
    break;}
    case 0x60000000: {
      if((instrCode & 0x80000000) == 0x0){
        // Instruction MULI
        return 83;
      } else {
        // Instruction LBUI
        return 70;
      }
    break;}
    case 0x68000000: {
      // Instruction LWI
      return 74;
    break;}
    case 0x50000000: {
      // Instruction SB
      return 101;
    break;}
    case 0x78000000: {
      // Instruction SWI
      return 106;
    break;}
    case 0x74000000: {
      // Instruction SHI
      return 104;
    break;}
    case 0x70000000: {
      // Instruction SBI
      return 102;
    break;}
    case 0x54000000: {
      // Instruction SH
      return 103;
    break;}
    default: {
      // Invalid pattern
      return 116;
    }
  }
  // Invalid pattern
  return 116;
} // decode()


