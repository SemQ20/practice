#include <iostream>
#include <set>
#include <string>
/* source: https://www.youtube.com/watch?v=dvLKY-oWqn0 */

struct MyData
{
    std::string key;
    std::string value;
};

struct Compare{
    bool operator()(const MyData &lhs, const MyData &rhs){
        return lhs.key < rhs.key;
    }
};


int main(){
    const auto lambda = [](const MyData &lhs, const MyData &rhs) {return lhs.key < rhs.key;};

    std::set<MyData, decltype(lambda)> myset{lambda}; // ???!!!
    myset.insert(MyData{"Bob"});
    myset.insert(MyData{"Nik"});
    myset.insert(MyData{"Jason"});
    myset.insert(MyData{"Deniel"});
    for(const auto & c : myset){
        std::cout << c.key << '\n';
    }
    return 0;
}