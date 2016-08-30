// vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 :
/// @addtogroup emc2quadcopter
/// @{
/// @file voter.h
/// Class definition of multi-processor interrupt controller. (IRQMP).
///
/// @date 2016-
/// @copyright All rights reserved.
///            Any reproduction, use, distribution or disclosure of this
///            program, without the express, prior written consent of the
///            authors is strictly prohibited.
/// @author Rolf Meyer
///

#ifndef EMC2QUADCOPTER_MODELS_VOTER_VOTER_H_
#define EMC2QUADCOPTER_MODELS_VOTER_VOTER_H_

#include "core/base/systemc.h"
#include "core/base/base.h"
#include "core/common/sr_param.h"
#include "core/base/clkdevice.h"
#include "core/common/sr_signal.h"

#include <boost/config.hpp>
#include <stdint.h>
#include <utility>


class Voter : public BaseModule<>, public CLKDevice {
  public:
    SC_HAS_PROCESS(Voter);
    SR_HAS_SIGNALS(Voter);
    GC_HAS_CALLBACKS();

    signal<bool>::selector reset;
    signal<std::pair<uint32_t, bool> >::out irq;
    signal<std::pair<uint32_t,uint32_t> >::infield commit;

    sc_event e_signal;

    Voter(sc_module_name name,
    //  uint32_t systems = 3,
      uint32_t irq = 1,
      uint32_t wdog = 0xFF
    );

    ~Voter();

    // function prototypes
    /// Initialize the generics with meta data.
    ///
    /// Will ne called from the constructor.
    void init_generics();

    /// Automatically called at start of simulation
    void start_of_simulation();

    /// SystemC end of elaboration implementation
    void end_of_elaboration();

    /// SystemC end of simulation
    void end_of_simulation();

    void watchdog();

    void dorst();
    void incomming_commit(const std::pair<uint32_t, uint32_t> &value, const uint32_t &system, const sc_time &time);
    //sr_param<int> g_systems;
    sr_param<uint32_t> g_irq;
    sr_param<uint32_t> g_wdog;
    std::map<uint32_t, std::map<uint32_t, uint32_t> > m_values;
    const uint32_t m_systems;
};

#endif  // EMC2QUADCOPTER_MODELS_VOTER_VOTER_H_
/// @}

