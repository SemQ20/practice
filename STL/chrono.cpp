#include <iostream>
#include <chrono>
#include <thread>
#include <ratio>

void timer(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}


int main()
{
    std::chrono::duration<double,std::milli> timer_ms;
    auto t1 = std::chrono::high_resolution_clock::now();
    timer(5);
    auto t2 = std::chrono::high_resolution_clock::now();
    timer_ms = t2 - t1;
    int result = std::chrono::duration_cast<std::chrono::seconds>(timer_ms).count();
    std::cout << result;
    return 0;
}
