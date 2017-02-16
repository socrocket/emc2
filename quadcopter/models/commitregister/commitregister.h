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
#include "core/base/systemc.h"
#include "core/base/verbose.h"

#include "core/common/sr_signal.h"
#include "core/base/clkdevice.h"
#include "amba/apbdevice.h"
#include "amba/apbslave.h"

#include <string>
#include <vector>

class CommitRegister : public APBSlave, public CLKDevice {
  public:
    SC_HAS_PROCESS(CommitRegister);
    SR_HAS_SIGNALS(CommitRegister);
    GC_HAS_CALLBACKS();

    signal<std::pair<uint32_t, uint32_t> >::out commit;

    CommitRegister(ModuleName name,  uint16_t pindex = 0, uint16_t paddr = 0, uint16_t pmask = 4095, uint32_t id = 0);

    /// Free all counter and unregister all callbacks.
    ~CommitRegister();
    void init_generics();
    void init_registers();

    void commit_write();
    void commit_read();
    virtual void dorst();
    void before_end_of_elaboration();
  private:
    const uint32_t m_nregisters;
    sr_param<uint32_t> m_id;
};

#endif  // EMC2QUADCOPTER_MODELS_COMMITREGS_COMMITREGISTER_H_
/// @}

