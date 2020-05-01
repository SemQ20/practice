#include <csetjmp>
#include <iostream>

jmp_buf jumps;

int main() {
    int val = setjmp(jumps);
    std::cout<< val << "\n";
    /* like try cath in C++ */
    if(!val) longjmp(jumps, 1);
    return 0;
}