#include <iostream>
#include <string>

/* Contains bitset class, class for work with bits */
/* all moves at left to right */
#include <bitset>

int main()
{
    std::bitset<10> b1("1010100101");
    std::cout<< std::boolalpha;
    std::cout << b1 << '\n';

    /* check is bit is set */
    std::cout << b1.test(2) << '\n';

    /* all() check if all bits set return true otherwise - false */
    std::cout << "all bit set? "<< b1.all() << '\n';

    /* any() check if any bits set return true otherwise - false  */
    std::cout << b1.any() << '\n';

    /* return size of bitset object */
    std::cout << b1.size() << '\n';

    /* return number of set bits */
    std::cout << b1.count() << '\n';

    /* return true if all bits are not set */
    std::cout << b1.none() << '\n';

    /* flip bit in position flip(position)*/
    /* example 1010100101 <= this not like [0-9] is default array  =>  this like [9-0] and if flip(1) = result 1010100111 */
    // std::cout << b1 << '\n';
    // b1.flip();
    // std::cout << b1 << '\n' << "\n";

    /* example 1010100101 <= this not like [0-9] is default array  =>  this like [9-0] and if set(1) = result 1010100111 */
    // std::cout << b1 << '\n';
    // b1.set(1);
    // std::cout << b1 << '\n';

    /* no comment */
    // std::cout << b1 << '\n';
    // b1.reset();
    // std::cout << b1 << '\n';

    /* inverted */
    std::bitset<b1.size()> _inverted_b = ~b1;
    std::cout << _inverted_b << '\n';

    std::string numstr = b1.to_string();
    
    /* to decimal */
    unsigned long b1l = b1.to_ulong();
    std::cout << numstr << '\n';
    std::cout << b1l << '\n';

    /* hash function for bitset */    
    std::hash<std::bitset<b1.size()>> f;
    std::cout << f(b1) << '\n';
    return 0;
}
