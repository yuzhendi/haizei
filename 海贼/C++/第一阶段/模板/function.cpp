/*************************************************************************
	> File Name: function.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月08日 星期六 15时25分39秒
 ************************************************************************/

#include <iostream>
#include <functional>
#include <typeinfo>
using namespace std;

void f(function<int (int , int)> g) {// 传入可调用对象: 函数 / 函数对象 可以替代函数指针
    cout << g(3, 4) << endl;                                    
}

int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) { // 函数对象
        return a > b ? a : b;
    }
};


namespace haizei{
    template<typename RT, typename ...PARGS> 
    class base{ // 基类
        public:
        virtual RT operator()(PARGS...) = 0; // 纯虚寒数
        virtual base<RT, PARGS...> *getCopy() = 0; // 传入一个变量时， 拷贝一分，防止析构后找不到原来的变量
        virtual ~base(){};
    };
    template<typename RT, typename ...PARGS>
    class normal_func : public base<RT, PARGS...>{ // 普通函数继承

    public:
        typedef RT (*func_type)(PARGS...);
        normal_func(func_type func) : ptr(func){}
        virtual RT operator()(PARGS... args) override {
            return this->ptr(args...);
        }
        virtual base<RT, PARGS...> *getCopy() override {
            return new normal_func<RT, PARGS...> (ptr);
        }
        private:
        func_type ptr;
    };
    template<typename C, typename RT, typename ...PARGS> 
    class functor : public base<RT, PARGS...>{  // 函数对象的继承
    public:
        functor(C &func) : ptr(func){}
        virtual RT operator()(PARGS... args) override {
            return this->ptr(args...);
        }
        virtual base<RT, PARGS...> *getCopy() override {
            return new functor<C, RT, PARGS...> (ptr);
        }
    private:
        C &ptr;
    };



template <typename RT, typename ...PARGS> class function;
template <typename RT, typename ...PARGS>
class function<RT(PARGS...)> {
public:
    function(RT (*func)(PARGS...)) : ptr(new normal_func<RT, PARGS...>(func)) { // 传入函数
        this->cnt = 0;
    }
    template<typename T>
    function(T a) : ptr(new functor<typename remove_reference<T>::type, RT, PARGS...>(a)){ // 传入可调用对象
        
        this->cnt = 0;
    }
    function(const function &f) {
        this->ptr = f.ptr->getCopy(); // 获取f的拷贝，因为上面的T 类型消失的(传入的不是引用，所以需要一个拷贝方法来进行存储)
    }
    function(function &&f) {
        this->ptr = f.ptr;
        f.ptr = nullptr;
    }
    RT operator()(PARGS... args) { // （） 重载为传入的函数或者 函数对象的功能
        this->cnt += 1;
        return this->ptr->operator()(args...);
    }
    ~function() {
        if(ptr != nullptr)
             delete this->ptr;
    }
        void output_cnt() {
            cout << "function has been used " << this->cnt << " times" << endl;                                    
        }

private:
    base<RT, PARGS...> *ptr; // 指向函数
    int cnt;

};
}
template<typename RT, typename ...PPARGS> class FunctionCnt;
template<typename RT, typename ...PPARGS>
class FunctionCnt <RT(PPARGS...)>{ // 改写成模板
public:
    FunctionCnt(haizei::function<RT(PPARGS...)> g) : g(g), __cnt(0) {} // haizei::funtion 中的g 传入到std中的function  g(g)时，调用的构造函数是 function (class g),传入变量
    RT operator()(PPARGS... ppargs) {                           // 因为调用的是浅拷贝， 所以当g析构的时候，std下的function里的指针也会析构，造成段错误
        __cnt++;
        return g(ppargs...);
    }
    int cnt(){return __cnt;}
private:
    function<RT(PPARGS...)> g;
    int __cnt;
};

double sum(double a, double b) {
    return a + b;
}

int main() {
    int n =1;
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    g1(4, 6);
    g1.output_cnt();
    cout << g2(3, 4) << endl;
    g2.output_cnt();
    FunctionCnt<int(int, int)>  add_cnt(add);
    add_cnt(3, 4);
    add_cnt(1, 2);
    FunctionCnt<double(double, double)> add_cnt_2(sum);
    add_cnt_2(2.3, 4.5);
    add_cnt_2(4.5, 3.5);
    cout << "sum " << add_cnt_2.cnt() << " times" << endl;
    cout <<"add " <<add_cnt.cnt() << " times" << endl;
    return 0;
}
