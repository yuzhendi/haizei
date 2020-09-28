/*************************************************************************
	> File Name: 223.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月24日 星期五 17时03分10秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000
#define lc(ind) (tree[ind].lind)
#define rc(ind) (tree[ind].rind)
#define tag(ind) tree[ind].tag
#define sum(ind) tree[ind].sum
#define cnt(ind) tree[ind].cnt

struct node {
    long long sum, tag, cnt;//tag为懒标记，cnt为当前区间的节点数
    int lind, rind;
} tree[(MAX_N << 1) + 5];
int root = 0, cnt = 1;
long long arr[MAX_N + 5];

void build(int ind, int l, int r);
    //建立线段树
void UP(int ind);
    //更新节点
void modify(int ind, int x, int y, long long  d, int l, int r);
    //修改操作
long long  query(int ind, int x, int y, int l, int r);
    //查询区间长度和

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(root, 1, n);
    for (int i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            modify(root, b, c, d, 1, n);
        } else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    return 0;
}
int getNode() { return cnt++; }

void DOWN(int ind) {
    //下沉一次
    if (tag(ind)) {
        tag(lc(ind)) += tag(ind);
        tag(rc(ind)) += tag(ind);
        sum(lc(ind)) += tag(ind) * cnt(lc(ind));
        sum(rc(ind)) += tag(ind) * cnt(rc(ind));
        tag(ind) = 0;
    }
    return ;
}

void UP(int ind) {
    tree[ind].sum = tree[lc(ind)].sum + tree[rc(ind)].sum;
}

void build(int ind, int l, int r) {
    tree[ind].cnt = (r - l + 1);
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    tree[ind].lind = getNode();
    tree[ind].rind = getNode();
    build(lc(ind), l, mid);
    build(rc(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, long long d, int l, int r) {
    //在[x,y]区间中加上d
    if (x <= l && r <= y) {
        tree[ind].tag += d;
        tree[ind].sum += d * tree[ind].cnt;
        return ;
    }
    DOWN(ind);//下沉一次
    /*递归操作*/
    int mid = (l + r) >> 1;
    if (x <= mid) modify(lc(ind), x, y, d, l, mid);
    if (y > mid) modify(rc(ind), x, y, d, mid + 1, r);
    /*递归结束*/
    UP(ind);
    return ;
}

long long query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return sum(ind);
    }
    DOWN(ind);//查到这个节点就下沉一次
    int mid = (l + r) >> 1;
    long long ans = 0;
    if (x <= mid) ans += query(lc(ind), x, y, l, mid);
    if (y > mid) ans += query(rc(ind), x, y, mid + 1, r);
    return ans;
}

