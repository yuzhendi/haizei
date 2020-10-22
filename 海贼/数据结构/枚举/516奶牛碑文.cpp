/*************************************************************************
	> File Name: 516奶牛碑文.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 19时47分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10005
int c[MAX_N], w[MAX_N];
int ans;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            cnt++;
        }
        c[i] = cnt;
    }
     cnt = 0;
    long long ans = 0;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == 'W') cnt++;
        if (s[i] == 'O') ans += (long long )(c[i] * cnt);
    }
    cout << ans << endl;
    return 0;
}

