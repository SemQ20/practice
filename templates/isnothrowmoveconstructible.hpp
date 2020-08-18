#ifndef ISNOTHROWMOVECONSTRUCTIBLE_HPP
#define ISNOTHROWMOVECONSTRUCTIBLE_HPP

#include <iostream>
#include <type_traits>
#include <utility>

template<typename T, typename = std::void_t<>>
struct IsNothrowMoveConstructible : std::false_type{
};

/* std::is_nothrow_move_constructible_v */
template<typename T>
struct IsNothrowMoveConstructible<T, std::void_t<decltype(T(std::declval<T>()))>>
                                 : std::bool_constant<noexcept(T(std::declval<T>()))>{};
/* IsNothrowMoveConstructible<T>::value */

template<typename T>
inline constexpr auto IsNothrowMoveConstructiblev = IsNothrowMoveConstructible<T>::value;

template<typename T, typename = std::void_t<>>
struct IsClassT : std::false_type{};

template<typename T>
struct IsClassT<T, std::void_t<int T::*>> : std::true_type{};
#endif