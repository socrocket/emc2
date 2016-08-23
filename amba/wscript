#! /usr/bin/env python
# vim : set fileencoding=utf-8 expandtab noai ts=4 sw=4 filetype=python :
top = '../..'

def build(self):
  self.install_files('${PREFIX}/include', self.path.ant_glob('**/*.h', excl=['**/tests/**', '**/extern/**', '**/contrib/**', '**/platform/**', '**/software/**', '**/.svn/**', '**/.git/**']), relative_trick=True)

