/*************************************************************************
	> File Name: 513.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 18时16分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int m, t, ans;

int check(int x) {
    while(x) {
        if (x % 10 == t) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        while(check(i)) i++;
        if (i > m) break;
        ans++;
    }
    cout << ans << endl;
    

    return 0;
}
