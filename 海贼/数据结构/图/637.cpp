/*************************************************************************
	> File Name: 637.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月29日 星期三 18时07分03秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge{
    int to, next;
};
edge edg[10000];

int n, m, head[30], in_degree[30], edg_cnt, ans_cnt;
char ans[30];

void insert_edg(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    head[a] = x;
    edg_cnt = x + 1;
    in_degree[b]++;
}

int check() {
    int temp_in[30];
    ans_cnt = 0;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        temp_in[i] = in_degree[i];
        if (temp_in[i] == 0) {
            que.push(i);
        }
    }
    int f1 = que.size(); // 入读为0的点的数量  这里f1的值不确定， 因为有没有读如的，初始化为0
    int f2 = 0;
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        int f3 = 0;
        ans[++ans_cnt] = t + 'A' - 1;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            temp_in[e]--;
            if (temp_in[e] == 0) {
                if (f3 == 1) {
                    f3 = 2; // 答案不确定
                    return 0;
                } else if(f3 == 0){
                    f3 = 1;
                }
                que.push(e);
            }
        }
        if (f3 == 2) f2 == 2;
    }
    for (int i = 1; i <= n; i++) {
        if (temp_in[i] != 0) {
            return 1;
        }
    }
    if (f1 != 1 || f2 == 2) return 0;
    return 2;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> b;
        insert_edg(a - 'A' + 1, b - 'A' + 1, i);
        int t = check(); // 0: normal  1 : error 2: right  // 每次输入检查一遍是否成环或者无法判断
        if (t == 1) { // 有环直接退出
            cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            return 0;

        } else if (t == 2) {
            cout << "Sorted sequence determined after " << i + 1 << " relations: ";
            int check();
            for (int i = 1; i <=ans_cnt; i++) {
                cout << ans[i];
            }
            cout << "." << endl;
            return 0;
        }

    }
            cout << "Sorted sequence cannot be determined." << endl;


    return 0;
}
