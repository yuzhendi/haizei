/*************************************************************************
	> File Name: 328_.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 20时16分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200000
#define lowbit(x) (x & (-x));
int c[MAX_N + 5] = {0};

int S(int i) {
    int sum = 0;
    while(i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
void add(int i, int val, int n) {
    while(i <= n) c[i] += val, i += lowbit(i);
}
int n;
int main() {
    cin >> n;
    int val;
    long long _n1, n1_, _n2, n2_;//必须long long
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        add(val + 1, 1, n);
        _n1 = S(val);//前面小于 val[i] 的数量
        _n2 = i - _n1 - 1;//前面大于 val[i] 的数量
        n1_ = val - 1 - _n1;//后面小于 val[i] 的数量
        n2_ = n - val - _n2;//后面大于 val[i] 的数量
        ans1 += 1LL * (_n1 * n1_);
        ans2 += 1LL *(_n2 * n2_);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
