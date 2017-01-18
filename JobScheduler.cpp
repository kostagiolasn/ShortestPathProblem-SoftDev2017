//
// Created by Panos Paparrigopoulos on 12/01/2017.
//

#include "JobScheduler.hpp"

JobScheduler::JobScheduler(int execution_threads){
    this->queue = new JobQueue();

    tids = (pthread_t*) malloc(sizeof(pthread_t)*execution_threads);
    for(int i = 0; i < execution_threads; i++)
    {
        pthread_create(&tids[i], NULL, JobScheduler::runJob, this);
    }

}


void* JobScheduler::runJob(void* schedulerPtr){
    JobScheduler* scheduler = (JobScheduler*) schedulerPtr;

    if(!scheduler->queueIsEmpty()){
        Job* job = scheduler->popJob();

        cout << "Running da job: " << job->getJobNumber() << endl;
    }
    else{
        cout << "This thread will die!" << endl;
    }


    pthread_exit(NULL);

}


int JobScheduler::getExecution_threads() const {
    return execution_threads;
}

void JobScheduler::setExecution_threads(int execution_threads) {
    JobScheduler::execution_threads = execution_threads;
}

void JobScheduler::pushJob(Job *job) {
    queue->pushBack(job);
}

Job* JobScheduler::popJob() {
    return queue->popFront();
}


bool JobScheduler::queueIsEmpty() {
    return queue->isEmpty();
}


void JobScheduler::printQueue() {
    queue->print();
}

JobScheduler::~JobScheduler() {
    delete [] tids;
}


