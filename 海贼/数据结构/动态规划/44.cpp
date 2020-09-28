/*************************************************************************
	> File Name: 44.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月30日 星期四 19时30分35秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5];
int len[MAX_N + 5], ans = 0;//len[i] 存放长度为i的 的最小值， 且有单调递增的性质， 来进行时间优化
int a[MAX_N + 5];

int bs(int *arr, int l, int r, int x) {
    //[l,r] 中第一个不小于x的位置
    if (l == r) return l;
    int mid = (l  + r) >> 1;
    if (arr[mid] < x) {
        return bs(arr, mid + 1, r, x);
    } return bs(arr, l, mid, x);
}

int main() {
    int n;
    cin >> n;
    a[0] = 0x3f3f3f3f;// 乘2也不会溢出
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = n + 1;//作为一个极大值
    }
    len[++ans] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]);
        len[dp[i]] = a[i];//更新长度为dp[i] 的序列的最小值(长度相同的序列比较)
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
