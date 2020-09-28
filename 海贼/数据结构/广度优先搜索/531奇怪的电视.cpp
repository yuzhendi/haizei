/*************************************************************************
	> File Name: 531奇怪的电视.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月21日 星期一 10时47分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int status, step; // 位运算(二进制表示)求每一种的状态
};

int n, num[25], arr[25][25], check[2200000]; // 取重数组，2^25

void init() {
    int t = 1;
    for (int i = 0; i <= 21; i++) {
        num[i] = t; // 表示第i的按钮被按下
        t = t << 1;
    }
}

int main() {
    init();
    cin >> n;
    int status_start = 0; // 初始状态
    for (int i = 1; i <= n; i++) {
        int t; 
        cin >> t;
        if (t == 1) status_start += num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0]; // 按下第 i 个按钮后会有哪些按钮被弹出的数量
        for (int j = 1; j <= arr[i][0]; j++) {
            cin >> arr[i][j];
            arr[i][24] += num[arr[i][j]]; // 存储被弹出的改变的状态
        }
    }
    queue<node> que;
    que.push({status_start, 0});
    check[status_start] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if ((temp.status & num[i]) == 0) {
                // 按钮是释放状态
                int status_temp = temp.status + num[i];
                status_temp &= (~arr[i][24]); // 减去被释放的按钮
                if (check[status_temp] == 0) {
                    check[status_temp] = 1;
                    que.push({status_temp, temp.step + 1});
                }
            }
        }
    }

    return 0;
}
