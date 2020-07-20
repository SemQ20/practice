#include <iostream>
#include <array>

/* user defined literals */
template<char...> int operator "" _B7();

template<char... cs>
int operator "" _B7(){
    std::array<char, sizeof...(cs)> chars{cs...};
    for(char c : chars){
        std::cout << "'" << c << "' "; 
    }
    std::cout << '\n';
    return 0;
}

template<typename T, typename... Args>
bool all_type_is_equal(std::tuple<Args...> tuple){
    return (std::is_same_v<Args, Args>& ...);
}

template<typename T, typename... Args>
bool all_type_is_equal(Args... args){
    return (std::is_same_v<Args, Args>& ...);
}


template<typename T, typename... Args>
bool all_type_is_equal(std::initializer_list<Args...> ilist){
    return (std::is_same_v<Args, Args>& ...);
}

int main()
{
    int a = 123_B7;
    return 0;
}
