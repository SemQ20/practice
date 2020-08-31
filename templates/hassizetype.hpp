#ifndef HASSIZETYPE_HPP
#define HASSIZETYPE_HPP

#include "isvalid.hpp"
#include <type_traits>
#include <utility>

#define DEFINE_HAS_TYPE(MemType)                     \
        template<typename, typename = std::void_t<>> \
        struct HasTypeT_##MemType                    \
               : std::false_type {};                 \
                                                     \
        template<typename T>                         \
        struct HasTypeT_##MemType<T,                 \
                   std::void_t<typename T::MemType>> \
               : std::true_type {};                  \

#define DEFINE_HAS_MEMBER(Member)                     \
        template<typename, typename = std::void_t<>>  \
        struct HasMember_##Member                     \
               : std::false_type {};                  \
                                                      \
        template<typename T>                          \
        struct HasMember_##Member<T,                  \
                   std::void_t<decltype(&T::Member)>> \
               : std::true_type {}                    \

template<typename...> using VoidT = void;

template<typename, 
         typename = VoidT<>>
struct HasSizeType : std::false_type{};

/* template<typename T>
struct HasSizeType<T, VoidT<typename std::remove_reference<T>::size_type>> : std::true_type{
    // for reference(&) type
}; */

template<typename T>
struct HasSizeType<T, 
                   VoidT<typename T::size_type>> : std::true_type{};

template<typename, 
         typename = std::void_t<>>
struct HasBeginT : std::false_type{};

template<typename T>
struct HasBeginT<T,
                 std::void_t<decltype(std::declval<T>().begin())>> : std::true_type{};

template<typename, 
         typename,
         typename = std::void_t<>>
struct HasLessT : std::false_type{};

template<typename T1, 
         typename T2>
struct HasLessT<T1, T2, 
                std::void_t<decltype(std::declval<T1>() < std::declval<T2>())>> 
                : std::true_type{};

/* Not need a macro: */
constexpr auto hasSizeType = 
               isValid([](auto x) -> typename decltype(valueT(x))::size_type {});

#endif