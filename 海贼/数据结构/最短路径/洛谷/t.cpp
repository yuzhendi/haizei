#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct edge {
  int e, next;
};

struct node {
  int now, dist;
  bool operator< (const node &b) const {
    return this->dist > b.dist;
  }
};

int n, m, mcnt, head[1000005], ans[1000005], cnt[1000005];
edge edg[4000005];//无向图

void add(int x, int y) {
  edg[mcnt].e = y;
  edg[mcnt].next = head[x];
  head[x] = mcnt;
  mcnt++;
}

int main() {
  memset(head, -1, sizeof(head));
  memset(ans, 0x3F, sizeof(ans));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  priority_queue<node> que;
  que.push((node){1, 0});
  ans[1] = 0;
  cnt[1] = 1;
  while (!que.empty()) {
    node temp = que.top();
    que.pop();
    if (temp.dist > ans[temp.now]) {
      continue;
    }
    for (int i = head[temp.now]; i != -1; i = edg[i].next) {
      int e = edg[i].e;
      if (ans[e] > ans[temp.now] + 1) {//两种情况
        ans[e] = ans[temp.now] + 1;
        cnt[e] = cnt[temp.now];
        que.push((node){e, ans[e]});
      } else if (ans[e] == ans[temp.now] + 1){
        cnt[e] += cnt[temp.now];
        cnt[e] %= 100003;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << cnt[i] << endl;
  }
  return 0;
}
