/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 16时41分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class A {
    public:
    int x;
    virtual void run(int x) {// 参数有隐藏的this, 编译器会自动增加
        cout << "this->x: " << this->x << endl;
    } // 只存放一个指针指向虚函数表
    virtual void run1() {}
};

typedef void (*func)(void *, int); // 成员函数有隐藏的this

int main() {
    cout << sizeof(A) << endl;
    A temp_a, temp_b;
    temp_a.x = 122;
    temp_b.x = 8888;
    ((func **)(&temp_a))[0][0](&temp_a, 6);
    return 0;
}
