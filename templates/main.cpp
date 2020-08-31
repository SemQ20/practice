#include "fold_expressions.hpp"
#include <iostream>

int
main()
{
    std::boolalpha(std::cout);
    std::cout << EqualsAnyOf(1,1,1,1,1,1) << '\n';
    
    return 0;
}
