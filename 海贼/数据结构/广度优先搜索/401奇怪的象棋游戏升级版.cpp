/*************************************************************************
	> File Name: 401奇怪的象棋游戏升级版.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 19时24分21秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int ans[505][505];

struct node {
    int x, y;
    int step;
};

int dir[12][2] = {
    1, 2, 1, -2,
    -1, 2, -1, -2,
    2, 1, 2, -1,
    -2, 1, -2, -1,
    2, 2, 2, -2,
    -2, 2, -2, -2
};
queue<node> que;
int main() {
        que.push({3, 3, 0});
        ans[3][3] = -1;
        while(!que.empty()) {
            node temp = que.front();
            que.pop();
            for (int i = 0; i < 12; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (x < 3 || y < 3 || x > 502 || y > 502) continue;
                if (ans[x][y]) continue;
                ans[x][y] = temp.step + 1;
                que.push({x, y, ans[x][y]});
            }
        }
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        if (x == 1 && y == 1) {
            cout << 0 << endl;
        } else {
            cout << ans[x + 2][y + 2] << endl;
        }
    }

    return 0;
}
