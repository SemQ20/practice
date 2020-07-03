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

#endif