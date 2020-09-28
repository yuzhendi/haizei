/*************************************************************************
	> File Name: 52.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月30日 星期四 20时50分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
inr dp[MAX_N + 5];
long long c[MAX_N + 5];//前缀和数组 long long 是中间运算时候可能越界
inline long long S(int x) {
    return x * x;
}
int main() {
    long long n, M;
    cin >> n >> M;
    c[0] = 0;
    for (long long i = 1; i <= n; i++) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (long long i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + S((c[i] - c[i - 1])) + M;// i直接新起一次
        for (long long j = 0; j < i - 1; j++) {// j = 0 开始
            dp[i] = min(dp[i], dp[j] + S(c[i] - c[j]) + M);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
