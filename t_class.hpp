/* Class for any tests */

#ifndef T_CLASS
#define T_CLASS
#include <string>
#include <cstdlib>
#include <cstring>

class tClass {
public:

    tClass() 
    : rint(0), rdouble(0.0), rlong(0), rfloat(0.0f), rstring(nullptr), rchar(nullptr) {};

    tClass(int _int, double _double, long _long) 
    : rint(_int), rdouble(_double), rlong(_long) {};

    tClass(int _int, double _double, long _long, float _float) 
    : rint(_int), rdouble(_double), rlong(_long), rfloat(_float) {};

    tClass(std::string _string) : rstring(_string) {};

    int print_mb(const char *ptr);

    int rint;
    double rdouble;
    long rlong;
    float rfloat;
    const char *rchar;
    std::string rstring;

private:

};
#endif
