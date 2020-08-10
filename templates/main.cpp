#include "isvalid.hpp"

struct S
{
    S(){};
};


int
main()
{
    std::pair<int, int> p1{10,15};
    /* BigInt arr[] = {12ll, 23ll, 24ll, 12ll, 28ll, 48ll};
    auto sum = accum(arr, arr + (sizeof(arr)/sizeof(*arr)));
    auto sum1 = accum1(arr, arr + (sizeof(arr)/sizeof(*arr)));
    std::cout << sum << '\n'; */

    /* int arr[4];
    printElementType(arr); */
    /* std::vector<int> ivec{1,3,4,56,7,878,12}; */
    /* printElementType(ivec); */
    /* auto sum = sumElement(ivec);
    std::cout << sum << '\n'; */

    std::boolalpha(std::cout);
    /* std::cout << isDefaultConstructibleT1<S>::value << '\n'; */
    S s;
    
    std::cout << isDefaultConstructible(type<int>) << '\n';
    std::cout << has_field_first(s) << '\n';
    std::cout << has_field_first(p1) << '\n';
    return 0;
}
