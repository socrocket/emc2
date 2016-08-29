// vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 :
/// @addtogroup emc2quadcopter
/// @{
/// @file commitregs.h
///
///
/// @date 2016
/// @copyright All rights reserved.
///            Any reproduction, use, distribution or disclosure of this
///            program, without the express, prior written consent of the
///            authors is strictly prohibited.
/// @author Rolf Meyer
///

#ifndef EMC2QUADCOPTER_MODELS_COMMITREGS_COMMITREGISTER_H_
#define EMC2QUADCOPTER_MODELS_COMMITREGS_COMMITREGISTER_H_

#include <greencontrol/all.h>
#include "core/common/systemc.h"
#include <string>
#include <vector>

#include "core/common/apbdevice.h"
#include "core/common/clkdevice.h"
#include "core/common/sr_signal.h"
#include "core/common/verbose.h"
#include "core/common/apbslave.h"

class CommitRegister : public APBSlave, public CLKDevice {
  public:
    SC_HAS_PROCESS(CommitRegister);
    SR_HAS_SIGNALS(CommitRegister);
    GC_HAS_CALLBACKS();

    signal<std::pair<uint32_t, uint32_t> >::out commit;

    CommitRegister(ModuleName name,  uint16_t pindex = 0, uint16_t paddr = 0, uint16_t pmask = 4095);

    /// Free all counter and unregister all callbacks.
    ~CommitRegister();
    void init_generics();
    void init_registers();

    void commit_write();
    virtual void dorst();
    void before_end_of_elaboration();
  private:
    const uint32_t m_nregisters;
};

#endif  // EMC2QUADCOPTER_MODELS_COMMITREGS_COMMITREGISTER_H_
/// @}

