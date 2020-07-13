#include <iostream>
#include <utility>
#include <tuple>
#include <string>

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

int main()
{
    Point<Color, Label> p;
    
    return 0;
}
