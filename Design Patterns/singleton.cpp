#include <iostream>
#include <mutex>
#include <future>
#include <chrono>

/* Thread Safety Singleton */

class Singleton{
    static Singleton* pinstance_;
    static std::mutex mutex_;
    protected:
        ~Singleton(){
            delete pinstance_;
        }
        Singleton(const char* value) : value_(value){}
        const char* value_;
    public:
        Singleton(Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        static Singleton* GetInstance(const char* value);

        const char* value(){
            return value_;
        }
        void SomeLogic(){}
};

Singleton* Singleton::pinstance_ = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const char* value){
    std::lock_guard<std::mutex> lock(mutex_);
    if(pinstance_ == nullptr){
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << '\n';
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << '\n';
}

int
main(){

    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    
    return EXIT_SUCCESS;
}