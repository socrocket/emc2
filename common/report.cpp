/***************************************************************************//**
*
*  _/_/_/_/_/  _/_/_/           _/        _/_/_/
*     _/      _/    _/        _/_/       _/    _/
*    _/      _/    _/       _/  _/      _/    _/
*   _/      _/_/_/        _/_/_/_/     _/_/_/
*  _/      _/    _/     _/      _/    _/
* _/      _/      _/  _/        _/   _/
*
* @file     report.cpp
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
#include "report.hpp"

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
//#ifdef __GNUC__
//extern "C" {
//#include <execinfo.h>
//}
//#endif

/**
 * @brief throw_exception_helper()
 */
void trap::throw_exception_helper(std::string message) {
  throw std::runtime_error(message);
}

/// ****************************************************************************

/**
 * @brief throw_error_helper()
 */
void trap::throw_error_helper(std::string message) {
  std::cerr << message << std::endl;
  ::exit(0);
}

/*#ifdef __GNUC__
void throw_exception_helper(std::string message) {
  void* array[25];
  int n_size = backtrace(array, 25);
  char** symbols = backtrace_symbols(array, n_size);
  std::ostringstream trace_os;

  if (symbols != NULL) {
    for (int i = 0; i < n_size; i++) {
      trace_os << symbols[i] << std::endl;
    }
    trace_os << std::endl;
    free(symbols);
  }
  trace_os << message;

  throw std::runtime_error(trace_os.str());
}
#else
void throw_exception_helper(std::string message) {
  throw std::runtime_error(message);
}
#endif*/
