/*************************************************************************
	> File Name: 4.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月26日 星期日 21时11分35秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class People {
public :
    People(string name) {
        cout << "string name :" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "const People &a" << endl;
        this->name = name;
    }
private :
    string name;
};

People func() {
    People temp_a("yu");
    return temp_a;
}

int main() {
    People a = func();
    return 0;
}
