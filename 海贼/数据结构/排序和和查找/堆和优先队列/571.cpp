/*************************************************************************
	> File Name: 571.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月26日 星期二 17时54分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    int now, step; 
};
int n, x, y, num[105][105], check[105];
queue<node>que;
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    que.push({x, 0});
    check[x] = 1;//走过了
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.now == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0 && num[temp.now][i] == 1) {
                que.push({i, temp.step + 1});
                check[i] = 1;
            }
        }
    }

    return 0;
}
