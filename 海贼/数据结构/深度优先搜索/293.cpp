/*************************************************************************
	> File Name: 293.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月11日 星期五 20时18分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int val[10][10];
int ans = -1;
int r[10], c[10], g[10];
void work(int i, int j, int x) {
    int num = i / 3 * 3 + j / 3; // 对应宫格数
    r[i] ^= (1 << x);
    c[j] ^= (1 << x);
    g[num] ^= (1 << x);
}

int count_one(int x) {
    int cnt = 0;
    while(x) x &= (x - 1), cnt += 1;
    return cnt;
}

void dfs(int cnt) {
    if (cnt == 0) {
        int temp  = 0; // 当前数独的得分
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                temp += (val[i][j] * (10 - max(abs(i - 4), abs(j - 4))));// 加上va[i][j] 点的权重
            }
        }
        ans = max(temp, ans);
        return ;
    }
    int x = -1, y = -1, k = 10; // k 表示（x,y)点的可能种类. 用于加速
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (val[i][j]) continue;
            int temp = 9 - count_one(~(r[i] & c[j] & g[i /3 * 3 + j / 3]));
            if (temp < k) {
                k = temp;
                x = i, y = j;
            }
        }
    }
    for (int k = 1, z = x / 3 * 3 + y / 3; k <= 9; k++) {
        int kk = (1 << k);
        if ((r[x] & kk) && (c[y] & kk) && (g[z] & kk)) {
            work(x, y, k);
            val[x][y] = k;
            dfs(cnt - 1);
            val[x][y] = 0;
            work(x, y, k);
        }
    }
}

int main() {
    int cnt = 0; // 要确定数的数量
    for (int i = 0; i < 9; i++) r[i] = c[i] = g[i] = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> val[i][j];
            if (val[i][j] == 0) cnt++;
            else work(i,j, val[i][j]);
        }
    }
    dfs(cnt);
    cout << ans << endl;
    return 0;
}
