#include "nAlgorithms.hpp"

std::pair<std::vector<int>, int> sieveEratosphene(int number){
    std::vector<int> wholeNumbers;
    unsigned int countNumbers;
    if(number == 1){return std::make_pair(wholeNumbers,countNumbers);}
    for(int i = 2; i <= number; ++i){
        if(check_isWholeNumber(i)){
            wholeNumbers.push_back(i);
            ++countNumbers;
        }
    }
    return std::make_pair(wholeNumbers,countNumbers);
}

bool check_isWholeNumber(unsigned int value){
    if(value == 1){
        return false;
    }
    if(value == 2 || value == 3){
        return true;
    }
    for(int i = 2;i != value; i++){
        if(value%i == 0){
            return false;
        } 
        /* if number is divided by i and remainder is 1 - it is not whole number, then
        if number divided by i and remainder is 1 AND result of divison number by i is 1 - it is whole number */
        if(value%i == 1 && value/i == 1){ 
            return true;
        }
    }
    return true;
}

int gcd(int a, int b){
    int c = 0;
    int cmp = 0;
    if(a%b == 0){
        return b;
    }else{
        while(a%b!=0){
            c = a%b;
            a = b;
            b = c;
            cmp = b;
        }
    }
    return cmp;
}

std::pair<std::vector<int> , int> factorization(int number){
    std::vector<int> multipliers;
    uint mcount = 0; // count multiplers
    uint y = 0;
    //uint tmp = number;

    if(check_isWholeNumber(number)){
        multipliers.push_back(number);
        ++mcount;
        return std::make_pair(multipliers,mcount);
    }

    for(int i = 2; i <= number;i++){
        if(number%i == 0){
           y = number/i;
           if(check_isWholeNumber(i)){
               multipliers.push_back(i);
               ++mcount;
           }
           if(check_isWholeNumber(y) || y == 1){
               multipliers.push_back(y);
               ++mcount;
               return std::make_pair(multipliers,mcount);
           }else{
                number = y;
                y = 0;
                i = 2;
           }
        }
    }
    return std::make_pair(multipliers,mcount);
}
