#include "templates_v1.hpp"
#include <iostream>
#include <vector>

int
main()
{
    std::boolalpha(std::cout);
    std::vector<int> ivec;
    
    std::cout << is_iterable_v<decltype(ivec)> << '\n';
    
    return 0;
}
