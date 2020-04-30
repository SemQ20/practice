
/* signals in c++ 
    no trows noexceptions
*/
#include <signal.h> // include signals
#include <iostream>
#include <functional> // functions ptrs

sig_atomic_t signaled;

void changeSignal(int some){ //handler for recieved signal current stage some == 2
    signaled = 1;
}

int main() {
    std::function<void(int)>  funct;
    funct = signal(SIGINT, changeSignal);
    raise(SIGINT); //send signal <= SIGINT to changeSignal
    std::cout<<signaled<< "\n";
    return 0;
}