#include <iostream>
#include <utility>

#define MYSTRUCT(name) struct name{ \
    int i = 10;                     \
};                                  \

MYSTRUCT(A);

int
main()
{
    A a;
    std::cout << a.i << '\n';
    return 0;
}
