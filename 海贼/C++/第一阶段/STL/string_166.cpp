/*************************************************************************
	> File Name: string_166.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月29日 星期三 17时48分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


int main() {
    string str1, str2;
    int n;
    cin >> str1 >> n >> str2;
    cout << min(str1.length(), (size_t )(100)) << endl;
    str1.insert(n - 1, str2);
    cout << str1 << endl;
    cout << str1.length() - str1.rfind('x') << endl;
    return 0;
}
