#ifndef TEMPLATES_V1_HPP
#define TEMPLATES_V1_HPP

#include <type_traits>
#include <iterator>

template<typename T, typename = void>
struct is_iterable : std::false_type{};

template<typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T&>())), 
                                  decltype(std::end(std::declval<T&>()))>> 
                                  : std::true_type {};

template<typename T>
inline constexpr bool is_iterable_v = is_iterable<T>::value;



#endif