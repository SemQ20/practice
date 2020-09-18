#include "mixins_v2.hpp"
#include <memory>

int
main()
{
    
    std::boolalpha(std::cout);
    std::unique_ptr<Base<NotVirtual>> p1(new Derived<NotVirtual>);
    p1.get()->foo();
    std::unique_ptr<Base<Virtual>> p2(new Derived<Virtual>);
    p2.get()->foo();
    
    return 0;
}
