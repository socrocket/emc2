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
import sys
import usi
from usi.shell import start as shell_start
from usi.systemc import NS as SC_NS
from sr_registry import module
from usi.sc_module import USIModule
from usi.tools import elf

usi.registry.load('./build/gaisler/libsr_gaisler.so')
usi.registry.load('./build/microblaze/libsr_microblaze.so')
usi.registry.load('./build/arm/libsr_arm.so')
usi.registry.load('./build/quadcopter/libsr_quadcopter.so')

class BaseSystem(USIModule):
    def __init__(self, name):
        self.ahbctrl = module.AHBCtrl("ahbctrl",
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

        self.apbctrl = module.APBCtrl("apbctrl",
            bar__0__haddr = 0x800,     # The 12 bit MSB address of the AHB area.
            bar__0__hmask = 0xFFF,     # The 12 bit AHB area address mask
            mcheck = True,     # Check for intersections in the memory map
            hindex = self.slave_id(),        # AHB bus index
        )
        # Connect to AHB and clock
        self.ahbctrl.ahbOUT.socket_bind(self.apbctrl.ahb)

        self.irqmp = module.Irqmp("irqmp",
            paddr = 0x002,    # paddr PSiegl: SoCRocket default 0x1F0, try to mimic TSIM therefore 0x2
            pmask = 0xFFF,    # pmask
            ncpu = 1,         # ncpu
            eirq = 0,         # eirq
            pindex = self.apb_id(),       # pindex
        )
        # Connect to APB and clock
        self.apbctrl.apb.socket_bind(self.irqmp.apb)

        self.apbuart = module.APBUART("apbuart",
            backend = "ReportIO",
            pindex = self.apb_id(),
            paddr = 0x001,
            pmask = 0xFFF,
            pirq = 2,
        #    power = power_mon
        )

        # Connecting APB Slave
        self.apbctrl.apb.socket_bind(self.apbuart.apb)
        # Connecting Interrupts
        self.irqmp.irq_in.signal_bind(self.apbuart.irq, 2)
        # Set clock
        #apbuart.set_clk(clk, SC_NS)

        self.apbuart = module.APBUART("apbuart1",
            backend = "ReportIO",
            pindex = self.apb_id(),
            paddr = 0x009,
            pmask = 0xFFF,
            pirq = 3,
        #    power = power_mon
        )

        # Connecting APB Slave
        self.apbctrl.apb.socket_bind(self.apbuart.apb)
        # Connecting Interrupts
        self.irqmp.irq_in.signal_bind(self.apbuart.irq, 3)
        # Set clock
        #apbuart.set_clk(clk,SC_NS)


        self.gptimer = module.GPTimer("gptimer",
            ntimers = 2,
            pindex = self.apb_id(),
            paddr = 0x003,
            pmask = 0xFFF,
            pirq = 8,
            sepirq = True,
            sbits = 16,
            nbits = 32,
            wdog = 1,
        #    power = power_mon
        )

        # Connect to apb and clock
        self.apbctrl.apb.socket_bind(self.gptimer.apb)
        #gptimer.set_clk(clk, SC_NS)

        # Connecting Interrupts
        for i in range(0, 8):
            self.irqmp.irq_in.signal_bind(self.gptimer.irq, 8 + i)


        self.mctrl = module.Mctrl( "mctrl",
        #    ambaLayer,
            romasel = 28,
            sdrasel = 29,
            romaddr = 0x000,
            rommask = 0xE00,
            ioaddr = 0x200,
            iomask = 0xE00,
            ramaddr = 0x400,
            rammask = 0xC00,
            paddr = 0x000, # APB Base Address
            pmask = 0xFFF, # APB Base Mask
            wprot = 0,
            srbanks = 4,
            ram8 = 1,
            ram16 = 1,
            sepbus = 0,
            sdbits = 32,
            mobile = 0,
            sden = 1,
            hindex = self.slave_id(),
            pindex = self.apb_id(),
        #    power = power_mon,
        );

        # Connecting AHB Slave
        self.ahbctrl.ahbOUT.socket_bind(self.mctrl.ahb);
        # Connecting APB Slave
        self.apbctrl.apb.socket_bind(self.mctrl.apb);
        # Set clock
        #mctrl.set_clk(clk, SC_NS);

        self.rom = module.Memory("rom",
            type = "0", #"ROM",
            banks = 2,
            bsize = 256 * 1024 * 1024, # bsize * 1024 * 1024
            bits = 32,
            cols = 0,
            storage = "ArrayStorage",
        #    power = power_mon
        )

        # Connect to memory controller and clock
        self.mctrl.mem.socket_bind(self.rom.bus)
        #rom.set_clk(clk, SC_NS)

        # IO memory instantiation
        self.io = module.Memory("io",
            type = "1", #"IO",
            banks = 1,
            bsize = 512 * 1024 * 1024,
            bits = 32,
            cols = 0,
            storage = "MapStorage",
        #    power = power_mon
        )

        # Connect to memory controller and clock
        self.mctrl.mem.socket_bind(self.io.bus)
        #io.set_clk(clk, SC_NS)

        # SRAM instantiation
        self.sram = module.Memory("sram",
            type = "2", #"SRAM",
            banks = 4,
            bsize = 128 * 1024 * 1024,
            bits = 32,
            cols = 0,
            storage = "MapStorage",
        #    power = power_mon
        )

        # Connect to memory controller and clock
        self.mctrl.mem.socket_bind(self.sram.bus)
        #sram.set_clk(clk, SC_NS)

        # SDRAM instantiation
        self.ram = module.Memory( "ram",
            type = "3", # "SDRAM",
            banks = 2,
            bsize = 256 * 1024 * 1024,
            bits = 32,
            cols = 16,
            storage = "ArrayStorage",
        #    power = power_mon
        )

        # Connect to memory controller and clock
        self.mctrl.mem.socket_bind(self.ram.bus)
        #sdram.set_clk(clk, SC_NS)


        self.ahbmem = module.AHBMem("ahbmem",
        #    ambaLayer,
            haddr = 0xA00,
            hmask = 0xFFF,
            hindex = 1,
            cacheable = 1,
            wait_states = 0,
        #    power = power_mon
        )

        # Connect to ahbctrl and clock
        self.ahbctrl.ahbOUT.socket_bind(self.ahbmem.ahb)
        #ahbmem.set_clk(clk, SC_NS)
        """
        self.ahbrom = module.AHBMem("ahbrom",
            bar__0__haddr = 0x000,
            bar__0__hmask = 0xFFF,
            hindex = self.slave_id(),
            cacheable = 1,
            wait_states = 0,
        )
        # Connect to ahbctrl and clock
        self.ahbctrl.ahbOUT.socket_bind(self.ahbrom.ahb)

        self.ahbram = module.AHBMem("ahbram",
            bar__0__haddr = 0x400,
            bar__0__hmask = 0xFFF,
            hindex = self.slave_id(),
            cacheable = 1,
            wait_states = 0,
        )
        # Connect to ahbctrl and clock
        self.ahbctrl.ahbOUT.socket_bind(self.ahbram.ahb)
        """
        self.commitreg = module.CommitRegister("commitregister",
            pindex = self.apb_id(),
            paddr = 0x008,
            pmask = 0xFFF
        )
        self.apbctrl.apb.socket_bind(self.commitreg.apb)

    def master_id(self):
        if not hasattr(self, '_master_id'):
            self._master_id = 0
        self._master_id += 1
        return self._master_id

    def slave_id(self):
        if not hasattr(self, '_slave_id'):
            self._slave_id = 0
        self._slave_id += 1
        return self._slave_id

    def apb_id(self):
        if not hasattr(self, '_apb_id'):
            self._apb_id = 0
        self._apb_id += 1
        return self._apb_id

    def connect_cpu(self, no_signals = False):
        # Connecting AHB Master
        self.cpu.ahb.socket_bind(self.ahbctrl.ahbIN)
        # Set clock
        self.cpu.snoop.signal_bind(self.ahbctrl.snoop)

        if not no_signals:
            self.irqmp.cpu_req.signal_bind(self.cpu.cpu.IRQ_port.irq_signal, long(0))
            self.cpu.cpu.irqAck.ack.signal_bind(self.irqmp.irq_ack, long(0))
            self.cpu.cpu.irqAck.run.signal_bind(self.irqmp.cpu_rst, long(0))
            self.cpu.cpu.irqAck.status.signal_bind(self.irqmp.cpu_stat, long(0))

        self.reset = module.ResetIrqmp("reset")
        self.irqmp.rst.signal_bind(self.reset.rst)
    def store_elf(self, rom, ram, use_intrinsics=False):
        self._rom = rom
        self._ram = ram
        self._use_intrinsics = use_intrinsics
    def start_of_simulation(self):
        if hasattr(self, '_rom'):
            print self.rom
            elf.load_elf_into_scireg(self._rom, self.rom, 0x00000000)
        if hasattr(self, '_ram'):
            print self.ram
            elf.load_elf_into_scireg(self._ram, self.ram, 0x40000000)
            #if self.use_intrinsics:
            elf.load_elf_intrinsics_to_processor(self._ram, [self.cpu], elf.intrinsic_groups['standard'])
        #shell_start()


class LeonSystem(BaseSystem):
    def __init__(self, name):
        print " * Creating Leon Subsystem:"
        super(LeonSystem, self).__init__(name)
        self.cpu = module.Leon3("cpu", hindex = 1)
        #self.cpu.cpu.historyEnabled.cci_write("true")
        #self.cpu.gdb.cci_write("2000")
        self.connect_cpu()

class MicroBlazeSystem(BaseSystem):
    def __init__(self, name):
        print " * Creating MicroBlaze Subsystem:"
        super(MicroBlazeSystem, self).__init__(name)
        self.cpu = module.MicroBlaze("cpu", hindex = 1)
        self.connect_cpu(True)

class ARMSystem(BaseSystem):
    def __init__(self, name):
        print " * Creating ARM Subsystem:"
        super(ARMSystem, self).__init__(name)
        self.cpu = module.CortexA9("cpu", hindex = 1)
        self.connect_cpu(True)

class SupervisorSystem(USIModule):
    def __init__(self, name):
        print " * Creating Supervisor Subsystem:"
        super(SupervisorSystem, self).__init__()
        voter = module.Voter("voter",
            irq=4,       # Interuptline Used
            wdog=0xFFF   # CLK Cycles to hit
        )

        for idx, name in enumerate(["leon", "microblaze", "arm"]):
            commitreg = usi.find(name + "_system.commitregister")[0]
            irqmp = usi.find(name + "_system.irqmp")[0]
            voter.commit.signal_bind(commitreg.commit, idx)
            #voter.irq.socket_bind(irqmp.irq_in, 4)
            #voter.reset(name->rst) # ?????? or Subsystem reseter ???? or interrupt ???

@usi.on('start_of_initialization')
def class_systems(*k, **kw):
    leonsystem = LeonSystem("leon_system")
    #leonsystem.store_elf("build/core/software/prom/ahbram/ahbram.prom", "build/core/software/grlib_tests/hello.sparc", True)
    leonsystem.store_elf("build/core/software/prom/sdram/sdram.prom", "build/core/software/grlib_tests/hello.sparc", True)
    # Fehlermeldung wenn store noch nciht existiert AHBMem/Memory!
    # 
    microblazesystem = MicroBlazeSystem("microblaze_system")
    #microblazesystem = LeonSystem("microblaze_system")
    microblazesystem.store_elf("build/core/software/prom/sdram/sdram.prom", "build/core/software/grlib_tests/hello.sparc", True)
    #microblazesystem.store_elf("./build/emc2quadcopter/software/hellospecial.sparc", True)

    armsystem = ARMSystem("arm_system")
    #armsystem = LeonSystem("arm_system")
    armsystem.store_elf("build/core/software/prom/sdram/sdram.prom", "build/core/software/grlib_tests/hello.sparc", True)
    #armsystem.store_elf("./build/emc2quadcopter/software/hellospecial.sparc", True)
    supervisorsystem = SupervisorSystem("supervisor_system")
    #usi.add_to_reporting_list("leon_system.ahbctrl", usi.report.SC_WARNING, 0)
    #for vec in ['ivectorcache', 'dvectorcache']:
    #    caches = usi.find("leon_system.cpu.{}.*".format(vec))
    #    usi.add_to_reporting_list(caches, usi.report.SC_WARNING, 0)
usi.report.set_filter_to_whitelist(True)

