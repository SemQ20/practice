#ifndef STRALGORITHMS_HPP
#define STRALGORITHMS_HPP
#include <string>
#include <cctype>

bool        has_isPalindrom             (std::string str);
std::string convStringtoLowerAndDelPunct(std::string str);
std::string reverseString               (std::string& str);

#endif