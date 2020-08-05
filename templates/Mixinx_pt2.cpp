#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <typeinfo>
#include "template.hpp"

//using TemplateTest::max_test;

template<typename... Mixins>
class Point : public Mixins...{
    double x, y, z;
public:
    Point() : Mixins()...{}
    template<typename Visitor>
    void visitMixins(Visitor visitor){
        visitor(static_cast<Mixins&>(*this)...);
    }
};

struct Color{
    char red, green, blue;
};

struct Label{
    std::string name;
};

template<typename F, typename... Types>
auto func(F f, Types... values){
    return f(Types(values)...);
}

template<typename T>
class Base{
public:
    int basefield = 0;
};

class D1 : public Base<Base<void>> {
public:
   void f(){
       basefield = 42;
       std::cout << basefield << '\n';
   }
};

template<typename T>
class D2 : public Base<double> {
public:
   void f(){
       basefield = 42;
       std::cout << basefield << '\n';
   }

   T exchange;
};

template <typename T>
class DD : public Base<T> {
public:
    auto f(){
        /* Base<T> or this-> is required */
        return this->basefield = 42;
    }
};

template<>
class Base<bool> {
public:
    enum {
        basefield = 42
    };
};

auto g(DD<int>& d){
    return d.f();
}

int main()
{
    //std::cout << max_test(15.1f, 7.3f) << '\n';
    D1 d;
    D2<int> d1;
    d1.basefield = 42;
    d1.exchange = 21;
    std::cout << typeid(d1.exchange).name() << '\n'; // without magic
    Base<void> b;
    d.f();
    std::cout << b.basefield << '\n';
    DD<int> dd;
    auto val = g(dd);
    std::cout << val << '\n';
    return 0;
}
