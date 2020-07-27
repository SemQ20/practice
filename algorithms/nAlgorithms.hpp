#ifndef NALGORITHSMS_HPP
#define NALGORITHSMS_HPP
#include <vector>
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

#endif