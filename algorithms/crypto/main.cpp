#include "sha_2.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::string input = "hello world";
    std::string output1 = sha256(input);
 
    std::cout << "sha256('"<< input << "'):" << output1 << '\n';
    return 0;
}