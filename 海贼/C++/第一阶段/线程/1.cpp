/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月13日 星期四 11时52分03秒
 ************************************************************************/

#include <iostream>
#include <thread>
using namespace std;

void func() {
    cout << "hello world" << endl;
    return ;
}
void func2(int x) {
    cout << x << endl;
    return ;
}
void func3(int &x) { // 最好加锁
    x += 1;
    cout << "&x" << endl;
    return ;
}

int main() {
    thread t1(func);
    t1.join(); //等待子进程的结束
    thread t2(func2, 45); // thread内部用到了bind 方法
    t2.join(); //等待子进程的结束
    int n = 0;
    thread t3(func3, ref(n)); // 传入引用
    t3.join(); //等待子进程的结束

    return 0;
}
