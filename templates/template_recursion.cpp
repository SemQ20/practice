#include <iostream>
#include <tuple>
#include <queue>

template<unsigned int pval, unsigned int dval>
struct DoIsPrime{
    static constexpr bool value = (pval % dval != 0) && DoIsPrime<pval, dval - 1>::value;
};

template<unsigned int p>
struct DoIsPrime<p, 2>{
    static constexpr bool value = (p % 2 != 0);
};

template<unsigned int p>
struct IsPrime{
    static constexpr bool value = DoIsPrime<p, p/2>::value;
};

/* Extentions */
template<>
struct IsPrime<0> {static constexpr bool value = false; };
template<>
struct IsPrime<1> {static constexpr bool value = false; };
template<>
struct IsPrime<2> {static constexpr bool value = true; };
template<>
struct IsPrime<3> {static constexpr bool value = true; };

/* recursion for print tuple args */
template<int Idx, int Max, typename... Args>
struct Print_tuple{
    static void print(std::ostream& os, std::tuple<Args...>& tuple){
        os << std::get<Idx>(tuple) << (Idx + 1 == Max ? "" : ",");
        Print_tuple<Idx + 1, Max, Args...>::print(os,tuple);
    }
};

/* end of recursion */
template<int Max, typename... Args>
struct Print_tuple<Max, Max, Args...>{
    static void print(std::ostream& os, std::tuple<Args...>& tuple){}
};

template<typename... Args>
std::ostream& operator<<(std::ostream& os, std::tuple<Args...>& tuple){
    Print_tuple<0,sizeof...(Args),Args...>::print(os,tuple);
    return os;
};


int main()
{
    std::tuple<float, float, int> t1{3.3f, 5.4f, 12};
    std::cout << t1 << '\n';
    std::boolalpha(std::cout);
    std::cout << "9 is whole? :" << IsPrime<9>::value << '\n';
    std::cout << "29 is whole? :" << IsPrime<29>::value << '\n';
    return 0;
}
