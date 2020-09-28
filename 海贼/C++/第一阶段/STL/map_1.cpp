/*************************************************************************
	> File Name: map_1.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月29日 星期三 22时17分10秒
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;


int main() {
    map<int, int> arr;
    arr[-100] = 3;
    arr[30] = 1;
    arr[-20] = 90;
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }


    return 0;
}
