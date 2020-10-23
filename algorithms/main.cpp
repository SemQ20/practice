#include <iostream>
#include <chrono>
#include "nAlgorithms.hpp"
#include <bitset>
#include <string>
#include <vector>


int main()
{
    std::string input = "hello world";
    const char* ch = input.c_str();
    std::vector<std::bitset<8>> vec8bit;
    for(std::size_t i = 0; i <= input.size(); i++){
      vec8bit.push_back(ch[i]);
    }
    std::bitset<8> b1;
    std::bitset<8> b2;
    std::bitset<8> b3;
    b1 = vec8bit[0] | vec8bit[1] | vec8bit[2] | vec8bit[3];
    b2 = vec8bit[4] | vec8bit[5] | vec8bit[6] | vec8bit[7];
    b3 = vec8bit[9] | vec8bit[10] | vec8bit[11];
    uint64_t t = vec8bit[0].to_ullong() << 24 | vec8bit[1].to_ullong() << 16 | 
                 vec8bit[2].to_ullong() << 8  | vec8bit[3].to_ullong();
    std::cout << t << '\n';
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    std::cout << b3 << '\n';
    std::cout << b1.to_ullong() << '\n';
    std::cout << b2.to_ullong() << '\n';
    std::cout << b3.to_ullong() << '\n';
    return 0;
}

