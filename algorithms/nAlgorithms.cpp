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

bool check_isWholeNumber(int const& value){
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

int gcd(int& a, int& b){
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

std::vector<int> fillVector_2_to_n(std::vector<int>& vector, int number){
    for(int i = 2; i <= number; i++){
        vector.push_back(i);
    }
    return vector;
}

/* measure fibonacci number */
constexpr int fib_binet(int i){

    #if __GNUC__ > 9
        constexpr const auto sqrt_5 = std::sqrt(5);
    #else
        const auto sqrt_5 = std::sqrt(5);
    #endif

    if(i == 0) return 0;
    if(i == 1) return 1;
    return static_cast<int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i))/(std::pow(2,i) * sqrt_5));
}

uint32 getWholePartOfNum(float number){
    std::string tmp = std::to_string(number);
    std::string result;
    uint32 ires;
    std::size_t index = 0;
    for(std::size_t i = 0; i != tmp.size(); ++i){
        if(index != 0){
            result += tmp[i];
        }
        if(tmp[i] == '.'){
            index = i;
        }
    }
    return ires = atoi(result.c_str());
}

uint32 hexToDecimal(const char* number){
    char* buf;
    unsigned int result = strtol(number, &buf, 16);
    return result;
}

std::string helperFunctionForHex(uint32 decimal){
    uint32 res = decimal - 10;
    std::string result = "";
    result = result + HEX_BUF[res];
    return result;
}

std::string decimalToHex(uint32 decimal){
    uint32 system = 16;
    uint32 tmp = decimal;
    uint32 mod = 0;
    std::string result;

    while(tmp >= system){
        mod = tmp % system;
        tmp = tmp / system;
        if(mod >= 10){
            result += helperFunctionForHex(mod);
        }else{
            result += std::to_string(mod);
        }
    }
    if(tmp >= 10){
            result += helperFunctionForHex(tmp);
        }else{
            result += std::to_string(tmp);
        }
    result += "x0";
    result = reverseString(result);
    return result;
}
