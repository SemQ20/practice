#include "isnothrowmoveconstructible.hpp"
#include <typeinfo>

struct S{
    S(S&& obj) noexcept {}
    int foo(){}
};

int
main()
{
    std::boolalpha(std::cout);
    std::cout << IsClassT<S>::value << '\n';
    return 0;
}
