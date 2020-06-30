#include <iostream>
#include <tuple>

template <int IDX, int MAX , typename... Args>
struct PRINT_TUPLE{
    static void print (std::ostream& os, const std::tuple<Args...>& tuple){
        os << std::get<IDX>(tuple) << (IDX + 1 == MAX ? "" : ",");
        PRINT_TUPLE<IDX+1, MAX, Args...>::print(os,tuple);
    }
};

//end of recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>{
    static void print (std::ostream& os, const std::tuple<Args...>& tuple){
    }
};

template <typename... Args>
std::ostream& operator<< (std::ostream& os, const std::tuple<Args...>& tuple){
    os << "[";
    PRINT_TUPLE<0,sizeof...(Args), Args...>::print(os, tuple);
    return os << "]";
}


int main()
{
    std::tuple<int, float, float> tpl(10, 10.3f, 3.7f);
    std::cout << tpl << '\n';
    return 0;
}
