#include <iostream>
#include <array>
#include <type_traits>
#include <utility>
#include <tuple>
#include <deque>
#include <stddef.h>

template<typename T, typename... Args>
bool all_type_is_equal(Args... args){
    return (std::is_same_v<T, Args>& ...);
}

template<typename T, typename... Args>
bool all_type_is_equal(std::initializer_list<Args...> ilist){
    return (std::is_same_v<T, Args>& ...);
}

template<typename... Args>
bool all_pack_is_fpoint(Args... args){
    return (all_type_is_equal<float>(args)& ...);
}

template<typename... Args>
void push_back_void_deque(std::deque<void*>& deq, Args... args){
    (deq.push_back(std::forward<Args>(args)), ...);
}

int main()
{
    std::deque<void*> deq;

    int ilist1 = {5};
    float ilist2 = {7.3f};

    push_back_void_deque(deq, &ilist1, &ilist2);
    auto i = *static_cast<int*>(deq[0]);
    auto i1 = *static_cast<float*>(deq[1]);

    std::cout << i << '\n';
    std::cout << i1 << '\n';

    std::boolalpha(std::cout);
    auto il = {2.3f, 4.3f, 8.2f};
    std::cout << all_pack_is_fpoint(il) << '\n';
    std::cout << all_type_is_equal<int>(10, 5.3, 5) << '\n';

    return 0;
}
