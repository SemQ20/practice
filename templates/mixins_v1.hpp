#ifndef MIXINS_V1
#define MIXINS_V1

#include <iostream>

/* Use:
    access ac;
    combined_class<access> ch;
    ac.on_handle_connect(ch);
    ac.on_handle_response(ch); */

struct access{
    template<typename Impl>
    static void on_handle_response(Impl impl){ impl.handle_response(); }
    template<typename Impl>
    static void on_handle_connect(Impl impl){ impl.handle_connect(); }
};

template<typename Base>
struct connection_handler{
    void on_connection(){
        access::on_handle_connect(static_cast<Base*>(this));
    }
};

template<typename Base>
struct response_handler{
    void on_response(){
        access::on_handle_response(static_cast<Base*>(this));
    }
};

/* Helper Class */
template<typename work>
struct combined_class : public connection_handler<work>, 
                        public response_handler<work>
{
private:
    friend struct access;
    void handle_connect() { std::cout << "Connecting" << '\n'; }
    void handle_response() { std::cout << "Responsing" << '\n'; }
};


/* Use:
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
    std::cout << val << '\n'; */

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
#endif