#include <iostream>
#include <climits>

/* Climits contains macroses platform 
    and compilator dependet  */

int main()
{
    /* uint64_t cval = INT_MAX;
    std::cout << "maximum value type int: "<< cval << '\n'; */
    std::cout << "numbers bit in a byte are: " << CHAR_BIT <<" sizeof: "<< sizeof(char) <<'\n';
    std::cout << "maximum number of bytes in a multibyte character: " << MB_LEN_MAX << '\n';
    std::cout << "minimum value type char: " << CHAR_MIN << '\n';
    std::cout << "maximum value type char: " << CHAR_MAX << '\n';
    std::cout << "minimum value type signed char: " << SCHAR_MIN << '\n';
    std::cout << "maximum value type signed char: " << SCHAR_MAX << '\n';
    std::cout << "maximum value type unsigned char: " << UCHAR_MAX << '\n';

    std::cout << "minimum value type short: " << SHRT_MIN << '\n';
    std::cout << "maximum value type short: " << SHRT_MAX << '\n';
    std::cout << "maximum value type unsigned short: " << USHRT_MAX << '\n';

    std::cout << "minimum value type int: " << INT_MIN << '\n';
    std::cout << "maximum value type int: " << INT_MAX << '\n';
    std::cout << "maximum value type unsigned int: " << UINT_MAX << '\n';

    std::cout << "maximum value type long: " << LONG_MAX << '\n';
    std::cout << "minimum value type long: " << LONG_MIN << '\n';
    std::cout << "maximum value type unsigned long: " << ULONG_MAX << '\n';

    std::cout << "maximum value type long long: " << LLONG_MAX << '\n';
    std::cout << "minimum value type long long: " << LLONG_MIN << '\n';
    std::cout << "maximum value type unsigned long long: " << ULLONG_MAX << '\n';

    return 0;
}
