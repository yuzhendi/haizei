/*************************************************************************
	> File Name: 80小明看电影.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 18时35分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    int x, y;
    int step;
};

int n, m;
char mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                que.push((node){i, j, 0});
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '1';
                que.push((node){x, y, temp.step + 1});
            }
            if (mmap[x][y] == 'g') {
                cout << temp.step + 1 << endl;
                return 0;
            }
        }

    }
    cout << "No" << endl;


    return 0;
}
