#!/usr/bin/python
import sys
import os
import subprocess
import argparse

# Creates a FlameGraph
# Enable FlameGraph in wscript of core/waf beforehand
def performance_test_flame ( name ):
    with open(name + ".perf", "r") as flame_perf_file, open(name + ".perf.folded", "w") as flame_perf_folded_file,open(name + "_flamegraph.svg", "w") as flame_image_file:
        print "Generating FlameGraph of" + name + ":"
        print " Fold Report Data"
        fg_p3 = subprocess.Popen([wd+"build/.conf_check_deps/dist/FlameGraph-1.0/stackcollapse-perf.pl", wd+flame_perf_file.name], stdout = flame_perf_folded_file)
        fg_p3.wait()
        print " Generate Image"
        fg_p4 = subprocess.Popen([wd+"build/.conf_check_deps/dist/FlameGraph-1.0/flamegraph.pl", wd+flame_perf_folded_file.name], stdout = flame_image_file)
        fg_p4.wait()

# Creates a Dotgraph
# Enable gprof2dot in pysc/usi/wscript beforehand
def performance_test_dot ( name ):
    #perf script | c++filt | gprof2dot.py -f perf | dot -Tpng -o output.png
    with open(name + "_callgraph.png", "w") as cg_image_file, open(name + ".perf", "r") as cg_perf_file:
        print "Generating Dot Graph of " + name + ":"
        cg_p3 = subprocess.Popen([
            wd+"/build/.conf_check_venv/bin/gprof2dot", # creates a dot graph
            "-f", "perf", #format perf
            "--strip", #strip funktction parameters
            "--wrap" #wrap function names
        ], stdin = cg_perf_file, stdout = subprocess.PIPE)
        cg_p4 = subprocess.Popen(("dot -Tpng -o "+ cg_image_file.name).split(), stdin=cg_p3.stdout)

# Saves results to textfile
def performance_test_txt ( name, rootuser ):
    #perf report --sort comm,dso | c++filt >> output.txt
    print "Generating Report txt"
    with open(name + "_report.txt","w") as cg_report_file:
        if rootuser:
            txt_p1 = subprocess.Popen([#"sudo",
            "perf",
            "report",
            "-I", # show CPU information in header
            "--header", # show header
            "--sort",
            "comm,dso"], stdout = subprocess.PIPE)
            txt_p2 = subprocess.Popen("c++filt", stdin=txt_p1.stdout, stdout=cg_report_file)
            txt_p2.wait();
        if not rootuser or 0==os.stat(cg_report_file.name).st_size:
            txt_p1 = subprocess.Popen(["sudo",
            "perf",
            "report",
            "-I",
             # show CPU information in header
            "--header", # show header
            "--sort",
            "comm,dso"], stdout = subprocess.PIPE)
            txt_p2 = subprocess.Popen("c++filt", stdin=txt_p1.stdout, stdout=cg_report_file)
            txt_p2.wait();

# Saves results to textfile
def performance_test_txt_stat( name, rootuser, origin ):
    #perf report --sort comm,dso | c++filt >> output.txt
    print "Generating statistics with execution time"
    with open(name+"_stat.txt","r+") as cg_report_file:
        perf_record = "perf stat -o %s -e cpu-clock %s" %(cg_report_file.name, origin) if asroot else "sudo perf stat -o %s -e cpu-clock %s" %(cg_report_file.name, origin)
        #perf_record = "(time %s) 2> %s" %(origin, cg_report_file.name)
        print perf_record
        txt_p1 = subprocess.Popen(perf_record.split())
        txt_p1.wait()
        #print cg_report_file.read()
        lines = cg_report_file.readlines()
        for i,line in enumerate(lines):
            if "seconds time elapsed" in line and i+1 < len(lines):
                seconds = lines[i]
                print seconds
                start = seconds.find('0,')
                end = seconds.find('seconds time elapsed')
                # extract number of seconds in line
                seconds = seconds[start:end-1]
                # replace , to .
                seconds = seconds.replace(',','.')
                # add to array
                execTime.append(float(seconds))
                break


print ("""

        SocRocket Performance test

        For this test you need to install

            perf (linux generic tools),  gprof2dot,  FlameGraph

                FlameGraph is part of /core/waf

                gprof2dot is part of usi's virtualenv

 """)

parser = argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument("--asroot", help="run this script as root", action="store_true")
parser.add_argument("--asuser", help="run this script as user", action="store_true")
parser.add_argument("-l", "--loop", type=int,
                    help="increase output verbosity")
args = parser.parse_args()

# Get path from first argument
origin_norm = os.path.realpath(args.filename)
origin=origin_norm.split()

# Get filename from path
name = os.path.basename(origin_norm)

# Update current working directory
wd = os.getcwd()+os.sep
print "Current Working Directory: " + wd

# Set User mode
asroot = True if args.asroot else False



print "Collect performance data:"
perf_record = "perf record --call-graph dwarf -F 99 %s" %(origin_norm) if asroot else "sudo perf record --call-graph dwarf -F 99 %s" %(origin_norm)
print " " + perf_record
pt_p0 = subprocess.Popen(perf_record.split())
pt_p0.wait()

##If performance data were collected
if os.stat('perf.data').st_size>0:
    print "Prepare performance data"

    with open(name + ".perf", "w") as name_perf_file:
        #If script is run as root
        if asroot:
            pt_p1 = subprocess.Popen([
                "perf", # converts perf.data into readable file
                "script"],
                 stdout = subprocess.PIPE)
            pt_p2 = subprocess.Popen(["c++filt"],
                stdin = pt_p1.stdout,
                stdout = name_perf_file)
            pt_p2.communicate()[0]
            pt_p2.wait()
#
        #Get super user permission
        else:
            pt_p1 = subprocess.Popen(["sudo",
                "perf", # converts perf.data into readable file
                "script"],
                 stdout = subprocess.PIPE)
            pt_p2 = subprocess.Popen(["c++filt"],
                stdin = pt_p1.stdout,
                stdout = name_perf_file)
            pt_p2.communicate()[0]
            pt_p2.wait()
#
    if os.stat(name +'.perf').st_size == 0:
        print name + ".perf not found"
        print "Performance data cannot be analysed."
    else:
        #post_processing
        performance_test_flame(name)
        performance_test_dot( name )
        performance_test_txt( name, asroot )
#
        print "Deleting system files"
        os.remove("perf.data")
        os.remove(name+".perf")

else:
    print "No samples recorded"

#Avarage Execution Time
execTime = []
loop = 1
if args.loop :
    loop = args.loop
for i in range (0, loop, 1) :
    performance_test_txt_stat(name,asroot, origin_norm)
execTimeSum = sum(execTime)/loop
print "Avarage Execution Time of %s Executions: %s seconds" %(loop, execTimeSum)
