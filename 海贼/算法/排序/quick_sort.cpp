/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月05日 星期六 15时41分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
#define MAX_N 30
int num[MAX_N + 1];
template<class Type>
int Partition(Type a[], int p, int r) {
	// 划分， 以 a[p] 为基准，一分为二 
	int i = p, j = r + 1;
	int x = a[p];
	while(1) {
		while(a[++i] < x && i < r) ;
		while(a[--j] > x && i >= p) ;
		if (j <= i) break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

template<class type>
void quick_sort(type a[], int p, int r) {
    if (p >= r) return;
    int ind = Partition(a, p, r);
    quick_sort(a, p, ind - 1);
    quick_sort(a, ind + 1, r);
}

int main() {
    srand(time(0));
    for (int i = 0; i < MAX_N; i++) {
        num[i] = (rand() % 100);
    }
    quick_sort(num, 0, MAX_N - 1);

    for (int i = 0; i < MAX_N; i++) {
        cout << num[i] << " ";
        if ((i + 1 % 10) == 0) cout << endl;
    }
    cout << endl;
    return 0;
}
