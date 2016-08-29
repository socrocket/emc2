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


#include "microblaze/intunit/alias.hpp"
#include "microblaze/intunit/registers.hpp"


#include <ostream>
#include <list>


using namespace core_microblaze_lt;
void core_microblaze_lt::Alias::immediateWrite(const unsigned int & value) throw() {
  this->reg->immediateWrite(value);
} // immediateWrite()

unsigned int core_microblaze_lt::Alias::readNewValue() throw() {
  return this->reg->readNewValue();
} // readNewValue()

unsigned int core_microblaze_lt::Alias::operator ~() throw() {
  return ~(*this->reg + this->offset);
} // operator ~()

unsigned int core_microblaze_lt::Alias::operator +(const Alias & other) const throw() {
  return ((*this->reg + this->offset) + *other.reg);
} // operator +()

unsigned int core_microblaze_lt::Alias::operator -(const Alias & other) const throw() {
  return ((*this->reg + this->offset) - *other.reg);
} // operator -()

unsigned int core_microblaze_lt::Alias::operator *(const Alias & other) const throw() {
  return ((*this->reg + this->offset) * *other.reg);
} // operator *()

unsigned int core_microblaze_lt::Alias::operator /(const Alias & other) const throw() {
  return ((*this->reg + this->offset) / *other.reg);
} // operator /()

unsigned int core_microblaze_lt::Alias::operator |(const Alias & other) const throw() {
  return ((*this->reg + this->offset) | *other.reg);
} // operator |()

unsigned int core_microblaze_lt::Alias::operator &(const Alias & other) const throw() {
  return ((*this->reg + this->offset) & *other.reg);
} // operator &()

unsigned int core_microblaze_lt::Alias::operator ^(const Alias & other) const throw() {
  return ((*this->reg + this->offset) ^ *other.reg);
} // operator ^()

unsigned int core_microblaze_lt::Alias::operator <<(const Alias & other) const
  throw() {
  return ((*this->reg + this->offset) << *other.reg);
} // operator <<()

unsigned int core_microblaze_lt::Alias::operator >>(const Alias & other) const
  throw() {
  return ((*this->reg + this->offset) >> *other.reg);
} // operator >>()

Alias & core_microblaze_lt::Alias::operator =(const Alias & other) throw() {
  *this->reg = *other.reg;
  return *this;
} // operator =()

Alias & core_microblaze_lt::Alias::operator +=(const Alias & other) throw() {
  *this->reg += *other.reg;
  return *this;
} // operator +=()

Alias & core_microblaze_lt::Alias::operator -=(const Alias & other) throw() {
  *this->reg -= *other.reg;
  return *this;
} // operator -=()

Alias & core_microblaze_lt::Alias::operator *=(const Alias & other) throw() {
  *this->reg *= *other.reg;
  return *this;
} // operator *=()

Alias & core_microblaze_lt::Alias::operator /=(const Alias & other) throw() {
  *this->reg /= *other.reg;
  return *this;
} // operator /=()

Alias & core_microblaze_lt::Alias::operator |=(const Alias & other) throw() {
  *this->reg |= *other.reg;
  return *this;
} // operator |=()

Alias & core_microblaze_lt::Alias::operator &=(const Alias & other) throw() {
  *this->reg &= *other.reg;
  return *this;
} // operator &=()

Alias & core_microblaze_lt::Alias::operator ^=(const Alias & other) throw() {
  *this->reg ^= *other.reg;
  return *this;
} // operator ^=()

Alias & core_microblaze_lt::Alias::operator <<=(const Alias & other) throw() {
  *this->reg <<= *other.reg;
  return *this;
} // operator <<=()

Alias & core_microblaze_lt::Alias::operator >>=(const Alias & other) throw() {
  *this->reg >>= *other.reg;
  return *this;
} // operator >>=()

bool core_microblaze_lt::Alias::operator <(const Register & other) const throw() {
  return ((*this->reg + this->offset) < other);
} // operator <()

bool core_microblaze_lt::Alias::operator >(const Register & other) const throw() {
  return ((*this->reg + this->offset) > other);
} // operator >()

bool core_microblaze_lt::Alias::operator <=(const Register & other) const throw() {
  return ((*this->reg + this->offset) <= other);
} // operator <=()

bool core_microblaze_lt::Alias::operator >=(const Register & other) const throw() {
  return ((*this->reg + this->offset) >= other);
} // operator >=()

bool core_microblaze_lt::Alias::operator ==(const Register & other) const throw() {
  return ((*this->reg + this->offset) == other);
} // operator ==()

bool core_microblaze_lt::Alias::operator !=(const Register & other) const throw() {
  return ((*this->reg + this->offset) != other);
} // operator !=()

Alias & core_microblaze_lt::Alias::operator =(const Register & other) throw() {
  *this->reg = other;
  return *this;
} // operator =()

Alias & core_microblaze_lt::Alias::operator +=(const Register & other) throw() {
  *this->reg += other;
  return *this;
} // operator +=()

Alias & core_microblaze_lt::Alias::operator -=(const Register & other) throw() {
  *this->reg -= other;
  return *this;
} // operator -=()

Alias & core_microblaze_lt::Alias::operator *=(const Register & other) throw() {
  *this->reg *= other;
  return *this;
} // operator *=()

Alias & core_microblaze_lt::Alias::operator /=(const Register & other) throw() {
  *this->reg /= other;
  return *this;
} // operator /=()

Alias & core_microblaze_lt::Alias::operator |=(const Register & other) throw() {
  *this->reg |= other;
  return *this;
} // operator |=()

Alias & core_microblaze_lt::Alias::operator &=(const Register & other) throw() {
  *this->reg &= other;
  return *this;
} // operator &=()

Alias & core_microblaze_lt::Alias::operator ^=(const Register & other) throw() {
  *this->reg ^= other;
  return *this;
} // operator ^=()

Alias & core_microblaze_lt::Alias::operator <<=(const Register & other) throw() {
  *this->reg <<= other;
  return *this;
} // operator <<=()

Alias & core_microblaze_lt::Alias::operator >>=(const Register & other) throw() {
  *this->reg >>= other;
  return *this;
} // operator >>=()

std::ostream & core_microblaze_lt::Alias::operator <<(std::ostream & stream)
  const throw() {
  stream << *this->reg + this->offset;
  return stream;
} // operator <<()

void core_microblaze_lt::Alias::directSetAlias(Alias & newAlias) throw() {
  this->reg = newAlias.reg;
  this->offset = newAlias.offset;
  if (this->referringAliases != NULL) {
    this->referringAliases->referredAliases.remove(this);
  }
  this->referringAliases = &newAlias;
  newAlias.referredAliases.push_back(this);
} // directSetAlias()

void core_microblaze_lt::Alias::directSetAlias(Register & newAlias) throw() {
  this->reg = &newAlias;
  if (this->referringAliases != NULL) {
    this->referringAliases->referredAliases.remove(this);
  }
  this->referringAliases = NULL;
} // directSetAlias()

core_microblaze_lt::Alias::Alias(
    Register * reg,
    unsigned int offset) :
  reg(reg),
  offset(offset),
  defaultOffset(0) {
  this->referringAliases = NULL;
} // Alias()

core_microblaze_lt::Alias::Alias() :
  offset(0),
  defaultOffset(0) {
  this->referringAliases = NULL;
} // Alias()

core_microblaze_lt::Alias::Alias(
    Alias * initAlias,
    unsigned int offset) :
  reg(initAlias->reg),
  offset(initAlias->offset + offset),
  defaultOffset(offset) {
  initAlias->referredAliases.push_back(this);
  this->referringAliases = initAlias;
} // Alias()

core_microblaze_lt::Alias::~Alias() {
  std::list<Alias *>::iterator referredIter, referredEnd;
  for (referredIter = this->referredAliases.begin(), referredEnd = this->referredAliases.end();
    referredIter != referredEnd; referredIter++) {
    if ((*referredIter)->referringAliases == this) {
      (*referredIter)->referringAliases = NULL;
    }
  }
  if (this->referringAliases != NULL) {
    this->referringAliases->referredAliases.remove(this);
  }
  this->referringAliases = NULL;
} // ~Alias()


