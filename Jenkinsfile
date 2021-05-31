pipeline {
  agent {
    node {
      label 'master'
    }

  }
  stages {
    stage('build') {
      steps {
        echo 'build'
      }
    }

    stage('Change Dir') {
      steps {
        dir(path: 'd:\\development\\Jenkins\\workspace\\HelloWorld\\')
        echo 'change dir'
      }
    }

    stage('Test') {
      steps {
        bat(script: 'HelloWorld.bat', encoding: 'UTF-8', label: 'TestBat', returnStdout: true, returnStatus: true)
      }
    }

  }
}