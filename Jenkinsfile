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
        bat(script: 'HelloWorld.bat', encoding: 'UTF-8', label: 'TestBat', returnStdout: true, returnStatus: true)
      }
    }

  }
}