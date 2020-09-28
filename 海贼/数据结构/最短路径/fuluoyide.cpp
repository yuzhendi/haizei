/*************************************************************************
	> File Name: fuluoyide.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月27日 星期三 18时41分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, s, ans[1005][1005];
/*弗洛伊德算法*/
int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;// n*n 矩阵  m 条边  到s
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;// a->b  权值c
        ans[a][b] = c;
    }
    for (int i = 1; i <= n; i++) ans[i][i] = 0;//自身到自身为0
    for (int i = 1; i <= n; i++) {//任意节点到任意节点的距离
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[s][i] ;//s -> i 的最短距离
    }
    cout << endl;
    return 0;
}
