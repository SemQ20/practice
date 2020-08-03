#include <iostream>
#include <type_traits>
#include <vector>

template<typename T>
struct AccumulatorTraits;

template<>
struct AccumulatorTraits<char>{
    using AccT = int;
};

template<>
struct AccumulatorTraits<short>{
    using AccT = int;
};

template<>
struct AccumulatorTraits<int>{
    using AccT = long;
};

template<>
struct AccumulatorTraits<unsigned int>{
    using AccT = unsigned long;
};

template<>
struct AccumulatorTraits<float>{
    using AccT = double;
};

template<typename T>
auto accum(T const* beg, T const* end){
    using AccT = typename AccumulatorTraits<T>::AccT;
    AccT total{};
    while(beg != end){
        total += *beg;
        ++beg;
    }
    return total;
}

int 
main()
{
    int arr[] = {1,2,3,445,23,21};
    int size = sizeof(arr)/sizeof(*arr);
    auto sumV = accum(arr, arr + size);
    std::cout << size << '\n';
    std::cout << sumV << '\n';
    return 0;
}
