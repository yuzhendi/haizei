/*************************************************************************
	> File Name: 253奶牛晒太阳.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月29日 星期二 16时12分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 2500
int c, l;
struct Data {
    int x, y; // 可以看作在区间里面放入点的类型
}cows[MAX_N + 5]; 
int cnt[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    if (a.y - b.y) return a.y < b.y; // 优先考虑右区间靠左的位置
    return a.x > b.x; // 当右边界相同时，尽量选择左边界考右的（小区间）
};

int main() {
    cin >> c >> l;
    for (int i = 0; i < c; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a] += b; // 可能有相同的防晒霜多次输入
    }
    sort(cows, cows + c, cmp); // 排序规则优先放置被包含的区间以及重叠时靠左的区间位置
    int ans = 0;
    for (int i = 0; i < c; i++) {
        for (int j = cows[i].x; j <= cows[i].y; j++) {
            if (cnt[j] == 0) continue;
            ans++;
            cnt[j] -= 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
