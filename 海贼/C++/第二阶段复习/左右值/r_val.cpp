/*************************************************************************
	> File Name: r_val.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年12月03日 星期四 21时15分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

void f(int &x) {
    // 单个&是左值
    cout << x << "is left value" << endl;
    return ;
}

void f(int &&x) {
    cout << x << "is right value" << endl;
    return ;
}

int func(int n) {
    int x = 1, k;
    if (n == 1) return x;
    for (k = 1; k < n; k++) {
        x = x + func(k) * func(n - k);
    }
    return x;
}
int main() {
    cout << func(5) << endl;

    return 0;
}
