// vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 :
/// @addtogroup emc2quadcopter
/// @{
/// @file commitregister.cpp
///
///
/// @date 2016-
/// @copyright All rights reserved.
///            Any reproduction, use, distribution or disclosure of this
///            program, without the express, prior written consent of the
///            authors is strictly prohibited.
/// @author Rolf Meyer
///

#include "models/commitregister/commitregister.h"
#include "core/common/sr_registry.h"
#include <string>

SR_HAS_MODULE(CommitRegister);

// Constructor: create all members, registers and Counter objects.
// Store configuration default value in conf_defaults.
CommitRegister::CommitRegister(ModuleName name,
  uint16_t pindex,
  uint16_t paddr,
  uint16_t pmask) :
  APBSlave(name, pindex, 0x1, 0x00C, 1, 0, APBIO, pmask, false, false, paddr),
  commit("commit"),
  m_nregisters(4) {

  srInfo("/configuration/commitregister/apbslave")
     ("addr", (uint64_t)apb.get_base_addr())
     ("size", (uint64_t)apb.get_size())
     ("APB Slave Configuration");

  init_registers();

  /*srInfo()
    ("pindex", pindex)
    ("paddr", paddr)
    ("pmask", pmask)
    ("An CommitRegister is created with these generics");*/
}

// Destructor: Unregister Register Callbacks.
// Destroy all Counter objects.
CommitRegister::~CommitRegister() {
  GC_UNREGISTER_CALLBACKS();
}

void CommitRegister::init_generics() {
}

void CommitRegister::init_registers() {
  /* create register */
  r.create_register("commit", "Do data commit",
    0,                                                              // offset
    0,                                                              // init value
    0x00000001)                                                     // write mask
  .callback(SR_POST_WRITE, this, &CommitRegister::commit_write);

  for(uint32_t reg = 0; reg < m_nregisters; ++reg) {
    r.create_register(gen_unique_name("data", true), "Data Register",
      ((1+reg)<<2), 0, 0);
  }
}

void CommitRegister::commit_write() {
  for(uint32_t reg = 0; reg<m_nregisters;++reg) {
    commit.write(std::pair<uint32_t, uint32_t>(reg, r[((1+reg)<<2)]));
  }
//  r[i]
}

void CommitRegister::dorst() {
}

void CommitRegister::before_end_of_elaboration() {
}

/// @}

