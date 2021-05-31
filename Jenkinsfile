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

    stage('Test') {
      steps {
        sh '''cd d:\\\\development\\\\Jenkins\\\\workspace\\\\HelloWorld\\\\release
call HelloWorld.exe'''
      }
    }

  }
}