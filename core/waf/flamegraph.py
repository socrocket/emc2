#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim: set expandtab:ts=4:sw=4:setfiletype python
import os
import subprocess
from waflib.Errors import ConfigurationError

if "check_output" not in dir( subprocess ): # duck punch it in!
    def f(*popenargs, **kwargs):
        if 'stdout' in kwargs:
            raise ValueError('stdout argument not allowed, it will be overridden.')
        process = subprocess.Popen(stdout=subprocess.PIPE, *popenargs, **kwargs)
        output, unused_err = process.communicate()
        retcode = process.poll()
        if retcode:
            cmd = kwargs.get("args")
            if cmd is None:
                cmd = popenargs[0]
            raise subprocess.CalledProcessError(retcode, cmd)
        return output
    subprocess.check_output = f

def options(self):
    self.add_option(
        '--with-flamegraph',
        type='string',
        help='Basedir of your FlameGraph installation',
        dest='flamegraphdir',
        default=os.environ.get("FLAMEGRAPH_HOME")
    )

def find(self, path = None):
    if path:
        path = os.path.abspath(os.path.expanduser(os.path.expandvars(os.path.join(path, "bin"))))

    self.find_program('flamegraph.pl', var='FLAMEGRAPH', mandatory=True, okmsg="ok")

    if "FLAMEGRAPH" in self.env:
        self.start_msg("Checking flamegraph version")
        flamegraph_version_str = subprocess.check_output(["flamegraph", "--version"])
        flamegraph_version_str = flamegraph_version_str.decode('utf-8').split('\n')[0]
        flamegraph_version = [int(v) for v in flamegraph_version_str.split(" ")[1].split(".")]
        flamegraph_version = flamegraph_version[0] * 1000000 + flamegraph_version[1] * 10000

    if not ("FLAMEGRAPH" in self.env) or flamegraph_version < 1000000:
        self.end_msg(flamegraph_version_str[:-2] + " is not enough using internal version")
        self.fatal("You need at least FLAMEGRAPH version 1.0")
    else:
        self.end_msg(flamegraph_version_str[:-2] + " is ok")

def configure(self):
    try:
        if self.options.flamegraphdir:
            find(self, self.options.flamegraphdir)
        else:
            find(self)
    except ConfigurationError as e:
        name    = "FlameGraph"
        version = "1.0"
        self.dep_fetch(
            name    = name,
            version = version,
            tar_url = "https://github.com/brendangregg/FlameGraph/archive/v1.0.tar.gz",
        )
        self.find_program('flamegraph.pl', var='FLAMEGRAPH', mandatory=True, okmsg="ok",
            path_list=[os.path.join(self.dep_path(name, version))])
