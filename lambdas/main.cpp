#include "lambdas.hpp"

int main()
{
    std::cout << "Left Identify "
          << stringify(15)()
          << "=="
          << bind(unit(15))(stringify)()
          << '\n';
    std::cout << "Right Identify "
          << stringify(5)()
          << "=="
          << bind(stringify(5))(unit)()
          << '\n';

    auto result = binaryc(mul)(5,4, inc);
    std::cout << result << '\n';
    
    return 0;
}