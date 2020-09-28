/*************************************************************************
	> File Name: nullptr.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月02日 星期日 20时06分43秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int f(int x) {
    cout << "output: intval: " << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address: " ;
    cout << x << endl;
    return 0;
}

int main() {
    cout << sizeof(NULL) << endl;
    cout << sizeof(nullptr) << endl;
    int n = 11, *p = &n;
    f(n);
    f(p);
    f(nullptr);//本质是一个地址
    //f(NULL); NULL：本质是一个整形， 看作一个地址
    f(int(NULL));
    //f((void *)(NULL)); error
    return 0;
}
