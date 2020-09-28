/*************************************************************************
	> File Name: visitor2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月18日 星期二 10时36分16秒
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;
class B;
class C;
class D;
class E;

class A {
public :
    class IVisitor{
    public:
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *vis) = 0;
    virtual ~A(){} 
};

class B : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class C : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class D : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class E : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor {
public:
    virtual void visit(A *obj) override {
        cout << "this is father class A" << endl;
    } 
    virtual void visit(B *obj) override {
        cout << "this is a class B object" << endl;
    }
    virtual void visit(C *obj) override {
        cout << "this is a class C object" << endl;
    }
    virtual void visit(D *obj) override {
        cout << "this is a class D object" << endl;
    }
    virtual void visit(E *obj) override {
        cout << "this is a class E object" << endl;
    }
};

int main() {
    srand(time(0));
    A *arr[5];
    for (int i = 0; i < 5; i++) {
        switch(rand() % 4) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
        }
    }
    OutputVisitor obj;
    for (int i = 0; i < 5; i++) {
        arr[i]->Accept(&obj);
    }


    return 0;
}
