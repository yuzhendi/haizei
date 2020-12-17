/*************************************************************************
	> File Name: num_add.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月05日 星期六 14时50分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t cond_odd = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_even = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_x = PTHREAD_MUTEX_INITIALIZER;

int kCount = 1;

void * countOdd(void * arg){
    for(int i=0; i<100;i++){
        pthread_mutex_lock(&mutex_x);
        if(kCount < 100){
            // 当前kCount是偶数，等待
            if((kCount%2) == 0) pthread_cond_wait(&cond_odd, &mutex_x); // 内部对mutex_x 解锁，等待信号被激活后再加锁
            // 打印奇数
            printf("Current Thread: %s, Current Count: %d.\n", (char *)arg, kCount);
            // 变成偶数
            kCount++;
            if((kCount%2) == 0){
                pthread_cond_signal(&cond_even);
            }
        }
        pthread_mutex_unlock(&mutex_x);
    }
    
}

void * countEven(void *arg){
    for(int i=0;i<100;i++){
        pthread_mutex_lock(&mutex_x);
        if(kCount < 100){
            // 当前kCount是奇数，等待
            if((kCount%2) == 1) pthread_cond_wait(&cond_even, &mutex_x);
            // 打印偶数
            printf("Current Thread: %s, Current Count: %d.\n", (char*)arg, kCount);
            // 变成奇数
            kCount++;
            if((kCount%2) == 1){
                pthread_cond_signal(&cond_odd);
            }
        }
        pthread_mutex_unlock(&mutex_x);
    }
}

int main(int argc, char* argv[]){
    pthread_t tids[2];
    int i;
    if(pthread_create(&tids[0], NULL, countOdd, (void*)("1"))){
        printf("pthread_creat_error");
    }
    if(pthread_create(&tids[1], NULL, countEven, (void*)("2"))){
        printf("pthread_creat_error");
    }
    sleep(3);
    for(i = 0;i < 2; i++){
        if(pthread_join(tids[i], NULL)){
            printf("pthread_join error");
            return -1;
        }
    }
    return 0;
}

