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


#include "microblaze/intunit/registers.hpp"


#include <ostream>


using namespace core_microblaze_lt;
InnerField & core_microblaze_lt::InnerField::operator =(const InnerField &
  other) throw() {
  *this = (unsigned int)other;
  return *this;
} // operator =()

core_microblaze_lt::InnerField::~InnerField() {

} // ~InnerField()

void core_microblaze_lt::Register::clockCycle() throw() {

} // clockCycle()

core_microblaze_lt::Register::Register() {

} // Register()

core_microblaze_lt::Register::Register(const Register & other) {

} // Register()

InnerField & core_microblaze_lt::Reg32_0::InnerField_Empty::operator =(const
  unsigned int & other) throw() {
  return *this;
} // operator =()

core_microblaze_lt::Reg32_0::InnerField_Empty::InnerField_Empty() {

} // InnerField_Empty()

core_microblaze_lt::Reg32_0::InnerField_Empty::~InnerField_Empty() {

} // ~InnerField_Empty()

void core_microblaze_lt::Reg32_0::immediateWrite(const unsigned int & value) throw() {
  this->value = value;
} // immediateWrite()

unsigned int core_microblaze_lt::Reg32_0::readNewValue() throw() {
  return this->value;
} // readNewValue()

unsigned int core_microblaze_lt::Reg32_0::operator ~() throw() {
  return ~(this->value);
} // operator ~()

Reg32_0 & core_microblaze_lt::Reg32_0::operator =(const unsigned int & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_0 & core_microblaze_lt::Reg32_0::operator +=(const unsigned int & other)
  throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator -=(const unsigned int & other)
  throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator *=(const unsigned int & other)
  throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator /=(const unsigned int & other)
  throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator |=(const unsigned int & other)
  throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator &=(const unsigned int & other)
  throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator ^=(const unsigned int & other)
  throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator <<=(const unsigned int & other)
  throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator >>=(const unsigned int & other)
  throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_0::operator +(const Reg32_0 & other)
  const throw() {
  return (this->value + other.value);
} // operator +()

unsigned int core_microblaze_lt::Reg32_0::operator -(const Reg32_0 & other)
  const throw() {
  return (this->value - other.value);
} // operator -()

unsigned int core_microblaze_lt::Reg32_0::operator *(const Reg32_0 & other)
  const throw() {
  return (this->value * other.value);
} // operator *()

unsigned int core_microblaze_lt::Reg32_0::operator /(const Reg32_0 & other)
  const throw() {
  return (this->value / other.value);
} // operator /()

unsigned int core_microblaze_lt::Reg32_0::operator |(const Reg32_0 & other)
  const throw() {
  return (this->value | other.value);
} // operator |()

unsigned int core_microblaze_lt::Reg32_0::operator &(const Reg32_0 & other)
  const throw() {
  return (this->value & other.value);
} // operator &()

unsigned int core_microblaze_lt::Reg32_0::operator ^(const Reg32_0 & other)
  const throw() {
  return (this->value ^ other.value);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_0::operator <<(const Reg32_0 & other)
  const throw() {
  return (this->value << other.value);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_0::operator >>(const Reg32_0 & other)
  const throw() {
  return (this->value >> other.value);
} // operator >>()

bool core_microblaze_lt::Reg32_0::operator <(const Reg32_0 & other) const throw() {
  return (this->value < other.value);
} // operator <()

bool core_microblaze_lt::Reg32_0::operator >(const Reg32_0 & other) const throw() {
  return (this->value > other.value);
} // operator >()

bool core_microblaze_lt::Reg32_0::operator <=(const Reg32_0 & other) const throw() {
  return (this->value <= other.value);
} // operator <=()

bool core_microblaze_lt::Reg32_0::operator >=(const Reg32_0 & other) const throw() {
  return (this->value >= other.value);
} // operator >=()

bool core_microblaze_lt::Reg32_0::operator ==(const Reg32_0 & other) const throw() {
  return (this->value == other.value);
} // operator ==()

bool core_microblaze_lt::Reg32_0::operator !=(const Reg32_0 & other) const throw() {
  return (this->value != other.value);
} // operator !=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator =(const Reg32_0 & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_0 & core_microblaze_lt::Reg32_0::operator +=(const Reg32_0 & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator -=(const Reg32_0 & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator *=(const Reg32_0 & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator /=(const Reg32_0 & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator |=(const Reg32_0 & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator &=(const Reg32_0 & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator ^=(const Reg32_0 & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator <<=(const Reg32_0 & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator >>=(const Reg32_0 & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_0::operator +(const Register & other)
  const throw() {
  return (this->value + other);
} // operator +()

unsigned int core_microblaze_lt::Reg32_0::operator -(const Register & other)
  const throw() {
  return (this->value - other);
} // operator -()

unsigned int core_microblaze_lt::Reg32_0::operator *(const Register & other)
  const throw() {
  return (this->value * other);
} // operator *()

unsigned int core_microblaze_lt::Reg32_0::operator /(const Register & other)
  const throw() {
  return (this->value / other);
} // operator /()

unsigned int core_microblaze_lt::Reg32_0::operator |(const Register & other)
  const throw() {
  return (this->value | other);
} // operator |()

unsigned int core_microblaze_lt::Reg32_0::operator &(const Register & other)
  const throw() {
  return (this->value & other);
} // operator &()

unsigned int core_microblaze_lt::Reg32_0::operator ^(const Register & other)
  const throw() {
  return (this->value ^ other);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_0::operator <<(const Register & other)
  const throw() {
  return (this->value << other);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_0::operator >>(const Register & other)
  const throw() {
  return (this->value >> other);
} // operator >>()

bool core_microblaze_lt::Reg32_0::operator <(const Register & other) const throw() {
  return (this->value < other);
} // operator <()

bool core_microblaze_lt::Reg32_0::operator >(const Register & other) const throw() {
  return (this->value > other);
} // operator >()

bool core_microblaze_lt::Reg32_0::operator <=(const Register & other) const throw() {
  return (this->value <= other);
} // operator <=()

bool core_microblaze_lt::Reg32_0::operator >=(const Register & other) const throw() {
  return (this->value >= other);
} // operator >=()

bool core_microblaze_lt::Reg32_0::operator ==(const Register & other) const throw() {
  return (this->value == other);
} // operator ==()

bool core_microblaze_lt::Reg32_0::operator !=(const Register & other) const throw() {
  return (this->value != other);
} // operator !=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator =(const Register & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_0 & core_microblaze_lt::Reg32_0::operator +=(const Register & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator -=(const Register & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator *=(const Register & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator /=(const Register & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator |=(const Register & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator &=(const Register & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator ^=(const Register & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator <<=(const Register & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_0 & core_microblaze_lt::Reg32_0::operator >>=(const Register & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Reg32_0::operator <<(std::ostream & stream)
  const throw() {
  stream << std::hex << std::showbase << this->value << std::dec;
  return stream;
} // operator <<()

core_microblaze_lt::Reg32_0::Reg32_0() {
  this->value = 0;
} // Reg32_0()

InnerField & core_microblaze_lt::Reg32_1::InnerField_BE::operator =(const
  unsigned int & other) throw() {
  this->value &= 0x7fffffff;
  this->value |= ((other & 0x1) << 31);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_BE::InnerField_BE(unsigned int & value) :
  value(value) {

} // InnerField_BE()

core_microblaze_lt::Reg32_1::InnerField_BE::~InnerField_BE() {

} // ~InnerField_BE()

InnerField & core_microblaze_lt::Reg32_1::InnerField_C::operator =(const unsigned
  int & other) throw() {
  this->value &= 0xdfffffff;
  this->value |= ((other & 0x1) << 29);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_C::InnerField_C(unsigned int & value) :
  value(value) {

} // InnerField_C()

core_microblaze_lt::Reg32_1::InnerField_C::~InnerField_C() {

} // ~InnerField_C()

InnerField & core_microblaze_lt::Reg32_1::InnerField_PVR::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xffdfffff;
  this->value |= ((other & 0x1) << 21);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_PVR::InnerField_PVR(unsigned int & value) :
  value(value) {

} // InnerField_PVR()

core_microblaze_lt::Reg32_1::InnerField_PVR::~InnerField_PVR() {

} // ~InnerField_PVR()

InnerField & core_microblaze_lt::Reg32_1::InnerField_UMS::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfff7ffff;
  this->value |= ((other & 0x1) << 19);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_UMS::InnerField_UMS(unsigned int & value) :
  value(value) {

} // InnerField_UMS()

core_microblaze_lt::Reg32_1::InnerField_UMS::~InnerField_UMS() {

} // ~InnerField_UMS()

InnerField & core_microblaze_lt::Reg32_1::InnerField_EIP::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xffbfffff;
  this->value |= ((other & 0x1) << 22);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_EIP::InnerField_EIP(unsigned int & value) :
  value(value) {

} // InnerField_EIP()

core_microblaze_lt::Reg32_1::InnerField_EIP::~InnerField_EIP() {

} // ~InnerField_EIP()

InnerField & core_microblaze_lt::Reg32_1::InnerField_EE::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xff7fffff;
  this->value |= ((other & 0x1) << 23);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_EE::InnerField_EE(unsigned int & value) :
  value(value) {

} // InnerField_EE()

core_microblaze_lt::Reg32_1::InnerField_EE::~InnerField_EE() {

} // ~InnerField_EE()

InnerField & core_microblaze_lt::Reg32_1::InnerField_DCE::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfeffffff;
  this->value |= ((other & 0x1) << 24);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_DCE::InnerField_DCE(unsigned int & value) :
  value(value) {

} // InnerField_DCE()

core_microblaze_lt::Reg32_1::InnerField_DCE::~InnerField_DCE() {

} // ~InnerField_DCE()

InnerField & core_microblaze_lt::Reg32_1::InnerField_FSL::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xf7ffffff;
  this->value |= ((other & 0x1) << 27);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_FSL::InnerField_FSL(unsigned int & value) :
  value(value) {

} // InnerField_FSL()

core_microblaze_lt::Reg32_1::InnerField_FSL::~InnerField_FSL() {

} // ~InnerField_FSL()

InnerField & core_microblaze_lt::Reg32_1::InnerField_VM::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfffbffff;
  this->value |= ((other & 0x1) << 18);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_VM::InnerField_VM(unsigned int & value) :
  value(value) {

} // InnerField_VM()

core_microblaze_lt::Reg32_1::InnerField_VM::~InnerField_VM() {

} // ~InnerField_VM()

InnerField & core_microblaze_lt::Reg32_1::InnerField_ICE::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfbffffff;
  this->value |= ((other & 0x1) << 26);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_ICE::InnerField_ICE(unsigned int & value) :
  value(value) {

} // InnerField_ICE()

core_microblaze_lt::Reg32_1::InnerField_ICE::~InnerField_ICE() {

} // ~InnerField_ICE()

InnerField & core_microblaze_lt::Reg32_1::InnerField_UM::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xffefffff;
  this->value |= ((other & 0x1) << 20);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_UM::InnerField_UM(unsigned int & value) :
  value(value) {

} // InnerField_UM()

core_microblaze_lt::Reg32_1::InnerField_UM::~InnerField_UM() {

} // ~InnerField_UM()

InnerField & core_microblaze_lt::Reg32_1::InnerField_CC::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfffffffe;
  this->value |= other;
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_CC::InnerField_CC(unsigned int & value) :
  value(value) {

} // InnerField_CC()

core_microblaze_lt::Reg32_1::InnerField_CC::~InnerField_CC() {

} // ~InnerField_CC()

InnerField & core_microblaze_lt::Reg32_1::InnerField_DZ::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfdffffff;
  this->value |= ((other & 0x1) << 25);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_DZ::InnerField_DZ(unsigned int & value) :
  value(value) {

} // InnerField_DZ()

core_microblaze_lt::Reg32_1::InnerField_DZ::~InnerField_DZ() {

} // ~InnerField_DZ()

InnerField & core_microblaze_lt::Reg32_1::InnerField_IE::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xbfffffff;
  this->value |= ((other & 0x1) << 30);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_IE::InnerField_IE(unsigned int & value) :
  value(value) {

} // InnerField_IE()

core_microblaze_lt::Reg32_1::InnerField_IE::~InnerField_IE() {

} // ~InnerField_IE()

InnerField & core_microblaze_lt::Reg32_1::InnerField_VMS::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfffdffff;
  this->value |= ((other & 0x1) << 17);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_VMS::InnerField_VMS(unsigned int & value) :
  value(value) {

} // InnerField_VMS()

core_microblaze_lt::Reg32_1::InnerField_VMS::~InnerField_VMS() {

} // ~InnerField_VMS()

InnerField & core_microblaze_lt::Reg32_1::InnerField_BIP::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xefffffff;
  this->value |= ((other & 0x1) << 28);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_BIP::InnerField_BIP(unsigned int & value) :
  value(value) {

} // InnerField_BIP()

core_microblaze_lt::Reg32_1::InnerField_BIP::~InnerField_BIP() {

} // ~InnerField_BIP()

InnerField & core_microblaze_lt::Reg32_1::InnerField_Empty::operator =(const
  unsigned int & other) throw() {
  return *this;
} // operator =()

core_microblaze_lt::Reg32_1::InnerField_Empty::InnerField_Empty() {

} // InnerField_Empty()

core_microblaze_lt::Reg32_1::InnerField_Empty::~InnerField_Empty() {

} // ~InnerField_Empty()

void core_microblaze_lt::Reg32_1::immediateWrite(const unsigned int & value) throw() {
  this->value = value;
} // immediateWrite()

unsigned int core_microblaze_lt::Reg32_1::readNewValue() throw() {
  return this->value;
} // readNewValue()

unsigned int core_microblaze_lt::Reg32_1::operator ~() throw() {
  return ~(this->value);
} // operator ~()

Reg32_1 & core_microblaze_lt::Reg32_1::operator =(const unsigned int & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_1 & core_microblaze_lt::Reg32_1::operator +=(const unsigned int & other)
  throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator -=(const unsigned int & other)
  throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator *=(const unsigned int & other)
  throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator /=(const unsigned int & other)
  throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator |=(const unsigned int & other)
  throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator &=(const unsigned int & other)
  throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator ^=(const unsigned int & other)
  throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator <<=(const unsigned int & other)
  throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator >>=(const unsigned int & other)
  throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_1::operator +(const Reg32_1 & other)
  const throw() {
  return (this->value + other.value);
} // operator +()

unsigned int core_microblaze_lt::Reg32_1::operator -(const Reg32_1 & other)
  const throw() {
  return (this->value - other.value);
} // operator -()

unsigned int core_microblaze_lt::Reg32_1::operator *(const Reg32_1 & other)
  const throw() {
  return (this->value * other.value);
} // operator *()

unsigned int core_microblaze_lt::Reg32_1::operator /(const Reg32_1 & other)
  const throw() {
  return (this->value / other.value);
} // operator /()

unsigned int core_microblaze_lt::Reg32_1::operator |(const Reg32_1 & other)
  const throw() {
  return (this->value | other.value);
} // operator |()

unsigned int core_microblaze_lt::Reg32_1::operator &(const Reg32_1 & other)
  const throw() {
  return (this->value & other.value);
} // operator &()

unsigned int core_microblaze_lt::Reg32_1::operator ^(const Reg32_1 & other)
  const throw() {
  return (this->value ^ other.value);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_1::operator <<(const Reg32_1 & other)
  const throw() {
  return (this->value << other.value);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_1::operator >>(const Reg32_1 & other)
  const throw() {
  return (this->value >> other.value);
} // operator >>()

bool core_microblaze_lt::Reg32_1::operator <(const Reg32_1 & other) const throw() {
  return (this->value < other.value);
} // operator <()

bool core_microblaze_lt::Reg32_1::operator >(const Reg32_1 & other) const throw() {
  return (this->value > other.value);
} // operator >()

bool core_microblaze_lt::Reg32_1::operator <=(const Reg32_1 & other) const throw() {
  return (this->value <= other.value);
} // operator <=()

bool core_microblaze_lt::Reg32_1::operator >=(const Reg32_1 & other) const throw() {
  return (this->value >= other.value);
} // operator >=()

bool core_microblaze_lt::Reg32_1::operator ==(const Reg32_1 & other) const throw() {
  return (this->value == other.value);
} // operator ==()

bool core_microblaze_lt::Reg32_1::operator !=(const Reg32_1 & other) const throw() {
  return (this->value != other.value);
} // operator !=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator =(const Reg32_1 & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_1 & core_microblaze_lt::Reg32_1::operator +=(const Reg32_1 & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator -=(const Reg32_1 & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator *=(const Reg32_1 & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator /=(const Reg32_1 & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator |=(const Reg32_1 & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator &=(const Reg32_1 & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator ^=(const Reg32_1 & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator <<=(const Reg32_1 & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator >>=(const Reg32_1 & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_1::operator +(const Register & other)
  const throw() {
  return (this->value + other);
} // operator +()

unsigned int core_microblaze_lt::Reg32_1::operator -(const Register & other)
  const throw() {
  return (this->value - other);
} // operator -()

unsigned int core_microblaze_lt::Reg32_1::operator *(const Register & other)
  const throw() {
  return (this->value * other);
} // operator *()

unsigned int core_microblaze_lt::Reg32_1::operator /(const Register & other)
  const throw() {
  return (this->value / other);
} // operator /()

unsigned int core_microblaze_lt::Reg32_1::operator |(const Register & other)
  const throw() {
  return (this->value | other);
} // operator |()

unsigned int core_microblaze_lt::Reg32_1::operator &(const Register & other)
  const throw() {
  return (this->value & other);
} // operator &()

unsigned int core_microblaze_lt::Reg32_1::operator ^(const Register & other)
  const throw() {
  return (this->value ^ other);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_1::operator <<(const Register & other)
  const throw() {
  return (this->value << other);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_1::operator >>(const Register & other)
  const throw() {
  return (this->value >> other);
} // operator >>()

bool core_microblaze_lt::Reg32_1::operator <(const Register & other) const throw() {
  return (this->value < other);
} // operator <()

bool core_microblaze_lt::Reg32_1::operator >(const Register & other) const throw() {
  return (this->value > other);
} // operator >()

bool core_microblaze_lt::Reg32_1::operator <=(const Register & other) const throw() {
  return (this->value <= other);
} // operator <=()

bool core_microblaze_lt::Reg32_1::operator >=(const Register & other) const throw() {
  return (this->value >= other);
} // operator >=()

bool core_microblaze_lt::Reg32_1::operator ==(const Register & other) const throw() {
  return (this->value == other);
} // operator ==()

bool core_microblaze_lt::Reg32_1::operator !=(const Register & other) const throw() {
  return (this->value != other);
} // operator !=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator =(const Register & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_1 & core_microblaze_lt::Reg32_1::operator +=(const Register & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator -=(const Register & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator *=(const Register & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator /=(const Register & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator |=(const Register & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator &=(const Register & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator ^=(const Register & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator <<=(const Register & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_1 & core_microblaze_lt::Reg32_1::operator >>=(const Register & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Reg32_1::operator <<(std::ostream & stream)
  const throw() {
  stream << std::hex << std::showbase << this->value << std::dec;
  return stream;
} // operator <<()

core_microblaze_lt::Reg32_1::Reg32_1() :
  field_BE(this->value), field_C(this->value), field_PVR(this->value), field_UMS(this->value),
  field_EIP(this->value), field_EE(this->value), field_DCE(this->value), field_FSL(this->value),
  field_VM(this->value), field_ICE(this->value), field_UM(this->value), field_CC(this->value),
  field_DZ(this->value), field_IE(this->value), field_VMS(this->value), field_BIP(this->value)
  {
  this->value = 0;
} // Reg32_1()

InnerField & core_microblaze_lt::Reg32_2::InnerField_EC::operator =(const
  unsigned int & other) throw() {
  this->value &= 0x7ffffff;
  this->value |= ((other & 0x1f) << 27);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_EC::InnerField_EC(unsigned int & value) :
  value(value) {

} // InnerField_EC()

core_microblaze_lt::Reg32_2::InnerField_EC::~InnerField_EC() {

} // ~InnerField_EC()

InnerField & core_microblaze_lt::Reg32_2::InnerField_S::operator =(const unsigned
  int & other) throw() {
  this->value &= 0xffdfffff;
  this->value |= ((other & 0x1) << 21);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_S::InnerField_S(unsigned int & value) :
  value(value) {

} // InnerField_S()

core_microblaze_lt::Reg32_2::InnerField_S::~InnerField_S() {

} // ~InnerField_S()

InnerField & core_microblaze_lt::Reg32_2::InnerField_Rx::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xf83fffff;
  this->value |= ((other & 0x1f) << 22);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_Rx::InnerField_Rx(unsigned int & value) :
  value(value) {

} // InnerField_Rx()

core_microblaze_lt::Reg32_2::InnerField_Rx::~InnerField_Rx() {

} // ~InnerField_Rx()

InnerField & core_microblaze_lt::Reg32_2::InnerField_DS::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xfff7ffff;
  this->value |= ((other & 0x1) << 19);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_DS::InnerField_DS(unsigned int & value) :
  value(value) {

} // InnerField_DS()

core_microblaze_lt::Reg32_2::InnerField_DS::~InnerField_DS() {

} // ~InnerField_DS()

InnerField & core_microblaze_lt::Reg32_2::InnerField_W::operator =(const unsigned
  int & other) throw() {
  this->value &= 0xffefffff;
  this->value |= ((other & 0x1) << 20);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_W::InnerField_W(unsigned int & value) :
  value(value) {

} // InnerField_W()

core_microblaze_lt::Reg32_2::InnerField_W::~InnerField_W() {

} // ~InnerField_W()

InnerField & core_microblaze_lt::Reg32_2::InnerField_Empty::operator =(const
  unsigned int & other) throw() {
  return *this;
} // operator =()

core_microblaze_lt::Reg32_2::InnerField_Empty::InnerField_Empty() {

} // InnerField_Empty()

core_microblaze_lt::Reg32_2::InnerField_Empty::~InnerField_Empty() {

} // ~InnerField_Empty()

void core_microblaze_lt::Reg32_2::immediateWrite(const unsigned int & value) throw() {
  this->value = value;
} // immediateWrite()

unsigned int core_microblaze_lt::Reg32_2::readNewValue() throw() {
  return this->value;
} // readNewValue()

unsigned int core_microblaze_lt::Reg32_2::operator ~() throw() {
  return ~(this->value);
} // operator ~()

Reg32_2 & core_microblaze_lt::Reg32_2::operator =(const unsigned int & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_2 & core_microblaze_lt::Reg32_2::operator +=(const unsigned int & other)
  throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator -=(const unsigned int & other)
  throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator *=(const unsigned int & other)
  throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator /=(const unsigned int & other)
  throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator |=(const unsigned int & other)
  throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator &=(const unsigned int & other)
  throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator ^=(const unsigned int & other)
  throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator <<=(const unsigned int & other)
  throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator >>=(const unsigned int & other)
  throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_2::operator +(const Reg32_2 & other)
  const throw() {
  return (this->value + other.value);
} // operator +()

unsigned int core_microblaze_lt::Reg32_2::operator -(const Reg32_2 & other)
  const throw() {
  return (this->value - other.value);
} // operator -()

unsigned int core_microblaze_lt::Reg32_2::operator *(const Reg32_2 & other)
  const throw() {
  return (this->value * other.value);
} // operator *()

unsigned int core_microblaze_lt::Reg32_2::operator /(const Reg32_2 & other)
  const throw() {
  return (this->value / other.value);
} // operator /()

unsigned int core_microblaze_lt::Reg32_2::operator |(const Reg32_2 & other)
  const throw() {
  return (this->value | other.value);
} // operator |()

unsigned int core_microblaze_lt::Reg32_2::operator &(const Reg32_2 & other)
  const throw() {
  return (this->value & other.value);
} // operator &()

unsigned int core_microblaze_lt::Reg32_2::operator ^(const Reg32_2 & other)
  const throw() {
  return (this->value ^ other.value);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_2::operator <<(const Reg32_2 & other)
  const throw() {
  return (this->value << other.value);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_2::operator >>(const Reg32_2 & other)
  const throw() {
  return (this->value >> other.value);
} // operator >>()

bool core_microblaze_lt::Reg32_2::operator <(const Reg32_2 & other) const throw() {
  return (this->value < other.value);
} // operator <()

bool core_microblaze_lt::Reg32_2::operator >(const Reg32_2 & other) const throw() {
  return (this->value > other.value);
} // operator >()

bool core_microblaze_lt::Reg32_2::operator <=(const Reg32_2 & other) const throw() {
  return (this->value <= other.value);
} // operator <=()

bool core_microblaze_lt::Reg32_2::operator >=(const Reg32_2 & other) const throw() {
  return (this->value >= other.value);
} // operator >=()

bool core_microblaze_lt::Reg32_2::operator ==(const Reg32_2 & other) const throw() {
  return (this->value == other.value);
} // operator ==()

bool core_microblaze_lt::Reg32_2::operator !=(const Reg32_2 & other) const throw() {
  return (this->value != other.value);
} // operator !=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator =(const Reg32_2 & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_2 & core_microblaze_lt::Reg32_2::operator +=(const Reg32_2 & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator -=(const Reg32_2 & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator *=(const Reg32_2 & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator /=(const Reg32_2 & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator |=(const Reg32_2 & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator &=(const Reg32_2 & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator ^=(const Reg32_2 & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator <<=(const Reg32_2 & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator >>=(const Reg32_2 & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_2::operator +(const Register & other)
  const throw() {
  return (this->value + other);
} // operator +()

unsigned int core_microblaze_lt::Reg32_2::operator -(const Register & other)
  const throw() {
  return (this->value - other);
} // operator -()

unsigned int core_microblaze_lt::Reg32_2::operator *(const Register & other)
  const throw() {
  return (this->value * other);
} // operator *()

unsigned int core_microblaze_lt::Reg32_2::operator /(const Register & other)
  const throw() {
  return (this->value / other);
} // operator /()

unsigned int core_microblaze_lt::Reg32_2::operator |(const Register & other)
  const throw() {
  return (this->value | other);
} // operator |()

unsigned int core_microblaze_lt::Reg32_2::operator &(const Register & other)
  const throw() {
  return (this->value & other);
} // operator &()

unsigned int core_microblaze_lt::Reg32_2::operator ^(const Register & other)
  const throw() {
  return (this->value ^ other);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_2::operator <<(const Register & other)
  const throw() {
  return (this->value << other);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_2::operator >>(const Register & other)
  const throw() {
  return (this->value >> other);
} // operator >>()

bool core_microblaze_lt::Reg32_2::operator <(const Register & other) const throw() {
  return (this->value < other);
} // operator <()

bool core_microblaze_lt::Reg32_2::operator >(const Register & other) const throw() {
  return (this->value > other);
} // operator >()

bool core_microblaze_lt::Reg32_2::operator <=(const Register & other) const throw() {
  return (this->value <= other);
} // operator <=()

bool core_microblaze_lt::Reg32_2::operator >=(const Register & other) const throw() {
  return (this->value >= other);
} // operator >=()

bool core_microblaze_lt::Reg32_2::operator ==(const Register & other) const throw() {
  return (this->value == other);
} // operator ==()

bool core_microblaze_lt::Reg32_2::operator !=(const Register & other) const throw() {
  return (this->value != other);
} // operator !=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator =(const Register & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_2 & core_microblaze_lt::Reg32_2::operator +=(const Register & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator -=(const Register & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator *=(const Register & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator /=(const Register & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator |=(const Register & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator &=(const Register & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator ^=(const Register & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator <<=(const Register & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_2 & core_microblaze_lt::Reg32_2::operator >>=(const Register & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Reg32_2::operator <<(std::ostream & stream)
  const throw() {
  stream << std::hex << std::showbase << this->value << std::dec;
  return stream;
} // operator <<()

core_microblaze_lt::Reg32_2::Reg32_2() :
  field_EC(this->value),
  field_S(this->value),
  field_Rx(this->value),
  field_DS(this->value),
  field_W(this->value) {
  this->value = 0;
} // Reg32_2()

InnerField & core_microblaze_lt::Reg32_3::InnerField_OF::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xdfffffff;
  this->value |= ((other & 0x1) << 29);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_OF::InnerField_OF(unsigned int & value) :
  value(value) {

} // InnerField_OF()

core_microblaze_lt::Reg32_3::InnerField_OF::~InnerField_OF() {

} // ~InnerField_OF()

InnerField & core_microblaze_lt::Reg32_3::InnerField_UF::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xbfffffff;
  this->value |= ((other & 0x1) << 30);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_UF::InnerField_UF(unsigned int & value) :
  value(value) {

} // InnerField_UF()

core_microblaze_lt::Reg32_3::InnerField_UF::~InnerField_UF() {

} // ~InnerField_UF()

InnerField & core_microblaze_lt::Reg32_3::InnerField_DZ::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xefffffff;
  this->value |= ((other & 0x1) << 28);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_DZ::InnerField_DZ(unsigned int & value) :
  value(value) {

} // InnerField_DZ()

core_microblaze_lt::Reg32_3::InnerField_DZ::~InnerField_DZ() {

} // ~InnerField_DZ()

InnerField & core_microblaze_lt::Reg32_3::InnerField_IO::operator =(const
  unsigned int & other) throw() {
  this->value &= 0xf7ffffff;
  this->value |= ((other & 0x1) << 27);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_IO::InnerField_IO(unsigned int & value) :
  value(value) {

} // InnerField_IO()

core_microblaze_lt::Reg32_3::InnerField_IO::~InnerField_IO() {

} // ~InnerField_IO()

InnerField & core_microblaze_lt::Reg32_3::InnerField_DO::operator =(const
  unsigned int & other) throw() {
  this->value &= 0x7fffffff;
  this->value |= ((other & 0x1) << 31);
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_DO::InnerField_DO(unsigned int & value) :
  value(value) {

} // InnerField_DO()

core_microblaze_lt::Reg32_3::InnerField_DO::~InnerField_DO() {

} // ~InnerField_DO()

InnerField & core_microblaze_lt::Reg32_3::InnerField_Empty::operator =(const
  unsigned int & other) throw() {
  return *this;
} // operator =()

core_microblaze_lt::Reg32_3::InnerField_Empty::InnerField_Empty() {

} // InnerField_Empty()

core_microblaze_lt::Reg32_3::InnerField_Empty::~InnerField_Empty() {

} // ~InnerField_Empty()

void core_microblaze_lt::Reg32_3::immediateWrite(const unsigned int & value) throw() {
  this->value = value;
} // immediateWrite()

unsigned int core_microblaze_lt::Reg32_3::readNewValue() throw() {
  return this->value;
} // readNewValue()

unsigned int core_microblaze_lt::Reg32_3::operator ~() throw() {
  return ~(this->value);
} // operator ~()

Reg32_3 & core_microblaze_lt::Reg32_3::operator =(const unsigned int & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_3 & core_microblaze_lt::Reg32_3::operator +=(const unsigned int & other)
  throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator -=(const unsigned int & other)
  throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator *=(const unsigned int & other)
  throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator /=(const unsigned int & other)
  throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator |=(const unsigned int & other)
  throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator &=(const unsigned int & other)
  throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator ^=(const unsigned int & other)
  throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator <<=(const unsigned int & other)
  throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator >>=(const unsigned int & other)
  throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_3::operator +(const Reg32_3 & other)
  const throw() {
  return (this->value + other.value);
} // operator +()

unsigned int core_microblaze_lt::Reg32_3::operator -(const Reg32_3 & other)
  const throw() {
  return (this->value - other.value);
} // operator -()

unsigned int core_microblaze_lt::Reg32_3::operator *(const Reg32_3 & other)
  const throw() {
  return (this->value * other.value);
} // operator *()

unsigned int core_microblaze_lt::Reg32_3::operator /(const Reg32_3 & other)
  const throw() {
  return (this->value / other.value);
} // operator /()

unsigned int core_microblaze_lt::Reg32_3::operator |(const Reg32_3 & other)
  const throw() {
  return (this->value | other.value);
} // operator |()

unsigned int core_microblaze_lt::Reg32_3::operator &(const Reg32_3 & other)
  const throw() {
  return (this->value & other.value);
} // operator &()

unsigned int core_microblaze_lt::Reg32_3::operator ^(const Reg32_3 & other)
  const throw() {
  return (this->value ^ other.value);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_3::operator <<(const Reg32_3 & other)
  const throw() {
  return (this->value << other.value);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_3::operator >>(const Reg32_3 & other)
  const throw() {
  return (this->value >> other.value);
} // operator >>()

bool core_microblaze_lt::Reg32_3::operator <(const Reg32_3 & other) const throw() {
  return (this->value < other.value);
} // operator <()

bool core_microblaze_lt::Reg32_3::operator >(const Reg32_3 & other) const throw() {
  return (this->value > other.value);
} // operator >()

bool core_microblaze_lt::Reg32_3::operator <=(const Reg32_3 & other) const throw() {
  return (this->value <= other.value);
} // operator <=()

bool core_microblaze_lt::Reg32_3::operator >=(const Reg32_3 & other) const throw() {
  return (this->value >= other.value);
} // operator >=()

bool core_microblaze_lt::Reg32_3::operator ==(const Reg32_3 & other) const throw() {
  return (this->value == other.value);
} // operator ==()

bool core_microblaze_lt::Reg32_3::operator !=(const Reg32_3 & other) const throw() {
  return (this->value != other.value);
} // operator !=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator =(const Reg32_3 & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_3 & core_microblaze_lt::Reg32_3::operator +=(const Reg32_3 & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator -=(const Reg32_3 & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator *=(const Reg32_3 & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator /=(const Reg32_3 & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator |=(const Reg32_3 & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator &=(const Reg32_3 & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator ^=(const Reg32_3 & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator <<=(const Reg32_3 & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator >>=(const Reg32_3 & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg32_3::operator +(const Register & other)
  const throw() {
  return (this->value + other);
} // operator +()

unsigned int core_microblaze_lt::Reg32_3::operator -(const Register & other)
  const throw() {
  return (this->value - other);
} // operator -()

unsigned int core_microblaze_lt::Reg32_3::operator *(const Register & other)
  const throw() {
  return (this->value * other);
} // operator *()

unsigned int core_microblaze_lt::Reg32_3::operator /(const Register & other)
  const throw() {
  return (this->value / other);
} // operator /()

unsigned int core_microblaze_lt::Reg32_3::operator |(const Register & other)
  const throw() {
  return (this->value | other);
} // operator |()

unsigned int core_microblaze_lt::Reg32_3::operator &(const Register & other)
  const throw() {
  return (this->value & other);
} // operator &()

unsigned int core_microblaze_lt::Reg32_3::operator ^(const Register & other)
  const throw() {
  return (this->value ^ other);
} // operator ^()

unsigned int core_microblaze_lt::Reg32_3::operator <<(const Register & other)
  const throw() {
  return (this->value << other);
} // operator <<()

unsigned int core_microblaze_lt::Reg32_3::operator >>(const Register & other)
  const throw() {
  return (this->value >> other);
} // operator >>()

bool core_microblaze_lt::Reg32_3::operator <(const Register & other) const throw() {
  return (this->value < other);
} // operator <()

bool core_microblaze_lt::Reg32_3::operator >(const Register & other) const throw() {
  return (this->value > other);
} // operator >()

bool core_microblaze_lt::Reg32_3::operator <=(const Register & other) const throw() {
  return (this->value <= other);
} // operator <=()

bool core_microblaze_lt::Reg32_3::operator >=(const Register & other) const throw() {
  return (this->value >= other);
} // operator >=()

bool core_microblaze_lt::Reg32_3::operator ==(const Register & other) const throw() {
  return (this->value == other);
} // operator ==()

bool core_microblaze_lt::Reg32_3::operator !=(const Register & other) const throw() {
  return (this->value != other);
} // operator !=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator =(const Register & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg32_3 & core_microblaze_lt::Reg32_3::operator +=(const Register & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator -=(const Register & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator *=(const Register & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator /=(const Register & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator |=(const Register & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator &=(const Register & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator ^=(const Register & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator <<=(const Register & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg32_3 & core_microblaze_lt::Reg32_3::operator >>=(const Register & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Reg32_3::operator <<(std::ostream & stream)
  const throw() {
  stream << std::hex << std::showbase << this->value << std::dec;
  return stream;
} // operator <<()

core_microblaze_lt::Reg32_3::Reg32_3() :
  field_OF(this->value),
  field_UF(this->value),
  field_DZ(this->value),
  field_IO(this->value),
  field_DO(this->value) {
  this->value = 0;
} // Reg32_3()

InnerField & core_microblaze_lt::Reg1_0::InnerField_Empty::operator =(const
  unsigned int & other) throw() {
  return *this;
} // operator =()

core_microblaze_lt::Reg1_0::InnerField_Empty::InnerField_Empty() {

} // InnerField_Empty()

core_microblaze_lt::Reg1_0::InnerField_Empty::~InnerField_Empty() {

} // ~InnerField_Empty()

void core_microblaze_lt::Reg1_0::immediateWrite(const unsigned int & value) throw() {
  this->value = value;
} // immediateWrite()

unsigned int core_microblaze_lt::Reg1_0::readNewValue() throw() {
  return this->value;
} // readNewValue()

unsigned int core_microblaze_lt::Reg1_0::operator ~() throw() {
  return ~(this->value);
} // operator ~()

Reg1_0 & core_microblaze_lt::Reg1_0::operator =(const unsigned int & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg1_0 & core_microblaze_lt::Reg1_0::operator +=(const unsigned int & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator -=(const unsigned int & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator *=(const unsigned int & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator /=(const unsigned int & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator |=(const unsigned int & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator &=(const unsigned int & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator ^=(const unsigned int & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator <<=(const unsigned int & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator >>=(const unsigned int & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg1_0::operator +(const Reg1_0 & other) const
  throw() {
  return (this->value + other.value);
} // operator +()

unsigned int core_microblaze_lt::Reg1_0::operator -(const Reg1_0 & other) const
  throw() {
  return (this->value - other.value);
} // operator -()

unsigned int core_microblaze_lt::Reg1_0::operator *(const Reg1_0 & other) const
  throw() {
  return (this->value * other.value);
} // operator *()

unsigned int core_microblaze_lt::Reg1_0::operator /(const Reg1_0 & other) const
  throw() {
  return (this->value / other.value);
} // operator /()

unsigned int core_microblaze_lt::Reg1_0::operator |(const Reg1_0 & other) const
  throw() {
  return (this->value | other.value);
} // operator |()

unsigned int core_microblaze_lt::Reg1_0::operator &(const Reg1_0 & other) const
  throw() {
  return (this->value & other.value);
} // operator &()

unsigned int core_microblaze_lt::Reg1_0::operator ^(const Reg1_0 & other) const
  throw() {
  return (this->value ^ other.value);
} // operator ^()

unsigned int core_microblaze_lt::Reg1_0::operator <<(const Reg1_0 & other) const
  throw() {
  return (this->value << other.value);
} // operator <<()

unsigned int core_microblaze_lt::Reg1_0::operator >>(const Reg1_0 & other) const
  throw() {
  return (this->value >> other.value);
} // operator >>()

bool core_microblaze_lt::Reg1_0::operator <(const Reg1_0 & other) const throw() {
  return (this->value < other.value);
} // operator <()

bool core_microblaze_lt::Reg1_0::operator >(const Reg1_0 & other) const throw() {
  return (this->value > other.value);
} // operator >()

bool core_microblaze_lt::Reg1_0::operator <=(const Reg1_0 & other) const throw() {
  return (this->value <= other.value);
} // operator <=()

bool core_microblaze_lt::Reg1_0::operator >=(const Reg1_0 & other) const throw() {
  return (this->value >= other.value);
} // operator >=()

bool core_microblaze_lt::Reg1_0::operator ==(const Reg1_0 & other) const throw() {
  return (this->value == other.value);
} // operator ==()

bool core_microblaze_lt::Reg1_0::operator !=(const Reg1_0 & other) const throw() {
  return (this->value != other.value);
} // operator !=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator =(const Reg1_0 & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg1_0 & core_microblaze_lt::Reg1_0::operator +=(const Reg1_0 & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator -=(const Reg1_0 & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator *=(const Reg1_0 & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator /=(const Reg1_0 & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator |=(const Reg1_0 & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator &=(const Reg1_0 & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator ^=(const Reg1_0 & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator <<=(const Reg1_0 & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator >>=(const Reg1_0 & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

unsigned int core_microblaze_lt::Reg1_0::operator +(const Register & other)
  const throw() {
  return (this->value + other);
} // operator +()

unsigned int core_microblaze_lt::Reg1_0::operator -(const Register & other)
  const throw() {
  return (this->value - other);
} // operator -()

unsigned int core_microblaze_lt::Reg1_0::operator *(const Register & other)
  const throw() {
  return (this->value * other);
} // operator *()

unsigned int core_microblaze_lt::Reg1_0::operator /(const Register & other)
  const throw() {
  return (this->value / other);
} // operator /()

unsigned int core_microblaze_lt::Reg1_0::operator |(const Register & other)
  const throw() {
  return (this->value | other);
} // operator |()

unsigned int core_microblaze_lt::Reg1_0::operator &(const Register & other)
  const throw() {
  return (this->value & other);
} // operator &()

unsigned int core_microblaze_lt::Reg1_0::operator ^(const Register & other)
  const throw() {
  return (this->value ^ other);
} // operator ^()

unsigned int core_microblaze_lt::Reg1_0::operator <<(const Register & other)
  const throw() {
  return (this->value << other);
} // operator <<()

unsigned int core_microblaze_lt::Reg1_0::operator >>(const Register & other)
  const throw() {
  return (this->value >> other);
} // operator >>()

bool core_microblaze_lt::Reg1_0::operator <(const Register & other) const throw() {
  return (this->value < other);
} // operator <()

bool core_microblaze_lt::Reg1_0::operator >(const Register & other) const throw() {
  return (this->value > other);
} // operator >()

bool core_microblaze_lt::Reg1_0::operator <=(const Register & other) const throw() {
  return (this->value <= other);
} // operator <=()

bool core_microblaze_lt::Reg1_0::operator >=(const Register & other) const throw() {
  return (this->value >= other);
} // operator >=()

bool core_microblaze_lt::Reg1_0::operator ==(const Register & other) const throw() {
  return (this->value == other);
} // operator ==()

bool core_microblaze_lt::Reg1_0::operator !=(const Register & other) const throw() {
  return (this->value != other);
} // operator !=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator =(const Register & other) throw() {
  this->value = other;
  return *this;
} // operator =()

Reg1_0 & core_microblaze_lt::Reg1_0::operator +=(const Register & other) throw() {
  this->value += other;
  return *this;
} // operator +=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator -=(const Register & other) throw() {
  this->value -= other;
  return *this;
} // operator -=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator *=(const Register & other) throw() {
  this->value *= other;
  return *this;
} // operator *=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator /=(const Register & other) throw() {
  this->value /= other;
  return *this;
} // operator /=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator |=(const Register & other) throw() {
  this->value |= other;
  return *this;
} // operator |=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator &=(const Register & other) throw() {
  this->value &= other;
  return *this;
} // operator &=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator ^=(const Register & other) throw() {
  this->value ^= other;
  return *this;
} // operator ^=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator <<=(const Register & other) throw() {
  this->value <<= other;
  return *this;
} // operator <<=()

Reg1_0 & core_microblaze_lt::Reg1_0::operator >>=(const Register & other) throw() {
  this->value >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Reg1_0::operator <<(std::ostream & stream)
  const throw() {
  stream << std::hex << std::showbase << this->value << std::dec;
  return stream;
} // operator <<()

core_microblaze_lt::Reg1_0::Reg1_0() {
  this->value = 0;
} // Reg1_0()


