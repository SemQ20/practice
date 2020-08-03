#include <iostream>
#include <array>
#include <type_traits>
#include <utility>
#include <tuple>
#include <deque>
#include <stddef.h>
#include <vector>

template<typename T>
class Array
{
    T* data;
public:
    Array(Array<T> const&);
    Array<T>& operator= (Array<T> const&);
    T& operator[](std::size_t k){
        return data[k];
    }
    std::size_t size = 0;
};

template<typename T, typename... Args>
bool 
all_type_is_equal(Args... args){
    return (std::is_same_v<T, Args>& ...);
}

template<typename T, typename... Args>
bool 
all_type_is_equal(std::initializer_list<Args...> ilist){
    return (std::is_same_v<T, Args>& ...);
}

template<typename... Args>
bool 
all_pack_is_fpoint(Args... args){
    return (all_type_is_equal<float>(args)& ...);
}

template<typename... Args>
void 
push_back_void_deque(std::deque<void*>& deq, 
                     Args... args){

    (deq.push_back(std::forward<Args>(args)), ...);
}

template<typename F, typename... Ts>
void 
invoke(F f, Ts... ts){
    f(ts...);
}

template<typename T>
struct A{
    T val;
};
template<typename T> A(T) -> A<T>; // rule for template type output

template<typename T>
void exchange(Array<T> *a, Array<T> *b){
    T* p = &(*a)[0];
    T* q = &(*b)[0];
    for(std::size_t k = 0; k = a->size; k-- != 0){
        exchange(p++, q++);
    }
}

class Coord{
    float const minusone = -1.0f;
    public:
        Coord(){}
        Coord(float x, float y) : pointX(x), pointY(y){}
        Coord(Coord const&){};
        Coord& operator=(Coord const& o1);
        const Coord operator-(Coord const& o1) const;
        Coord abs();
        float pointX;
        float pointY;
        ~Coord(){}
};

Coord& Coord::operator=(Coord const& obj){
    pointX = obj.pointX;
    pointY = obj.pointY;
    return *this;
}

const Coord Coord::operator-(Coord const& o1) const{
    return Coord(pointX - o1.pointX, pointY - o1.pointY);
}

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
    return Coord(pointX, pointY);
}

/* **************** Static polymorphysm **************** */
class GeoLine{
    public:
        Coord coords;
        GeoLine(float px, float py) : coords(px, py){}
        void draw();
        Coord center_of_gravity();
        ~GeoLine(){}
};

void GeoLine::draw(){
    std::cout << "Line " << " point x: " << coords.pointX << " point y: " << coords.pointY << '\n';
}

Coord GeoLine::center_of_gravity(){
    return Coord(coords.pointX, coords.pointY);
}

class GeoCircle{
    public:
        Coord coords;
        GeoCircle(float px, float py) : coords(px, py){}
        void draw();
        Coord center_of_gravity();
        ~GeoCircle(){}
};

void GeoCircle::draw(){
    std::cout << "Circle " << " point x: " << coords.pointX << " point y: " << coords.pointY << '\n';
}

Coord GeoCircle::center_of_gravity(){
    return Coord(coords.pointX, coords.pointY);
}

template<typename GeoObj>
void MyDraw(GeoObj const& obj){
    obj.draw();
}

template<typename Obj1, typename Obj2>
Coord distance(Obj1& o1, Obj2& o2){
    Coord c = o1.center_of_gravity() - o2.center_of_gravity();
    return c.abs();
}

template<typename GeoObj>
void drawElems(std::vector<GeoObj*> const& vec){
    for(std::size_t i = 0; i < vec.size(); ++i){
        vec[i].draw();
    }
}

/* **************************************************** */

int 
main()
{
    std::deque<void*> deq;

    int ilist1 = {5};
    float ilist2 = {7.3f};

    push_back_void_deque(deq, &ilist1, &ilist2);
    auto i = *static_cast<int*>(deq[0]);
    auto i1 = *static_cast<float*>(deq[1]);

    std::cout << i << '\n';
    std::cout << i1 << '\n';

    std::boolalpha(std::cout);
    auto il = {2.3f, 4.3f, 8.2f};
    std::cout << all_pack_is_fpoint(il) << '\n';
    std::cout << all_type_is_equal<int>(10, 5.3, 5) << '\n';

    /* transfer in template function invoke
     * functional object - lambda expression */
    auto lamb = [](auto x, auto y){
        std::cout << x + y << '\n';
    };

    invoke([](auto x, auto y){
        std::cout << x + y << '\n';
    }, 21 , 21);

    //invoke(lamb, 21, 21);

    /* works only with agregate initialization: */
    A a = {42}; // this A<int> a; A<int>::val = 42; 
    std::cout << "A<T>::val: "<< a.val << '\n';


    return 0;
}