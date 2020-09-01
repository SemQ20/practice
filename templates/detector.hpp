#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include <type_traits>
#include <iterator>
#include <utility>

/* for Clang++ need compile with flag: 
    -frelaxed-template-template-args  */

template<typename Default, typename AlwaysVoid,
         template<typename> class Op, typename... Args>
struct detector{
    using value_t = std::false_type;
    using type = Default;
};

template<typename Default, template<typename...> class Op,
         typename... Args>
struct detector<Default, std::void_t<Op<Args...>>, Op, Args...>{
    using value_t = std::true_type;
    using type = Op<Args...>;
};

struct nonesuch{
    nonesuch() = delete;
    nonesuch(const nonesuch&) = delete;
    nonesuch(nonesuch&&) = delete;
    nonesuch& operator=(const nonesuch&) = delete;
    nonesuch& operator=(nonesuch&&) = delete;
};

template<template<typename...> class Op, typename... Args>
using is_detected = typename detector<nonesuch, void, Op,
                                      Args...>::value_t;

template<template<typename...> class Op, typename... Args>
inline constexpr auto is_detected_v = is_detected<Op, Args...>::value;

template<template<typename...> class Op, typename... Args>
using detected_t = typename detector<nonesuch, void, Op, Args...>::value;

template<typename Default, template<typename...> class Op, typename... Args>
using detector_or = typename detector<Default, void, Op, Args...>::type;

template<typename Default, template<typename...> class Op, typename... Args>
using detector_or_t = typename detector_or<Default, Op, Args...>::type;

template<typename T>
using free_begin = decltype(std::begin(std::declval<T>()));

template<typename T>
using free_end = decltype(std::end(std::declval<T>()));

template<typename T>
using free_rbegin = decltype(std::rbegin(std::declval<T>()));

template<typename T>
using free_rend = decltype(std::rend(std::declval<T>()));

template<typename T>
inline constexpr auto is_iterable_v = is_detected_v<free_begin, T> && 
                                      is_detected_v<free_end, T>;

template<typename T>
inline constexpr auto is_reverse_iterable_v = is_iterable_v<T> &&
                                              is_detected_v<free_rbegin, T> && 
                                              is_detected_v<free_rend, T>;

/* Example how to use:
 
template<typename T>
using v_foo_v = decltype(std::declval<T&>().foo());

template<typename T>
using v_foo_i = decltype(std::declval<T&>().foo(std::declval<int>()));

template<typename T>
inline constexpr bool has_foo = is_detected_v<v_foo_v, T> && is_detected_v<v_foo_i, T>; */

#endif