/*************************************************************************
	> File Name: 535瓷砖.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 18时21分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, ans;
char mmap[60][60];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
    int x, y;
};
queue<node> que;
int main() {
    cin >> m >> n; // 题目是反着输入的
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') { // 判断起点
                que.push({i, j});
            }
        }
    }
    while(!que.empty()) { // 将所有的可以走的点遍历
        node temp = que.front();
        que.pop(); // 每次从队头里面取出一个
        for (int i = 0; i < 4; i++) { // 四个方向
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') { // 可以走
                ans++;
                que.push({x, y});
                mmap[x][y] = '#'; // 去重标记
            }
        }
    }
    cout << ans + 1 << endl; // 起点也算一个点

    return 0;
}
