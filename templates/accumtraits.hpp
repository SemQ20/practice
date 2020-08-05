#ifndef ACCUMTRAITS_HPP
#define ACCUMTRAITS_HPP
#include <iostream>

struct BigInt{
    long long value;
    inline static unsigned long zero = 0;
    BigInt(long long val) : value(val){}
    const BigInt operator+=(BigInt const& i){
        return this->value = this->value + i.value;
    }
};

std::ostream& operator<<(std::ostream& os, BigInt& obj){
    return os<< obj.value;
}

template<typename T>
struct AccumulationTraits;

template<>
struct AccumulationTraits<char>
{
    using AccT = int;
    static constexpr AccT zero(){
        return 0;
    }
};

template<>
struct AccumulationTraits<short>
{
    using AccT = int;
    static constexpr AccT zero(){
        return 0;
    }
};

template<>
struct AccumulationTraits<int>{
    using AccT = long;
    static constexpr AccT zero(){
        return 0;
    }
};

template<>
struct AccumulationTraits<unsigned int>
{
    using AccT = long long;
    static constexpr AccT zero(){
        return 0;
    }
};

template<>
struct AccumulationTraits<float>
{
    using AccT = double;
    static constexpr AccT zero(){
        return 0;
    }
};

template<>
struct AccumulationTraits<BigInt>
{
    using AccT = BigInt;
    static AccT zero(){
        return BigInt{0};
    }
};

template<typename T>
auto accum(T* begin, T* end){
    using AccT = typename AccumulationTraits<T>::AccT;
    AccT total = AccumulationTraits<T>::zero();
    while(begin != end){
        total += *begin;
        ++begin;
    }
    return total;
}


#endif