#include <iostream>
#include <utility>
#include <string>
#include <type_traits>

template<typename T>
using EnableIfString = std::enable_if_t<
                       std::is_convertible_v<T, std::string>>;
class Person{

private:
    std::string name;
public:
    template<typename STR, typename = EnableIfString<STR>>
    explicit Person(STR && n) : name(std::forward<STR>(n)){
        std::cout << "Template Constructor for " << name << '\n';
    }

    Person(Person const& p) : name(p.name){
        std::cout << "Copy-constructor for " << name << '\n';
    }

    Person(Person&& p) : name(std::move(p.name)){
        std::cout << "Move-constructor for " << name << '\n';
    }
    void print_mes(){
        std::cout << name << '\n';
        std::cout << "size string: " << name.size() << '\n';
    }
};

int main()
{   
    std::string somestr = "sdKSo";
    Person p2(somestr);
    Person p1(std::move(p2));
    p1.print_mes();
    return 0;
}
