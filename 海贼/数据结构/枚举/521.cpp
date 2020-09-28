/*************************************************************************
	> File Name: 521.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 18时39分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 3000000

int prime[MAX_N + 5] = {1, 1}, n, r, num[35], ans;

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = 2; j * i <= MAX_N; j++) {
                prime[i * j] = 1;
            }
        }     
    }
}

void func(int start, int sum, int len) {
    if (len == r) {//递归长度为r ， 因为长度为n的时候会超时
        if (prime[sum] == 0) ans++;//判断和是不是素数
        return ;
    }
    for (int i = start; i < n - r + len + 1; i++) {
        sum += num[i];//求数组中长度为 r 的数据 的和
        func(i + 1, sum, len + 1);
        sum -= num[i];
    }
}


int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    init();
    func(0, 0, 0);
    cout << ans << endl;

    return 0;
}
