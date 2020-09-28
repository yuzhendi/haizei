/*************************************************************************
	> File Name: auto.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月02日 星期日 18时41分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;



int main() {
    auto a = 12;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[1] = 1;
    arr[4] = 3;
    arr[3] = 1;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto x : arr) { // C++11 新引进的语法
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
