#include <iostream>
#include "nAlgorithms.hpp"
#include <chrono>

int main()
{
    uint16_t uintval = 525;
    std::chrono::duration<uint64_t,std::nano> timer_ms; //variable for measuring runtime algorithm/programm
    auto t1 = std::chrono::high_resolution_clock::now();
    auto[vec,val] = sieveEratosphene(1234536);
    std::cout << "whole multipliers: "<< val << '\n';
    auto t2 = std::chrono::high_resolution_clock::now();
    timer_ms = t2-t1;
    
    for(auto &el : vec){
        std::cout << el << '\n';
    }
    std::boolalpha(std::cout);
    std::cout << "time: "<< std::chrono::duration_cast<std::chrono::seconds>(timer_ms).count() << '\n';
    return 0;
}
