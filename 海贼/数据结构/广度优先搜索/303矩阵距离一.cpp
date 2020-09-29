/*************************************************************************
	> File Name: 303矩阵距离一.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 18时02分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 1000
int n, m;
int ans[MAX_N + 5][MAX_N + 5];
char mmap[MAX_N + 5][MAX_N + 5];
struct node {
    int x, y;
    int step;
};
queue<node> que;

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push({i, j, 0});
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '0') {
                mmap[x][y] = '2';//标记去重
                ans[x][y] = temp.step + 1;
                que.push({x, y, ans[x][y]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
