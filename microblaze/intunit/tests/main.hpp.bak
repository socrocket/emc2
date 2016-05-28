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

#ifndef MICROBLAZE_CORE_FUNC_LT_MAIN_HPP
#define MICROBLAZE_CORE_FUNC_LT_MAIN_HPP



#include <boost/test/included/unit_test.hpp>
#include <systemc.h>


class trap_log_formatter : public ::boost::unit_test::output::compiler_log_formatter {
  public:
  void log_entry_value(
      std::ostream & output, ::boost::unit_test::const_string value);

}; // class trap_log_formatter

boost::unit_test::test_suite * init_unit_test_suite(
    int argc, char * argv[]);
/** @brief    Main Processor Component Testbench
*   @details
*   Uses the boost::test framework to call the tests defined in decoderTests
*   and isaTests*. Each test instantiates the required DUT submodules individually.
*/
int sc_main(
    int argc, char * * argv);


#endif
