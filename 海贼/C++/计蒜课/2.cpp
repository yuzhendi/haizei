/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月15日 星期六 21时04分14秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>
using namespace std;
struct A {
    int data;
    A(int theData) 
    :data(theData) {
        
    }
};
struct  B : virtual A {
    B() : A{1} {
        cout << data << endl;
    }
};

struct C : A {
    C() : A{2} {
        cout << data << endl;
    }
};

struct D : B, C {
    D () : A{3}{

    }
};

int main() {
    D d;
    cout << d.data << endl;
    return 0;
}
