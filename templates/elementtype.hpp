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


/* template<typename T>
struct isDefaultConstructibleT{
    private:
        template<typename U, 
                 typename = decltype(U())>
        static char test(void*);

        template<typename>
        static long test(...);
    public:
        static constexpr bool value = std::is_same_v<decltype(test<T>(nullptr)), char>;
}; */

template<typename T>
struct isDefaultConstructibleHelper{
    private:
        template<typename U, 
                 typename = decltype(U())>
        static std::true_type
        test(void*);

        template<typename>
        static std::false_type
        test(...);

    public:
        /* Type is compile time measured type(true_type or false_type)
           * true_type and false type includes static constexpr fields
           * Type takes a user defined type of true_type/false_type and included fields */
        using Type = decltype(test<T>(nullptr));
};


template<typename T>
struct isDefaultConstructibleT : isDefaultConstructibleHelper<T>::Type{};

template<typename...> using VoidT = void;

template<typename, typename = VoidT<>>
struct isDefaultConstructibleT1 : std::false_type{};

template<typename T>
struct isDefaultConstructibleT1<T, VoidT<decltype(T())>> : std::true_type{};

#endif