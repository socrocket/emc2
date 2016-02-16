#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

import os

def build(bld):
    if bld.env['LICENSE'] == 'gpl':
        bld.recurse(os.path.join('libbfd', 'elfloader'))
    else:
        bld.recurse(os.path.join('libelf', 'elfloader'))

    bld.recurse('common debugger modules osemu profiler')

    bld.install_files(os.path.join(bld.env.PREFIX, 'include'), 'trap.hpp')
