/*************************************************************************
	> File Name: 590树塔狂想曲.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 20时27分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
// 从下往上来一次， 从上往下来一边，相加求过某一点的路径最大值

int n, m;
int num[1005][1005], up[1005][1005], down[1005][1005], sum[1005][1005], ans[1005][3]; // 0 : max  1: max_ind  2 : second_max


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
            sum[i][j] = up[i][j] + down[i][j] - num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (sum[i][j] > ans[i][0]) {
                ans[i][0] = sum[i][j];
                ans[i][1] = j;
            }
        }
        for (int j  =1; j <= i; j++)
            if (j != ans[i][1] && sum[i][j] > ans[i][2]) {
                ans[i][2] = sum[i][j];
            }
        
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        if (a == 1 && b == 1) {
            cout << -1 << endl;
            continue;
        } else {
            if (ans[a][1] == b) { // 是最大值下标，有多个也无所谓
                cout << ans[a][2] << endl;
            } else {
                cout << ans[a][0] << endl;
            }
        }
    }
    

    return 0;
}
