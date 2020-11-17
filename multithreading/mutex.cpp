#include <thread>
#include <mutex>
#include <iostream>
#include <string>

std::mutex mtx;

void shared_print(std::string msg, int id){
    std::lock_guard<std::mutex> guard(mtx);
    std::cout << msg << id << '\n';
}

void function_1(){
    for(std::size_t i = 0; i < 100; ++i){
        shared_print("From t1: ", i);
    }
}

int main(){
    std::thread t1(function_1);
    for(std::size_t i = 0; i < 100; ++i){
        shared_print("From main: ", i);
    }
    t1.join();
    return EXIT_SUCCESS;
}