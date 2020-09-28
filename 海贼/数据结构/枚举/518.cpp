/*************************************************************************
	> File Name: 518.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 18时23分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long ans = 0, x, num = 1, day = 0;

int main() {
    cin >> x;
    int t = 1, num = 0;
    while(1) {
        for (int i = 0; i < num; i++) {
             ans += num;
             day++;
            if (x == day) {
                cout << ans << endl;
                return 0;
            }
        }
        num++;
    }
    return 0;
}

