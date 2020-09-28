/*************************************************************************
	> File Name: 490.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月28日 星期二 19时11分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 32767
int f[MAX_N + 5];
int main() {
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        //求幸存者
        f[i] = (f[i - 1] + 2 - 1) % i + 1;//映射： 
    }
    int x  = n;
    while(f[x] - x) x = f[x];
    cout << n + x << endl;//剩余x个人，额外给1元

    return 0;
}
