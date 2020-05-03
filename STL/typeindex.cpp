#include <typeindex>
#include <iostream>


int main()
{
    int i;
    /* wrapper for type_info for associative containers\
    */
    
    std::cout<< std::type_index(typeid(i)).name() <<"\n";
    return 0;
}
