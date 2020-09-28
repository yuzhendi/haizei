/*************************************************************************
	> File Name: str.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月27日 星期一 22时18分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "12345";
    string *p = &s;
    cout << *(p )  << endl;
    return 0;
}
