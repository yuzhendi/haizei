/*************************************************************************
	> File Name: thread_pool.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月13日 星期四 16时08分08秒
 ************************************************************************/

#include <iostream>
#include <functional>
#include<thread>
#include <vector>
#include <queue>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include <unistd.h>
#include <map>
#include <cmath>
using namespace std;

class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...); // 按照参数类型列表进行展开
    }
    void operator()() {
        this->func();
        return ;
    }

private:
    function<void()> func;
};

class Thread_Pool {
public :
    Thread_Pool(int n = 5) : max_threads_num(n), m_mutex(), m_cond(){}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&Thread_Pool::worker, this, i)); // 成员方法作为入口， 并且绑定this指针, 虽然this是隐藏参数，也要跟着work进行传递绑定 成员方法要加&
        }
        return ;
    }
    void worker(int i) { // 隐藏this指针
        thread::id id = this_thread::get_id();
        is_runing[id] = true;
        while(is_runing[id]) {
            // 取任务
            Task *t = this->getOneTask();
            // 执行
            (*t)();
            // 释放
            delete t;
        }
    }
    void stop() {
        
        for (int i = 0; i < max_threads_num; i++) { // 加入相应线程池数量的特殊函数，用来改变对应线程的is_runing标志位
            this->addOneTask(&Thread_Pool::stop_task, this);
        }
        for (int i = 0 ; i < max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
       do {
            unique_lock<mutex> lock(m_mutex);
            while(task_queue.size() >= 1) task_queue.pop();
        }while(0); // 
        return ;
    }
    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS... args) {
        unique_lock<mutex> lock(m_mutex); // 加锁  局部变量自动释放 解锁
        unique_lock<mutex> cnt_lock(cnt_mutex);
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }
private:
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (task_queue.empty()) m_cond.wait(lock); // 队列为空等待，直到队列中有任务,  配合条件变量的使用就是互斥锁(释放锁， 再加锁)
        Task *t = task_queue.front();
        task_queue.pop();
        unique_lock<mutex> cnt_lock(cnt_mutex);
        return t;
    }
    void stop_task() {
        thread::id id = this_thread::get_id();
        is_runing[id] = false;
    }
    //bool is_running;
    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> task_queue;
    std::mutex m_mutex;
    std::mutex cnt_mutex;
    map<thread::id, bool> is_runing; // 每个线程设置一个标志位
    std::condition_variable m_cond; // 条件变量
};

/****************************************************************/
void thread_func1(int a, int b) {
    cout << a <<" + " << b << " = " << a + b << endl;
}
void thread_func2(int &n) {
    n += 1;
    return ;
}

void task_func(int x) {
    cout << "task_func : " << x << endl;
}
bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void test_prime(int l, int r, int &n) {
    for (int i = l; i < r; i++) {
        if (is_prime(i)) n++;
    }
}
int cnt = 0;

void count_prime(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (is_prime(i)) __sync_fetch_and_add(&cnt, 1); // linux自带的原子操作 无锁化编程
    }
}


int main() {
    Thread_Pool tp(6);
    int n = 0;
    tp.start();
    for (int i = 0, j = 1; i < 5; i++, j += 200000) { // 输出前1000000以内的素数的个数
        tp.addOneTask(count_prime, j, j + 200000 - 1);
    }
    tp.stop();
    cout << cnt << endl;

    return 0;
}
