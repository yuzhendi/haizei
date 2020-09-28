/*************************************************************************
	> File Name: 1.stl.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月21日 星期二 19时51分48秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
int main() {
    int op, val;
    queue<int> q;
    cout << "每次输入1-4，和val, 1是入队列， 2 出， 3 打印头部， 4 退出" << endl;
    while(cin >> op >> val) {
        switch(op) {
            case 1: q.push(val);break;
            case 2: q.pop();break;
            case 3: cout << q.front() << endl; break;
            case 4:exit(0);break;
        }
        cout << q.size() << " 个数" << endl;
    }

    return 0;
}
