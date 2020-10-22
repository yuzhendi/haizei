/*************************************************************************
	> File Name: 542奶酪.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月20日 星期二 18时03分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX_N 1000
#define end Final
int T, n, h, r;
int q[MAX_N + 5][3], start[MAX_N + 5], cnt, end[MAX_N + 5], check[MAX_N + 5];
int arr[MAX_N + 5][MAX_N + 5];

bool func(int now) {
    if (end[now] == 1) return true;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0 && arr[i][now] == 1) {
            check[i] = 1;
            if (func(i)) return true; // 不需要回溯
        }
    }
    return false;
}

int main() {
    cin >> T;
    while(T--) {
        memset(end, 0, sizeof(end));
        memset(check, 0, sizeof(check));
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            cin >> q[i][0] >> q[i][1] >> q[i][2];
            if (q[i][2] <= r) {
                // 起点
                start[cnt++] = i;
            }
            if (q[i][2] + r >= h) {
                end[i] = 1;
            }
            for (int j = 1; j < i; j++) {
                int t0 = q[i][0] - q[j][0];
                int t1 = q[i][1] - q[j][1];
                int t2 = q[i][2] - q[j][2];
                if (sqrt(t0 * t0 + t1 * t1 + t2 * t2) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;
                }
            }
            
        }
        int f = 0;
        for (int i = 0; i < cnt; i++) {
            if (check[start[i]] == 0) {
                check[start[i]] = 1;
                if (func(start[i])) {
                    cout << "Yes" << endl;
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            cout << "No" << endl;
        }
    }
    return 0;
}
