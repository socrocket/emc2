// vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 :
/// @addtogroup emc2quadcopter
/// @{
/// @file voter.cpp
/// Implementation of multi-processor interrupt controller (IRQMP).
///
/// @date 2016-
/// @copyright All rights reserved.
///            Any reproduction, use, distribution or disclosure of this
///            program, without the express, prior written consent of the
///            authors is strictly prohibited.
/// @author Rolf Meyer
///

#include <string>
#include <utility>

#include "models/voter/voter.h"
#include "core/base/verbose.h"
#include "core/common/sr_registry.h"

SR_HAS_MODULE(Voter);

/// Constructor
Voter::Voter(ModuleName name,
  //uint32_t systems,
  uint32_t irq,
  uint32_t wdog) :
  BaseModule<>(name),
  reset("reset"),
  irq("irq"),
  commit(&Voter::incomming_commit, "commit"),
  //g_systems("systems", systems, m_generics),
  g_irq("irq", irq, m_generics),
  g_wdog("wdog", wdog, m_generics),
  m_systems(3)
  {

  init_generics(); 
  init_registers();

  SC_THREAD(watchdog);

  srInfo()
  //  ("systems", g_systems)
    ("irq", irq)
    ("wdog", wdog)
    ("Created an Irqmp with this parameters");
}

Voter::~Voter() {
}

void Voter::init_generics() {
  //g_systems.add_properties()
  //  ("name"," Number of Subsystems to Vote for")
  //  ("vhdl_name","systems")
  //  ("Needed to determ the number of comarrisons.");
    
  g_irq.add_properties()
    ("name","Interrupt Line")
    ("vhdl_name","irq")
    ("Number of the Interrupt Line used to signal subsystems that the vote is done.");
  g_wdog.add_properties()
    ("name","Clocksycles to reset")
    ("vhdl_name","wdog")
    ("Number of the Interrupt Line used to signal subsystems that the vote is done.");
}

// Automatically called at start of simulation
void Voter::start_of_simulation() {
}

void Voter::end_of_elaboration() {
}

// Print execution statistic at end of simulation
void Voter::end_of_simulation() {
}

void Voter::dorst() {
  // initialize registers with values defined above
  srInfo()("Do Reset");
  m_values.clear();
}

void Voter::incomming_commit(const std::pair<uint32_t, uint32_t> &value, const uint32_t &system, const sc_time &time) {
  m_values[system][value.first] = value.second;
}

void Voter::watchdog() {
  while (1) {
    e_signal.notify(g_wdog* get_clk());
    wait(e_signal);

    bool fes = m_values[0]==m_values[1];
    bool fet = m_values[0]==m_values[2];
    bool set = m_values[1]==m_values[2];
    uint32_t mask = 0;
    if(fes && fet && set) {
      // Everything OK
      mask = 0x0;
    } else if(!fes && !fet && !set) {
      // Alle unterscheidlich
      srWarn()("All three Systems calculated different values");
      mask = 0x7;
    } else if(fes) {
      // 3. Falsch
      srWarn()("System 2 Error");
      mask = 1 << 2;
    } else if(fet) {
      // 2. Falsch
      srWarn()("System 1 Error");
      mask = 1 << 1;
    } else if(set) {
      // 1. Falsch
      srWarn()("System 0 Error");
      mask = 1 << 0;
    }
    printf("\n%x (%d, %d, %d) #####################################################################\n", mask, m_values[0][0], m_values[1][0], m_values[2][0]);
    if(mask) {
      reset.write(0xF, false);
    }
    wait(get_clk());
    if(mask) {
      reset.write(0xF, true);
    }

    if(g_irq) {
      irq.write(std::make_pair(uint32_t(g_irq), true));
    }
    wait(get_clk());
    if(g_irq) {
      irq.write(std::make_pair(uint32_t(g_irq), false));
    }
  }
}

/// @}

