/*************************************************************************
	> File Name: heap_sort.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月17日 星期四 19时57分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    a ^= b; b^= a; a^= b; \
}

void Up_to_down(int *arr, int len, int ind) {
    while((ind << 1) <= len) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= len && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1; // 从arr[1]开始当作第一个元素
    for (int i = n >> 1; i >= 1; i--) { // 建堆
        Up_to_down(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]); // 
        Up_to_down(arr, i - 1, 1);
    }
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    n % 10 == 0 || printf("\n");
}

int main() {
    srand(time(0));
    #define max_op 10
    int *arr = (int *)malloc(sizeof(int) * (max_op + 1));
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 101;
        arr[i] = val;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    
    return 0;
}
