#include <iostream>
#include <cmath>
#include "algorithms/nAlgorithms.hpp"

void search(std::vector<int>& vec, int k, int n){
    if(k == n + 1){
    }else{
        vec.push_back(k);
        search(vec,k + 1, n);
        vec.pop_back();
        search(vec,k + 1, n);
    }
}

int 
main(){
    std::vector<uint64_t> ui64vec{2,3,1,4,5};
    uint64_t n = 6;
    uint64_t x = 1;
    //uint64_t value = 0;
    uint64_t result = 0;
    
    ui64vec.push_back(0);
    std::sort(ui64vec.begin(), ui64vec.end());
    for(std::size_t i = 1; i <= n; ++i){
        if(ui64vec[i] == i){
            ++x;
        }else{
            result = x;
        }
    }
    std::cout << result << '\n';
    return 0;
}
