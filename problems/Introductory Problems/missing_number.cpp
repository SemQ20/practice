/* You are given all numbers between 1,2,…,n except one. 
   Your task is to find the missing number.
Input:
    The first input line contains an integer n.
    The second line contains n−1 numbers. 
    Each number is distinct and between 1 and n (inclusive).
Output:
    Print the missing number.
Constraints:
    2≤n≤2⋅10^5 
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
int main(){
    std::vector<uint64_t> ui64vec;
    uint64_t n = 0;
    uint64_t x = 0;
    uint64_t y = 1;
    uint64_t value = 0;
    uint64_t result = 0;
    std::cin >> n;
    while(x != n - 1){
        std::cin >> value;
        ui64vec.push_back(value);
        x++;
    }
    ui64vec.push_back(0);
    std::sort(ui64vec.begin(), ui64vec.end());
    for(std::size_t i = 1; i <= n; ++i){
        if(ui64vec[i] == i){
            ++y;
        }else{
            result = y;
        }
    }
    std::cout << result << '\n';
    return 0;
}