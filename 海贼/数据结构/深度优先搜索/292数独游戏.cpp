/*************************************************************************
	> File Name: 292数独游戏.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月10日 星期四 20时08分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
string s;
int x[9], y[9], z[9], gx, gy, gz; // x y z 表示行 列 和 九宫格的序号（0-8, 二进制位置为1表示可以选取）； gx gy gz 表示具体位置
void get(int i) {
    // 求 s[i] 的具体位置
    gx = i / 9;
    gy = i % 9;
    gz = (gx / 3) * 3 + gy / 3;
    return ;
}

void work(int i, int num) { // s[i] 的位置上数字为num, 0->1 或者 1->0
    get(i);
    x[gx] ^= (1 << num);
    y[gy] ^= (1 << num);
    z[gz] ^= (1 << num);
    return ;
}

int cnt_one(int x) { // 求二进制数x里面1的个数
    int ret = 0;
    while(x) ret += 1, x &= (x - 1);
    return ret;
}

bool dfs(int cnt) {
    if (cnt == 0) return true;
    int ind = -1, k = 100; // ind 表示可能填充数字情况最小的位置
    for (int i = 0; i < 81; i++) {
        if (s[i] != '.') continue;
        get(i); // 获取s[i] 对应的位置
        int temp = 9 - cnt_one(~(x[gx] & y[gy] & z[gz])); // temp 表示可能填充的数字的种数
        if (temp < k) {
            ind = i;
            k = temp;
        }
    }
    for (int i = 1; i <= 9; i++) {
        get(ind); // 从最小情况位置数开始，减少dfs的数量
        if (x[gx] & y[gy] & z[gz] & (1 << i)) {
            // 可以 填 i
            work(ind, i);
            s[ind] = i + '0'; // 可以覆盖，不用再改
            if (dfs(cnt - 1)) return true; // 情况走的通
            s[ind] = '.'; // 复原
            work(ind, i);
        }
    }
    return false;

}
void Sudoku() {
    for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = -1;
    int cnt = 0;
    for (int i = 0; i < 81; i++) {
        if (s[i] == '.') {
            cnt += 1;
            continue;
        }
        work(i, s[i] - '0');
    }
    dfs(cnt);
    cout << s << endl;
    return ;
}
/*
void Sudoku {
    for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = -1;
    for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = -1; // ；利用二进制上的1表示对应数字可以选
    int cnt = 0; // 表示要填充的数的个数
    for (int i= 0; i < 81; i++) {
        if (s[i] == '.') {
            cnt += 1; 
            continue;
        }
        work(i, s[i] - '0'); // 对应位置的数字变为不可填
    }
    dfs(cnt); // 深搜求答案
    cout << s << endl;
    return ;
}
*/
int main() {
    while(cin >> s && s[0] != 'e') Sudoku();
    
    return 0;
}
