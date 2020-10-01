#include "sha_2.hpp"
#include <iostream>


int main()
{
    SHA256 sh;
    std::cout << sh.sha256("The quick brown fox jumps over the lazy dog") << '\n';
    return 0;
}