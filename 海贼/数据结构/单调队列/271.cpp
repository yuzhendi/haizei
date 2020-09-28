/*************************************************************************
	> File Name: 271.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月28日 星期二 19时51分25秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 300000
int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;
int n, k;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < k; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail--;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail--;
        q[tail++] = i;
       if (q[head] <= i -k) head++;
        i == k || cout << " ";
        cout << a[q[head]];//当前区间最小值
    }
    cout << endl;
    head = tail = 0;
    for (int i = 1; i < k; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail--;
        q[tail++] = i;
       if (q[head] <= i -k) head++;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}
