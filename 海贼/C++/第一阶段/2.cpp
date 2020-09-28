/*************************************************************************
	> File Name: 2.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月21日 星期二 20时06分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "Hello", s2 = "world!";
    s1 += " ";
    s1 += s2;
    cout << s1 << endl;
    cout << "s1.size(): " << s1.size() << endl;
    return 0;
}
