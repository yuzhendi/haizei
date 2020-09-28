/*************************************************************************
	> File Name: 546.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月20日 星期日 18时04分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000007;
int n, m;
int a[105];
int ans;
int dfs(int loc, int num, int sum) {
    //cout << "loc : " << loc << endl;
    if (loc == n && num <= a[n] && sum == m) {
        ans++;
        //cout << "end" << endl;
        ans %= MAX_N;
        return 1;
    }
    if (sum == m) return 0;
    if (num > a[loc]) return 0;
    num += 1; // 将这种花至少选一个
    sum += 1;
    for (int i = 0; i < a[loc] - num; i++) { // 尽可能选本种花的时候
        if (dfs(loc, num, sum) == 0) break;
    }
    // 选后面种类的花
    dfs(loc + 1, 0, sum);
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1,0, 0); // 现在的位置和所摆的盆数
    cout << ans << endl;
    return 0;
}
