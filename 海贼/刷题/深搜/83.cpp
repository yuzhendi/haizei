/*************************************************************************
	> File Name: 83.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月27日 星期四 21时24分21秒
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int s, int left_num, int left_cnt) {//从s开始，传入剩余的数和剩余的个数
    if (left_cnt == 0) {
        if (left_num == 0) return 1;//成功
        return 0; //失败
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}
