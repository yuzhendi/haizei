/*************************************************************************
	> File Name: 530警察找车.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月21日 星期一 20时36分59秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
    int x, y;
};

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int n, m, cnt;
char mmap[60][60];
int check[60][60];

int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                que.push({i, j});
                mmap[i][j] = '.';
                check[i][j] = 1;
            }
        }
    }
    cin >> cnt;
    while (cnt--) {
        string t;
        cin >> t;
        int dir_num, times = que.size();
        if (t == "NORTH") {
            dir_num = 0;
        } else if (t == "SOUTH") {
            dir_num = 1;
        } else if (t == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        for (int i = 0; i < times; i++) { // 每进行一次方向之后就需要将上次走过的地点清空
            node temp = que.front();
            que.pop();
            check[temp.x][temp.y] = 0;
            que.push(temp);
        }
        for (int i = 0; i < times; i++) {
            node temp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int x = temp.x + dir[dir_num][0] * j;
                int y = temp.y + dir[dir_num][1] * j;
                if (mmap[x][y] != '.') break;
                if (check[x][y] == 0) {
                    que.push({x, y});
                    check[x][y] = 1;
                }
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        mmap[temp.x][temp.y] = '*';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
        }
        cout << endl;
    }
    return 0;
}
 
