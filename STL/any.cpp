#include <iostream>
#include <any>

int main()
{
    std::any a = 10;
    std::cout << std::any_cast<int>(a) << '\n';
    std::cout << a.type().name() << '\n';
    std::cout << std::boolalpha;
    std::cout << a.has_value() << '\n';
    return 0;
}
