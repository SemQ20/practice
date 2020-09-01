#ifndef HASPLUS_HPP
#define HASPLUS_HPP

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

template<typename T1, typename T2>
class HasLess{
    template<typename T> struct Identity;
    template<typename U1, typename U2> static std::true_type
    /* check:
       if type T1 and type T2 includes operator< :
        * template instantaition as class HasLess with inheritance std::true_type public fields */
    test(Identity<decltype(std::declval<U1>() < std::declval<U2>())> *); // like: test(Identity<T>*)
    /* sfinae, template instantaition as class HasLess with inheritance std::false_type public fields */
    template<typename U1, typename U2> static std::false_type
    test(...);
public:
    /* This like:
        HasLess<T1, T2>::value;
        test function as a helper template function for correctness difinition 
        for included operator< in types T1, T2;
    call function test(nullptr) for correctness difinition value 
    here nullptr - is a fiction for satisfaction callable template function 
    for template type deducing and instantation tamplate class with std::true_type/std::false_type inheritance */
    static constexpr auto value =
           decltype(test<T1, T2>(nullptr))::value;
};

template<typename T1, typename T2, bool HasLess>
class LessResultImpl{

public:
    using Type = decltype(std::declval<T1>() < std::declval<T2>());
};

template<typename T1, typename T2>
class LessResultImpl<T1, T2, false>{};

template<typename T1, typename T2>
class LessResultT : public LessResultImpl<T1, T2, HasLess<T1, T2>::value>{};

template<typename T1, typename T2>
using LessResult = typename LessResultT<T1, T2>::Type;

/* template<typename T>
std::enable_if_t<std::is_convertible_v<LessResult<T const&, T const&>, bool>,
                                                                   T const&>
min(T const& a, T const& b){
    if(a < b){
        return a;
    }
    return b;
} */

template<typename T>
class IsContextualBoolT{
private:
    template<typename> struct Identity;
    template<typename U> static std::true_type
    /* check for contextual convertion to bool
    here pointer to a member type (Identity) concidered like bool value
    this pointer not convertible to int like trivial type bool */
    test(Identity<decltype(std::declval<U>() ? 0 : 1) > *); // like: test(Identity<T>*)
    template<typename U> static std::false_type
    test(...);
public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};

template<typename T>
constexpr bool isContextualBool = IsContextualBoolT<T>::value;

template<typename T>
std::enable_if_t<isContextualBool<LessResult<T const&, T const&>>,
                                                       T const &>
min(T const& a, T const& b){
    if(a < b){
        return a;
    }
    return b;
}

#endif