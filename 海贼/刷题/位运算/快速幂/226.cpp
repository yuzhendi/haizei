/*************************************************************************
	> File Name: 226.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月23日 星期三 21时46分41秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long quick_m(long long a, long long b, long long p) {
    long long temp = a, ans = 1;
    while(b) {
        if (b & 1) ans = (ans * temp) % p;
        temp = temp * temp % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << quick_m(a, b , p) << endl;

    return 0;
}
