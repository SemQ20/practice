#include <iostream>
#include <cfloat>

/* platform/compilator specific macro implementations for work with floating point numbers */

int main()
{
    /* type float = mantissa*base^degree 
    mantissa - responsible for precision of floating point value*/

    std::cout << "return base of floating point type: " << FLT_RADIX << '\n'; 
    std::cout << "decimal precision for convertion from long: " << DECIMAL_DIG << '\n';

    /* example: 
    if FLT_DECIMAL_DIG return 9 (cpprefernce) then:
    float fval = 0.030405451 this maximum for conversion with minimal losses to decimal and back convertion */
    std::cout << "decimal pricision for conversion from float to decimal and back with minimal losses(exception 10): " << FLT_DECIMAL_DIG << '\n';
    std::cout << "also for type double: " << DBL_DECIMAL_DIG << '\n';
    std::cout << "also for type long double: " << LDBL_DECIMAL_DIG << '\n';

    std::cout << "maximum value for positive number float type: " << FLT_MAX << '\n';
    std::cout << "minimum value for positive number float type: " << FLT_MIN << '\n';

    std::cout << "maximum value for positive number double type: " << DBL_MAX << '\n';
    std::cout << "minimum value for positive number double type: " << DBL_MIN << '\n';

    std::cout << "maximum value for positive number long double type: " << LDBL_MAX << '\n';
    std::cout << "minimum value for positive number long double type: " << LDBL_MIN << '\n';

    std::cout << "he smallest number of float: " << FLT_EPSILON << '\n';
    std::cout << "he smallest number of double: " << DBL_EPSILON << '\n';
    std::cout << "he smallest number of long double: " << LDBL_EPSILON << '\n';

    std::cout << "minimum positive value of float: " << FLT_TRUE_MIN << '\n';
    std::cout << "minimum positive value of double: " << DBL_TRUE_MIN << '\n';
    std::cout << "minimum positive value of long double: " << LDBL_TRUE_MIN << '\n';

    std::cout << "number of decimal digit round to float type: " << FLT_DIG << '\n';
    std::cout << "also for double: " << DBL_DIG << '\n';
    std::cout << "also for long double: " << LDBL_DIG << '\n';

    std::cout << "number of base FLT_RADIX digits that can be represented without losing precision for float: " << FLT_MANT_DIG << '\n';
    std::cout << "also for double: " << DBL_MANT_DIG << '\n';
    std::cout << "also for long double: " << LDBL_MANT_DIG << '\n';

    std::cout << "minimal negative integer value of base FTL_RADIX float type for represents value in normalized form: " << FLT_MIN_EXP << '\n';
    std::cout << "also for double: " << DBL_MIN_EXP << '\n';
    std::cout << "also for long double: " << LDBL_MIN_EXP << '\n';

    std::cout << "maximum positive integer value of base FTL_RADIX float type for represents value in normalized form: " << FLT_MAX_EXP << '\n';
    std::cout << "also for double: " << DBL_MAX_EXP << '\n';
    std::cout << "also for long double: " << LDBL_MAX_EXP << '\n';
    /* And other values for base FTL_RADIX = 10 
    Ex: FTL_MIN_10_EXP, DBL_MIN_10_EXP, LDBL_MIN_10_EXP,
    FTL_MMAX_10_EXP, DBL_MAX_10_EXP, LDBL_MAX_10_EXP*/

    /* if return (cppreference):
     FLT_ROUNDS = -1 - the default rounding direction is not known,
     FLT_ROUNDS = 0 - toward zero; same meaning as FE_TOWARDZERO (round => 0),
     FLT_ROUNDS = 1 - to nearest; same meaning as FE_TONEAREST (round => 1),
     FLT_ROUNDS = 2 - towards positive infinity; same meaning as FE_UPWARD,
     FLT_ROUNDS = 3 - towards negative infinity; same meaning as FE_DOWNWARD. */
    std::cout << "type round for floating - point numbers: " << FLT_ROUNDS << '\n';

    return 0;
}
