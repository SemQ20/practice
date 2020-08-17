#include "ifthenelse.hpp"

int
main()
{
    int a = 10;
    UnsignedT<decltype(a)>::Type b;
    std::boolalpha(std::cout);
    std::cout << std::is_unsigned_v<decltype(b)> << '\n';
    return 0;
}
