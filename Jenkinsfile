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
cmd.exe /K ..//HelloWorld//release//HelloWorld.exe'''
      }
    }

  }
}