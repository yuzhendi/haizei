/*************************************************************************
	> File Name: t.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年10月29日 星期四 19时37分00秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
void example(char acWelcome[]){
    printf("%d",sizeof(acWelcome));
    return;
}
int main(){
    char acWelcome[]="Welcome to Huawei Test";
    example(acWelcome);
    return 0;
}
