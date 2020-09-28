/*************************************************************************
	> File Name: 1144.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月01日 星期三 16时46分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct edge {
    int to, val ,next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

edge edg[4000005];
int n, m, edg_cnt, 

int main() {

    return 0;
}
