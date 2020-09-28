/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月12日 星期三 20时00分45秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

/* 单调栈解决看楼层数问题*/

int n, num[10005], ans1[10005], ans2[10005];


int main() {
    stack<int> left, right; // 两个单调栈
    cin >> n;
    left.push(99999);
    right.push(99999);
    for (int i = 1; i <= n; i ++) {
        cin >> num[i];
        ans1[i] = left.size(); // 左边能看到的楼的数量
        while(left.top() <= num[i]) {
            left.pop();
        }
        left.push(num[i]);
    }
    for (int i = n; i >= 1; i--) {
        ans2[i] = right.size();
        while(right.top() <= num[i]) {
            right.pop();
        }
        right.push(num[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << ans1[i] + ans2[i] - 1; // 左 + 右 + 脚下的楼的数量 (-1 是因为多了两个99999)
    }
    cout << endl;

    return 0;
}

