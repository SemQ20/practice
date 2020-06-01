#include <iostream>
#include <limits>

int main()
{
    int ival = 10;
    float fpoint = 3.5f;
    std::cout << std::boolalpha;
    /* check type T if type is integer return true */
    std::cout << "is_integer?: " << std::numeric_limits<decltype(ival)>::is_integer << '\n';

    /* check for all integer types */
    std::cout << "int is specialized?: " << std::numeric_limits<decltype(ival)>::is_specialized << '\n';
    std::cout << "float is specialized?: " << std::numeric_limits<decltype(fpoint)>::is_specialized << '\n';
    std::cout << "b is signed?: " << std::numeric_limits<decltype(ival)>::is_signed << '\n';

    /* check type for exact representation */
    std::cout << "int is exact?: " << std::numeric_limits<decltype(ival)>::is_exact << '\n';

    /* check for type representation in positive infinity */
    std::cout << "type of ival have infinity representation? " << std::numeric_limits<decltype(ival)>::has_infinity << '\n';
    std::cout << "type of fpoint have infinity representation? " << std::numeric_limits<decltype(fpoint)>::has_infinity << '\n';

    /* checks for floating point types: */
    std::cout << "quiet NaN float: " << std::numeric_limits<decltype(fpoint)>::quiet_NaN() << '\n';
    double dnan = std::numeric_limits<double>::quiet_NaN();
    std::cout << "double nan: "<< dnan << '\n';

    /* if return 1 = denorm present
    return - 1 = indeterminate
    return 0 = absent */
    std::cout << "denorm? " << std::numeric_limits<decltype(fpoint)>::has_denorm << '\n';
    std::cout << std::numeric_limits<decltype(dnan)>::has_signaling_NaN << '\n';

    std::cout << "denorm loss: " << std::numeric_limits<decltype(fpoint)>::has_denorm_loss << '\n';

    /* if return (cppreference):
     FLT_ROUNDS = -1 - the default rounding direction is not known,
     FLT_ROUNDS = 0 - toward zero; same meaning as FE_TOWARDZERO (round => 0),
     FLT_ROUNDS = 1 - to nearest; same meaning as FE_TONEAREST (round => 1),
     FLT_ROUNDS = 2 - towards positive infinity; same meaning as FE_UPWARD,
     FLT_ROUNDS = 3 - towards negative infinity; same meaning as FE_DOWNWARD. */
    std::cout << "round style: " << std::numeric_limits<decltype(fpoint)>::round_style << '\n';

    std::cout << "requirements of IEC 559: " << std::numeric_limits<decltype(fpoint)>::is_iec559 << '\n';

    /* check for bound */
    std::cout << "int is bounded?: " << std::numeric_limits<decltype(ival)>::is_bounded << '\n';
    std::cout << "float is bounded?: " << std::numeric_limits<decltype(fpoint)>::is_bounded << '\n';

    /* number of digits in base-radix that can representation by the type T witout change */
    std::cout << "of int: " << std::numeric_limits<decltype(ival)>::digits << '\n';
    std::cout << "of float: " << std::numeric_limits<decltype(fpoint)>::digits << '\n';

    /* base radix */
    std::cout << "base radix" << '\n';
    std::cout << "of int: " << std::numeric_limits<decltype(ival)>::radix << '\n';
    std::cout << "of float: " << std::numeric_limits<decltype(fpoint)>::radix << '\n';

    /* for modulo arithmetics */
    std::cout << "modulo" << '\n';
    std::cout << "of int: " << std::numeric_limits<decltype(ival)>::is_modulo << '\n';
    std::cout << "of float: " << std::numeric_limits<decltype(fpoint)>::is_modulo << '\n';

    std::cout << "traps of int: " << std::numeric_limits<decltype(ival)>::traps << '\n';
    std::cout << "traps of float: " << std::numeric_limits<decltype(fpoint)>::traps << '\n';

    std::cout << "tinyness_before of int: " << std::numeric_limits<decltype(ival)>::tinyness_before << '\n';
    std::cout << "tinyness_before of float: " << std::numeric_limits<decltype(fpoint)>::tinyness_before << '\n';

    std::cout << "value of the number of base-10 digits for int: " << std::numeric_limits<decltype(ival)>::digits10 << '\n';
    std::cout << "value of the number of base-10 digits for float: " << std::numeric_limits<decltype(fpoint)>::digits10 << '\n';

    std::cout << "infinity int: " << std::numeric_limits<decltype(ival)>::infinity() << '\n';
    std::cout << "infinity float: " << std::numeric_limits<decltype(fpoint)>::infinity() << '\n';

    std::cout << "round error int: " << std::numeric_limits<decltype(ival)>::round_error() << '\n';
    std::cout << "round error float: " << std::numeric_limits<decltype(fpoint)>::round_error() << '\n';

    std::cout << "epsilon int: " << std::numeric_limits<decltype(ival)>::epsilon() << '\n';
    std::cout << "epsilon float: " << std::numeric_limits<decltype(fpoint)>::epsilon() << '\n';

    std::cout << "std::numeric_limits<T>::min(): " << '\n' << "int: " << std::numeric_limits<decltype(ival)>::min() << '\n';
    std::cout << "float: " << std::numeric_limits<decltype(fpoint)>::min() << '\n';

    std::cout << "std::numeric_limits<T>::max(): " << '\n' << "int: " << std::numeric_limits<decltype(ival)>::max() << '\n';
    std::cout << "float: " << std::numeric_limits<decltype(fpoint)>::max() << '\n';

    std::cout << "std::numeric_limits<T>::lowest(): " << '\n' << "int: " << std::numeric_limits<decltype(ival)>::lowest() << '\n';
    std::cout << "lowest: " << std::numeric_limits<decltype(fpoint)>::lowest() << '\n';

    return 0;
}
