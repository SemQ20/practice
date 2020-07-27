#include <iostream>
#include <type_traits>
#include <atomic>
#include <cstdlib>
#include <string>

template<typename T>
void print_values(T value){
    std::cout << "type: " << typeid(T).name() <<" and value: " << value << '\n';
}

template<typename Head, typename... Types>
void f(Head&& h, Types&& ...ts){
    print_values(h);
    if constexpr(sizeof...(ts) != 0){
        f(ts...);
    }
}

struct Int{
    Int(std::string &t_s) : ival(std::atoi(t_s.c_str())){}
    int val() const {
        return ival;
    }
    int ival;
};

int 
main()
{
    std::string ival = "571";
    Int i(ival);
    std::cout << i.val() << '\n';
    //f(1,3,4,5.4f,6.2,"hello");
    return 0;
}
