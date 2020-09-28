/*************************************************************************
	> File Name: 305乳草入侵.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月20日 星期日 19时21分09秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
int x, y, mx, my;
char map[105][105];
int ans;
struct node {
    int x, y;
    int step;
};
int dir[8][2] = {
    1, 0, 0, 1, -1, 0, 0, -1,
    1, 1, 1, -1, -1, -1, -1, 1
};
int main() {
    cin >> y >> x >> my >> mx;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> map[i][j];
        }
    }
    queue<node> que;
    que.push({x - mx + 1, my, 0});
    map[x - mx + 1][my] = 'c';
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        ans = temp.step;
        for (int i = 0; i < 8; i++) {
            int t1 = temp.x + dir[i][0];
            int t2 = temp.y + dir[i][1];
            if (map[t1][t2] == '.') {
                que.push({t1, t2, temp.step + 1});
                map[t1][t2] = 'c';
            }
        }
    }
    cout << ans << endl;

    return 0;
}
