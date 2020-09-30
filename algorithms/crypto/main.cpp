#include "sha_2.hpp"
#include <iostream>

int main()
{
    SHA256 sh;
    std::cout << sh.sha256("grape") << '\n';
    
    return 0;
}