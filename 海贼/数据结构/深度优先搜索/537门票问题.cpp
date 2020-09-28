/*************************************************************************
	> File Name: 537门票问题.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年09月11日 星期五 22时13分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char arr[30], ans[16];
int ans_cnt, ycnt, fcnt, sum;
bool cmp(char a, char b) {
    return a < b;
}

int dfs(int s, int left) {
    if (left == 0) {
        if (!(ycnt >= 1 && fcnt >= 2)) return 0;
        for (int i = 0; i < l; i++) {
            cout << ans[i];
        }
        cout << endl;
        sum++;
        if (sum >= 25000) return -1;
        return 0;
    }
    for (int i = s; i < c; i++) {
        int flag = 0;
        switch(arr[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': ycnt++; break;
            default : flag = 1, fcnt++; break; 
        }
        ans[ans_cnt++] = arr[i];
        if (dfs(i + 1, left - 1) == -1) return -1;
        ans_cnt--;
        if (flag == 1) fcnt--;
        else ycnt--;
    }
    return 0;
}


int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + c, cmp);
    dfs(0, l); // 从0号位置搜索， 剩余数量为 l
    return 0;
}
