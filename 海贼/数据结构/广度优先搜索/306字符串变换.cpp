/*************************************************************************
	> File Name: 306字符串变换.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月21日 星期一 08时45分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
string A, B;
int cnt;
int ans = 0x3fffffff;
string rule[7][2]; // 转换规则
struct node  {
    string now;
    int step;
};
map<string, int> check; // 取重， 防止相同的字符串多次进行转换


int main() {
    cin >> A >> B;
    while(cin >> rule[cnt][0] >> rule[cnt][1]) {
        cnt++;
    }
    queue<node> que;
    que.push({A, 0});
    check[A] = 1;
    while(!que.empty()) {
        for (int i = 0; i < cnt; i++) {
            // 对每一种规则进行转换
            int j = 0; // 从s[0]开始
            while(1) {
                node temp = que.front();
                int x = temp.now.find(rule[i][0], j); // 从j位置向后找
                j = x + 1;
                if (x != string::npos) {
                    temp.now.replace(x, rule[i][0].size(), rule[i][1]);
                    temp.step++;
                    if (temp.step > 10) continue; 
                    if (check[temp.now] == 1) continue; //字符串已经找过
                    if (temp.now == B) {
                        cout << temp.step << endl;
                        return 0;
                    }
                    check[temp.now] = 1;
                    que.push(temp);
                } else {
                    break;
                }
            }

        }
        que.pop();
    }
    cout << "NO ANSWER!" << endl;
    return 0;
}
