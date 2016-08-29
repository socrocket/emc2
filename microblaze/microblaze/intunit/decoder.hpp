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

#ifndef MICROBLAZE_CORE_FUNC_LT_DECODER_HPP
#define MICROBLAZE_CORE_FUNC_LT_DECODER_HPP

#include "microblaze/intunit/instructions.hpp"




#define FUNC_MODEL
#define LT_IF
namespace core_microblaze_lt {

  class CacheElem {
    public:
    CacheElem();
    CacheElem(
        Instruction * instr, unsigned int count);
    Instruction * instr;
    unsigned int count;

  }; // class CacheElem

} // namespace core_microblaze_lt

namespace core_microblaze_lt {

  /** @brief    Decoder Class
  *   @details
  *   Implements the state-machine that decodes an instruction string and
  *   returns an ID specifying the instruction.
  */
  class Decoder {
    public:
    int decode(unsigned int instrCode) const throw();

  }; // class Decoder

} // namespace core_microblaze_lt



#endif
