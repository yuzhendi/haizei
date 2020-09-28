/*************************************************************************
	> File Name: E.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 19时52分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int Judge(int x) {
    if (x % 4) return 0;
    if (x % 400 == 0 || (x % 100)) return 1;
    return 0;
}


int main() {
    int x, y, ans = 0;
    cin >> x >> y;
    for(int i = x; i <= y; i++) {
        if (Judge(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
