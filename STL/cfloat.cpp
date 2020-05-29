#include <iostream>
#include <cfloat>

/* platform/compilator specific macro implementations for work with floating point numbers */

int main()
{
    /* type float = mantissa*base^degree 
    mantissa - responsible for precision of floating point value*/

    std::cout << "retrun base of floating point type: " << FLT_RADIX << '\n'; 
    std::cout << "decimal precision for convertion from long: " << DECIMAL_DIG << '\n';

    /* example: 
    if FLT_DECIMAL_DIG return 9 (cpprefernce) then:
    float fval = 0.030405451 this maximum for conversion with minimal losses to decimal and back convertion */
    std::cout << "decimal pricision for conversion from float to decimal and back wit minimal losses(exception 10): " << FLT_DECIMAL_DIG << '\n';
    std::cout << "alse for type double" << DBL_DECIMAL_DIG << '\n';
    std::cout << "alse for type long double" << LDBL_DECIMAL_DIG << '\n';

    std::cout << "maximum value for positive number float type: " << FLT_MAX << '\n';
    std::cout << "minimum value for positive number float type: " << FLT_MIN << '\n';

    std::cout << "maximum value for positive number double type: " << DBL_MAX << '\n';
    std::cout << "minimum value for positive number double type: " << DBL_MIN << '\n';

    std::cout << "maximum value for positive number long double type: " << LDBL_MAX << '\n';
    std::cout << "minimum value for positive number long double type: " << LDBL_MIN << '\n';


    return 0;
}
