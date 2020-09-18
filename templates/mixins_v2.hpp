#ifndef MIXINS_V2
#define MIXINS_V2

#include <iostream>

template<typename... Mixins>
class Point : Mixins... {
    public:
        double x, y;
        Point() : Mixins()..., x(0.0), y(0.0) {}
        Point(double x, double y) : Mixins()..., x(x), y(y) {}
};

class Label{
    public:
        const char* label;
        Label() : label("") {}
};
using LabeledPoint = Point<Label>;

class Color{
    public:
        unsigned char red = 0, green = 0, blue = 0;
};
using MyPoint = Point<Label, Color>;

class NotVirtual{
};

class Virtual{
    public:
        virtual void foo(){ }
};

template<typename... Mixins>
class Base : public Mixins...{
    public:
        void foo(){
            std::cout << "Base::foo()" << '\n';
        }
};

template<typename... Mixins>
class Derived : public Base<Mixins...>{
    public:
        void foo(){
            std::cout << "Derived::foo()" << '\n';
        }
};

#endif