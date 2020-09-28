/*************************************************************************
	> File Name: 327.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月26日 星期日 19时19分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000
int fa[MAX_N + 5], val[MAX_N + 5];//加权并查集
/*/一共两个监狱，将怒气值从此小到大排序，先尽量放在不同监狱，
* （不能在统一监狱的放在同一个并查及中*/
void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i ]= i;
        val[i] = 0;
    }
    return ;
}

int get(int x) {
    if (x== fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 2;//0 在同一个， 1不再
    return fa[x] == root;
}
int merge(int a, int b, int t) {
    int x = get(a), y = get(b);
    if (x == y) {
        return (val[x] - val[b] - t) %2 == 0;
    }
    fa[x] = y;
    val[x] = (t + val[b] - va[a] + 2) % 2;
    return 1;//不放在同一个监狱里
}
struct Data {
    int x, y, c;
} arr[MAX_M];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].t;
    }
    sort(arr, arr + m, cmp);
    arr[m].x = arr[m].y = 1;
    arr[m].c = 0;
    for (int i = 0; i <=m; i++) {
        if (merge(arr[i].x, arr[i].y, 1)) continue;// 安排不同监狱
        cout << arr[i].c << endl;
        break;
    }
    return 0;
}

