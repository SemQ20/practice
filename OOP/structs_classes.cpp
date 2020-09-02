#include <iostream>
#include "t_class.hpp"
/* It's all valid for pure C */

struct RndPosType {
    int a = 10;
    char b[5];
    double _bdbl = 5.0;
    float _fval = 3.03f;
    bool check = true;
};

struct StrictPosType {
    bool check = true;
    char b[5];
    int a = 10;
    float _fval = 3.03f;
    double _bdbl = 5.0;
};

struct Int{
    Int(std::string &t_s) : ival(std::atoi(t_s.c_str())){}
    int val() const {
        return ival;
    }
    int ival;
};

int main()
{
    RndPosType strt1;
    StrictPosType strt2;

    std::cout << "struct with rand pos type: "<< sizeof(strt1) << '\n'; // 32
    std::cout << "struct with strict pos type: "<< sizeof(strt2) << '\n'; // 24

    /* This method allocate memory not working for classes */
    TClass tclass;
    TClassWithStrictTypePos _tclass;

    std::cout << "class with rand pos type: "<< sizeof(tclass) << '\n'; // 72
    std::cout << "class with strict pos type: "<< sizeof(_tclass) << '\n'; // 72
    return 0;
}
