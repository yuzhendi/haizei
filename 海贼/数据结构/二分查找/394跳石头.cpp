/*************************************************************************
	> File Name: 394跳石头.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月22日 星期二 20时42分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, L, l = 1, r;
long long arr[50005];

long long func2(long long len) {
    long long cnt = 0, last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if ( arr[i] - last >= len) {
            last = arr[i];
        } else{
            cnt++;
        }
    }

    return cnt;
}

int func() {
    while(l != r) {
        long long mid = (l + r + 1) >> 1;
        long long s = func2(mid); // 需要撤出的石头数量
        if (s > m) {
            r = mid  - 1;
        } else {
            l = mid;
        }

    }
    return l;
}

int main() {
    cin >> r >> n >> m;
    arr[0] = 0;
    for (int i = 1; i <= n ;i++) {
        cin >> arr[i];
    }
    arr[n + 1] = r;
    cout << func() << endl;
    return 0;
}
