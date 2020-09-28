/*************************************************************************
	> File Name: 334.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月24日 星期五 22时10分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAX_N 500000
struct Node {
    long long d;
} tree[MAX_N << 2];
int root = 1;
long long c[MAX_N + 5];
/*树状数组*/
inline int lowbit(int x) { return x & (-x); }

void add(int x, long long val, int n) {
    while (x <= n) c[x] += val, x += lowbit(x);
}

long long query(int x) ;

long long gcd(long long a, long long b);
    //获取最大公约数
void UP(int);
    //更新节点所在区间的最大公约数
void build(int ind, int l, int r);
    //建立线段树
void modify(int ind, int x, long long y, int l, int r);
    //修改操作
long long query(int ind, int x, int y, int l, int r);
    //查询最大公约数
    

int main() {
    int n, m;
    long long now, pre = 0;
    char str[10];
    cin >> n >> m;
    build(root, 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> now;//拆分数据加进数组中
        modify(root, i, now - pre, 1, n);
        add(i, now - pre, n);
        pre = now;
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        switch (str[0]) {
            case 'Q': {
                int l, r;
                long long x;
                cin >> l >> r;
                x = query(l);
                cout << abs(gcd(x, query(root, l + 1, r, 1, n))) << endl;
            } break;
            case 'C': {
                int l, r;
                long long d;
                cin >> l >> r >> d;
                modify(root, l, d, 1, n);
                modify(root, r + 1, -d, 1, n);
                add(l, d, n);
                add(r + 1, -d, n);
            } break;
        }
    }
    return 0;
}



long long query(int x) {
    long long sum = 0;
    while (x) sum += c[x], x -= lowbit(x);
    return sum;
}

long long gcd(long long a, long long b) {
    return (b ? gcd(b, a % b) : a);
}

void UP(int ind) {
    //更新节点所在区间的最大公约数
    tree[ind].d = gcd(tree[ind << 1].d, tree[ind << 1 | 1].d);
}

void build(int ind, int l, int r) {
    if (l == r) {
        tree[ind].d = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    return ;
}

void modify(int ind, int x, long long y, int l, int r) {
    //在x处加上y
    if (l == r) {
        if (x - l) return ;//x != y  
        tree[ind].d += y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(ind << 1, x, y, l, mid);
    else modify(ind << 1 | 1, x, y, mid + 1, r);
    UP(ind);
    return ;
}

long long query(int ind, int x, int y, int l, int r) {
    //当前坐标所在区间的最大公约数
    if (x > y) return 0;
    if (x <= l && r <= y) {
        return tree[ind].d;
    }
    long long ans = 0;
    int mid = (l + r) >> 1;
    if (x <= mid) ans = gcd(query(ind << 1, x, y, l, mid), ans);
    if (y > mid) ans = gcd(query(ind << 1 | 1, x, y, mid + 1, r), ans);
    return ans;
}

