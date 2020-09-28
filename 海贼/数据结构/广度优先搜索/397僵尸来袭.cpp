
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    int x, y;
};

int n, m, ans;
int mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int main() {
    queue<node> que;
    cin >> n >> m;
    int sx, sy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == 0) continue;
            if (mmap[i][j]) {
                mmap[i][j] = 0;
                ans++;
                //cout << "ans : " << ans << endl;
                que.push({i, j});
                while(!que.empty()) {
                    node temp = que.front();
                    que.pop();
                    //cout << "que.pop" << endl;
                    for (int k = 0; k < 4; k++) {
                        int x = temp.x + dir[k][0];
                        int y = temp.y + dir[k][1];
                        if (mmap[x][y] != 0) {
                            mmap[x][y] = 0;
                            //cout << "an : " <<  ans << endl;
                            que.push((node){x, y});
                        }
                        //cout << "k = " << endl;
                    }
                   // cout << "end pop" << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
