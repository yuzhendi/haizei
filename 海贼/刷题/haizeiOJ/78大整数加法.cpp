/*************************************************************************
	> File Name: 78大整数加法.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 15时47分48秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int a[MAX_N + 5];
int b[MAX_N + 5];
string l, s;
int main() {
    cin >> l >> s;
    for (int i = l.size() - 1, j = 1; i >= 0; i--) {
        a[0]++;
        a[j++] = l[i] - '0';
    }
    for (int i = s.size() - 1, j = 1; i >= 0; i--) {
        b[0]++;
        b[j++] = s[i] - '0';
    }
    int len = max(a[0], b[0]);
    for (int i = 1; i <= len; i++) {
        b[i] += a[i];
    }
    b[0] = len;
    for (int i = 1; i <= b[0]; i++) {
        if (b[i] < 10) continue;
        b[i + 1] += (b[i] / 10);
        b[i] %= 10;
        b[0] += (i == b[0]);
    }
    for (int i = b[0]; i; i--) {
        cout << b[i];
    }
    cout << endl;
    return 0;
}
