#include <iostream>
#include <chrono>
//#include "strAlgorithms.hpp"
#include "nAlgorithms.hpp"



int main()
{
    std::cout << fib_binet(46) << '\n';
    const int a = 5;
    constexpr auto primes = eratospheneSieve<5>();
    for(std::size_t i = 0; i < primes.size(); ++i){
        std::cout << primes[i] << '\n';
    }
    return 0;
}

