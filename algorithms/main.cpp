#include <iostream>
#include "nAlgorithms.hpp"

int main()
{
    uint16_t uintval = 525;
    auto[vec,val] = factorization(525);
    std::cout << "whole multipliers: "<< val << '\n';
    
    for(auto &el : vec){
        std::cout << el << '\n';
    }
    std::boolalpha(std::cout);
    
    return 0;
}
