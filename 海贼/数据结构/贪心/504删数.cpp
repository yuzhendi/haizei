/*************************************************************************
	> File Name: 504删数.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月22日 星期四 18时04分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int val[250];
int n;
string s;
int main() {
    cin >> s >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int ind = s.size() - 1; // 默认删除最后一位
        for (int j = 0; j < s.size() - 1; j++) {
            if (s[j] > s[j + 1]) {
                ind = j;
                break;
            }
        }
        s.replace(ind, 1, "");
    }
    int f = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            f = 1;
        }
        if (f) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
