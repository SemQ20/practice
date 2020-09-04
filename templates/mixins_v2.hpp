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


#endif