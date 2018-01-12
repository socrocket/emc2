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

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <sstream>

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
 * @brief Exceptions
 */
class annul_exception : public std::runtime_error {
  public:
  annul_exception() : std::runtime_error("") {}
  annul_exception(const char* message) : std::runtime_error(message) {}
}; // class annul_exception

/// ****************************************************************************

/**
 * @brief Logging
 */
enum LogLevel {
  EXCEPTION,
  ERROR,
  WARNING,
  INFO,
  TRACE
};

inline std::ostream& operator<<(std::ostream& os, const LogLevel level) {
  static const char* const level_str[] = {
    "EXCEPTION",
    "ERROR",
    "WARNING",
    "INFO",
    "TRACE"};
  return os << level_str[(unsigned)level];
}

class Log {
  public:
  Log() {}
  ~Log() {
    *os << std::endl;
  }

  private:
  Log(const Log&);
  Log& operator=(const Log&);

  public:
  static void set_level(LogLevel level_) { level = level_; }

  static LogLevel& get_level() { return level; }

  static void set_stream(std::ostream& os_) { os = &os_; }

  static std::ostream& get_stream(LogLevel level, const char *file_, int line_) {
    *os << "[" << level << "]: " << file_ << ':' << line_ << ": ";
    return *os;
  }

  protected:
  static LogLevel level;
  static std::ostream* os;
}; // class Log

#define LOG(level) \
  if (level <= trap::Log::get_level()) \
    trap::Log().get_stream(level, __FILE__, __LINE__)

#define THROW_WARNING(msg) \
  if (trap::WARNING <= trap::Log::get_level()) \
    trap::Log().get_stream(trap::WARNING, __FILE__, __LINE__);

} // namespace trap

/// ****************************************************************************

namespace trap {
inline void throw_error_helper(std::string message){
    std::cerr << message << std::endl;
    ::exit(0);
}

inline void throw_exception_helper(std::string message){
    throw std::runtime_error(message);
}
}

#ifndef __GNUC__
#ifndef __PRETTY_FUNCTION__
#ifdef __FUNCDNAME__
#define __PRETTY_FUNCTION__ __FUNCDNAME__
#else
#define __PRETTY_FUNCTION__ "NONAME"
#endif
#endif
#endif

#ifdef MAKE_STRING
#undef MAKE_STRING
#endif
#define MAKE_STRING(msg)  (((std::ostringstream &)((std::ostringstream() << '\x0') << msg)).str().substr(1))

#ifdef THROW_EXCEPTION
#undef THROW_EXCEPTION
#endif
#define THROW_EXCEPTION(msg) (trap::throw_exception_helper(MAKE_STRING("At: function " << __PRETTY_FUNCTION__ << \
  " file: " << __FILE__ << ":" << __LINE__ << " --> " << msg)))

#ifdef THROW_ERROR
#undef THROW_ERROR
#endif
#define THROW_ERROR(msg) (trap::throw_error_helper(MAKE_STRING("At: function " << __PRETTY_FUNCTION__ << " file: " << \
  __FILE__ << ":" << __LINE__ << " --> " << msg << std::endl)))

#endif // TRAP_REPORT_HPP
