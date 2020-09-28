/*************************************************************************
	> File Name: 532.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月20日 星期日 19时44分04秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
/* 二分答案， 难度为h， 高度差高于难度的路不同， 找一个通的路 h最小 */
int n, m, ans;
int sx, sy, l, r, h;
int map[505][505], eend[505][505];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

struct node {
    int x, y;  
};
int start_num;

bool func(int mid) {
    int check[505][505] = {0};
    queue<node> que;
    que.push({sx, sy});
    check[sx][sy] = 1;
    int num1 = start_num - 1;
    while(!que.empty()) {
        if (num1 == 0) break;
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == 0 || y == 0 || x > n || y > m) continue;
            if (check[x][y] == 0 && abs(map[x][y] - map[temp.x][temp.y]) <= mid) {
                check[x][y] = 1;
                que.push({x, y});
                if (eend[x][y] == 1) num1--;
            }
        }
    }
    if (num1 == 0) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            r = max(r, map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> eend[i][j];
            if (eend[i][j] == 1) {
            sx = i; // 起点随即
            sy = j;
            start_num++;
            }
        }
    }
    while(l != r) {
        int mid = (r + l ) >> 1;
        if (func(mid) == 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;

    return  0;
}
