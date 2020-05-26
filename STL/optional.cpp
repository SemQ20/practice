#include <iostream>
#include <optional>
#include <any>
#include <string>
#include <utility>

std::optional<int> check(bool val){
    if(val){
        return 5;
    }
    return {};
}

int main()
{
    std::optional<std::string> oStr;
    std::optional<int> val1 = 5;
    std::optional<int> val2 = 10;

    oStr.emplace("Emplace");

    std::cout << "val2 = " << *val2 << '\n';
    /* return value or throw std::bad_optional_access */
    std::cout << oStr.value() << '\n';

    /* std::swap it works */
    std::swap(val1,val2);
    std::cout << "val1 = " << *val1 << '\n';
    std::cout << "val2 = " << *val2 << '\n';

    bool op = check(false).has_value();
    std::cout << std::boolalpha;
    std::cout << op << '\n';

    /* return value or your value */
    std::cout << "val1 = "<< val1.value_or(0) << '\n';
    std::cout << "val1 > val2? " << (val1 > val2) << '\n';
    std::cout << check(true).value() << '\n';

    val1.reset();
    std::cout << "Val1 empty? "<< (val1 == std::nullopt) << '\n';
    std::cout << "val1 = "<< val1.value_or(0) << '\n';

    return 0;
}
