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
        sh 'sh cmd:"call HelloWorld.exe", name: "HelloWorld.exe"'
      }
    }

  }
}