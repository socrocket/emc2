#!/usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 :
# @addtogroup platform
# @{
# @file sc_main.cpp
#
# @date 2010-2014
# @copyright All rights reserved.
#            Any reproduction, use, distribution or disclosure of this
#            program, without the express, prior written consent of the
#            authors is strictly prohibited.
# @author Rolf Meyer
import usi
from usi.shell import start as shell_start
from usi.systemc import NS as SC_NS
from sr_registry import module

shell_start()
usi.registry.api.load('./build/gaisler/libsr_gaisler.so')

def create_base(name):
    ahbctrl = module.AHBCtrl(name + "_ahbctrl",
        ioaddr = 0xFFF,    # The MSB address of the I/O area
        iomask = 0xFFF,    # The I/O area address mask
        cfgaddr = 0xFF0,   # The MSB address of the configuration area
        cfgmask = 0xFF0,   # The address mask for the configuration area
        rrobin = False,    # 1 - round robin, 0 - fixed priority arbitration (only AT)
        split = False,     # Enable support for AHB SPLIT response (only AT)
        defmast = 0,       # Default AHB master
        ioen = True,       # AHB I/O area enable
        fixbrst = False,   # Enable support for fixed-length bursts (disabled)
        fpnpen = True,     # Enable full decoding of PnP configuration records
        mcheck = True,     # Check if there are any intersections between core memory regions
    )

    apbctrl = module.APBCtrl(name + "_apbctrl",
        bar__0__haddr = 0x800,     # The 12 bit MSB address of the AHB area.
        bar__0__hmask = 0xFFF,     # The 12 bit AHB area address mask
        mcheck = True,     # Check for intersections in the memory map
        hindex = 2,        # AHB bus index
    )
    # Connect to AHB and clock
    ahbctrl.ahbOUT.socket_bind(apbctrl.ahb)

    irqmp = module.Irqmp(name + "_irqmp",
        paddr = 0x002,    # paddr PSiegl: SoCRocket default 0x1F0, try to mimic TSIM therefore 0x2
        pmask = 0xFFF,    # pmask
        ncpu = 1,         # ncpu
        eirq = 0,         # eirq
        pindex = 2,       # pindex
    )
    # Connect to APB and clock
    apbctrl.apb.socket_bind(irqmp.apb)

    ahbmem = module.AHBMem(name + "_ahbmem",
        bar__0__haddr = 0x400,
        bar__0__hmask = 0xE00,
        hindex = 1,
        cacheable = 1,
        wait_states = 0,
    )
    # Connect to ahbctrl and clock
    ahbctrl.ahbOUT.socket_bind(ahbmem.ahb)

    commitreg = module.CommitRegister(name + "_commitregister",
        pindex = 1,
        paddr = 0x001,
        pmask = 0xFFF
    )
    apbctrl.apb.socket_bind(commitreg.apb)

    return (ahbctrl, apbctrl, irqmp, ahbmem)

@usi.on('start_of_initialization')
def leon_system(*k, **kw):
    print " * Creating Leon 3 Subsystem:"
    ahbctrl, apbctrl, irqmp, ahbmem = create_base("leon")

    leon3 = module.Leon3("leon3_0", hindex = 0)
    # Connecting AHB Master
    leon3.ahb.socket_bind(ahbctrl.ahbIN)
    # Set clock
    leon3.snoop.signal_bind(ahbctrl.snoop)

    irqmp.cpu_req.signal_bind(leon3.cpu.IRQ_port.irq_signal, long(0))
    leon3.cpu.irqAck.ack.signal_bind(irqmp.irq_ack, long(0))
    leon3.cpu.irqAck.run.signal_bind(irqmp.cpu_rst, long(0))
    leon3.cpu.irqAck.status.signal_bind(irqmp.cpu_stat, long(0))

    reset = module.ResetIrqmp("leon_reset")
    irqmp.rst.signal_bind(reset.rst)

@usi.on('start_of_initialization')
def microblaze_system(*k, **kw):
    print " * Creating MicroBlaze Subsystem:"
    ahbctrl, apbctrl, irqmp, ahbmem = create_base("microblaze")

    microblaze = module.MicroBlaze("microblase_0", hindex = 0)
    # Connecting AHB Master
    microblaze.ahb.socket_bind(ahbctrl.ahbIN)
    # Set clock
    microblaze.snoop.signal_bind(ahbctrl.snoop)

    #irqmp.cpu_req.signal_bind(microblaze.cpu.IRQ_port.irq_signal, long(0))
    #microblaze.cpu.irqAck.ack.signal_bind(irqmp.irq_ack, long(0))
    #microblaze.cpu.irqAck.run.signal_bind(irqmp.cpu_rst, long(0))
    #microblaze.cpu.irqAck.status.signal_bind(irqmp.cpu_stat, long(0))

    reset = module.ResetIrqmp("microblaze_reset")
    irqmp.rst.signal_bind(reset.rst)

@usi.on('start_of_initialization')
def arm_system(*k, **kw):
    print " * Creating ARM Subsystem:"
    ahbctrl, apbctrl, irqmp, ahbmem = create_base("arm")

    arm = module.Leon3("arm_0", hindex = 0)
    # Connecting AHB Master
    arm.ahb.socket_bind(ahbctrl.ahbIN)
    # Set clock
    arm.snoop.signal_bind(ahbctrl.snoop)

    irqmp.cpu_req.signal_bind(arm.cpu.IRQ_port.irq_signal, long(0))
    arm.cpu.irqAck.ack.signal_bind(irqmp.irq_ack, long(0))
    arm.cpu.irqAck.run.signal_bind(irqmp.cpu_rst, long(0))
    arm.cpu.irqAck.status.signal_bind(irqmp.cpu_stat, long(0))

    reset = module.ResetIrqmp("arm_reset")
    irqmp.rst.signal_bind(reset.rst)

@usi.on('start_of_initialization')
def supervisor_system(*k, **kw):
    print " * Creating Supervisor Subsystem:"
    voter = module.Voter("voter",
        irq=4,       # Interuptline Used
        wdog=0xFFF   # CLK Cycles to hit
    )

    for idx, name in enumerate(["leon", "microblaze", "arm"]):
        commitreg = usi.find(name + "_commitregister")[0]
        irqmp = usi.find(name + "_irqmp")[0]
        voter.commit.signal_bind(commitreg.commit, idx)
        #voter.irq.socket_bind(irqmp.irq_in, 4)
        #voter.reset(name->rst) # ?????? or Subsystem reseter ???? or interrupt ???

    microblaze_reg = usi.find("microblaze_commitregister")[0]
    voter.commit.signal_bind(microblaze_reg.commit, 1)
    arm_reg = usi.find("arm_commitregister")[0]
    voter.commit.signal_bind(arm_reg.commit, 2)

    shell_start()
