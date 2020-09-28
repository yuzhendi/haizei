/*************************************************************************
	> File Name: 599.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月20日 星期三 20时01分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[10000005], t;

int main() {//双指针
    cin >> n >> t;        
     for (int i = 0; i < n; i++) {
        cin >> num[i];       
     }
    
    int r = n - 1, l = 0;
            while(l < r) {
                int sum = num[l] + num[r];
                if (sum == t) {
                    cout << l << " " << r << endl;
                    return 0;
                } else if (sum < t) {
                    l++;
                } else {
                    r--;
                }
            }


    return 0;
}
