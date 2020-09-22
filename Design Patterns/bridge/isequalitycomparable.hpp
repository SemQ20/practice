#ifndef ISEQUALITYCOMPARABLE_HPP
#define ISEQUALITYCOMPARABLE_HPP

#include <exception>
#include <utility>
#include <type_traits>

template<typename T>
class IsEqualityComparable{
    static void* conv(bool);
    template<typename U>
    static std::true_type test(
                                decltype(conv(std::declval<U const&>() ==
                                std::declval<U const&>())),
                                decltype(conv(!std::declval<U const&>() ==
                                std::declval<U const&>()))
                              );
    template<typename U>
    static std::false_type test(...);
    public:
        static constexpr bool value = decltype(test<T>(nullptr, 
                                                       nullptr))::value;
};

template<typename T,
         bool EqComparable = IsEqualityComparable<T>::value>
struct TryEquals{
    static bool equals(T const& t1, T const& t2){
        return t1 == t2;
    }
};

class NotEqualityComparable : public std::exception {};

template<typename T>
struct TryEquals<T, false>{
    static bool equals(T const& t1, T const& t2){
        throw NotEqualityComparable();
    }
};

#endif