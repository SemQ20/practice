#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>


/* create overload operator for view result of std::tuple */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::tuple<T...> &_tuple) noexcept { //compile time, not trow exceptions
    return os << std::get<0>(_tuple) <<", "<< std::get<1>(_tuple) <<", "<< std::get<2>(_tuple) <<'\n';
} 

/* create overload operator for view result of std::pair */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::pair<T...> &_pair) noexcept { //compile time, not trow exceptions
    return os << _pair.first << ", "<< _pair.second << '\n';
}

template <class T>  // lvalue
T&& go(T& x)
{
    std::cout << "Lval this" << '\n';
    return std::forward<T>(x);
}
 
template <class T>
T&& go(T&& x)                  //rvalue
{
    std::cout << "Rval this" << '\n';
    return std::forward<T>(x);
    /* maybe similarly static_cast<T&&>(x) */
}

class someType {
public:
    int foo () {return 1;}
};

int main()
{
    /* std::swap */
    std::vector<int> numbers1 = {1, 2, 3, 4 , 5};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50};
    std::swap(numbers1,numbers2);

    for(auto &c : numbers2){
        std::cout << c << ',';
    }
    std::cout << '\n';

    /* std::exchange */
    std::exchange(numbers1, numbers2);
    for(auto &c : numbers2){
        std::cout << c << ',';
    }
    std::cout << '\n';

    /* std::move */
    std::string str1 = "Hello";
    std::string str2;
    str2 = std::move(str1);
    std::cout << str2 << '\n';

    /* std::tuple */
    std::tuple<int, float, std::string> t1 (10, 3.0f, "Hello");
    std::cout << t1;
    
    /* std::pair */
    std::pair<int,float> p1 (10, 1.0);
    std::cout << p1;

    /* std::is_const_v */
    int i = 200;
    const int mi = std::as_const(i);
    bool check = std::is_const_v<decltype(mi)>;
    std::cout << std::boolalpha;
    std::cout << check << '\n';

    /* std::forward */
    /* Forwards lvalues as either lvalues or as rvalues */
    /* Need for implementing type template constructor */
    int lval = 30;
    int rval = 0;
    rval = go(lval); // OK, call lval, return lval, used move semantic
    rval = go(500); // OK, overload function for rval , return rval, used move semantic

    /* small example for use std::declval */
    decltype(std::declval<someType>().foo()) n2;
    n2 = 100;
    std::cout << n2 << '\n';

    /* small example to use std::initializer list */
    /*  */
    std::initializer_list<int> ilist = {1, 2, 3, 4, 5};
    auto alist = {1, 2, 3, 4, 5}; // it's also initializer list

    for(auto &n : ilist){
        std::cout << n << '\n';
    } 
    std::cout << "Initializer list size: " << ilist.size() << '\n';
    return 0;
}
