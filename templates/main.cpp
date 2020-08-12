#include "isconvertible.hpp"


int
main()
{
    std::boolalpha(std::cout);
    std::cout << IsConvertibleT<int, int>::value << '\n';
    return 0;
}
