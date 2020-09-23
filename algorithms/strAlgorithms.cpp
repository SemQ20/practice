#include "strAlgorithms.hpp"

bool has_isPalindrom(std::string str){
    std::string cmp = convStringtoLowerAndDelPunct(str);
    std::string rstr = reverseString(cmp);
    int scmp = cmp.size();
    int srstr = rstr.size(); 
    if(cmp == rstr){
        return true;
    }else{
        return false;
    }
}

std::string convStringtoLowerAndDelPunct(std::string str){
    std::string str1;
    const char* cmp = str.c_str();
    for(int i = 0; i <= str.size()-1;){
        if(isalpha(cmp[i])){
            str1 += tolower(cmp[i]);
            i++;
        }else if(isdigit(cmp[i])){
            str1 += tolower(cmp[i]);
            i++;
        }
        else{
            i++;
        }
    }
    return str1;
}

std::string reverseString(std::string& str){
    std::string tmp = convStringtoLowerAndDelPunct(str);
    std::string rstr;
    for(auto it = tmp.rbegin(); it <= tmp.rend()-1; it++){
        rstr += *it;
    }
    return rstr;
}