#include <iostream>
#include <deque>

int main()
{
    std::deque<int> deq{1,3,5,6,7,8,9};
    for(auto &el : deq){
        std::cout << el << '\n';
    }

    std::cout << "deque size(): " << deq.size() << '\n';
    deq.push_front(9);
    std::cout << "deque push_front(): " << deq[0] << '\n';
    deq.push_back(123);
    /* because size() == deq.end() and for access to last element in container need substracting of size()-1 one value */
    std::cout << "deque push_back(): " << deq[deq.size()-1] << '\n'; 
    std::cout << *(deq.end()-1) << '\n';
    std::cout << "deque at(): " << deq.at(0) << '\n';
    std::cout << "deque front(): " << deq.front() << '\n';
    std::cout << "deque back(): " << deq.back() << '\n';
    deq.emplace(deq.cbegin()+3, 11);

    std::cout << "emplace in position for deque: "<< *(deq.cbegin()+3) << '\n';
    return 0;
}
