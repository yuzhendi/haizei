/*************************************************************************
	> File Name: 325.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月26日 星期日 18时22分42秒
 ************************************************************************/
#include <iostream>
#include<algorithm>
#include<map>
using namespace std;
#define MAX_N 10000
int fa[MAX_N + 5], val[MAX_N + 5];//坐标映射，最多需要Q*2ge 坐标


void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i] = 0;//到副节点的距离, 加权并查集，0表示偶数，1表奇数
    }
    return ;
}

int get(int x) {
    if (x == fa[x]) return x;//一直错误， 写成 x = fa[x];
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 2;
    return fa[x] = root;
}

int merge(int x, int y, int t) {
    //t=0表示偶数
    int a = get(x), b = get(y);
    if (a == b) {
        return (val[x] - val[y] - t) % 2 == 0;
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 2) % 2;
    return 1;//连接了两集合
}
map<int,int> ind;//坐标映射
 int ind_cnt = 0; 
struct Data {
    int x, y;
    string t;
} arr[MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].t;
        arr[i].y += 1;//左闭右开
        ind[arr[i].x] = 0;
        ind[arr[i].y] = 0;
    }
    for (auto iter = ind.begin(); iter != ind.end(); iter++) {
        //坐标离散化
        iter->second = (++ind_cnt);
    }
/*for (int i = 0; i < n; i++) {
     * 映射后的坐标
        cout << ind[arr[i].x] <<" "<< ind[arr[i].y] << end;
    }/*/
    init(ind_cnt);
    for (int i = 0; i < m; i++) {
        if (merge(ind[arr[i].x],ind[arr[i].y], arr[i].t[0] == 'o')) continue;
        cout << i << endl;
        return 0;
    }
    cout << m << endl;
    return 0;
}
