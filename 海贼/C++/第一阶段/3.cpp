/*************************************************************************
	> File Name: 3.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月21日 星期二 20时10分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <map> // 有序的， 底层是红黑数
#include <unordered_map> // 非排序哈希表
using namespace std;

int main() {
    //map<double, string> arr;
    unordered_map<double, string> arr;
    arr[1.2] = "1.2";
    arr[2.4] = "2.4";
    arr[-2.3] = "-2.3";
    arr[78] = "78";
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }


    return 0;
}
