#include <iostream>
#include <exception> // contain <cstdexcept>
#include <system_error> // also contain <cstdexcept>
#include <cstring> // for std::strerror
#include <cerrno>

class MyExc{
public:
    MyExc(const char* err_str, int line) : err_code(err_str) ,err_line(line){};
    [[noreturn]] const char* what() const noexcept{
        std::cout << err_code << err_line << '\n';
    };
    ~MyExc() noexcept {};
private:
    const char* err_code;
    int err_line;
};

int sum (int a, int b, int line){
    if (b == 0){
        throw(MyExc("Error: dividing by zero in line:",line));
    }    
    return a/b;
}

int main()
{

    try
    {
        sum(10,0, __LINE__);
    }
    catch(const MyExc& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const std::runtime_error &ex){
        std::cout << ex.what() << '\n';
    }
    return 0;
}
