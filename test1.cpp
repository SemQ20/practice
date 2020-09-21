#include <vector>
#include <iostream>

template<typename F>
void forUpTo(int n, F f){
    for(int i = 0; i <= n; i++){
        f(i);
    }
}

void printInt(int i){
    std::cout << i << '\n';
}

int 
main(){
    std::vector<int> values;
    forUpTo(5, [&values](int i){
        values.push_back(i);
    });

    forUpTo(5, printInt);
    return 0;
}