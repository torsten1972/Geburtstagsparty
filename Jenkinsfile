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
        sh '''
bat \'start cmd.exe /c d:\\\\development\\\\Jenkins\\\\workspace\\\\HelloWorld\\\\release\\\\HelloWorld.exe\''''
      }
    }

  }
}