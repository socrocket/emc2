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
  }
}
