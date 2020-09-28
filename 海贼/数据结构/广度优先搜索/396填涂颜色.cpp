/*************************************************************************
	> File Name: 396填涂颜色.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月24日 星期四 17时46分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int mmap[35][35];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void func(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int x = sx + dir[i][0];
        int y  = sy + dir[i][1];
        if (x < 0 || y < 0 || x > n + 1 || y > n + 1) continue; // 注意边界条件从 0 开始向下计算
        if (mmap[x][y] == 0) { // 将最外面的0标记为3
            mmap[x][y] = 3;
            func(x, y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    func(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) cout << " ";
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 1) {
                cout << 1;
            }  else {
                cout << 2;
            }
        }
        cout << endl;
    }

    return 0;
}
