/*************************************************************************
	> File Name: thread_pool.h
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月09日 星期二 18时15分05秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include "head.h"

#define MAXTASK 100
#define MAXTHREAD 10

struct task_queue{
    int sum;
    int epollfd;
    struct User **team;
    int head;
    int tail;
    pthread_mutex_t mutex; //互斥锁
    pthread_cond_t cond;
};


void task_queue_init(struct task_queue *taskQueue, int sum, int epollfd);
void task_queue_push(struct task_queue *taskQueue, struct User *user);
struct User *task_queue_pop(struct task_queue *task_Queue);
void *thread_pool_run(void *arg);
void *thread_run(void *arg);



#endif
