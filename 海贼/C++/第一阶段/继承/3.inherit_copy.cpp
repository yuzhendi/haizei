/*************************************************************************
	> File Name: 3.inherit_copy.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月28日 星期二 20时44分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

class A {
public:
    A() {
        cout << "A 的构造" << endl;
        this->x = 0x01020304;
    }
    A(const A &a){
        cout << "A -> copy" << this <<endl;
    }
    int x;
};

class B : public A {
public:
    B() {
        cout << "B 的构造" << endl;
        this->y = 0x05060708;
    }
    B(const B &b) : A(b){ // class B b 也是一个 A类
    //B(const B &b){ // 不会调用 父类的拷贝，会直接构造一个父类的构造
        cout << "B的copy" << this << endl; // this的地址一样, 即头部是 父类A，当他变成A传参时，this指针不需要变化
    }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char*msg = (const char *)(&b1);
    for (int i = 0; i < sizeof(B); i++) {
        printf("%X",msg[i]); // 小机端：低位放在低地址
    }
    return 0;
}
