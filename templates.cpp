#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
auto _add(T1 x, T2 y) -> decltype(x+y){
    return x+y;
}

template<typename T1, typename T2>
std::common_type_t <T1, T2> max(T1 a, T2 b){
    return b < a ? a : b;
}

template<typename T1, typename T2>
auto max_v1(T1 a, T2 b) -> typename std::decay_t<decltype(true? a : b)>
{
    return b < a ? a : b;
}

int main()
{
    std::cout << _add(5, 7.4) << '\n';
    std::cout << ::max(3.5f, 2) << '\n';
    std::cout << max_v1(5.6f, 3) << '\n';
    return 0;
}
