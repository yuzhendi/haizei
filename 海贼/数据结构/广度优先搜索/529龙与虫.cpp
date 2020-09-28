/*************************************************************************
	> File Name: 529龙与虫.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月23日 星期三 20时30分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
char map[150][150];
int check[150][150];
int dir[8][2] = {
    0, -1, // 上 
    1, -1, 
    1, 0, // 右
    1, 1, 
    0, 1, //下
    -1, 1,
    -1, 0, // 左
    -1, -1
};

struct node {
    int x, y;
    int step;
};


int main() {
   cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
        getchar();
    }
    while(1) {
        memset(check, 0, sizeof(check));
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0) break;
        queue<node> que;
        que.push({x1, y1, 0});
        int f = 0;
        check[x1][y1] = 1;
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            continue;
        }
       // cout << endl << "**********" << endl;
        while(!que.empty()) {
            node temp = que.front();
            que.pop();
            int len = max(n, m);
            for (int i = 0; i < 8; i++) {
                for (int j = 1; j <= len; j++) { // 对射击范围进行判断
                    int x = temp.x + j * dir[i][0];
                    int y = temp.y + j * dir[i][1];
                    if (x <= 0 || y <= 0 || x > n || y > m) {
                        break;
                    }
                    if (check[x][y] || map[x][y] == 'X') break;
                    if (x == x2 && y == y2) {
                        f = temp.step + 1;
                        break;
                    }
                    // 向四个方向移动
                    //cout << x << " , " << y << endl;
                }
                if (f) break;
               // cout << "before i % 2" << endl;
                if (i % 2 == 0) { // 虫向下移动
                    //cout << "i = " << i << endl;
                    int x = temp.x + dir[i][0], y = temp.y + dir[i][1];
                    if (x <= 0 || y <= 0 || x > n || y > m) {
                        continue;
                    }
                    if (check[x][y] || map[x][y] == 'X') continue;
                    que.push({x, y, temp.step + 1});
                    check[x][y] = 1;
                    //cout << "(" << x << " , " << y << ")" << endl;
                }

            }
            if (f) break;
        }
        if (f) {
            cout << f - 1 << endl;
        } else {
            cout << "Impossible!" << endl;
        }
    }


    return 0;
}
