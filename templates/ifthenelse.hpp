#ifndef IFTHENELSE_HPP
#define IFTHENELSE_HPP

#include <type_traits>
#include <utility>
#include <iostream>
#include <limits>


/* Analog in STL std::conditional_t<>: */
template<bool COND, 
         typename trueType, 
         typename falseType>
struct IfThenElse{
    using Type = trueType;
};

template<typename trueType, 
         typename falseType>
struct IfThenElse<false, trueType, falseType>{
    using Type = falseType;
};

template<bool COND, 
         typename trueType, 
         typename falseType>
using IfThenElseT = typename
                    IfThenElse<COND, trueType, falseType>::Type;

template<auto N>
struct SmallesIntT{
    using Type =
        typename IfThenElseT<N <= std::numeric_limits<char>::max(), char,
        typename IfThenElseT<N <= std::numeric_limits<short>::max(), short,
        typename IfThenElseT<N <= std::numeric_limits<int>::max(), int,
        typename IfThenElseT<N <= std::numeric_limits<long>::max(), long,
        typename IfThenElseT<N <= std::numeric_limits<long long>::max(), long long,
                 void>::Type
                 >::Type
                 >::Type
                 >::Type
                 >::Type;
};

template<typename T>
struct Unsigned{
    using Type = IfThenElseT<std::is_integral_v<T> && !std::is_same_v<T, bool>,
                            typename std::make_unsigned_t<T>, T>;
};

template<typename T>
struct IdentityT{
    using Type = T;
};

template<typename T>
struct MakeUnsignedT{
    using Type = typename std::make_unsigned_t<T>;
};

template<typename T>
struct UnsignedT{
    using Type = typename IfThenElseT<std::is_integral_v<T> && !std::is_same_v<T, bool>,
                 MakeUnsignedT<T>, IdentityT<T>>::Type;
};

#endif