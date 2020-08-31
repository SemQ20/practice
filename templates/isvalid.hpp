#ifndef ISVALID_HPP
#define ISVALID_HPP
#include <type_traits>
#include <utility>

/* helper template function */
template<typename F,
         typename... Args,
         typename = decltype(
             std::declval<F>()(std::declval<Args&&>()...))>
std::true_type isValidImpl(void*);

template<typename F, typename... Args>
std::false_type isValidImpl(...);

template<typename T>
struct TypeT{
    using Type = T;
};

template<typename T>
constexpr auto type = TypeT<T> {};

template<typename T>
T valueT(TypeT<T>);

/* only in C++17 */
inline constexpr auto isValid = [](auto f){  
    return [](auto&&... args){
        return decltype(isValidImpl<decltype(f),
                                    decltype(args)&&...>(nullptr)){};
    };
};

constexpr auto hasfirst =
    isValid([](auto x) -> decltype((void)valueT(x).first){});

constexpr auto isDefaultConstructible =
    isValid([](auto x) -> decltype((void)decltype(valueT(x))()){});


template<typename T>
auto isDefaultConstructibleT(T type_t){
    return isDefaultConstructible(type<T>);
}

template<typename T>
bool has_field_first(T pair){
   return hasfirst(type<T>);
}

#endif