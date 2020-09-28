/*************************************************************************
	> File Name: heap_sort.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月21日 星期四 22时38分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {// 从1 开始存储 
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;// 0 --》1
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);//大顶堆
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);//排序（相当于出堆）
        downUpdate(arr, i - 1, 1);
    }
    return ;
}
void output(int *arr, int n) {
    printf("arr(%d) = [",n);
    for (int i = 0; i < n; i++) {
        printf(" %d",arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10
    int *arr = (int *)malloc(sizeof(int) * (max_op + 1));
    for (int i = 0; i < max_op; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);
    return 0;
}
