#include <iostream>
#include <type_traits>
#include <cstdlib>
#include <string>
#include <vector>

class Coord{
    //TODO finalize
    public:
        Coord abs(){};
        Coord& operator-(Coord const& o1){};
};

/* ************************* dynamic polymorphism ********************** */
class GeoObj{
    public:
        virtual void draw() const = 0;
        virtual Coord center_of_gravity() const = 0;
        virtual ~GeoObj() = default;
};

class Circle : GeoObj{
    public:
        virtual void draw() const override;
        virtual Coord center_of_gravity() const override;
};

class Line : GeoObj{
    public:
        virtual void draw() const override;
        virtual Coord center_of_gravity() const override;
};

void myDraw(GeoObj const &go){
    go.draw();
}

Coord distance(GeoObj const& t1, GeoObj const& t2){
    Coord c = t1.center_of_gravity() - t2.center_of_gravity();
    return c.abs();
}

/* void drawElems(std::vector<GeoObj*> const& vec){
    for(std::size_t i = 0; i < vec.size() ++i){
        vec[i]->draw();
    }
} */
/* ******************************************************************* */


int 
main()
{
    return 0;
}
