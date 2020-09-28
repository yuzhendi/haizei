/*************************************************************************
	> File Name: 安置路灯.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月19日 星期三 16时20分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    while(n--) {
        int t, ans = 0;
        string s;
        cin >> t >> s;
        for (int i = 0; i < t; i++) {
            if (s[i] == '.') {
                ans++;
                i += 2;
            }
        
        }
        cout << ans << endl;
    }


    return 0;
}
