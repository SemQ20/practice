#include <csetjmp>
#include <iostream>

jmp_buf jumps;

int main() {
    int val = setjmp(jumps);
    std::cout<< val << "\n";
    /* like try cath in C++ */
    int some_variable = 5;
    if(!val) longjmp(jumps, some_variable); // jump to line 7 and set val == some_variable
    return 0;
}