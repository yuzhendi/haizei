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
    People() {
        arr = new int[10];
        cout << "默认构造函数(申请资源)" << endl;
    }
    ~People() {
        delete arr;
        cout << "析构函数(释放资源)" << endl;
    }
    
};


int main() {
    People a; // 局部变量， main结束后自动调用析构函数
    cout << "Hello world!" << endl;
    return 0;
}
