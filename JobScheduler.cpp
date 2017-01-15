//
// Created by Panos Paparrigopoulos on 12/01/2017.
//

#include "JobScheduler.hpp"

JobScheduler::JobScheduler(int execution_threads){
    this->queue = new JobQueue();
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


