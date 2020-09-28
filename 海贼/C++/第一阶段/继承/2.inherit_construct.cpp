/*************************************************************************
	> File Name: 2.inherit_construct.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月28日 星期二 19时55分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class D{
public:
    D() {cout << "D constructor" << endl;}
    ~D() {cout << "D 析构" << endl;}
};

class A {
public :
    A(){cout << "A constructor" << endl;}
    ~A(){cout << "A 析构" << endl;}
};

class B{
public:
    B(){cout << "B constructor " << endl;} 
    ~B() {cout << "B 析构" << endl;}
};

class C: public D{
public:
    C(){cout << "C constructor" << endl;} // 隐式构造 
    // 等价于 C() : a(), b() {cout << "" << endl;}
    // 等价于 C() : b(), c() {cout << "" << endl;}
    ~C() {cout << "C 析构" << endl;}
private: // 初始化顺序：  a b c
    A a; // 由声明的顺序决定构造顺序
    B b;
};

int main() {
    C c ; // 执行顺序D B A C， 先执行父构造

    return 0;
}
