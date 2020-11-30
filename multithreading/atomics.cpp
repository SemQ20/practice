#include <cstdint>
#include <limits>
#include <string>
#include <algorithm>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#include <vector>
#include <chrono>

const int num{1000};
std::atomic<int> i{};
std::mutex mtx;

int main(){
    std::chrono::duration<uint64_t,std::nano> timer_ms;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> v(num);
    
    for(auto& c : v){
        c = std::thread([&i, &num, &mtx]{
            for(int n = 0; n < num; ++n) 
                ++i;
                //std::unique_lock<std::mutex> ga(mtx);

        });
    }
    for(auto& t : v){
        t.join();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    timer_ms = t2 - t1;
    auto t3 = std::chrono::duration_cast<std::chrono::milliseconds>(timer_ms).count();
    std::cout << i << '\n';
    std::cout << t3 << '\n';
    return 0;
}