#include <iostream>
#include <cctype> /* Work with C-style strings */

int main()
{
    int snum = 101;
    const char *cch = "Ab";
    const char * chnum = "2020";
    unsigned char ch = 'A';
    unsigned char lch = 'a';
    unsigned char symb = '/';
    char symbol = '\t';
    const char *csymb = "\n";
    const char *punct = ".,!";

    std::cout << std::boolalpha;

    /* return int > 0 if parameter integer value or letter in lowercase or uppercase otherwise return 0 */
    std::cout << "1. "<< static_cast<bool>(isalnum(symb)) << '\n';

    /* return int > 0 if parameter - letter in lowercase or uppercase, otherwise return 0 */
    std::cout << "2. "<< static_cast<bool>(isalpha(ch)) << '\n';

    /* return int > 0 if parameter - symbol(\n, \t), otherwise return 0 */
    std::cout << "3. "<< static_cast<bool>(iscntrl(*csymb)) << '\n';
    std::cout << "4. "<< static_cast<bool>(iscntrl(symbol)) << '\n';

    /* return int > 0 if parameter - printed symbol, if parameter - not printed symbol */
    std::cout << "5. "<< static_cast<bool>(isprint(symbol)) << '\n';

    /* return int > 0 if parameter - digit, otherwise return 0 */
    std::cout << "6. " << static_cast<bool>(isdigit(*chnum)) << '\n';
    std::cout << "7. " << chnum[2] << " - " << static_cast<bool>(isdigit(chnum[2])) << '\n';
    std::cout << "8. " << static_cast<bool>(isdigit(ch)) << '\n';

    /* similary isprint() */
    std::cout << "9. " << static_cast<bool>(isgraph(ch)) << '\n';
    std::cout << "10. " << static_cast<bool>(isgraph(*csymb)) << '\n';

    /* check is letter in lowercase return int > 0, otherwise return 0 */
    std::cout << "11. " << ch << " in lowercase?: " << static_cast<bool>(islower(ch)) << '\n';
    std::cout << "12. " << static_cast<bool>(islower(lch)) << '\n';

    /* Apposite islower(): */
    std::cout << "13. " << ch << " in uppercase?: " << static_cast<bool>(isupper(ch)) << '\n';
    std::cout << "14. " << static_cast<bool>(isupper(lch)) << '\n';

    /* return int > 0 if parameter - punctuation symbol, otherwise return 0 */
    std::cout << "15. " << punct << " - "<< static_cast<bool>(ispunct(*punct)) << '\n';
    std::cout << "16. " << static_cast<bool>(ispunct(lch)) << '\n';

    /* return int > 0 if parameter - space symbol(like " ", ' ', "\n" e.t.c.), otherwise return 0 */
    std::cout << "17. " << static_cast<bool>(isspace(*punct)) << '\n';
    std::cout << "18. " << static_cast<bool>(isspace(*csymb)) << '\n';
    
    /* return int > 0 if parameter - is hexadeciminal digit, otherwise return 0 */
    std::cout << "19. " << static_cast<bool>(isxdigit(ch)) << '\n';
    std::cout << "20. " << static_cast<bool>(isxdigit(*csymb)) << '\n';

    char lc = static_cast<char>(tolower(ch));
    std::cout << "21. " << ch << " tolower: "<< lc << '\n';

    char uc = static_cast<char>(toupper(lch));
    std::cout << "21. " << lch << " toupper: "<< uc << '\n';

    return 0;
}
