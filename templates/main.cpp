#include "hasplus_hasless.hpp"
#include <iostream>

struct X1 {};
bool operator<(X1 const&, X1 const&){
    return true;
}

struct X2 {};
bool operator<(X2 , X2){
    return true;
}

struct X3 {};
bool operator<(X3&, X3&){
    return true;
}

struct X4 {};
struct BoolConvertible{
    operator bool() const{
        return true;
    }
};

struct X5 {};
BoolConvertible operator< (X5 const&, X5 const&){
    return BoolConvertible();
}

struct NotBoolConvertible{};

struct X6{};
NotBoolConvertible operator< (X6 const&, X6 const&){
    return NotBoolConvertible();
}

struct BoolLike{
    explicit operator bool() const{
        return true;
    }
};

struct X7{};
BoolLike operator< (X7 const&, X7 const&){
    return BoolLike();
}

int
main()
{
    std::boolalpha(std::cout);
    
    min(X1(),X1());
    min(X2(),X2());
    min(X5(),X5());


    return 0;
}
