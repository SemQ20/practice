// Example from Jason Turner
#include <string>
#include <algorithm>
#include <iostream>

struct C {
    static const std::string &magic_static(){
        static const std::string s = "bob";
        return s;
    }
    const std::string &s = magic_static();

    // maybe this is equal to &s or not?
    const std::string &magic_static_ref(){
        return s;
    }
};

int main(){
    C c;
    int total_size = 0;
    //assembly output optimization automaticaly
    for(uint64_t i = 0;  i < 100000000; ++i){
        total_size += c.s.size();
    }
    return total_size;
}