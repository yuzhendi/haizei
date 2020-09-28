/*************************************************************************
	> File Name: 3.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月27日 星期一 20时04分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class A {
public :
    int x, y;
};

class B {  // 内在实现很复杂
public :
    B():obj(nullptr) {
        arr = new int[10];
        arr[3] = 99;
    }
    B(A *obj):B() {
        this->obj = obj;
    }
    int operator()(int a, int b) {
        return a + b;
    }
    int &operator[](int ind) {
        return arr[ind];
    }
    void operator[](const char *msg) {
        cout << msg << endl;
        return ;
    }
    A &operator*() { // 返回指针指向的值
        return *obj;         
    } 
    ~B() {
        delete this->arr;
    }
    A *operator->() { // 返回 A 的地址
        return obj;
    }
private :
    int *arr;
    A *obj;
};

ostream &operator<<(ostream &out, const A a) {
    cout << "A: " << a.x << " , " << a.y << endl;
    return out;
}

int main() { // 外部表现很简单
    B add; //函数对象
    cout << add(3, 4) << endl;
    cout << add[3] << endl; // 数组对象
    add[3] = 0;
    cout << add[3] << endl;
    add["Hello world~"];
    A a;
    a.x = 77;
    a.y = 88;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;
    return 0;
}
