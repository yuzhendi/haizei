/*************************************************************************
	> File Name: 291小猫爬山.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月07日 星期一 18时36分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int cnt, ans = 0x3fffffff, n, w, store[20], height[20], check[20];

void dp(int ind, int cnt) { // 第 ind 个小猫
    if (cnt >= ans) return ; // 加速，防止不必要的情况
    if (ind == n) {
        ans = cnt;
        return ;
    }
    for (int i = 0; i < cnt; i++) {
        if (store[i] < height[ind]) continue; // 第i个缆车不能存放小猫
        store[i] -= height[ind];
        dp(ind + 1, cnt);
        store[i] += height[ind];
    }
    // 每个小猫可以选择存放前面的缆车或者新的一辆缆车
    store[cnt++] = w - height[ind];
    dp(ind + 1, cnt);
    return ;
}
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    sort(height, height + n, cmp); // 小猫从大到小排序，前面缆车的空间越小，递归次数越少（小猫只能选择新的缆车）
    dp(0,  0);
    cout << ans << endl;
    
    return 0;
}
