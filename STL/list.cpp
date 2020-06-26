#include <list>
#include <forward_list>
#include <iostream>
#include <algorithm>

int main(){
    std::initializer_list<int> il{1,3,5,9,0,12,45,7,99};
    std::list<int> lst{il};
    std::list<int> lst1{lst};

    for(const auto& el : lst){
        std::cout << el << '\n';
    }

    std::cout << "list size: " << lst.size() << '\n';
    std::cout << "front(): " << lst.front() << '\n';
    std::cout << "back(): " << lst.back() << '\n';
    std::list<int>::iterator list_iter = (lst.insert(std::find(lst.begin(),lst.end(),5),6));

    std::cout << "insert(): " << *(list_iter) << '\n';
    lst.push_front(678);
    std::cout << "after push front: " << lst.front() << '\n';
    lst.push_back(78);
    std::cout << "after push back: " << lst.back() << '\n';
    lst.pop_back();
    lst.pop_front();
    lst.merge(lst1);
    lst.unique();
    
    for(const auto& el : lst){
        std::cout << el << '\n';
    }

	return 0;
}
