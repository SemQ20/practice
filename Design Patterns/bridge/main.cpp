#include "bridge.hpp"

void
forUpToInt(int n, FunctionPtr<void(int)> f){
    for(int i = 0; i != n; ++i){
        f(i);
    }
}

void
printInt(int i){
    std::cout << i << '\n';
}

int
main(){
    forUpToInt(5, printInt);
    return 0;
}