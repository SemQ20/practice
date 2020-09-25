#include <iostream>
#include <chrono>
#include "nAlgorithms.hpp"
#include <bitset>
#include <string>
#include <vector>


int main()
{
    std::string input = "jakdj ajndkjqw qjwknda askdjq";
    const char* ch = input.c_str();
    std::vector<std::bitset<8>> vec8bit;
    int64_t cs = 0x12345671FBC00045;
    int16_t c16 = (cs & 0x0000FFFF00000000) >> 32;

    std::cout << decimalToHex(c16) << '\n';
    unsigned int mask4bit[] = { 0x000000FF, 
                                0x0000FF00, 
                                0x00FF0000, 
                                0xFF000000 
                              };
    int byte = 8;
    int b1 = ch[0] << (0    ) * mask4bit[0];
    vec8bit.push_back(b1);
    int b2 = ch[1] << (8    ) * mask4bit[1];
    vec8bit.push_back(b2);
    int b3 = ch[2] << (8 * 2) * mask4bit[2];
    int b4 = ch[3] << (8 * 3) * mask4bit[3];
    int c = (unsigned char) ch[0] << 24 | (unsigned char) ch[1] << 16 | (unsigned char) ch[2] << 8 |
            (unsigned char) ch[3];
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    std::cout << b3 << '\n';
    std::cout << b4 << '\n';
    std::cout << c << '\n';
    std::cout << vec8bit[0].to_ullong() << '\n';
    std::cout << vec8bit[1] << '\n';

    return 0;
}

