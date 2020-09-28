/*************************************************************************
	> File Name: 236.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月27日 星期四 21时00分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int cnt, num[15], m, n;

void output() {
    for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        if (cnt == m) output();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1);
    return 0;
}
