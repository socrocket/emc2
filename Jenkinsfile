#!/usr/bin/env groovy
// -*- coding: utf-8 -*-

def efWs(cb) {
    def ws = pwd().replace("%2F", "_")
    sh "mkdir -p ${ws} || true"
    dir(ws, cb)
}

node('rocketbrew.c0e.de') {
  efWs {
    stage('Checkout') {
      deleteDir()
      checkout scm
    }
    stage('Configure') {
      sh 'cp ~/amba_socket-1.0.15.tgz .'
      sh './waf configure'
    }
    stage('Build') {
      sh './waf build --nosystests'
    }
    stage('Documents') {
      sh './waf docs'
    }
    stage('Testing') {
      sh 'python performance_test.py --sudo --name leon3mp.platform_hanoi_ --loop=100  -- ./build/core/platforms/leon3mp/leon3mp.platform --loadelf rom=./build/core/software/prom/sdram/sdram.prom --loadelf sdram="./build/core/software/trapgen/hanoi.sparc(0x40000000)" --intrinsics "leon3_0=./build/core/software/trapgen/hanoi.sparc(standard)"'
      archiveArtifacts 'leon3mp.platform_hanoi_*'

      sh 'python performance_test.py --sudo --name usiexec.platform_hanoi_ --loop=100 -- ./build/pysc/usiexec/usiexec.platform -s quadcopter/quadcopter.py -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/hanoi.sparc -o conf.system.osemu=./build/core/software/trapgen/hanoi.sparc'
      archiveArtifacts 'usiexec.platform_hanoi_*'

      sh 'python performance_test.py --sudo --name nopython.platform_hanoi_ --loop=100  -- ./build/core/platforms/nopython/nopython.platform -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/hanoi.sparc -o conf.system.osemu=./build/core/software/trapgen/hanoi.sparc'
      archiveArtifacts 'nopython.platform_hanoi_*'

      sh 'python performance_test.py --sudo --name puretlm.platform_hanoi_  --loop=100 -- ./build/core/platforms/puretlm/puretlm.platform -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/hanoi.sparc -o conf.system.osemu=./build/core/software/trapgen/hanoi.sparc'
      archiveArtifacts 'puretlm.platform_hanoi_*'

      sh 'python performance_test.py --sudo --name leon3mp.platform_matrix_ --loop=100  -- ./build/core/platforms/leon3mp/leon3mp.platform --loadelf rom=./build/core/software/prom/sdram/sdram.prom --loadelf sdram="./build/core/software/trapgen/matrix.sparc(0x40000000)" --intrinsics "leon3_0=./build/core/software/trapgen/matrix.sparc(standard)"'
      archiveArtifacts 'leon3mp.platform_matrix_*'

      sh 'python performance_test.py --sudo --name usiexec.platform_matrix_ --loop=100 -- ./build/pysc/usiexec/usiexec.platform -s quadcopter/quadcopter.py -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/matrix.sparc -o conf.system.osemu=./build/core/software/trapgen/matrix.sparc'
      archiveArtifacts 'usiexec.platform_matrix_*'

      sh 'python performance_test.py --sudo --name nopython.platform_matrix_ --loop=100  -- ./build/core/platforms/nopython/nopython.platform -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/matrix.sparc -o conf.system.osemu=./build/core/software/trapgen/matrix.sparc'
      archiveArtifacts 'nopython.platform_matrix_*'

      sh 'python performance_test.py --sudo --name puretlm.platform_matrix_  --loop=100 -- ./build/core/platforms/puretlm/puretlm.platform -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/matrix.sparc -o conf.system.osemu=./build/core/software/trapgen/matrix.sparc'
      archiveArtifacts 'puretlm.platform_matrix_*'
    }
  }
}
