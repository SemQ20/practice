#include <array>
#include <iostream>
#include <algorithm>

int main(){
    std::array<int,5> arr; // alternative for C-style stack located static arrays
    arr = {5,4,3,2,1};

    std::cout << "std::array<T>::operator[ ]:" << arr[0] << '\n';
    std::cout << "std::array<T>::at()" << arr.at(1) << '\n';
    std::cout << "std::array<T>::front()" << arr.front() << '\n';
    std::cout << "std::array<T>::back(): " << arr.back() << '\n';
    std::cout << "using std::get<>() for STL-version array: " << std::get<1>(arr) << '\n';
    //std::sort(arr.begin(),arr.end());
    std::cout << "array size: " << arr.size(); << '\n';

    return 0;
}