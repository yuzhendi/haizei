/*************************************************************************
	> File Name: 222.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月24日 星期五 16时11分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_N 10000
#define lc(ind) (ind << 1)
#define rc(ind) (ind << 1 | 1)


struct node {
    int sum;
} tree[MAX_N << 2 + 5];
int root = 1;//根结点的下标

struct star {
    int x, int y, int c;
} S[MAX_N];

int arr[MAX_N + 5];//存放原数组的值

void UP(int ind);
    //更新节点内容
void build(int ind, int l, int r, int low, int h);
    //建立线段树
void modify(int ind, int x, int y, int l, int r, int low, int h);
    //在[l,r]中x位置的数改称 y
int query(int ind, int x, int y, int l, int r, int low, int h);
    //寻找区间的最大值
int main() {
    int n, w, h;
    while(~scanf("%d%d%d",&n,&w,&h)) {
    for(int i = 1; i <= n; i++) {
        cin >> S[i].x >> S[i].y >> S[i].c;
    }
    build(root, 1, n, 1, h);
    int ans = query(root, 1, w, 1, h);
    for (int i = 1; i <= )
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

