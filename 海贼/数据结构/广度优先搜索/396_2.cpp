/*************************************************************************
	> File Name: 396_2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 19时39分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int x, y;
};
int n, mmap[35][35];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node> que;
    que.push({0, 0}); // 从图形的外圈向里找，可以防止边界全1的起点寻找的困难
    mmap[0][0] = 3;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || y < 0 || x > n + 1 || y > n + 1) {
                continue;
            }
            if (mmap[x][y] == 0) {
                mmap[x][y] = 3;
                que.push({x, y});
            
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) cout << " ";
            if (mmap[i][j] == 3) {
                cout << 0 ;
            } else if (mmap[i][j] == 1) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }

    return 0;
}
