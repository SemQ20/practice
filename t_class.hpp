/* Class for any tests */

#ifndef T_CLASS
#define T_CLASS
#include <string>
#include <cstdlib>
#include <cstring>

class TClass {
public:

    TClass() 
    : rint(0), rdouble(0.0), rlong(0), rfloat(0.0f), rstring(""), rchar(nullptr) {};

    TClass(int _int, double _double, long _long) 
    : rint(_int), rdouble(_double), rlong(_long) {};

    TClass(int _int, double _double, long _long, float _float) 
    : rint(_int), rdouble(_double), rlong(_long), rfloat(_float) {};

    TClass(std::string _string) : rstring(_string) {};

    int print_mb(const char *ptr);

    int rint;
    double rdouble;
    long rlong;
    float rfloat;
    const char *rchar;
    std::string rstring;

private:

};


class TClassWithStrictTypePos {
public:

    TClassWithStrictTypePos() 
    : rint(0), rdouble(0.0), rlong(0), rfloat(0.0f), rstring(""), rchar(nullptr) {};

    TClassWithStrictTypePos(int _int, double _double, long _long) 
    : rint(_int), rdouble(_double), rlong(_long) {};

    TClassWithStrictTypePos(int _int, double _double, long _long, float _float) 
    : rint(_int), rdouble(_double), rlong(_long), rfloat(_float) {};

    TClassWithStrictTypePos(std::string _string) : rstring(_string) {};

    int print_mb(const char *ptr);

    int rint;
    const char *rchar;
    std::string rstring;
    double rdouble;
    long rlong;
    float rfloat;
private:

};
#endif
