/*************************************************************************
	> File Name: 250.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月17日 星期日 20时11分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000000
long long a[MAX_N + 4];
long long s[MAX_N + 5];
long long g[MAX_N + 5];//gi = si - i * c; // 从1点开始调整的代价
long long n, sum, c;

int main() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n;
    for (long long i = 1; i <= n; i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + n + 1);
    c = g[n >> 1];// 排序后的中为数， 代价最小 
    /* 设 k 的地方分开的时候代价最小， 则ans = |gi - gk| 的和*/
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
