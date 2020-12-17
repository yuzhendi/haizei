/*************************************************************************
	> File Name: 521组合取数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 20时49分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n, m, num[35], ans, prime[300005];

void init() {
    prime[0] = prime[1] = 1;
    for(int i = 2; i * i < 300005; i++) {
        if (prime[i]) continue;
        for (int j = 2; j * i< 300005; j++) {
            prime[j * i] = 1;
        }
    }
}

void func(int s, int left, int sum) {
    if (left == 0) {
        if(prime[sum] == 0) {
            ans++;
        }
        return ;
    }
    for (int i = s; i <= (n - left); i++) {
        func(i + 1, left - 1, sum + num[i]);
    }
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    func(0, m, 0);
    cout << ans << endl;
    return 0;
}
