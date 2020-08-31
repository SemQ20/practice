#ifndef NALGORITHSMS_HPP
#define NALGORITHSMS_HPP
#include <vector>
#include <array>
#include <utility>
#include <cmath>
#include <algorithm>

std::pair<std::vector<int>, int> sieveEratosphene(int number);
std::pair<std::vector<int>, int> sieveEratosphene_v1(int number);
bool check_isWholeNumber(int const& value);
int gcd(int a, int b);
std::pair<std::vector<int> , int> factorization(int number);
std::vector<int> fillVector_2_to_n(std::vector<int>& vector, int number);


constexpr int fib_binet(int i){
    constexpr auto sqrt_5 = std::sqrt(5);
    if(i == 0) return 0;
    if(i == 1) return 1;
    return static_cast<int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i))/(std::pow(2,i) * sqrt_5));
}

template<int N, std::size_t... Idx>
constexpr std::array<bool, N + 1> eratospheneSieve_impl(std::index_sequence<Idx...>) noexcept{
    std::array<bool, N + 1> primes{(Idx, true)...};
    primes[0] = primes[1] = false;
    for(std::size_t i = 2; i*i <= N; ++i){
        if(primes[i]){
            for(std::size_t j = i*i; j <= N; j += i){
                primes[j] = false;
            }
        }
    }
    return primes;
}

template<int N, typename Idx = std::make_index_sequence<N+1>>
constexpr std::array<bool, N + 1> eratospheneSieve() noexcept{
    return eratospheneSieve_impl<N>(Idx{});
}

#endif