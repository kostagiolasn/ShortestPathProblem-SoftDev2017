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
    pthread_t* tids; // Threads
    pthread_cond_t jobs_created;
    pthread_mutex_t array_mutex;

public:
    JobScheduler(int execution_threads);

    virtual ~JobScheduler();

    int getExecution_threads() const;
    void setExecution_threads(int execution_threads);

    void pushJob(Job* job);
    Job* popJob();

    static void* runJob(void*);

    bool queueIsEmpty();

    void printQueue();
};


#endif //SHORTESTPATHPROBLEM_SOFTDEV2017_JOBSCHEDULER_HPP
