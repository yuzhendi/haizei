/*************************************************************************
	> File Name: 222.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月24日 星期五 16时11分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)


struct node {
    int sum;
} tree[MAX_N << 2 + 5];
int root = 1;//根结点的下标
int arr[MAX_N + 5];//存放原数组的值

void UP(int ind);
    //更新节点内容
void build(int ind, int l, int r);
    //建立线段树
void modify(int ind, int x, int y, int l, int r);
    //在[l,r]中x位置的数改称 y
int query(int ind, int x, int y, int l, int r);
    //寻找区间的最大值
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(root, 1, n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            modify(root, b, c, 1, n);
        } else {
            cout << query(root, b, c, 1, n) << endl;
        }
    }
    return 0;

}
void UP(int ind) {
    tree[ind].sum = max(tree[lc(ind)].sum, tree[rc(ind)].sum);
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        //叶子节点
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lc(ind), l, mid);//构建左子树
    build(rc(ind), mid + 1, r);//构建右子树
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int l, int r) {
    //在[l,r]中x位置的数改称 y
    if (l == r) {
        if (l - x) {
            //坐标超出
            return ;
        } else {
            tree[ind].sum = y;
            return ;
        }
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        modify(lc(ind), x, y, l, mid);
    } else {
        modify(rc(ind), x, y, mid + 1, r);
    }
    UP(ind);
    return ;
}
int query(int ind, int x, int y, int l, int r) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    int ans = 0x80000000, mid = (l + r) >> 1;
    if (x <= mid) ans = max(ans, query(lc(ind), x, y, l, mid));
    if (y > mid) ans = max(ans, query(rc(ind), x, y, mid + 1, r));
    return ans;
}

