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
    Thread_Pool(int n = 5) : is_running(false), max_threads_num(n){
    }
    void start() {
        if (is_running) return ; // 线程池已经再工作
        is_running = true;
        this->cnt = 0;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&Thread_Pool::worker, this, i)); // 成员方法作为入口， 并且绑定this指针, 虽然this是隐藏参数，也要跟着work进行传递绑定 成员方法要加&
        }
        return ;
    }
    void worker(int i) { // 隐藏this指针
        while(is_running) {
            // 取任务
            Task *t = this->getOneTask();
            if (t == nullptr) break; // 线程池要结束工作
            // 执行
            (*t)();
            // 释放
            delete t;
        }
    }
    void stop() {
        if (is_running == false) return ;
        do {
            unique_lock<mutex> lock(m_mutex); // lock是局部变量
            is_running = false;
            m_cond.notify_all(); // 给所有人发信息，防止一直等待
        }while(0);
        cout << "before while..." << endl;
        while(1) {
            if (get_cnt() == 0) break; 
            //sleep(0.5);
        }
        cout << "after while... ******* 这句话不一定最后一个输出，虽然任务队列空了，但是线程可能还在运行" << endl;
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
        if (is_running == false) return ;
        unique_lock<mutex> cnt_lock(cnt_mutex);
        this->cnt += 1; // 任务数加一
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }
    int get_cnt() {
        unique_lock<mutex> cnt_lock(cnt_mutex);
        return this->cnt;
    }
private:
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (is_running && task_queue.empty()) m_cond.wait(lock); // 队列为空等待，直到队列中有任务,  配合条件变量的使用就是互斥锁(释放锁， 再加锁)
        if (get_cnt() == 0) return nullptr;// m_mutex已经加锁，所以不能再对m_mutex加锁
        //if (is_running == false) return nullptr;
        Task *t = task_queue.front();
        task_queue.pop();
        unique_lock<mutex> cnt_lock(cnt_mutex);
        this->cnt -= 1;
        return t;
    }
    bool is_running;
    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> task_queue;
    std::mutex m_mutex;
    std::mutex cnt_mutex;
    int cnt; // 执行任务总数
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

int main() {
    Task t(thread_func1, 1, 2);
    t();
    int n = 0;
    Task t1(thread_func2, ref(n));
    t1(), t1();
    cout << n << endl;
    Thread_Pool tp(6); // 容量为6的线程池
    tp.start();
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 123);
    //sleep(2); // sleep 2s
    tp.stop();
    tp.addOneTask(task_func, 123);
    return 0;
}
