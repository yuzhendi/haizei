/*************************************************************************
	> File Name: A.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时33分09秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, p, ans = 1;
int main() {
    cin >> a >> b >> p;
    long long temp = a;
    while(b) {
        if (b & 1) {
            ans = ans * temp % p;
        }
        temp = temp * temp % p;
        b = b >> 1;
    }
    cout << ans % p << endl;
    return 0;
}
