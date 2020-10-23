#include <iostream>
#include <cmath>
#include "algorithms/nAlgorithms.hpp"
#include <set>


int 
main(){
    std::multiset<std::string> mmit;
    /* mmit.insert(1);
    mmit.insert(2);
    mmit.insert(1);
    mmit.insert(3);
    mmit.insert(4);
    mmit.insert(1); */
    std::string s = "";
    while(std::cin >> s){
        mmit.insert(s);
    }

    for(const auto &c : mmit){
        std::cout << c << '\n';
    }

    return 0;
}
