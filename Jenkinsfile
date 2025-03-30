pipeline {
    agent any
   
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
       
        stage('Docker Build and Test') {
            steps {
                sh 'docker build -t shaneg07/calculator:latest .'
                sh 'docker run --rm shaneg07/calculator /app/build/calculator_test'
            }
        }
       
        stage('Docker Push') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'docker-hub-credentials',
                                                usernameVariable: 'DOCKER_USERNAME',
                                                passwordVariable: 'DOCKER_PASSWORD')]) {
                    sh '''
                    echo $DOCKER_PASSWORD | docker login -u $DOCKER_USERNAME --password-stdin
                    docker push shaneg07/calculator:latest
                    '''
                }
            }
        }
       stage('Deploy with Ansible') {
        steps {
            sh '''
                cd ${WORKSPACE}/ansible && 
                ansible-playbook deploy-calculator.yml
                '''
        }
    }
 }

   
    post {
        always {
            cleanWs()
        }
    }
}
