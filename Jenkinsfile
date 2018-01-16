#!groovy

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
      sh 'python performance_test.py --asroot "./build/pysc/usiexec/usiexec.platform -s quadcopter/quadcopter.py"'
      archiveArtifacts 'quadcopter.py_*'
      sh 'python performance_test.py --asroot --loop=100 "./build/core/platforms/nopython/nopython.platform -o conf.mctrl.prom.elf=./build/core/software/prom/sdram/sdram.prom -o conf.mctrl.ram.sdram.elf=./build/core/software/trapgen/hanoi.sparc -o conf.system.osemu=./build/core/software/trapgen/hanoi.sparc"'
      archiveArtifacts 'nopython.platform_*'
      sh 'python performance_test.py --asroot "./build/core/platforms/puretlm/puretlm.platform"'
      archiveArtifacts 'puretlm.platform_*'
      //publishHTML for gui
    }
  }
}
