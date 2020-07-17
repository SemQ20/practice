#include <iostream>
#include <array>
#include <type_traits>
#include <utility>
#include <tuple>
#include <deque>

/* user defined literals */
template<char...> int operator "" _B7();

template<char... cs>
int operator "" _B7(){
    std::array<char, sizeof...(cs)> chars{cs...};
    for(char c : chars){
        std::cout << "'" << c << "' "; 
    }
    std::cout << '\n';
    return 0;
}

template<typename T, typename... Args>
bool all_type_is_equal(std::tuple<Args...> tuple){
    return (std::is_same_v<Args, Args>& ...);
}

template<typename T, typename... Args>
bool all_type_is_equal(Args... args){
    return (std::is_same_v<Args, Args>& ...);
}


template<typename T, typename... Args>
bool all_type_is_equal(std::initializer_list<Args...> ilist){
    return (std::is_same_v<Args, Args>& ...);
}

template<typename... Args>
void push_back_void_deque(std::deque<void*>& deq, Args... args){
    (deq.push_back(std::forward<Args>(args)), ...);
}

int main()
{
    std::deque<void*> deq;
    
    int d = 4;
    void* p = new void*[10];
    p = &d;
    auto f = *static_cast<int*>(p);
    std::cout << f << '\n';
    int ilist1 = {5};
    int ilist2 = {7};

    push_back_void_deque(deq, &ilist1, &ilist2);
    //push_back_void_deque(deq,&ilist1);
    auto i = *static_cast<int*>(deq[1]);
    std::cout << i << '\n';
    std::boolalpha(std::cout);
    auto t1 = std::make_tuple(10, 4.3f, 8);
    auto tuple = {10, 4, 1};
    std::cout << all_type_is_equal<int>(tuple) << '\n';
    delete[] p;
    return 0;
}
