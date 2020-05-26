#include <iostream>
#include <any>
#include "../t_class.hpp"
#include <string>
#include <utility>

/* std::any maybe need for use in controversual situations
 when necessary used void* type or in situation when type undifined*/

int main()
{
    TClass tclass;
    tclass.rchar = "Class method";
    /* typically initialization */
    std::any a = 10;
    std::cout << std::boolalpha;
    std::cout << std::any_cast<int>(a) << '\n';
    std::cout << a.type().name() << '\n';
    std::cout << a.has_value() << '\n';

    /* any erase memory before create new object */
    a = std::string("Hello");
    std::cout << std::any_cast<std::string>(a) << '\n';
    std::cout << a.type().name() << '\n';

    /* clear variable */
    a.reset();
    std::cout << a.has_value() << '\n';

    /* in place */
    std::any b{5.3f};
    std::cout << std::any_cast<float>(b) << '\n';

    /* feature std::any 
    emplace()*/
    a.emplace<const char*>("Const char*");
    std::cout << std::any_cast<const char*>(a) << '\n';

    std::swap(a,b);
    std::cout << "a = "<< std::any_cast<float>(a) << '\n';
    std::cout << "b = "<< std::any_cast<const char*>(b) << '\n';

    /* Uses class method */
    std::any_cast<TClass>(tclass).print_mb(tclass.rchar);

    /* make_any */
    std::any btest = std::make_any<float>(5.5f);
    std::cout << std::any_cast<float>(btest) << '\n';
    return 0;
}
