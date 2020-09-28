/*************************************************************************
	> File Name: turing.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月13日 星期四 14时25分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
template <int n>
struct IsEven { // 判断n 是否时偶数
    static constexpr int r = !(n % 2); 
};

template <int a, int b>

struct Add {
    static constexpr int r = a + b;
};

template<int n>
struct Sum {
    static constexpr int r = (n + Sum<n - 1>::r);
};
template<> 
struct Sum<1> {
    static constexpr int r = 1;  
};
template<int n>
struct Factorial{
    static constexpr int r = (n * Factorial<n - 1>::r);
};
template<> 
struct Factorial<1> {
    static constexpr int r = 1;  
};

template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n); // 根据n的大小判断是否可以停止
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1); // 根据 i 是否时素数判断是否加一
};

template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<0, i> { // i * i > n 的情况 是素数
    static constexpr int r = 1;
};
template<int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};
template<int i>
struct IsTest<1, i> {
    static constexpr int r = 0;
};
template<int n>
struct IsTest<n, 0> { // n % i == 0 的情况不是素数
    static constexpr int r = 0;
};

template<int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};
/*
template<int n, int m>
struct check {
    static constexpr bool r = (n % m != 0) && check<n, m - 1>::r;
};

template<int n>
struct Check<n, 2>{
    static constexpr bool r = (n%2 != 0);
};


template<int n>
struct IsPrime{
    static constexpr int r = Check<n, (int)sqrt(n)>::r;
};
*/
template<int n>
struct SumPrime {
    static constexpr int r = (IsPrime<n>::r * n) + SumPrime<n - 1>::r;
};
template<>
struct SumPrime<0>{
    static constexpr int r = 0;
};
int tes() {
    cout <<  " " << endl;
    return 1;
}
int a[100];
constexpr int out_num(int n, int i) {
  //  cout << n << " ";
    return 1;
}
template<int n, int i>
struct OutPrimes {
    static constexpr int r =  (IsPrime<n>::r ? (out_num(n, i) && OutPrimes<n - 1, i + 1>::r) : OutPrimes<n - 1, i + 1>::r);
};
template<int i>
struct OutPrimes<1, i> {
    static constexpr int r = out_num(1, 1);
};
template <int i,int n>
struct edg{ // 判断是否终止
constexpr static int r=(i>n?0:1);
};
template<int n>
struct pprime{
    template <int i,int k>
    struct _output{
        static void run(){
        if(IsPrime<i>::r){ // 是素数的话就输出
            cout<<i<<endl;
        }
        pprime<n>::_output<i+1,edg<i+1,n>::r>::run();// 找下一个数
        }
    };
    template<int i>
    struct _output<i,0>{ // 大于n的时候停止 
        static void run(){
            return ;
        }
    };
    static void output(){ // 从2开始往下找
        pprime<n>::_output<2,1>::run();
        return ;
    }
};


int main() {
    cout << "*****************" << endl;
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << "*****************" << endl;
    cout << Add<3, 7>::r << endl;
    cout << "*****************" << endl;
    cout << Sum<100>::r << endl;
    cout << "*****************" << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << SumPrime<10>::r << endl;
    cout << "******************作业：输出n以内的所以素数*********************"<< endl;
    pprime<100>::output();
    
    cout << OutPrimes<10, 1>::r << endl;;
    cout << endl;
    return 0;
}
