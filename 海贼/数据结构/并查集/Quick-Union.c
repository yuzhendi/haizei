/*************************************************************************
	> File Name: Quick-Find.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月23日 星期四 22时13分31秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *father, *size;//只需要路径压缩，不需要安节点多少来判断(高度为1)
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->size = (int *)malloc(sizeof(int) * (n + 1));
    u->father = (int *)malloc(sizeof(int) * (n + 1));
    u->n = n;
    for (int i = 1; i <= n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    return u;
}

int find(UnionSet *u, int x) {
    //找代表元素，根结点
    if (u->father[x] == x) return x;
    
    return u->father[x] = find(u, u->father[x]);//路径压缩
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] > u->size[fb]) {
        u->father[fb] = fa;//b 挂到 a上
        u->size[fa] += u->size[fb];
    } else {
        u->father[fa] = fb;
        u->size[fb] += u->size[fa];
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u->size);
    free(u);
    return ;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    UnionSet *u = init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: merge(u, b, c); break;
            case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No"); break;
        }
    }
    clear(u);
    return 0;
}

