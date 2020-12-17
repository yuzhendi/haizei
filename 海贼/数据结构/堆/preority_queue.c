/*************************************************************************
	> File Name: preority_queue.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月17日 星期四 19时39分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) t = a;\
    a = b;\
    b = t;\
}

typedef struct Node {
    int size;
    int cnt;
    int *data;
}Node;

Node *init(int n) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->size = n;
    p->cnt = 0;
    p->data = (int *)malloc(sizeof(int) * (n + 1));
    return p;
}
int top(Node *p) {
    if (p == NULL) return -1;
    return p->data[1];
}

int push(Node *p, int val) {
    if (p->cnt == p->size) return 0;
    p->data[++p->cnt] = val;
    // 自下而上的进行调整
    int ind = p->cnt;
    while((ind >> 1) && p->data[ind >> 1] > p->data[ind]) {
        swap(p->data[ind], p->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int pop(Node *p) {
    if (p == NULL || p->cnt == 0) return 0;
    p->data[1] = p->data[p->cnt--];
    int ind = 1;
    while((ind << 1) <= (p->cnt + 1)) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (p->data[temp] > p->data[l]) temp = l;
        if (r <= (p->cnt + 1) && p->data[temp] > p->data[r]) temp = r;
        if (temp == ind) break;
        swap(p->data[ind], p->data[temp]);
        ind <<= 1;
    }
    return 1;
}

void clear(Node *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
    return ;
} 
int main() {
    srand(time(0));
    #define max_op 10
    Node *p = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(p, val);
        printf("push %d into queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(p));
        pop(p);
    }
    printf("\n");
    clear(p);
    return 0;
}
