/*************************************************************************
	> File Name: 4.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年07月21日 星期二 20时53分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b; // a > b 的时候排在 b 前面
}
struct CMP_FUNC {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int arr[1000+ 5], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) cout << arr[i] << " "; // 默认从小到大排序
    cout << endl;
    sort(arr, arr + n, cmp);
    //sort(arr, arr + n, CMP_FUNC());
    //sort(arr, arr + n, [](int a, int b)->bool {return a > b;});
    for (int i = 0; i < n; i++) cout << arr[i] << " "; 
    cout << endl;
    nth_element(arr, arr + 1, arr + n); // 快速选择排序 O(n), 只保证arr[1]是正确的位置
    cout << "第 2 小的元素:" << arr[1] << endl;
    return 0;
}
