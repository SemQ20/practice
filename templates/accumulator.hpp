#ifndef ACCUMULATOR_HPP
#define ACCUMULATOR_HPP
#include <iostream>
#include "policy.hpp"

template<typename T>
struct AccumulatorTraits;

class BigInt{
    public:
    long long value;
    BigInt(long long val) : value(val){}
    const BigInt operator+=(BigInt const& i){
        return this->value = this->value + i.value;
    }
    const BigInt operator*=(BigInt const& i){
        return this->value = this->value * i.value;
    } 
};

std::ostream& operator<<(std::ostream& os, BigInt& obj){
    return os<< obj.value;
}

template<>
struct AccumulatorTraits<char>{
    using AccT = int;
    inline static int zero = 0;
};

template<>
struct AccumulatorTraits<short>{
    using AccT = int;
    inline static int zero = 0;
};

template<>
struct AccumulatorTraits<int>{
    using AccT = long;
    inline static long zero = 0;
};

template<>
struct AccumulatorTraits<unsigned int>{
    using AccT = unsigned long;
    inline static unsigned long zero = 0;
};

template<>
struct AccumulatorTraits<float>{
    using AccT = double;
    inline static double zero = 0.0;
};

template<>
struct AccumulatorTraits<BigInt>
{
    using AccT = BigInt;
    inline static BigInt const zero = BigInt{0}; /* only C++17 */
    inline static BigInt const one = BigInt{1};
};

template<typename T,
         typename Policy = SubPolicy,
         typename Traits = AccumulatorTraits<T>>
auto accum(T const* beg, T const* end){
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero;
    while(beg != end){
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

template<typename T,
         template<typename, typename> class Policy = SubPolicy1,
         typename Traits = AccumulatorTraits<T>>
auto accum1(T const* begin, T const* end){
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero;
    while(begin != end){
        Policy<AccT, T>::accumulate(total, *begin);
        ++begin;
    }
    return total;
}

#endif