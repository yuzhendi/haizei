/*************************************************************************
	> File Name: 329.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 17时25分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
int c[MAX_N + 5];
inline int lowbit(int x) { return x & (-x) ;}

void add(int x, int val, int n) {
    while(x <= n) c[x] += val, x += lowbit(x);
}

int query(int i) {
    int sum = 0;
    while(i) sum += c[i], i -= lowbit(i);
    return sum;
}


int main() {
    int n, m, pre = 0, now;
    cin >> n;
    for (int i = 1; i <= n; i++) {//差分数组进行两次单点修改，进行区间修改
        cin >> now;
        add(i, now - pre, n);
        pre = now;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b , val;
        char ch;
        cin >> ch;
        if (ch == 'C') {
            cin >> a >> b >> val;
            add(a, val, n);
            add(b + 1, -val, n);
        } else {
            cin >> val;
            cout << query(val) << endl;//区间和
        }
    }
    return 0;
}
