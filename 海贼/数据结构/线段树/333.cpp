/*************************************************************************
	> File Name: 333.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月25日 星期六 07时26分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 500000
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)

struct Node {
    int sum, inmax, lmax, rmax;//sum为区间和， inmax:中间部分最长...
} tree[MAX_N << 2];
int root = 1;
int arr[MAX_N + 5];

void build(int ind, int l, int r);
    //建立线段树
void UP(int ind);
    //更新节点
void modify(int ind, int x, int y, int l, int r);
    //修改操作
void query(int ind, int x, int y, int l, int r, Node &ret);
    //查询区间最大连续序列和，放到ret节点内


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        cin >> k >> x >> y;
        switch (k) {
            case 2: modify(root, x, y, 1, n); break;
            case 1: {
                if (x > y) swap(x, y);
                Node ret;
                query(root, x, y, 1, n, ret);
                cout << ret.inmax << endl;
            } break;
        }
    }
    return 0;
}
void _UP(Node &a, Node &b) {
    //a ， b 分别为左右子树，将结果更新到节点a中
    a.inmax = max(a.inmax, max(b.inmax, a.rmax + b.lmax));
    a.lmax = max(a.lmax, a.sum + b.lmax);
    a.rmax = max(b.rmax, b.sum + a.rmax);
    a.sum += b.sum;
}

void UP(int ind) {
    //更新Ind位置处的值
    tree[ind] = tree[lc(ind)];
    _UP(tree[ind], tree[rc(ind)]);
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int l, int r) {
    //修改操作，[l,r]区间x位置处改称y
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, l, mid);
    else modify(rc(ind), x, y, mid + 1, r);
    UP(ind);
    return ;
}

void query(int ind, int x, int y, int l, int r, Node &ret) {
    if (x <= l && r <= y) {
        if (l == x) ret = tree[ind];
        else _UP(ret, tree[ind]);
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) query(lc(ind), x, y, l, mid, ret);
    if (y > mid) query(rc(ind), x, y, mid + 1, r, ret);
    return ;
}


