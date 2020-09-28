/*************************************************************************
	> File Name: 1.class.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月25日 星期六 16时19分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class People {
    friend int main();// 在 int main() 函数里可以访问私有成员和方法
    int x, y;
public:
    void set(int x);
    void say();
};

void People::set(int x) {
    this->x = x;
    return ;
}
void People::say() {
    cout << x << " " << y << endl; // 首先在函数内部查找x, 接下来去类里面查找 x
}

int main() {
    People a;
    friend People b;
    b.y = 2;
    b.x = 2;
    b.say();
    a.set(3);
    a.say();

    return 0;
}
