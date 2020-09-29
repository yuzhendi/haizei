/*************************************************************************
	> File Name: 44最长上升子序列.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 11时38分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
#define INF 0x3f3f3f3f
int dp[MAX_N + 5]; // dp[i] 表示以a[i]为结尾的最大长度
int len[MAX_N + 5], ans = 0;
int a[MAX_N + 5];
int bs(int *arr, int l, int r, int x) {
    // 找到上升数组arr中x应该放置的位置
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) return bs(arr, mid + 1, r, x);
    else return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = INF; // 初始化为极大值
    }
    len[++ans] = a[1]; //先把第一个数放进去； len[i]表示以len[i]为结尾的最大长度为i
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
