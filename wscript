#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '../../../'
REPOSITORY_PATH = "core/common/sr_register"
REPOSITORY_NAME = "SoCRocket Register implementation"
REPOSITORY_VERSION = [3,0,0]
REPOSITORY_DESC = """Based on the Cadence SystemC Register proposal"""

def build(self):
    self(
        target            = 'sr_register',
        features          = 'cxx cxxstlib pyembed venv_package',
        source            = ['scireg.i', 'scireg.cpp'],
        export_includes   = self.top_dir,
        includes          = self.top_dir,
        swig_flags        = '-c++ -python -Wall',
        use               = 'usi SYSTEMC TLM PYTHON',
        install_path      = '${PREFIX}/lib',
  )

