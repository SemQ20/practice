#ifndef ELEMENTTYPE_HPP
#define ELEMENTTYPE_HPP
#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <type_traits>

template<typename T>
struct ElementT;

template<typename T>
struct ElementT<std::vector<T>>{
    using Type = T;
};

template<typename T>
struct ElementT<std::list<T>>{
    using Type = T;
};

template<typename T, std::size_t N>
struct ElementT<T[N]>{
    using Type = T;
};

template<typename T>
struct ElementT<T[]>{
    using Type = T;
};

template<typename T>
void printElementType(T const& c){
    std::cout << typeid(typename ElementT<T>::Type).name() << '\n';
}

template<typename T>
using ElementType = typename ElementT<T>::Type;

template<typename T>
ElementType<T> sumElement(T const& arr){
    using ArrT = typename ElementT<T>::Type;
    ArrT sum = 0;
    for(auto const& i : arr){
        sum += i;
    }
    return sum;
}


template<typename T>
struct isDefaultConstructibleT
{
    private:
        template<typename U, typename = decltype(U())>
        static char test(void*);

        template<typename>
        static long test(...);
    public:
        static constexpr bool value = std::is_same_v<decltype(test<T>(nullptr)), char>;
};

#endif