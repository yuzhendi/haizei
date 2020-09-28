/*************************************************************************
	> File Name: 287.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月23日 星期四 18时53分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<long long, long long >PLL;

int main() {
    int n, t= 0;
    set<PLL> s; // 防止去重
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long height;
        cin >> height;
        s.insert(PLL(height, t++));
    }
    long long sum = 0;
    for(int i = 0; i < n - 1; i++) {
        long long a = s.begin()->first;
        s.erase(s.begin());
        long long b = s.begin()->first;
        s.erase(s.begin());
        sum += (a + b);
        s.insert(PLL(a+b, t++));
    }
    cout << sum << endl;

    return 0;
}
