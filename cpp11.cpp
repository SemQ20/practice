/* This file contain a features of C++ 11 */
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cassert>

/* 6. move constructors / move assignment */
class SomeClass{
public:
    /* move constructor*/
    SomeClass(SomeClass && sc);
    /* Copy constructor */
    SomeClass(const SomeClass &sc);
};

/* 29. static assertion */
template<typename T>
void swap (T &a, T &b){
    static_assert(std::is_copy_constructible_v<T>,"Swap requires copying");
    static_assert(std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_copy_assignable_v<T>
    , "Swap requires nothrow copy/assign");
    auto c = a;
    a = b;
    b = c;
}

/* 16. Variadic templates */
/* 8. constexpr and literal types */
/* create overload operator for view result of std::tuple */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::tuple<T...> &_tuple) noexcept { //compile time, not trow exceptions
    return os << std::get<0>(_tuple) <<", "<< std::get<1>(_tuple) <<", "<< std::get<2>(_tuple) <<'\n';
} 

/* 23. noexcept - keyword for method are not trow exceptions */
/* create overload operator for view result of std::pair */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::pair<T...> &_pair) noexcept { //compile time, not trow exceptions
    return os << _pair.first << ", "<< _pair.second << '\n';
}

/* 5. rvalue reference */
template <class T>  // lvalue
T&& go(T& x)
{
    std::cout << "Lval this" << '\n';
    return std::forward<T>(x);
}

template <class T>
T&& go(T&& x)                  //rvalue
{
    std::cout << "Rval this" << '\n';
    return std::forward<T>(x);
    /* maybe similarly static_cast<T&&>(x) */
}

int main()
{
    /* 9. list initialization */
    std::vector<int> numbers2 = {10, 20, 30, 40, 50};
   
    int ival = 10;
    /* 1. auto and decltype */
    auto rval = go(ival);
    std::cout << std::boolalpha;
    /* 1. decltype is tranformation unit for any type decltype(variable) */
    std::cout << "rval is interal type?: " << std::is_integral_v<decltype(rval)> << '\n';
    std::cout << "result of go(): " << rval << '\n';

    /* 19. Unicode string literals */
    const char *lstr = u8"z\u00df\u6c34\U0001d10b";; // wchar_t
    int lenght = std::mblen(lstr, std::strlen(lstr));
    std::cout << "lenght wstring: " << lenght << '\n';

    /* 22. lambda expressions */
    int x_pos = 0;
    auto z = [&]() mutable {
        return ++x_pos;
    };
    int bval = z();
    std::cout << "lambda work result: " << bval << '\n';

    /* 12. nullptr */
    std::cout << "nullptr: " << std::is_null_pointer<decltype(nullptr) >::value << '\n';

    /* 28. range for */
    for(auto &elem : numbers2){
        std::cout << elem << '\n';
    }

    int a,b;
    swap(a,b);
    return 0;
}
