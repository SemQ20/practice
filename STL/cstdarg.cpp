#include <cstdarg>
#include <iostream>

int add_nums(int count, ...) 
{
    int result = 0;
    /* all args ... wrapped std::va_list */
    std::va_list args;

    /* transfer in va_start numbers of args */
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        /* use all args for algorithm */
        result += va_arg(args, int);
    }
    /* free memory allocated for args */
    va_end(args);
    return result;
}
 
int main() 
{
    
    std::cout << add_nums(4, 25, 25, 50, 50) << '\n';
}