/*************************************************************************
	> File Name: priority_queue.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月18日 星期一 23时01分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}



typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof (priority_queue));
    q->data = (int *)malloc (sizeof(int) * (n + 1));//从1开始存储
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
        //判空操作，  空则返回 1
    return q->cnt == 0;
}

int top(priority_queue *q) {
        //返回堆顶元素
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q == NULL) return 0;
    if (q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt; // 大顶堆
    while(ind >> 1 && q->data[ind] > q->data[ind >> 1]) { // 自下向上调整堆
        swap(q->data[ind], q->data[ind >> 1]); // 和父节点交换
        ind >>= 1;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--]; // 堆尾元素覆盖堆顶
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        //自上向下调整
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break; // 无需再调整
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}


void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d to queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
