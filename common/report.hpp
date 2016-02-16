/***************************************************************************//**
*
*  _/_/_/_/_/  _/_/_/           _/        _/_/_/
*     _/      _/    _/        _/_/       _/    _/
*    _/      _/    _/       _/  _/      _/    _/
*   _/      _/_/_/        _/_/_/_/     _/_/_/
*  _/      _/    _/     _/      _/    _/
* _/      _/      _/  _/        _/   _/
*
* @file     report.hpp
* @brief    This file is part of the TRAP runtime library.
* @details
* @author   Luca Fossati
* @author   Lillian Tadros (Technische Universitaet Dortmund)
* @date     2008-2013 Luca Fossati
*           2015-2016 Technische Universitaet Dortmund
* @copyright
*
* This file is part of TRAP.
*
* TRAP is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation; either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
* or see <http://www.gnu.org/licenses/>.
*
* (c) Luca Fossati, fossati@elet.polimi.it, fossati.l@gmail.com
*
*******************************************************************************/
#ifndef TRAP_REPORT_HPP
#define TRAP_REPORT_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <stdexcept>

#ifndef __GNUC__
#ifndef __PRETTY_FUNCTION__
#ifdef __FUNCDNAME__
#define __PRETTY_FUNCTION__ __FUNCDNAME__
#else
#define __PRETTY_FUNCTION__ "NONAME"
#endif
#endif
#endif

namespace trap {

/**
 * @brief MemAccessType
 */
struct MemAccessType {
  double simulation_time;
  unsigned program_counter;
  unsigned address;
  char val;
}; // struct MemAccessType

/// ****************************************************************************

/**
 * @brief annul_exception
 */
class annul_exception : public std::runtime_error {
  public:
  annul_exception() : std::runtime_error("") {}
  annul_exception(const char* message) : std::runtime_error(message) {}
}; // class annul_exception

/// ****************************************************************************

#ifdef MAKE_STRING
#undef MAKE_STRING
#endif
#define MAKE_STRING(msg) (((std::ostringstream&)((std::ostringstream() << '\x0') << msg)).str().substr(1))

/// ****************************************************************************

/**
 * @brief throw_exception_helper
 */
void throw_exception_helper(std::string message);

#ifdef THROW_EXCEPTION
#undef THROW_EXCEPTION
#endif
#define THROW_EXCEPTION(msg) (trap::throw_exception_helper(MAKE_STRING("At function " << __PRETTY_FUNCTION__ << \
  ", file " << __FILE__ << ":" << __LINE__ << ": " << msg)))

/// ****************************************************************************

/**
 * @brief throw_error_helper
 */
void throw_error_helper(std::string message);

#ifdef THROW_ERROR
#undef THROW_ERROR
#endif
#define THROW_ERROR(msg) (trap::throw_error_helper(MAKE_STRING("At function " << __PRETTY_FUNCTION__ << ", file " << \
  __FILE__ << ":" << __LINE__ << ": " << msg << std::endl)))

} // namespace trap

/// ****************************************************************************
#endif // TRAP_REPORT_HPP
