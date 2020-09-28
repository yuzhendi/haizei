/*************************************************************************
	> File Name: 4.inherit_problem.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月01日 星期六 15时13分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct A{
    int x;
};
struct B :virtual public A{ // 虚拟继承， 会将多余的继承的同一个父类合成一个 解决了菱形继承的问题
    void set(int x) {
        this->x = x;
        cout << "set: " <<&this->x << endl;
    }
};
struct C : virtual public A{
    int get() {
        cout << "get: " << &this->x << endl;
        return x;
    }
};
struct D : public B, public C{

};
int main() {
    D d;
    d.set(44); // x 指向不明， 有两个x
    cout << d.get() << endl;
    return 0;
}
