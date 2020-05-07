#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <tuple>


/* create overload operator for view result of std::tuple */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::tuple<T...> &_tuple) noexcept {
    return os << std::get<0>(_tuple) <<", "<< std::get<1>(_tuple) <<", "<< std::get<2>(_tuple) <<'\n';
} 

/* create overload operator for view result of std::pair */
template<typename ...T>
constexpr std::ostream &operator<<(std::ostream &os, std::pair<T...> &_pair) noexcept {
    return os << _pair.first << ", "<< _pair.second << '\n';
}

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
    
    return 0;
}
