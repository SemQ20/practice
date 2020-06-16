#include <iostream>
#include <string>
#include <utility>
#include <chrono>
//#include "strAlgorithms.hpp"
#include "nAlgorithms.hpp"



int main()
{
    std::chrono::duration<uint64_t,std::nano> timer_ms; //variable for measuring runtime algorithm/programm
    auto t1 = std::chrono::high_resolution_clock::now();
    auto[vec,val] = sieveEratosphene(40000);
    std::cout << "whole multipliers: "<< val << '\n';
    auto t2 = std::chrono::high_resolution_clock::now();
    timer_ms = t2-t1;

    std::cout << "vector size: " << vec.size() << '\n';
    std::cout << "time: "<< std::chrono::duration_cast<std::chrono::seconds>(timer_ms).count() << '\n';

    /* std::string str = "676";
    
    std::boolalpha(std::cout);
    std::cout << has_isPalindrom(str) << '\n'; */

    return 0;
}

