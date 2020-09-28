/*************************************************************************
	> File Name: 5.set.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月23日 星期四 18时14分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
//底层也是红黑数
int main() {
    set<int> s; // 自带去重
    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(4);
    cout << "s.size() : "<< s.size() << endl;
    cout << "*s.begin(): " << *(s.begin()) << endl;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << "after erase s.begin(), s.begin() : "*s.begin() << endl;
    return 0;
}
