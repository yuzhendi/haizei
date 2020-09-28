/*************************************************************************
	> File Name: 516.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 20时28分40秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100000
string str;
long long n, ans, num_c[MAX_N + 5], num_w[MAX_N], nc, nw;
//解决：遍历所有O 左边的 C 的数量 * 右边 W 的数量为 COW 的总数量
//用前缀和数组 记录C 和 W 的数量
int main() {
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') nc++;
        num_c[i] = nc;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'W') nw++;
        num_w[i] = nw;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == 'O') {
            //cout << "No." << ans << endl;
            ans += (num_c[i] * num_w[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
