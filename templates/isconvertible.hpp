#ifndef ISCONVERTIBLE_HPP
#define ISCONVERTIBLE_HPP
#include <iostream>
#include <type_traits>  // for true_type and false_type
#include <utility>      // for declval

template<typename FROM, typename TO>
struct IsConvertibleT {
  private:
    // to check whether we can call this helper func for a FROM object:
    static void func(TO);
    // test() trying to call the helper func():
    template<typename F, typename T,
             typename = decltype(func(std::declval<F>()))>
      static char test(void*);
    // test() fallback:
    template<typename, typename>
      static long test(...);
  public:
    static constexpr bool value = sizeof(test<FROM, TO>(nullptr)) == 1;
};

template<typename FROM, typename TO>
  constexpr bool IsConvertible = IsConvertibleT<FROM, TO>::value;

#endif