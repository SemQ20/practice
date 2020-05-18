/* Increaced macro NULL is an implementation-defined 
null pointer constant
after C++11:
#define NULL nullptr 
*/
#include <iostream>
#include <cstddef>
#include <array>


struct SClass{
    int zero = 0;
    double sdouble;
    char somech;
    
};

int main()
{
    /* offset macro */
    std::cout << offsetof(SClass,sdouble) << '\n';
    /* std::size_t is the unsigned integer type
     of the result of the sizeof operator */
     std::array<std::size_t,10> a;
    for (std::size_t i = 0; i != a.size(); ++i)
        a[i] = i;
    for (std::size_t i = a.size()-1; i < a.size(); --i)
        std::cout << a[i] << " ";

    std::cout << '\n';

    /* C++17:
    std::byte */
    std::byte b{42};
    b <<= 1;
    std::cout << "b*2= " << std::to_integer<int>(b) << '\n';

    /* std::max_align_t */
    std::cout << alignof(std::max_align_t);
    return 0;
}
