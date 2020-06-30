#include <iostream>
#include <mutex>
#include <future>
#include <atomic>
#include <string>

void print(std::string str){
    std::mutex mtx;
    std::lock_guard<std::mutex> lg(mtx);
    std::cout << "Thread id: " << std::this_thread::get_id() << '\n';
    std::cout << str << '\n';
}


int main(){
    auto f1 = std::async(std::launch::async, print, "Hello from a first thread");
    auto f2 = std::async(std::launch::async, print, "Hello from a second thread");
    std::cout << "Main thread id: " << std::this_thread::get_id() << '\n';
    print("Hello from the main thread");
    return 0;
}
