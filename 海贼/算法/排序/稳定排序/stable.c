/*************************************************************************
	> File Name: stable.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月17日 星期四 09时28分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

// 插入排序
void insert(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--){
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}
// 冒泡排序
void bubble_sort(int *num, int n) {
    for (int i = 1; i < n; i++){
        int flag = 0; // 用来加速
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
    return ;
}
//归并排序
void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, mid + 1, r);
    merge_sort(num, l, mid);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <=mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}


int main() {
    srand(time(0));
    #define max_op 20
    for (int i = 0; i < max_op; i++) {
        
    }
    return 0;
}
