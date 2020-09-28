/*************************************************************************
	> File Name: 391数列分段.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 20时16分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, l, r;
long long arr[100005];

long long func2(long long x) {
    long long sum = 0, temp = 0;
    for  (int i = 0; i < n; i++) {
        if (temp + arr[i] == x) {
            sum++;
            temp = 0;
        } else if (temp + arr[i] > x) {
            sum++;
            temp = arr[i];
        } else {
            temp += arr[i];
        }
    }
    if (temp) sum++;
    return sum;
}

int func() {
    while(l != r) {
        long long mid = (l + r) >> 1;
        long long s = func2(mid);
        if (s > m) {
            l = mid + 1;
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
        l = max(l, arr[i]);
        r += arr[i];
    }
    cout << func() << endl;

    return 0;
}
