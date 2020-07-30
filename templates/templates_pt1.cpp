#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <list>

template<typename T1, typename T2,
         typename RT = std::decay_t<decltype(true? std::declval<T1>() :
         std::declval<T2>())>>
RT max (T1& a, T2& b){
    return a < b ? b : a;
}

template<typename T>
class SomeClass{
    
public:
    SomeClass() = default;

template<typename U>
class Handle;

template<typename U>
SomeClass(SomeClass<U> const&);

template<typename U>
static U zero;

};

template<typename T>
    template<typename U>
class SomeClass<T>::Handle{

public:
    static T it;
};

template<typename T>
    template<typename T2>
SomeClass<T>::SomeClass(SomeClass<T2> const& b){

}

template<typename T>
    template<typename U>
U SomeClass<T>::zero = 0;

template<typename... Ts> 
struct Arglist
{
    
    template<Ts... vals> struct Vals{
        std::tuple<Ts...> tuple{vals...};
        
        auto print(){
            return tuple;
        }
    };
};

template<typename T, template<typename X> class C>
class OtherClass{
public:
    C<T> someval;
};

template<typename... Types>
class Tuple{

};

template<typename... Types>
class MyTuple : public Tuple<Types...>{

};

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

int main()
{
    int x = 3;
    float y = 4.5f;
    
    std::cout << ::max(x, y) << '\n';
    Arglist<int, char, char>::Vals<3, 'x' , 'y'> tada;
    auto t1 = tada.print();
    std::cout << std::get<0>(t1) << '\n';
    OtherClass<int, std::vector> oc;
    oc.someval = {1,3,4,56,7};
    std::cout << "vector: " << '\n';
    for(auto const& i : oc.someval){
        std::cout << i << '\n';
    }


    return 0;
}
