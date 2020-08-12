#ifndef HASPLUS_HPP
#define HASPLUS_HPP

#include <iostream>
#include <utility>
#include <type_traits>

template<typename T>
class Array{
public:
    Array(T obj) : arrval(obj.val){}
    int arrval = 0;
    template<typename U>
    const Array<T> operator+(Array<U>& cv){
        return Array<T>(arrval + cv.arrval);
    }
};

class B{
public:
    B(){}
    B(int ival) : val(ival) {}
    int val = 0;
};

class A{
public:
    A(){}
    A(int ival) : val(ival) {}
    int val = 0;
    const A operator+(B& objb){
        return (val + objb.val);
    }
};

/* concrete function for addition classes Array<T> */
auto addAB(Array<A>& arrayA, Array<B>& arrayB){
    auto sum = arrayA + arrayB;
    return sum;
}

/* generalized version addAB */
template<typename T1, typename T2>
auto addAB1(Array<T1>& obja, Array<T2>& objb){
    auto sum = obja + objb;
    return sum;
}

template<typename, typename, typename = std::void_t<>>
struct HasplusT : std::false_type{};

template<typename T1, typename T2>
struct HasplusT<T1, T2, std::void_t<decltype(std::declval<T1>() + 
                                    std::declval<T2>())>> : std::true_type{
};

template<typename T1, typename T2, bool = HasplusT<T1, T2>::value>
struct PlusResultT{
    using Type = decltype(std::declval<T1>() + std::declval<T2>());
};

template<typename T1, typename T2>
struct PlusResultT<T1, T2, false>{};


template<typename T1, typename T2>
Array<typename PlusResultT<T1,T2>::Type> operator+(Array<T1> /* const */& obja, 
                                            Array<T2> /* const */& objb){
};

#endif