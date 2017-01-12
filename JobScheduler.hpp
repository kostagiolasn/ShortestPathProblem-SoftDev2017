//
// Created by Panos Paparrigopoulos on 12/01/2017.
//

#ifndef SHORTESTPATHPROBLEM_SOFTDEV2017_JOBSCHEDULER_HPP
#define SHORTESTPATHPROBLEM_SOFTDEV2017_JOBSCHEDULER_HPP

#include <pthread.h>

#include "JobQueue.hpp"

class JobScheduler {
private:
    int execution_threads; // number of execution threads
    JobQueue* queue;  // a queue that holds submitted jobs / tasks

public:
    JobScheduler(int execution_threads);

    int getExecution_threads() const;

    void setExecution_threads(int execution_threads);

    void pushJob(Job* job);
    Job* popJob();

    void printQueue();
};


#endif //SHORTESTPATHPROBLEM_SOFTDEV2017_JOBSCHEDULER_HPP
