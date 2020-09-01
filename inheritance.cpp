#include <iostream>
#include <memory>
#include <vector>

class Base{
public:
    virtual ~Base() = default;
    Base() = default;
    Base(const Base&) = default;
    Base& operator=(const Base&) = default;
    Base(Base&&) = default;
    Base& operator=(Base&&) = default;

    virtual void do_anything() = 0;
};

class Derived : public Base {
public:
    void do_anything() override{
        std::cout << "Hello from derived class" << '\n';
    }
};

void print_base(Base *p){
    p->do_anything();
}

class Coord{
    public:
        Coord(){}
        Coord(float x, float y) : pointX(x), pointY(y){};
        Coord& operator=(Coord const& obj){
            pointX = obj.pointX;
            pointY = obj.pointY;
            return *this;
        }
        Coord abs();
        const Coord operator-(const Coord& o1) const;
        float pointX = 0.0f;
        float pointY = 0.0f;
        ~Coord(){};
    private:
        float const minusone = -1.0f;
};

Coord Coord::abs(){
    if (pointX < 0 && pointY > 0){
        pointX *= minusone, pointY;
    }
    if(pointX > 0 && pointY < 0){
        pointX, pointY *= minusone;
    }
    if(pointX < 0 && pointY < 0){
        pointX *= minusone, pointY;
        pointX, pointY *= minusone;
    }

    return *this;
}

const Coord Coord::operator-(const Coord& o1) const{
    return Coord(pointX-o1.pointX, pointY - o1.pointY);
}
/* ************************* dynamic polymorphism ********************** */

class GeoObj{
    public:
        /* GeoObj(){}
        GeoObj(float px , float py) : x(px), y(py){} */
        virtual void draw() const = 0;
        virtual Coord center_of_gravity() const = 0;
};

class Circle : public GeoObj{
    public:
        Coord coords;
        Circle(float px , float py) : coords(px,py){}
        virtual void draw() const override;
        virtual Coord center_of_gravity() const override;
};

Coord Circle::center_of_gravity() const{
    return Coord(coords.pointX, coords.pointY);
}

void Circle::draw() const{
    std::cout << "Circle " << " point x: " << coords.pointX << " point y: " << coords.pointY << '\n';
}

class Line : public GeoObj{
    public:
        Coord coords;
        Line(float px , float py) : coords(px,py){}
        virtual void draw() const override;
        virtual Coord center_of_gravity() const override;
};

Coord Line::center_of_gravity() const{
    return Coord(coords.pointX, coords.pointY);
}

void Line::draw() const{
    std::cout << "Line " << " point x: " << coords.pointX << " point y: " << coords.pointY << '\n';
}

void myDraw(GeoObj const &go){
    go.draw();
}

Coord distance(GeoObj const& t1, GeoObj const& t2){
    Coord c = t1.center_of_gravity() - t2.center_of_gravity();
    return c.abs();
}

void drawElems(std::vector<GeoObj*> const& vec){
    for(std::size_t i = 0; i < vec.size(); ++i){
        vec[i]->draw();
    }
}

/* virtual inheritance: */
struct A
{
    void foo() { std::cout << "is class A" << '\n';}
};

struct B : public virtual A {};
struct C : public virtual A {};

struct D : public B, public C
{
    void bar()
    {
        foo(); // not ambiguous A::foo one object A in object D OK
    }
};

/* ******************************************************************* */

int main()
{
    /* Derived dr;
    auto ptr = std::make_shared<Derived>();
    print_base(ptr.get()); */
    D d;
    d.bar(); d.foo(); /* demostrates how to virtual inheritance works */

    Circle cr(-5.5f, -6.7f);
    Line ln(3.0f, 5.7f);
    std::vector<GeoObj*> vec{&cr,&ln};
    cr.coords = distance(cr,ln);
    std::cout << "distance: "<< cr.coords.pointX << ", "<< cr.coords.pointY << '\n';
    drawElems(vec);
    return 0;
}
