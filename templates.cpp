#include <iostream>

template<typename T1, typename T2>
auto _add(T1 x, T2 y) -> decltype(x+y){
    return x+y;
}

int main()
{
    std::cout << _add(5,7) << '\n';
    return 0;
}
