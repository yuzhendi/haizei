/*************************************************************************
	> File Name: c_arr.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月24日 星期日 17时09分18秒
 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))
int c[MAX_N + 5] = {0};

void add(int i, int val, int n) {
    while (i <= n) c[i] += val, i += lowbit(i);
    return ;
}

int S(int i) {
    int sum = 0;
    while (i) sum += c[i], i -= lowbit(i);
    return sum;
}

int main() {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cout << S(a) << endl;
        add(a, 1, n);
    }
    return 0;
}
