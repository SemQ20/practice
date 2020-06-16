#include "nAlgorithms.hpp"

std::pair<std::vector<int>, int> sieveEratosphene(int number){
    std::vector<int> wholeNumbers;
    unsigned int countNumbers{0};
    if(number == 1){return std::make_pair(wholeNumbers,countNumbers);}
    for(int i = 2; i <= number; ++i){
        if(check_isWholeNumber(i)){
            wholeNumbers.push_back(i);
            ++countNumbers;
        }
    }
    return std::make_pair(wholeNumbers,countNumbers);
}

std::pair<std::vector<int>, int> sieveEratosphene_v1(int number){
    std::vector<int>::iterator vit;
    std::vector<int> wholeNumbers; // initialization and fill vector in one line - bad idea !!!
    wholeNumbers = fillVector_2_to_n(wholeNumbers,number);
    unsigned int countNumbers{1}; // 2 - start index and 2 in vector
    int m = 0;
    for(auto it = wholeNumbers.begin(); it != wholeNumbers.end()-1;){ // because end()++ == trash

        int fval = ((*it)*(*it)) + m; // number for erase == current number^2 in array and plus offset

        if(fval <= number){ 
        if(vit = std::find(wholeNumbers.begin(),wholeNumbers.end(),fval);vit != wholeNumbers.end()){
            wholeNumbers.erase(vit);
        }
        /* in original algorithm it's iteraror for this degree: for degree: 2 need to erase fval = 2^2 = 4, m += degree(2)
        * fval + m = 6, m(2) += degree(2) == 4, fval + m = 8 e.t.c.*/
            m += (*it);
        }else{
                ++it;
                m = 0;
                ++countNumbers;
        }
    }
    return std::make_pair(wholeNumbers,countNumbers);
}

bool check_isWholeNumber(int value){
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

std::vector<int> fillVector_2_to_n(std::vector<int> vector, int number){
    for(int i = 2; i <= number; i++){
        vector.push_back(i);
    }
    return vector;
}
