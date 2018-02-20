#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Performance Tool for SocRocket
==============================

Requirements
------------
Please enable FlameGraph and gprof2dot in core/waf beforehand

Usage
-----
Just call it as an application
"""
from __future__ import print_function
import os
import sys
import subprocess
# from usi.tools.waf import OBJECT as waf_config # Does not work
sys.path.insert(0, os.path.abspath('pysc/usi/tools'))
# pylint: disable=import-error,wrong-import-position
from waf import OBJECT as waf_config

__author__ = "Luise Moritz <luise.moritz@tu-braunschweig.de>"
__copyright__ = "Copyright 2018, SoCRocket TLM Framework"
__license__ = "GPL"
__version__ = "1.0.1"

APP_DESCRIPTION = """
SocRocket performance test tool
-------------------------------
For this script you need to install:
    perf (linux generic tools),
    graphviz (dot),
    sudo,
    c++filt[,  gprof2dot,  FlameGraph]

- FlameGraph is part of /core/waf
- gprof2dot is part of usi's virtualenv
"""

FILENAME_DATA = "{}.perf.data"
FILENAME_PERF = "{}.perf"
FILENAME_FOLDED = "{}.perf.folded"
FILENAME_SVG = "{}.perf.flamegraph.svg"
FILENAME_CALL = "{}.perf.callgraph.png"
FILENAME_REPORT = "{}.perf.report.txt"
FILENAME_STATS = "{}.perf.stat.txt"
FILENAME_AVG_TIME = "{}.perf.time.txt"

OUT_DIR = waf_config['out_dir']
VENV_DIR = os.path.join(OUT_DIR, '.conf_check_venv', 'bin')
DIST_DIR = os.path.join(OUT_DIR, '.conf_check_deps', 'dist')
FGRAPH_DIR = os.path.join(DIST_DIR, 'FlameGraph-1.0')

STACKCOLLAPSE = os.path.join(FGRAPH_DIR, 'stackcollapse-perf.pl')
FLAMEGRAPH = os.path.join(FGRAPH_DIR, 'flamegraph.pl')
GPROF2DOT = os.path.join(VENV_DIR, 'gprof2dot')
SUDO = 'sudo'
PERF = 'perf'
CFILT = 'c++filt'
DOT = 'dot'


def sudo(as_root, cmd):
    """
    Add sudo to a command if as_root is True.

    Parameter
    ---------
      as_root: boolean
      cmd: list of strings
    """
    if as_root:
        return [SUDO] + cmd
    return cmd


class PerformanceTest(object):
    """Wrapper class for the perf command and some tools."""

    def __init__(self, name, root, command, loop=1):
        """Init member of Class."""
        self.name = name
        self.root = root
        self.command = command
        self.loop = loop

    def _flame(self):
        """Generate a FlameGraph of perf.data.

        Enable FlameGraph in wscript of core/waf beforehand.
        """
        with open(FILENAME_FOLDED.format(self.name), "w") as flame_folded_file:
            print("Generating FlameGraph of {}:".format(self.name))
            print(" Fold Report Data")
            cmd = [STACKCOLLAPSE, FILENAME_PERF.format(self.name)]
            print(' '.join(cmd))
            fg_p3 = subprocess.Popen(cmd, stdout=flame_folded_file)
            fg_p3.wait()

        with open(FILENAME_SVG.format(self.name), "w") as flame_image_file:
            print(" Generate Image")
            fg_p4 = subprocess.Popen(
                [FLAMEGRAPH, FILENAME_FOLDED.format(self.name)],
                stdout=flame_image_file)
            fg_p4.wait()

    def _dot(self):
        """
        Generate a DotGraph.

        Enable gprof2dot in pysc/usi/wscript beforehand
        """
        with open(FILENAME_PERF.format(self.name), "r") as dot_perf_file:
            print("Generating Dot Graph of {}:".format(self.name))
            cg_p3 = subprocess.Popen([
                GPROF2DOT,  # creates a dot graph
                "-f", "perf",  # format perf
                "--strip",  # strip funktction parameters
                "--wrap"  # wrap function names
            ], stdin=dot_perf_file, stdout=subprocess.PIPE)
            subprocess.Popen(
                [DOT, '-Tpng', '-o', FILENAME_CALL.format(self.name)],
                stdin=cg_p3.stdout)

    def _txt(self):
        """
        Save Results in a Textfile.

        Sorted by command and name of library.
        """
        print("Generating Report txt")
        for rootuser in [self.root, True]:
            with open(FILENAME_REPORT.format(self.name), "w") as txt_file:
                txt_p1 = subprocess.Popen(sudo(rootuser, [
                    "perf",
                    "report",
                    "--input={}".format(FILENAME_DATA.format(self.name)),
                    "-I",  # show CPU information in header
                    "--header",  # show header
                    "--sort",
                    "comm,dso"]), stdout=subprocess.PIPE)
                txt_p2 = subprocess.Popen(
                    "c++filt",
                    stdin=txt_p1.stdout,
                    stdout=txt_file)
                txt_p2.wait()
            if os.stat(FILENAME_REPORT.format(self.name)).st_size != 0:
                break

    # Saves results to textfile
    def _txt_stat(self):
        """
        Measure Execution Time.

        Extract Execution Time of File.
        """
        result = 0.0
        print("Generating statistics with execution time")
        perf_record = sudo(self.root, [
            PERF,
            'stat',
            '-o',
            FILENAME_STATS.format(self.name),
            '-e' 'cpu-clock'
            ] + self.command)
        print(" ".join(perf_record))
        txt_p1 = subprocess.Popen(perf_record)
        txt_p1.wait()
        lines = []

        with open(FILENAME_STATS.format(self.name), "r") as cg_report_file:
            lines = cg_report_file.readlines()
        for i, line in enumerate(lines):
            if 'seconds time elapsed' in line and i+1 < len(lines):
                seconds = lines[i]
                start = seconds.find(',')
                end = seconds.find('seconds time elapsed')
                # extract number of seconds in line
                seconds = seconds[start-1:end-1]
                # replace , to . to convert to float
                seconds = seconds.replace(',', '.')
                # add to array
                result = float(seconds)
                print("Execution Time:  {}s".format(seconds))
                break
        return result

    def _collect(self):
        """Collect performance data."""
        print("Collect performance data:")
        perf_record = sudo(self.root, [
            PERF,
            'record',
            '--output={}'.format(FILENAME_DATA.format(self.name)),
            '--call-graph=dwarf',
            '--freq=99',
            '--'
            ] + self.command)
        print(" ".join(perf_record))
        pt_p0 = subprocess.Popen(perf_record)
        pt_p0.wait()

    def _prepare(self):
        """Prepare performance data."""
        print("Prepare performance data")

        with open(FILENAME_PERF.format(self.name), "w") as name_perf_file:
            # If script is run as root
            # converts perf.data into readable file
            pt_p1 = subprocess.Popen(sudo(self.root, [
                PERF,
                'script',
                '--input={}'.format(FILENAME_DATA.format(self.name))
                ]), stdout=subprocess.PIPE)
            pt_p2 = subprocess.Popen([CFILT],
                                     stdin=pt_p1.stdout,
                                     stdout=name_perf_file)
            pt_p2.communicate()
            pt_p2.wait()

    def _check(self):
        """Check if data file exists."""
        return os.stat(FILENAME_DATA.format(self.name)).st_size > 0

    def _cleanup(self):
        """Clean up data files."""
        print("Clean up data files")
        os.remove(FILENAME_DATA.format(self.name))
        os.remove(FILENAME_PERF.format(self.name))

    def averagetime(self):
        """Sample execution time and calculate its average time."""
        exec_time = []
        loop = 1
        if self.loop:
            loop = self.loop

        for _ in range(0, loop, 1):
            exec_time.append(self._txt_stat())

        exec_time_avg = sum(exec_time)/loop
        exec_time_avg_print = "Average Execution Time of {} Executions: "\
                              "{} seconds" \
                              .format(loop, exec_time_avg)
        print(exec_time_avg_print)

        with open(FILENAME_AVG_TIME.format(self.name), "w") as avg_time_file:
            for item in exec_time:
                    avg_time_file.write("%s,\n" % item)
            avg_time_file.write(exec_time_avg_print)

        os.remove(FILENAME_STATS.format(self.name))

    def test(self):
        """Start performance test."""
        self._collect()

        # If performance data were collected
        if self._check():
            self._prepare()

            if os.stat(FILENAME_PERF.format(self.name)).st_size == 0:
                print(FILENAME_PERF.format(self.name), "not found")
                print("Performance data cannot be analysed.")

            else:
                # post_processing
                self._flame()
                self._dot()
                self._txt()

                self._cleanup()

        else:
            print("No samples recorded")


def main():
    """Run performance test as a cli command."""
    import argparse
    from argparse import RawTextHelpFormatter
    parser = argparse.ArgumentParser(description=APP_DESCRIPTION,
                                     formatter_class=RawTextHelpFormatter)
    parser.add_argument('-s', '--sudo', dest='root', action='store_true',
                        default=False,
                        help="run this script as root")
    parser.add_argument('-n', '--name', dest='name', default=None,
                        help="basename of the outputfiles")
    parser.add_argument('-l', '--loop', type=int,
                        help="increase output verbosity")
    parser.add_argument('--', dest='orig_args', nargs=argparse.REMAINDER)

    argv = sys.argv[1:]
    idx = argv.index('--') if '--' in argv else len(argv)
    args, extra = parser.parse_args(argv[:idx]), argv[idx + 1:]

    perf = PerformanceTest(args.name or os.path.basename(extra[0]),
                           args.root, extra, args.loop)
    perf.test()
    perf.averagetime()


if __name__ == "__main__":
    main()
