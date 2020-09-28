/*************************************************************************
	> File Name: 235.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月27日 星期四 20时50分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, num[15];// cnt 代表当前存放的个数

void output() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}


void func(int start) {
    for (int i = start; i <= n; i++) {
        num[cnt++] = i; // 覆盖原来数据
        output(); // 先输出
        func(i + 1); // 进入下一层
        cnt--; // 回溯,不看17行
    }
}


int main() {
    cin >> n;
    func(1);
    return 0;
}
