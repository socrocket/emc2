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

#ifndef MICROBLAZE_CORE_FUNC_LT_REGISTERS_HPP
#define MICROBLAZE_CORE_FUNC_LT_REGISTERS_HPP



#include <ostream>


#define FUNC_MODEL
#define LT_IF
#define key_BE 0
#define key_C 1
#define key_PVR 2
#define key_UMS 3
#define key_EIP 4
#define key_EE 5
#define key_DCE 6
#define key_FSL 7
#define key_VM 8
#define key_ICE 9
#define key_UM 10
#define key_CC 11
#define key_DZ 12
#define key_IE 13
#define key_VMS 14
#define key_BIP 15
#define key_EC 16
#define key_S 17
#define key_Rx 18
#define key_DS 19
#define key_W 20
#define key_OF 21
#define key_UF 22
#define key_IO 23
#define key_DO 24
namespace core_microblaze_lt {

  class InnerField {
    public:
    InnerField & operator =(const InnerField & other) throw();
    virtual InnerField & operator =(const unsigned int & other) throw() = 0;
    virtual operator unsigned int() const throw() = 0;
    virtual ~InnerField();

  }; // class InnerField

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  /** @brief    Register Class
  *   @details
  *   An register holds fields that can be accessed in array notation. Most
  *   operators are defined, as well as callback functions per field. Some
  *   concepts were inspired by the by the Cadence scireg implementation.
  */
  class Register {
    public:
    Register(const Register & other);
    Register();
    virtual void immediateWrite(const unsigned int & value) throw() = 0;
    virtual unsigned int readNewValue() throw() = 0;
    virtual void clockCycle() throw();
    virtual InnerField & operator [](int bitField) throw() = 0;
    virtual unsigned int operator ~() throw() = 0;
    virtual unsigned int operator +(const Register & other) const throw() = 0;
    virtual unsigned int operator -(const Register & other) const throw() = 0;
    virtual unsigned int operator *(const Register & other) const throw() = 0;
    virtual unsigned int operator /(const Register & other) const throw() = 0;
    virtual unsigned int operator |(const Register & other) const throw() = 0;
    virtual unsigned int operator &(const Register & other) const throw() = 0;
    virtual unsigned int operator ^(const Register & other) const throw() = 0;
    virtual unsigned int operator <<(const Register & other) const throw() = 0;
    virtual unsigned int operator >>(const Register & other) const throw() = 0;
    virtual bool operator <(const Register & other) const throw() = 0;
    virtual bool operator >(const Register & other) const throw() = 0;
    virtual bool operator <=(const Register & other) const throw() = 0;
    virtual bool operator >=(const Register & other) const throw() = 0;
    virtual bool operator ==(const Register & other) const throw() = 0;
    virtual bool operator !=(const Register & other) const throw() = 0;
    virtual Register & operator =(const unsigned int & other) throw() = 0;
    virtual Register & operator +=(const unsigned int & other) throw() = 0;
    virtual Register & operator -=(const unsigned int & other) throw() = 0;
    virtual Register & operator *=(const unsigned int & other) throw() = 0;
    virtual Register & operator /=(const unsigned int & other) throw() = 0;
    virtual Register & operator |=(const unsigned int & other) throw() = 0;
    virtual Register & operator &=(const unsigned int & other) throw() = 0;
    virtual Register & operator ^=(const unsigned int & other) throw() = 0;
    virtual Register & operator <<=(const unsigned int & other) throw() = 0;
    virtual Register & operator >>=(const unsigned int & other) throw() = 0;
    virtual Register & operator =(const Register & other) throw() = 0;
    virtual Register & operator +=(const Register & other) throw() = 0;
    virtual Register & operator -=(const Register & other) throw() = 0;
    virtual Register & operator *=(const Register & other) throw() = 0;
    virtual Register & operator /=(const Register & other) throw() = 0;
    virtual Register & operator |=(const Register & other) throw() = 0;
    virtual Register & operator &=(const Register & other) throw() = 0;
    virtual Register & operator ^=(const Register & other) throw() = 0;
    virtual Register & operator <<=(const Register & other) throw() = 0;
    virtual Register & operator >>=(const Register & other) throw() = 0;
    virtual std::ostream & operator <<(std::ostream & other) const throw() = 0;
    virtual operator unsigned int() const throw() = 0;

  }; // class Register

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class Reg32_0 : public Register {
    public:
    class InnerField_Empty : public InnerField {
      public:
      InnerField_Empty();
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return 0;
      } // operator unsigned int()

      virtual ~InnerField_Empty();

    }; // class InnerField_Empty

    public:
    Reg32_0();
    inline InnerField & operator [](int bitField) throw() {
      return this->field_empty;
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    unsigned int operator ~() throw();
    Reg32_0 & operator =(const unsigned int & other) throw();
    Reg32_0 & operator +=(const unsigned int & other) throw();
    Reg32_0 & operator -=(const unsigned int & other) throw();
    Reg32_0 & operator *=(const unsigned int & other) throw();
    Reg32_0 & operator /=(const unsigned int & other) throw();
    Reg32_0 & operator |=(const unsigned int & other) throw();
    Reg32_0 & operator &=(const unsigned int & other) throw();
    Reg32_0 & operator ^=(const unsigned int & other) throw();
    Reg32_0 & operator <<=(const unsigned int & other) throw();
    Reg32_0 & operator >>=(const unsigned int & other) throw();
    unsigned int operator +(const Reg32_0 & other) const throw();
    unsigned int operator -(const Reg32_0 & other) const throw();
    unsigned int operator *(const Reg32_0 & other) const throw();
    unsigned int operator /(const Reg32_0 & other) const throw();
    unsigned int operator |(const Reg32_0 & other) const throw();
    unsigned int operator &(const Reg32_0 & other) const throw();
    unsigned int operator ^(const Reg32_0 & other) const throw();
    unsigned int operator <<(const Reg32_0 & other) const throw();
    unsigned int operator >>(const Reg32_0 & other) const throw();
    bool operator <(const Reg32_0 & other) const throw();
    bool operator >(const Reg32_0 & other) const throw();
    bool operator <=(const Reg32_0 & other) const throw();
    bool operator >=(const Reg32_0 & other) const throw();
    bool operator ==(const Reg32_0 & other) const throw();
    bool operator !=(const Reg32_0 & other) const throw();
    Reg32_0 & operator =(const Reg32_0 & other) throw();
    Reg32_0 & operator +=(const Reg32_0 & other) throw();
    Reg32_0 & operator -=(const Reg32_0 & other) throw();
    Reg32_0 & operator *=(const Reg32_0 & other) throw();
    Reg32_0 & operator /=(const Reg32_0 & other) throw();
    Reg32_0 & operator |=(const Reg32_0 & other) throw();
    Reg32_0 & operator &=(const Reg32_0 & other) throw();
    Reg32_0 & operator ^=(const Reg32_0 & other) throw();
    Reg32_0 & operator <<=(const Reg32_0 & other) throw();
    Reg32_0 & operator >>=(const Reg32_0 & other) throw();
    unsigned int operator +(const Register & other) const throw();
    unsigned int operator -(const Register & other) const throw();
    unsigned int operator *(const Register & other) const throw();
    unsigned int operator /(const Register & other) const throw();
    unsigned int operator |(const Register & other) const throw();
    unsigned int operator &(const Register & other) const throw();
    unsigned int operator ^(const Register & other) const throw();
    unsigned int operator <<(const Register & other) const throw();
    unsigned int operator >>(const Register & other) const throw();
    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Reg32_0 & operator =(const Register & other) throw();
    Reg32_0 & operator +=(const Register & other) throw();
    Reg32_0 & operator -=(const Register & other) throw();
    Reg32_0 & operator *=(const Register & other) throw();
    Reg32_0 & operator /=(const Register & other) throw();
    Reg32_0 & operator |=(const Register & other) throw();
    Reg32_0 & operator &=(const Register & other) throw();
    Reg32_0 & operator ^=(const Register & other) throw();
    Reg32_0 & operator <<=(const Register & other) throw();
    Reg32_0 & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return this->value;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();

    private:
    InnerField_Empty field_empty;
    unsigned int value;

  }; // class Reg32_0

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class Reg32_1 : public Register {
    public:
    class InnerField_BE : public InnerField {
      public:
      InnerField_BE(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x80000000) >> 31;
      } // operator unsigned int()

      virtual ~InnerField_BE();

      private:
      unsigned int & value;

    }; // class InnerField_BE

    class InnerField_C : public InnerField {
      public:
      InnerField_C(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x20000000) >> 29;
      } // operator unsigned int()

      virtual ~InnerField_C();

      private:
      unsigned int & value;

    }; // class InnerField_C

    class InnerField_PVR : public InnerField {
      public:
      InnerField_PVR(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x200000) >> 21;
      } // operator unsigned int()

      virtual ~InnerField_PVR();

      private:
      unsigned int & value;

    }; // class InnerField_PVR

    class InnerField_UMS : public InnerField {
      public:
      InnerField_UMS(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x80000) >> 19;
      } // operator unsigned int()

      virtual ~InnerField_UMS();

      private:
      unsigned int & value;

    }; // class InnerField_UMS

    class InnerField_EIP : public InnerField {
      public:
      InnerField_EIP(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x400000) >> 22;
      } // operator unsigned int()

      virtual ~InnerField_EIP();

      private:
      unsigned int & value;

    }; // class InnerField_EIP

    class InnerField_EE : public InnerField {
      public:
      InnerField_EE(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x800000) >> 23;
      } // operator unsigned int()

      virtual ~InnerField_EE();

      private:
      unsigned int & value;

    }; // class InnerField_EE

    class InnerField_DCE : public InnerField {
      public:
      InnerField_DCE(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x1000000) >> 24;
      } // operator unsigned int()

      virtual ~InnerField_DCE();

      private:
      unsigned int & value;

    }; // class InnerField_DCE

    class InnerField_FSL : public InnerField {
      public:
      InnerField_FSL(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x8000000) >> 27;
      } // operator unsigned int()

      virtual ~InnerField_FSL();

      private:
      unsigned int & value;

    }; // class InnerField_FSL

    class InnerField_VM : public InnerField {
      public:
      InnerField_VM(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x40000) >> 18;
      } // operator unsigned int()

      virtual ~InnerField_VM();

      private:
      unsigned int & value;

    }; // class InnerField_VM

    class InnerField_ICE : public InnerField {
      public:
      InnerField_ICE(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x4000000) >> 26;
      } // operator unsigned int()

      virtual ~InnerField_ICE();

      private:
      unsigned int & value;

    }; // class InnerField_ICE

    class InnerField_UM : public InnerField {
      public:
      InnerField_UM(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x100000) >> 20;
      } // operator unsigned int()

      virtual ~InnerField_UM();

      private:
      unsigned int & value;

    }; // class InnerField_UM

    class InnerField_CC : public InnerField {
      public:
      InnerField_CC(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x1);
      } // operator unsigned int()

      virtual ~InnerField_CC();

      private:
      unsigned int & value;

    }; // class InnerField_CC

    class InnerField_DZ : public InnerField {
      public:
      InnerField_DZ(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x2000000) >> 25;
      } // operator unsigned int()

      virtual ~InnerField_DZ();

      private:
      unsigned int & value;

    }; // class InnerField_DZ

    class InnerField_IE : public InnerField {
      public:
      InnerField_IE(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x40000000) >> 30;
      } // operator unsigned int()

      virtual ~InnerField_IE();

      private:
      unsigned int & value;

    }; // class InnerField_IE

    class InnerField_VMS : public InnerField {
      public:
      InnerField_VMS(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x20000) >> 17;
      } // operator unsigned int()

      virtual ~InnerField_VMS();

      private:
      unsigned int & value;

    }; // class InnerField_VMS

    class InnerField_BIP : public InnerField {
      public:
      InnerField_BIP(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x10000000) >> 28;
      } // operator unsigned int()

      virtual ~InnerField_BIP();

      private:
      unsigned int & value;

    }; // class InnerField_BIP

    class InnerField_Empty : public InnerField {
      public:
      InnerField_Empty();
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return 0;
      } // operator unsigned int()

      virtual ~InnerField_Empty();

    }; // class InnerField_Empty

    public:
    Reg32_1();
    inline InnerField & operator [](int bitField) throw() {
      switch(bitField) {
        case key_BE: {
          return this->field_BE;
          break;
        }
        case key_C: {
          return this->field_C;
          break;
        }
        case key_PVR: {
          return this->field_PVR;
          break;
        }
        case key_UMS: {
          return this->field_UMS;
          break;
        }
        case key_EIP: {
          return this->field_EIP;
          break;
        }
        case key_EE: {
          return this->field_EE;
          break;
        }
        case key_DCE: {
          return this->field_DCE;
          break;
        }
        case key_FSL: {
          return this->field_FSL;
          break;
        }
        case key_VM: {
          return this->field_VM;
          break;
        }
        case key_ICE: {
          return this->field_ICE;
          break;
        }
        case key_UM: {
          return this->field_UM;
          break;
        }
        case key_CC: {
          return this->field_CC;
          break;
        }
        case key_DZ: {
          return this->field_DZ;
          break;
        }
        case key_IE: {
          return this->field_IE;
          break;
        }
        case key_VMS: {
          return this->field_VMS;
          break;
        }
        case key_BIP: {
          return this->field_BIP;
          break;
        }
        default: {
          return this->field_empty;
          break;
        }
      }
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    unsigned int operator ~() throw();
    Reg32_1 & operator =(const unsigned int & other) throw();
    Reg32_1 & operator +=(const unsigned int & other) throw();
    Reg32_1 & operator -=(const unsigned int & other) throw();
    Reg32_1 & operator *=(const unsigned int & other) throw();
    Reg32_1 & operator /=(const unsigned int & other) throw();
    Reg32_1 & operator |=(const unsigned int & other) throw();
    Reg32_1 & operator &=(const unsigned int & other) throw();
    Reg32_1 & operator ^=(const unsigned int & other) throw();
    Reg32_1 & operator <<=(const unsigned int & other) throw();
    Reg32_1 & operator >>=(const unsigned int & other) throw();
    unsigned int operator +(const Reg32_1 & other) const throw();
    unsigned int operator -(const Reg32_1 & other) const throw();
    unsigned int operator *(const Reg32_1 & other) const throw();
    unsigned int operator /(const Reg32_1 & other) const throw();
    unsigned int operator |(const Reg32_1 & other) const throw();
    unsigned int operator &(const Reg32_1 & other) const throw();
    unsigned int operator ^(const Reg32_1 & other) const throw();
    unsigned int operator <<(const Reg32_1 & other) const throw();
    unsigned int operator >>(const Reg32_1 & other) const throw();
    bool operator <(const Reg32_1 & other) const throw();
    bool operator >(const Reg32_1 & other) const throw();
    bool operator <=(const Reg32_1 & other) const throw();
    bool operator >=(const Reg32_1 & other) const throw();
    bool operator ==(const Reg32_1 & other) const throw();
    bool operator !=(const Reg32_1 & other) const throw();
    Reg32_1 & operator =(const Reg32_1 & other) throw();
    Reg32_1 & operator +=(const Reg32_1 & other) throw();
    Reg32_1 & operator -=(const Reg32_1 & other) throw();
    Reg32_1 & operator *=(const Reg32_1 & other) throw();
    Reg32_1 & operator /=(const Reg32_1 & other) throw();
    Reg32_1 & operator |=(const Reg32_1 & other) throw();
    Reg32_1 & operator &=(const Reg32_1 & other) throw();
    Reg32_1 & operator ^=(const Reg32_1 & other) throw();
    Reg32_1 & operator <<=(const Reg32_1 & other) throw();
    Reg32_1 & operator >>=(const Reg32_1 & other) throw();
    unsigned int operator +(const Register & other) const throw();
    unsigned int operator -(const Register & other) const throw();
    unsigned int operator *(const Register & other) const throw();
    unsigned int operator /(const Register & other) const throw();
    unsigned int operator |(const Register & other) const throw();
    unsigned int operator &(const Register & other) const throw();
    unsigned int operator ^(const Register & other) const throw();
    unsigned int operator <<(const Register & other) const throw();
    unsigned int operator >>(const Register & other) const throw();
    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Reg32_1 & operator =(const Register & other) throw();
    Reg32_1 & operator +=(const Register & other) throw();
    Reg32_1 & operator -=(const Register & other) throw();
    Reg32_1 & operator *=(const Register & other) throw();
    Reg32_1 & operator /=(const Register & other) throw();
    Reg32_1 & operator |=(const Register & other) throw();
    Reg32_1 & operator &=(const Register & other) throw();
    Reg32_1 & operator ^=(const Register & other) throw();
    Reg32_1 & operator <<=(const Register & other) throw();
    Reg32_1 & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return this->value;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();

    private:
    InnerField_BE field_BE;
    InnerField_C field_C;
    InnerField_PVR field_PVR;
    InnerField_UMS field_UMS;
    InnerField_EIP field_EIP;
    InnerField_EE field_EE;
    InnerField_DCE field_DCE;
    InnerField_FSL field_FSL;
    InnerField_VM field_VM;
    InnerField_ICE field_ICE;
    InnerField_UM field_UM;
    InnerField_CC field_CC;
    InnerField_DZ field_DZ;
    InnerField_IE field_IE;
    InnerField_VMS field_VMS;
    InnerField_BIP field_BIP;
    InnerField_Empty field_empty;
    unsigned int value;

  }; // class Reg32_1

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class Reg32_2 : public Register {
    public:
    class InnerField_EC : public InnerField {
      public:
      InnerField_EC(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0xf8000000) >> 27;
      } // operator unsigned int()

      virtual ~InnerField_EC();

      private:
      unsigned int & value;

    }; // class InnerField_EC

    class InnerField_S : public InnerField {
      public:
      InnerField_S(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x200000) >> 21;
      } // operator unsigned int()

      virtual ~InnerField_S();

      private:
      unsigned int & value;

    }; // class InnerField_S

    class InnerField_Rx : public InnerField {
      public:
      InnerField_Rx(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x7c00000) >> 22;
      } // operator unsigned int()

      virtual ~InnerField_Rx();

      private:
      unsigned int & value;

    }; // class InnerField_Rx

    class InnerField_DS : public InnerField {
      public:
      InnerField_DS(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x80000) >> 19;
      } // operator unsigned int()

      virtual ~InnerField_DS();

      private:
      unsigned int & value;

    }; // class InnerField_DS

    class InnerField_W : public InnerField {
      public:
      InnerField_W(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x100000) >> 20;
      } // operator unsigned int()

      virtual ~InnerField_W();

      private:
      unsigned int & value;

    }; // class InnerField_W

    class InnerField_Empty : public InnerField {
      public:
      InnerField_Empty();
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return 0;
      } // operator unsigned int()

      virtual ~InnerField_Empty();

    }; // class InnerField_Empty

    public:
    Reg32_2();
    inline InnerField & operator [](int bitField) throw() {
      switch(bitField) {
        case key_EC: {
          return this->field_EC;
          break;
        }
        case key_S: {
          return this->field_S;
          break;
        }
        case key_Rx: {
          return this->field_Rx;
          break;
        }
        case key_DS: {
          return this->field_DS;
          break;
        }
        case key_W: {
          return this->field_W;
          break;
        }
        default: {
          return this->field_empty;
          break;
        }
      }
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    unsigned int operator ~() throw();
    Reg32_2 & operator =(const unsigned int & other) throw();
    Reg32_2 & operator +=(const unsigned int & other) throw();
    Reg32_2 & operator -=(const unsigned int & other) throw();
    Reg32_2 & operator *=(const unsigned int & other) throw();
    Reg32_2 & operator /=(const unsigned int & other) throw();
    Reg32_2 & operator |=(const unsigned int & other) throw();
    Reg32_2 & operator &=(const unsigned int & other) throw();
    Reg32_2 & operator ^=(const unsigned int & other) throw();
    Reg32_2 & operator <<=(const unsigned int & other) throw();
    Reg32_2 & operator >>=(const unsigned int & other) throw();
    unsigned int operator +(const Reg32_2 & other) const throw();
    unsigned int operator -(const Reg32_2 & other) const throw();
    unsigned int operator *(const Reg32_2 & other) const throw();
    unsigned int operator /(const Reg32_2 & other) const throw();
    unsigned int operator |(const Reg32_2 & other) const throw();
    unsigned int operator &(const Reg32_2 & other) const throw();
    unsigned int operator ^(const Reg32_2 & other) const throw();
    unsigned int operator <<(const Reg32_2 & other) const throw();
    unsigned int operator >>(const Reg32_2 & other) const throw();
    bool operator <(const Reg32_2 & other) const throw();
    bool operator >(const Reg32_2 & other) const throw();
    bool operator <=(const Reg32_2 & other) const throw();
    bool operator >=(const Reg32_2 & other) const throw();
    bool operator ==(const Reg32_2 & other) const throw();
    bool operator !=(const Reg32_2 & other) const throw();
    Reg32_2 & operator =(const Reg32_2 & other) throw();
    Reg32_2 & operator +=(const Reg32_2 & other) throw();
    Reg32_2 & operator -=(const Reg32_2 & other) throw();
    Reg32_2 & operator *=(const Reg32_2 & other) throw();
    Reg32_2 & operator /=(const Reg32_2 & other) throw();
    Reg32_2 & operator |=(const Reg32_2 & other) throw();
    Reg32_2 & operator &=(const Reg32_2 & other) throw();
    Reg32_2 & operator ^=(const Reg32_2 & other) throw();
    Reg32_2 & operator <<=(const Reg32_2 & other) throw();
    Reg32_2 & operator >>=(const Reg32_2 & other) throw();
    unsigned int operator +(const Register & other) const throw();
    unsigned int operator -(const Register & other) const throw();
    unsigned int operator *(const Register & other) const throw();
    unsigned int operator /(const Register & other) const throw();
    unsigned int operator |(const Register & other) const throw();
    unsigned int operator &(const Register & other) const throw();
    unsigned int operator ^(const Register & other) const throw();
    unsigned int operator <<(const Register & other) const throw();
    unsigned int operator >>(const Register & other) const throw();
    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Reg32_2 & operator =(const Register & other) throw();
    Reg32_2 & operator +=(const Register & other) throw();
    Reg32_2 & operator -=(const Register & other) throw();
    Reg32_2 & operator *=(const Register & other) throw();
    Reg32_2 & operator /=(const Register & other) throw();
    Reg32_2 & operator |=(const Register & other) throw();
    Reg32_2 & operator &=(const Register & other) throw();
    Reg32_2 & operator ^=(const Register & other) throw();
    Reg32_2 & operator <<=(const Register & other) throw();
    Reg32_2 & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return this->value;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();

    private:
    InnerField_EC field_EC;
    InnerField_S field_S;
    InnerField_Rx field_Rx;
    InnerField_DS field_DS;
    InnerField_W field_W;
    InnerField_Empty field_empty;
    unsigned int value;

  }; // class Reg32_2

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class Reg32_3 : public Register {
    public:
    class InnerField_OF : public InnerField {
      public:
      InnerField_OF(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x20000000) >> 29;
      } // operator unsigned int()

      virtual ~InnerField_OF();

      private:
      unsigned int & value;

    }; // class InnerField_OF

    class InnerField_UF : public InnerField {
      public:
      InnerField_UF(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x40000000) >> 30;
      } // operator unsigned int()

      virtual ~InnerField_UF();

      private:
      unsigned int & value;

    }; // class InnerField_UF

    class InnerField_DZ : public InnerField {
      public:
      InnerField_DZ(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x10000000) >> 28;
      } // operator unsigned int()

      virtual ~InnerField_DZ();

      private:
      unsigned int & value;

    }; // class InnerField_DZ

    class InnerField_IO : public InnerField {
      public:
      InnerField_IO(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x8000000) >> 27;
      } // operator unsigned int()

      virtual ~InnerField_IO();

      private:
      unsigned int & value;

    }; // class InnerField_IO

    class InnerField_DO : public InnerField {
      public:
      InnerField_DO(unsigned int & value);
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return (this->value & 0x80000000) >> 31;
      } // operator unsigned int()

      virtual ~InnerField_DO();

      private:
      unsigned int & value;

    }; // class InnerField_DO

    class InnerField_Empty : public InnerField {
      public:
      InnerField_Empty();
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return 0;
      } // operator unsigned int()

      virtual ~InnerField_Empty();

    }; // class InnerField_Empty

    public:
    Reg32_3();
    inline InnerField & operator [](int bitField) throw() {
      switch(bitField) {
        case key_OF: {
          return this->field_OF;
          break;
        }
        case key_UF: {
          return this->field_UF;
          break;
        }
        case key_DZ: {
          return this->field_DZ;
          break;
        }
        case key_IO: {
          return this->field_IO;
          break;
        }
        case key_DO: {
          return this->field_DO;
          break;
        }
        default: {
          return this->field_empty;
          break;
        }
      }
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    unsigned int operator ~() throw();
    Reg32_3 & operator =(const unsigned int & other) throw();
    Reg32_3 & operator +=(const unsigned int & other) throw();
    Reg32_3 & operator -=(const unsigned int & other) throw();
    Reg32_3 & operator *=(const unsigned int & other) throw();
    Reg32_3 & operator /=(const unsigned int & other) throw();
    Reg32_3 & operator |=(const unsigned int & other) throw();
    Reg32_3 & operator &=(const unsigned int & other) throw();
    Reg32_3 & operator ^=(const unsigned int & other) throw();
    Reg32_3 & operator <<=(const unsigned int & other) throw();
    Reg32_3 & operator >>=(const unsigned int & other) throw();
    unsigned int operator +(const Reg32_3 & other) const throw();
    unsigned int operator -(const Reg32_3 & other) const throw();
    unsigned int operator *(const Reg32_3 & other) const throw();
    unsigned int operator /(const Reg32_3 & other) const throw();
    unsigned int operator |(const Reg32_3 & other) const throw();
    unsigned int operator &(const Reg32_3 & other) const throw();
    unsigned int operator ^(const Reg32_3 & other) const throw();
    unsigned int operator <<(const Reg32_3 & other) const throw();
    unsigned int operator >>(const Reg32_3 & other) const throw();
    bool operator <(const Reg32_3 & other) const throw();
    bool operator >(const Reg32_3 & other) const throw();
    bool operator <=(const Reg32_3 & other) const throw();
    bool operator >=(const Reg32_3 & other) const throw();
    bool operator ==(const Reg32_3 & other) const throw();
    bool operator !=(const Reg32_3 & other) const throw();
    Reg32_3 & operator =(const Reg32_3 & other) throw();
    Reg32_3 & operator +=(const Reg32_3 & other) throw();
    Reg32_3 & operator -=(const Reg32_3 & other) throw();
    Reg32_3 & operator *=(const Reg32_3 & other) throw();
    Reg32_3 & operator /=(const Reg32_3 & other) throw();
    Reg32_3 & operator |=(const Reg32_3 & other) throw();
    Reg32_3 & operator &=(const Reg32_3 & other) throw();
    Reg32_3 & operator ^=(const Reg32_3 & other) throw();
    Reg32_3 & operator <<=(const Reg32_3 & other) throw();
    Reg32_3 & operator >>=(const Reg32_3 & other) throw();
    unsigned int operator +(const Register & other) const throw();
    unsigned int operator -(const Register & other) const throw();
    unsigned int operator *(const Register & other) const throw();
    unsigned int operator /(const Register & other) const throw();
    unsigned int operator |(const Register & other) const throw();
    unsigned int operator &(const Register & other) const throw();
    unsigned int operator ^(const Register & other) const throw();
    unsigned int operator <<(const Register & other) const throw();
    unsigned int operator >>(const Register & other) const throw();
    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Reg32_3 & operator =(const Register & other) throw();
    Reg32_3 & operator +=(const Register & other) throw();
    Reg32_3 & operator -=(const Register & other) throw();
    Reg32_3 & operator *=(const Register & other) throw();
    Reg32_3 & operator /=(const Register & other) throw();
    Reg32_3 & operator |=(const Register & other) throw();
    Reg32_3 & operator &=(const Register & other) throw();
    Reg32_3 & operator ^=(const Register & other) throw();
    Reg32_3 & operator <<=(const Register & other) throw();
    Reg32_3 & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return this->value;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();

    private:
    InnerField_OF field_OF;
    InnerField_UF field_UF;
    InnerField_DZ field_DZ;
    InnerField_IO field_IO;
    InnerField_DO field_DO;
    InnerField_Empty field_empty;
    unsigned int value;

  }; // class Reg32_3

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  class Reg1_0 : public Register {
    public:
    class InnerField_Empty : public InnerField {
      public:
      InnerField_Empty();
      InnerField & operator =(const unsigned int & other) throw();
      inline operator unsigned int() const throw() {
        return 0;
      } // operator unsigned int()

      virtual ~InnerField_Empty();

    }; // class InnerField_Empty

    public:
    Reg1_0();
    inline InnerField & operator [](int bitField) throw() {
      return this->field_empty;
    } // operator []()

    void immediateWrite(const unsigned int & value) throw();
    unsigned int readNewValue() throw();
    unsigned int operator ~() throw();
    Reg1_0 & operator =(const unsigned int & other) throw();
    Reg1_0 & operator +=(const unsigned int & other) throw();
    Reg1_0 & operator -=(const unsigned int & other) throw();
    Reg1_0 & operator *=(const unsigned int & other) throw();
    Reg1_0 & operator /=(const unsigned int & other) throw();
    Reg1_0 & operator |=(const unsigned int & other) throw();
    Reg1_0 & operator &=(const unsigned int & other) throw();
    Reg1_0 & operator ^=(const unsigned int & other) throw();
    Reg1_0 & operator <<=(const unsigned int & other) throw();
    Reg1_0 & operator >>=(const unsigned int & other) throw();
    unsigned int operator +(const Reg1_0 & other) const throw();
    unsigned int operator -(const Reg1_0 & other) const throw();
    unsigned int operator *(const Reg1_0 & other) const throw();
    unsigned int operator /(const Reg1_0 & other) const throw();
    unsigned int operator |(const Reg1_0 & other) const throw();
    unsigned int operator &(const Reg1_0 & other) const throw();
    unsigned int operator ^(const Reg1_0 & other) const throw();
    unsigned int operator <<(const Reg1_0 & other) const throw();
    unsigned int operator >>(const Reg1_0 & other) const throw();
    bool operator <(const Reg1_0 & other) const throw();
    bool operator >(const Reg1_0 & other) const throw();
    bool operator <=(const Reg1_0 & other) const throw();
    bool operator >=(const Reg1_0 & other) const throw();
    bool operator ==(const Reg1_0 & other) const throw();
    bool operator !=(const Reg1_0 & other) const throw();
    Reg1_0 & operator =(const Reg1_0 & other) throw();
    Reg1_0 & operator +=(const Reg1_0 & other) throw();
    Reg1_0 & operator -=(const Reg1_0 & other) throw();
    Reg1_0 & operator *=(const Reg1_0 & other) throw();
    Reg1_0 & operator /=(const Reg1_0 & other) throw();
    Reg1_0 & operator |=(const Reg1_0 & other) throw();
    Reg1_0 & operator &=(const Reg1_0 & other) throw();
    Reg1_0 & operator ^=(const Reg1_0 & other) throw();
    Reg1_0 & operator <<=(const Reg1_0 & other) throw();
    Reg1_0 & operator >>=(const Reg1_0 & other) throw();
    unsigned int operator +(const Register & other) const throw();
    unsigned int operator -(const Register & other) const throw();
    unsigned int operator *(const Register & other) const throw();
    unsigned int operator /(const Register & other) const throw();
    unsigned int operator |(const Register & other) const throw();
    unsigned int operator &(const Register & other) const throw();
    unsigned int operator ^(const Register & other) const throw();
    unsigned int operator <<(const Register & other) const throw();
    unsigned int operator >>(const Register & other) const throw();
    bool operator <(const Register & other) const throw();
    bool operator >(const Register & other) const throw();
    bool operator <=(const Register & other) const throw();
    bool operator >=(const Register & other) const throw();
    bool operator ==(const Register & other) const throw();
    bool operator !=(const Register & other) const throw();
    Reg1_0 & operator =(const Register & other) throw();
    Reg1_0 & operator +=(const Register & other) throw();
    Reg1_0 & operator -=(const Register & other) throw();
    Reg1_0 & operator *=(const Register & other) throw();
    Reg1_0 & operator /=(const Register & other) throw();
    Reg1_0 & operator |=(const Register & other) throw();
    Reg1_0 & operator &=(const Register & other) throw();
    Reg1_0 & operator ^=(const Register & other) throw();
    Reg1_0 & operator <<=(const Register & other) throw();
    Reg1_0 & operator >>=(const Register & other) throw();
    inline operator unsigned int() const throw() {
      return this->value;
    } // operator unsigned int()

    std::ostream & operator <<(std::ostream & stream) const throw();

    private:
    InnerField_Empty field_empty;
    unsigned int value;

  }; // class Reg1_0

} // namespace core_microblaze_lt



#endif
