/*************************************************************************
	> File Name: visitor.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月18日 星期二 09时57分56秒
 ************************************************************************/
 
/*************************************************************************
   > File Name: 28.visitor.cpp
   > Author: 
   > Mail: 
   > Created Time: 二  3/24 18:29:20 2020
 ************************************************************************/

#include <iostream>
#include <ctime>
using namespace std;

class B; // +5
class C; // *2
class D; // -4
class E; // +6
class F; // -7

class A {
public :
    class IVisitor {
    public :
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
    };
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    virtual ~A() {}
};

class B : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class C : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class D : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class E : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class F : public A {
public :
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class OutputVisitor : public A::IVisitor {
public :
    virtual void visit(A *obj) {
        cout << "this is father class A" << endl;
    }
    virtual void visit(B *obj) {
        cout << "this is a class B object" << endl;
    }
    virtual void visit(C *obj) {
        cout << "this is a class C object" << endl;
    }
    virtual void visit(D *obj) {
        cout << "this is a class D object" << endl;

    }
    virtual void visit(E *obj) {
        cout << "this is a class E object" << endl;
    }
    virtual void visit(F *obj) {
        cout << "this is a class F object" << endl;
    }
};

class CalcVisitor : public A::IVisitor {
public :
    CalcVisitor(int val = 1) : val(val) {}
    virtual void visit(A *obj) {}
    virtual void visit(B *obj) { val += 5; }
    virtual void visit(C *obj) { val *= 2; }
    virtual void visit(D *obj) { val -= 4; }
    virtual void visit(E *obj) { val += 6; }
    virtual void visit(F *obj) { val -= 7; }
    int val;
};

int main() {
    srand(time(0));
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 5) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
            case 4: arr[i] = new F(); break;
        }
    }
    OutputVisitor vis1;
    CalcVisitor vis2;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis1);
        arr[i]->Accept(&vis2);
    }
    cout << vis2.val << endl;
    return 0;
}

