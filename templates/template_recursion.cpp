#include <iostream>
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

template<typename Cont, bool = Cont::std::queue>
struct print;

template<typename Cont>
struct print<Cont, true>{
    print(Cont& q){
        while(!q.empty()){
            std::cout << q.front() << '\n';
            q.pop();
        }
    }
};

int main()
{
    std::queue<int> q;
    print(q);
    std::boolalpha(std::cout);
    std::cout << "9 is whole? :" << IsPrime<9>::value << '\n';
    std::cout << "29 is whole? :" << IsPrime<29>::value << '\n';
    return 0;
}
