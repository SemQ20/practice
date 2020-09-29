#include "sha_2.hpp"
#include <iostream>

int main()
{
    SHA256 sh;
    sh.sha256("The quick brown fox jumps over the lazy dog");
    return 0;
}