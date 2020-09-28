/*************************************************************************
	> File Name: 1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月26日 星期日 18时15分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class People {
public :
    People(){}
    People(string name) {
        this->name = name;
        cout << "有参构造函数(申请资源)" << endl;
        cout << this->name << endl;
    }
    People(int x) {
        cout << "构造函数:People(int x):" << endl;
        this->x = x;
        cout << x << endl;
    }
    People(const People &a) {
        this->name = a.name;
        this->x = a.x;
    }
    void operator=(const People &a) {
        cout << "=的默认构造" << endl;
        this->name = a.name;
        this->x = a.x;
        
    }
    ~People() {
        cout << "析构函数(释放资源)" << endl;
    }
    string name;
    int x; 
};

void incr(int &a) { // 引用，相当于绑定
    a += 1;
    return ;
}
int add(People a, People b) {
    return a.x + b.x;
}
int main() {
    int n = 0;
    incr(n);
    cout << "1 + 2 = " << add(1,2) << endl;// 类型强转，参数传递时可以类型转换
    cout << n << endl;
    People a("yu zhen di");
    //People a = string("yu zhen di");
    cout << "Hello world!" << endl;
    People b(33);
    b = 44;
    People d = a; // 拷贝构造函数的使用
    return 0;
}
