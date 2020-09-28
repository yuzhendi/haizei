/*************************************************************************
	> File Name: 393切绳子.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 19时51分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define E  0.000001
int n, m;
double arr[10005];
double r;

int func2(double len) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] / len);
    }
    return sum;
}

double func() {
    double l = 0;
    while(r - l > E) {
        double mid = (l + r) / 2.0;
        int num = func2(mid);
        if (num >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r = (r > arr[i]) ? r : arr[i];
    }
    double ans = func();
    printf("%.2lf\n", (int )(ans * 100) / 100.0); // 保留2位小数
    return 0;
}
