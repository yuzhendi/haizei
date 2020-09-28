/*************************************************************************
	> File Name: thread_pool.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年06月09日 星期二 18时14分05秒
 ************************************************************************/

#include "thread_pool.h"
#include "./datatype.h"
void do_echo(struct User *user) {
    struct FootBallMsg msg;
    int size = recv(user->fd, (void *)&msg, sizeof(msg), 0);
    if (msg.type & FT_ACK) {
        if (user->team) {
            DBG(L_BLUE" %s "NONE"心跳\n", user->name);
        } else {
            DBG(L_RED" %s "NONE"新桃\n",user->name);
        }
    } else if (msg.type & (FT_WALL || FT_MSG)) {
        if (user->team) {
            DBG(L_BLUE" %s : %s "NONE, user->name, msg.msg);
        } else {
            DBG(L_RED" %s :  %s"NONE,user->name, msg.msg);
        }
        send(user->fd, (void *)&msg, sizeof(msg), 0);

    }
    return ;
}

void task_queue_init(struct task_queue *task_Queue, int sum, int epollfd) {
    task_Queue->sum = sum;
    task_Queue->epollfd = epollfd;
    task_Queue->team = calloc(sum, sizeof(void *));
    task_Queue->head = task_Queue->tail = 0;
    pthread_mutex_init(&task_Queue->mutex, NULL);
    pthread_cond_init(&task_Queue->cond, NULL);
}

void task_queue_push(struct task_queue *task_Queue, struct User *user) { 
    pthread_mutex_lock(&task_Queue->mutex); //加互斥锁
    task_Queue->team[task_Queue->tail] = user;
    DBG(L_GREEN"Thread Poll :"NONE" Task Push %s\n", user->name);
    if (++task_Queue->tail == task_Queue->sum) {
        DBG(L_GREEN"Thread poll : "NONE"Task Queue End!\n");
        task_Queue->head = 0;
    }
    pthread_cond_signal(&task_Queue->cond);
    pthread_mutex_unlock(&task_Queue->mutex);
}

struct User*task_queue_pop(struct task_queue *task_Queue) {
    pthread_mutex_lock(&task_Queue->mutex);
    while (task_Queue->tail == task_Queue->head) {
        DBG(GREEN"Thread poll : "NONE"Task Queue Empty, Waiting for task\n");
        pthread_cond_wait(&task_Queue->cond ,&task_Queue->mutex);
    }
    struct User *user = task_Queue->team[task_Queue->head];
    DBG(GREEN"Thread poll : "NONE"Task Queue pop %s \n",user->name);
    if (++task_Queue->head == task_Queue->tail) {
        DBG(L_GREEN"Thread poll : "NONE"Task Queue Empty, Waiting for task\n");
        task_Queue->tail = 0;
    }
    return user;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);
    struct task_queue *taskQueue = (struct task_queue *)arg;
    while(1) {
        struct User *user = task_queue_pop(taskQueue);
        do_echo(user);
    }

}
