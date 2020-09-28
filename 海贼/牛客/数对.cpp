/*************************************************************************
	> File Name: 数对.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 16时37分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long n, k;
    long long ans = 0;
    cin >> n >> k;
    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }
    for (long long y = k + 1; y <= n; y++) { // 将除数固定， 被除数是0 - (y-1)
        int t1 = n / y, t2 = n % y;
        ans += t1 * (y - k);
        ans += t2 - k + 1 > 0 ? t2 - k + 1 : 0;
    }
    cout << ans << endl;
    return 0;
}
