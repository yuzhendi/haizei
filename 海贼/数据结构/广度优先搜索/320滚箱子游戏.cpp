/*************************************************************************
	> File Name: 320滚箱子游戏.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月21日 星期一 10时20分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int X, Y;
struct node {
    int x, y;
    int step;
};

int main() {
    while(cin >> X >> Y) {
        if (X == 0 && Y == ;``0) break;
        char map[505];
        int sx, sy;
        for (int i = 1; i <= X; i++) {
            for (int j = 1; j <= Y; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'X') {
                    sx = i;
                    sy = j;
                }
            }
            getchar();
        }
    }

    return 0;
}
