#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '../../..'
REPOSITORY_PATH = "core/common/sr_signal"
REPOSITORY_NAME = "SoCRocket TLM Signals"
REPOSITORY_VERSION = [3,0,0]
REPOSITORY_DESC = """High level signaling library"""

def build(self):
    features = 'cxx cxxstlib'
    source = []

    if True:
        source += ['sr_signal.i']
        features += ' pyembed venv_package'

    self(
        target            = 'sr_signal',
        features          = features,
        source            = source,
        #pysource          = 'klasses.py',
        export_includes   = self.top_dir,
        includes          = [self.top_dir, '.'],
        swig_flags        = '-c++ -python -Wall',
        use               = 'usi SYSTEMC TLM PYTHON',
        install_path      = '${PREFIX}/lib',
  )

    """
    self(
        target            = 'sr_report',
        features          = 'cxx cxxstlib pyembed venv_package',
        source            = ['sr_report.i', 'sr_report.cpp'],
        export_includes   = self.top_dir,
        includes          = self.top_dir,
        swig_flags        = '-c++ -python -Wall',
        use               = 'usi SYSTEMC TLM PYTHON',
        install_path      = '${PREFIX}/lib',
    )
    """

