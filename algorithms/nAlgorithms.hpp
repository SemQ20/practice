#ifndef NALGORITHSMS_HPP
#define NALGORITHSMS_HPP
#include <vector>
#include <utility>
#include <cmath>

std::pair<std::vector<int>, int> sieveEratosphene(int number);
bool check_isWholeNumber(unsigned int value);
int gcd(int a, int b);
std::pair<std::vector<int> , int> factorization(int number);
#endif