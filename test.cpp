#include <iostream>
#include <cmath>

template<typename T>
T sub(T a, T b){
    return a - b;
}

/* base set precision for floating point value, point after zero
   base = 1, 2, 3, 4 ... n */
float set_precision_float(float x, int base){
    if(base == 0){
        return std::round(x);
    }
    int precision = pow(10, base);
    return std::round(x * precision)/precision;
}

int 
main(){
    auto c = set_precision_float(5.4345334f, 2);
    std::cout << c << '\n';
    return 0;
}
