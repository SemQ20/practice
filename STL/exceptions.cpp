#include <iostream>
/* STL Exceptions:
Contain more exceptions. All exceptions inherited of class exception.
Exceptions classes:
    * logic_error - bad logic,
    * ivalid_argument - bad argument,
    * domain_error - if mathematical function not defined for this argument(s),
    * length_error - out of range this object,
    * out_of_range - out of the border range,
    * future_error - failed to execute function in asynchronous mode,
    * runtime_error - throw if going on run time errors,
    * overflow_error - lose precision in measure values floating-point type(value too big),
    * underflow_error - also overflow_errror, but value is too small,
    * system_error - throw if going on run time errors,
    * bad_typeid - bad type id,
    * bad_optional_access - if std::optional::value dont have a value,
    * regex_error - errors of regular expressions,
    * filesystem_error - errors of filesystem manipulations,
    * bad_any_cast - if std::any_cast can not be used
    * bad_weak_ptr - if intelligent pointer indicate of free memory location,
    * bad_function_call - if object of std::function is not defined,
    * bad_alloc - if failed to access memory with operator new,
    * bad_array_new_length - if array size too big, if array size negative (for dynamicaly arrays),
    * bad_exception - this bad exception.
 */
#include <exception> // contain <cstdexcept>
#include <system_error> // also contain <cstdexcept>
#include <cstring> // for std::strerror
/* <cerrno> contain errno macro implementation, which 
 accepts in parameter once of values(macroses) like 
 E2BIG - argument too big,
 EACCES - permission denied 
 e. t. c.*/
#include <cerrno> // macro implementation for system errors
#include <cmath> // for math functions

/* User defined exception class, 
maybe need public inherited of STL exceptions */
class MyExc{
public:
    MyExc(const char* err_str, int line) : err_code(err_str), err_line(line){};
    [[noreturn]] const char* what() const noexcept{
        std::cout << err_code << ", "<< err_line << '\n';
    };
    ~MyExc() noexcept {};
private:
    const char* err_code;
    int err_line;
};

int sum (int a, int b, int line){
    if (b == 0){
        throw(MyExc("Error: dividing by zero ",line));
    }    
    return a/b;
}

int main()
{
    double notAnum = std::log(-1.0);
    if(errno = EDOM){ /* EDOM - Mathematics argument out of domain of function (macro define) */
        std::cout << "log(-1) failed: " << std::strerror(errno) << '\n';
    }
    
    try
    {
        sum(10,0, __LINE__);
    }
    catch(const MyExc& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const std::runtime_error &e){
        std::cout << e.what() << '\n';
    }
    return 0;
}
