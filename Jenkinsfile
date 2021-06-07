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
      parallel {
        stage('Test') {
          steps {
            bat(script: 'HelloWorld.bat', encoding: 'UTF-8', label: 'TestBat', returnStdout: true, returnStatus: true)
            bat(script: 'test2', returnStatus: true)
          }
        }

        stage('Test2') {
          steps {
            bat(script: 'test2', returnStatus: true)
          }
        }

      }
    }

  }
}