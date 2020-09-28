/*************************************************************************
	> File Name: 245.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月17日 星期日 19时26分34秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int pos = a[n >> 1];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - pos);
    }
    cout << sum << endl;
    return 0;
}
