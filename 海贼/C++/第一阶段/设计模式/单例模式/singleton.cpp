/*************************************************************************
	> File Name: singleton.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年08月18日 星期二 10时50分42秒
 ************************************************************************/

#include <iostream>
#include <mutex>
using namespace std;

// 单例模式， 一个对象再全局值有一个
class HttpServer {
public:
    static HttpServer *getInstance(){
        if (instance == nullptr) { // 提高效率，防止每次初始化都加锁
            std::unique_lock<std::mutex> lock(m_mutex); // 防止多线程下出现内存泄漏，  懒汉模式：直到该初始化的时候才初始化
            if (instance == nullptr) {
                instance = new HttpServer();
            }
        }
        return instance;
    }
    void destory() {
        
        delete this;
    }
    void set(int a) {
        this->x = a;
    }
    void print() {
        cout << this->x << endl;
    }
private:
    int x;
    static HttpServer *instance; // 静态函数和静态变量可以在未实例化前使用
    static std::mutex m_mutex;
    HttpServer(){} //外部创建不了对象
    HttpServer(const HttpServer &) = delete;
    ~HttpServer(){} // 防止外部调用delete导致对象不是真正的被删除
};

HttpServer *HttpServer::instance = nullptr; // 也可以直接 instance = new HttpServer()  饿汉模式： 再程序开始前就初始化一个对象，就不需要加锁了
std::mutex HttpServer::m_mutex;
int main() {
    HttpServer *t1 = HttpServer::getInstance();
    t1->set(3);
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << " " << t2 << endl;
    t1->print();
    t2->print();
    t1->destory();
    cout << "*************after delete ********************" << endl;
    cout << t1 << " " << t2 << endl;
    HttpServer *t3 = HttpServer::getInstance();
    cout << t3 << " " << sizeof(t1) << endl;
    t1->print();
    t2->print();
    return 0;
}
