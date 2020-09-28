/*************************************************************************
	> File Name: 528关系网络.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月21日 星期一 08时29分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, x, y;
int ans = 0x3fffffff;
int a[105][105], check[105];
struct node  {
    int x;
    int step;
};
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    queue<node> que;
    que.push({x, 0});
    check[x] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.x == y) {
            ans = min(ans, temp.step - 1);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (check[i] == 1 || a[temp.x][i] == 0) continue;
            check[i] = 1;
            que.push({i, temp.step + 1});
        }
    }
    cout << ans << endl;
    return 0;
}
