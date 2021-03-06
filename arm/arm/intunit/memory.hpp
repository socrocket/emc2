/***************************************************************************//**
*
*           _/       _/_/_/      _/         _/
*         _/_/      _/    _/    _/_/      __/
*       _/  _/     _/    _/    _/ _/    _/_/
*     _/_/_/_/    _/_/_/      _/  _/  _/ _/
*   _/      _/   _/    _/    _/   _/_/  _/
* _/        _/  _/      _/  _/    _/   _/
*
* @brief    This file is part of the SoCRocket ARM ISS generated by TRAP.
* @details  This SystemC model was automatically generated by running
*           $ python ARMArch.py
*           Please refer to the ARM TRAP source files for documentation.
* @author   Lillian Tadros (Technische Universitaet Dortmund)
* @date     2015-2016 Technische Universitaet Dortmund
*
*
* (c) 2014-2016
* Technische Universitaet Dortmund
* Institut fuer Roboterforschung
* Project Embedded Multi-Core Systems for Mixed Criticality
* Applications in Dynamic and Changeable Real-time Environments (EMC2)
*
*
* This file is part of ARMCortexA9.
*
* ARMCortexA9 is free software; you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation; either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#ifndef CORE_ARMCORTEXA9_FUNC_LT_MEMORY_HPP
#define CORE_ARMCORTEXA9_FUNC_LT_MEMORY_HPP

#include "arm/arm/mmucache/cpu_if.h"

#include <systemc.h>
#include <common/tools_if.hpp>
#include <common/report.hpp>


#define FUNC_MODEL
#define LT_IF

using namespace trap;

namespace core_armcortexa9_funclt {

class MemoryInterface : public cpu_if {};
typedef MemoryInterface LocalMemory;

} // namespace core_armcortexa9_funclt

#endif // CORE_ARMCORTEXA9_FUNC_LT_MEMORY_HPP
