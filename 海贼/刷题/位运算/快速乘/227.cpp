/*************************************************************************
	> File Name: 227.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月23日 星期三 21时42分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

long long quick_mul(long long a, long b, long p) {
    long long temp = a, ans = 0;
    while(b) {
        if (b & 1) ans = (ans + temp) % p;
        temp = (temp * 2) % p;
        b >>= 1; 
    }
    return ans;
}


int main() {
    long long a , b, p;
    cin >> a >> b >> p;
    cout << quick_mul(a, b , p) << endl;

    return 0;
}
