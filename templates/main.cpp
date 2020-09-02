#include "facade.hpp"

int
main()
{
    
    std::boolalpha(std::cout);
    ListNode<int> *ptr;
    ptr->value = 10;
    ListNodeIterator iter(ptr);
    std::cout << *iter << '\n';
    return 0;
}
