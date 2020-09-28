/*************************************************************************
	> File Name: 216.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月23日 星期四 18时27分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<string, int> PSI;

int main() {
    set<PSI> s; //set 自带去重，防止去重
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        name = name.substr(name.find('.') + 1, name.size());  // 截取字符串， 传入足够大的长度会找到字符串末尾
        s.insert(PSI(name, i)); // name 相等时 比较 i
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;  //输出第一项的字符串
    }

    return 0;
}
