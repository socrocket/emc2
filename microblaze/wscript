#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '..'
REPOSITORY_PATH = "microblaze"
REPOSITORY_NAME = "MicroBlaze Extensions"
REPOSITORY_DESC = "SoCRockets MicroBlaze extensions"
REPOSITORY_TOOLS = [
]

def build(self):
  self.recurse_all()
  self.recurse_all_tests()
  self(
        target       = 'sr_microblaze',
        features     = 'cxx cxxshlib',
        source = [
            'microblaze/intunit/instructions.cpp',
            'microblaze/intunit/registers.cpp',
            'microblaze/intunit/alias.cpp',
            'microblaze/intunit/processor.cpp',
            'microblaze/intunit/interface.cpp',
            'microblaze/intunit/decoder.cpp',
#            'microblaze/intunit/irqPorts.cpp',
#            'microblaze/intunit/externalPins.cpp',
            'microblaze/microblaze.cpp',
        ],
        includes = [self.repository_root.abspath()],
        defines = 'ENABLE_HISTORY', 
        use          = [
                        'sr_gaisler',
                        'sr_registry',
                        'sr_register',
                        'sr_report',
                        'sr_signal',
                        'common',
                        'AMBA', 'GREENSOCS', 'TLM', 'SYSTEMC', 'BOOST'
                       ],
        idx=99,
  )
