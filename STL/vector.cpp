#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    /* uniform initialization */
    std::vector<int> vec{1,3,4,5,6,7,8,9};
    std::vector<float> fvec; // alternative
    fvec.reserve(2); // reserve for 2 elements
    fvec = {3.1f,5.2f};

    vec.assign({1,3,4,5,6,7,8,9}); // initializer list

    /* alternative for operator[] */
    std::cout << "method at() result: " << vec.at(0) << '\n';
    std::cout << "operator[] result: " << fvec[0] << '\n';
    /* return first element in container */
    std::cout << "method front() result: " << vec.front() << '\n';
    /* return last element in container */
    std::cout << "method back() result: " << vec.back() << '\n';
    /* return pointer to range of data container */
    std::cout << "method data() result: " << vec.data() << '\n';
    std::cout << "check data(): " << *vec.data() << '\n';
    /* return number elements in vector */
    std::cout << "vec size(): " << vec.size() << '\n';
    /* return allocate storage for this vector */
    std::cout << "fvec capacity(): " << fvec.capacity() << '\n';
    /* free unused memory */
    fvec.shrink_to_fit();
    fvec.clear();
    fvec.insert(fvec.begin(), 3.5f);
    std::cout << "after insert(): " << fvec[0] << '\n';
    fvec.insert(fvec.begin(),2, 5.2f);
    /* insert two 5.2f values in fvec.begin()*/
    for(auto &el : fvec){
        std::cout << el << '\n';
    }
    /* insert element in position */
    fvec.emplace(fvec.cbegin()+1, 3.6f);
    std::cout << "emplace(): "<< '\n';
    for(auto &el : fvec){
        std::cout << el << '\n';
    }
    fvec.emplace_back(4.7f);
    std::cout << "emplace_back(): "<< '\n';
    for(auto &el : fvec){
        std::cout << el << '\n';
    }
    std::cout << "erase(): "<< '\n';
    fvec.erase(fvec.begin()+2);
    for(auto &el : fvec){
        std::cout << el << '\n';
    }
    std::cout << "after resize(): "<< '\n';
    fvec.resize(5);
    for(auto &el : fvec){
        std::cout << el << '\n';
    }
    return 0;
}
