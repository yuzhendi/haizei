/*************************************************************************
	> File Name: stable_sort.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 21时32分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int ) * n);\
    memcpy(num, arr, sizeof(int) * n );\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

// 插入排序
void insert(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}
// 冒泡排序
void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0; // 如果有一次循环没有进行交换，证明已经有序了
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                times++;
            }
        }
    }
    return ;
}
// 归并排序
void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1)); // 有序的数组进行合并
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] < num[p2])) { //从左侧数组取值
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

void rand_int(int *arr, int n) {
    while(n--) arr[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n\n");
}

int main() {
    srand(time(0));
    #define maxp_op 20
    int arr[maxp_op];
    rand_int(arr, maxp_op);
    TEST(arr, maxp_op, insert, num, maxp_op);
    TEST(arr, maxp_op, bubble_sort, num, maxp_op);
    TEST(arr, maxp_op, merge_sort, num, 0, maxp_op - 1);
    return 0;
}
