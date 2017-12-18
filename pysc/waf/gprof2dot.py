#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim: set expandtab:ts=4:sw=4:setfiletype python
import os
import stat
from waflib import Context
from waflib.Build import BuildContext
import atexit

def options(self):
    pass

packages = [
    "gprof2dot"
]

# packages for perf
# sudo apt-get install linux-tools-common linux-tools-generic linux-tools-`uname -r`

# sudo apt install python-pip
# pip install gprof2dot

ACTIVATE = """
#!/bin/bash
. ~/.bashrc
. %(venv)s/bin/activate
export LD_LIBRARY_PATH="%(libpath)s:$LD_LIBRARY_PATH"
export PYTHONPATH="%(pythonpath)s:$PYTHONPATH"
export PATH="%(path)s:$PATH"
alias deactivate=exit
"""

def configure(self):

    for package in packages:
        self.python_get(package)

def vexecute(self, cmd = ""):
    path = []
    libpath = []
    pythonpath = []
    for key in list(self.env.table.keys()):
        if key.startswith("PATH_"):
            for val in self.env[key]:
                if not val in path:
                    path.append(val)
        if key.startswith("LIBPATH_") and not key == "LIBPATH_ST":
            for val in self.env[key]:
                if not val in libpath:
                    libpath.append(val)
        if key.startswith("PYTHONPATH_"):
            for val in self.env[key]:
                if not val in pythonpath:
                    pythonpath.append(val)
    path.append(os.path.join(self.srcnode.abspath(), "tools"))
    pythonpath.append(self.srcnode.abspath())

    activate = self.bldnode.find_or_declare("activate")
    activate.write(ACTIVATE % {"path" : ':'.join(path), "libpath" : ':'.join(libpath), "pythonpath" : ':'.join(pythonpath), "venv": self.env.VENV_PATH})
    activate.chmod(stat.S_IXUSR | stat.S_IXGRP | stat.S_IRUSR | stat.S_IRGRP | stat.S_IWUSR | stat.S_IWGRP)
    def eexit():
        os.execve(self.env.BASH, [self.env.BASH , '--rcfile', activate.abspath(), '-i'], os.environ)
    atexit.register(eexit)

def bash(self):
    vexecute(self)

class Bash(BuildContext):
    cmd = 'bash'
    fun = 'bash'

setattr(Context.g_module, 'bash', bash)
