/*************************************************************************
	> File Name: heap_sort.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月17日 星期四 08时47分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) t = a;\
    a = b;\
    b = t;\
}

// 字上向下调整， 从ind 开始
void downUpdata(int *arr, int n, int ind) {
    while((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return;
}

void heap_sort(int *arr, int n) {
    arr -= 1; // 从下标1开始
    for (int i = n >> 1; i >= 1; i--) { // 建堆，只能保证堆的性质，父节点大于孩子节点，但是不能保证孩子节点之间的关系
        downUpdata(arr, n, i); // 自上而下的进行调整
    }
    for (int i = n; i > 1; i--) { // 排序
        swap(arr[i], arr[1]); // 利用大顶堆的性质，把最大值放到数组的最后一个
        downUpdata(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *)malloc(sizeof(int) *max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);
    return 0;
}
