/*************************************************************************
	> File Name: 3.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月12日 星期三 20时34分05秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/*动态规划解决小明休息时间最少天树的问题*/

#define MAX_N 100000

int n, work[MAX_N + 5], gym[MAX_N + 5], ans[MAX_N + 5][3]; // ans[i][0]： 工作时最少休息数  ans[i][1] ： 健身  ans[i][2]： 休息
int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> work[i];
    for (int i = 1; i <= n; i++) cin >> gym[i];
    if (work[1] == 1) ans[1][0] = 0;
    if (gym[1] == 1) ans[1][1] = 0;
    ans[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        if (work[i] == 1) { // 当天工作， 休息的天数是昨天休息或健身的最小值
            ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]);
        }
        if (gym[i] == 1) { // 当天健身， 休息的天数是昨天休息或工作的最小值
            ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]);
        }
        ans[i][2] = min(ans[i - 1][0], min(ans[i - 1][1], ans[i - 1][2])) + 1; // 当天休息，是昨天三种情况的最小值加一
    }
    cout << min(ans[n - 1][0], min(ans[n - 1][1], ans[n - 1][2]));

    return 0;
}
