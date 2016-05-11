#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '../../../'
REPOSITORY_PATH = "core/common/sr_registry"
REPOSITORY_NAME = "SoCRocket SystemC Model Registry"
REPOSITORY_VERSION = [3,0,0]
REPOSITORY_DESC = """Stores SystemC Models in Groups to Dynamiclay create and identify"""

def build(self):
    features = 'cxx cxxstlib'
    source = ['sr_registry.cpp']

    if True:
        source += ['sr_registry.i']
        features += ' pyembed venv_package'

    self(
        target            = 'sr_registry',
        features          = features,
        source            = source,
        pysource          = '__init__.py',
        export_includes   = self.top_dir,
        includes          = self.top_dir,
        swig_flags        = '-c++ -python -Wall',
        use               = 'usi SYSTEMC TLM PYTHON',
        install_path      = '${PREFIX}/lib',
  )

