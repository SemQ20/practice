/*  You are given an array of n integers. 
    You want to modify the array so that it is increasing, i.e., 
    every element is at least as large as the previous element.
    On each turn, you may increase the value of any element by one. 
    What is the minimum number of turns required?
Input:
    The first input line contains an integer n: the size of the array.
    Then, the second line contains n integers x1,x2,…,xn: the contents of the array.
Output:
    Print the minimum number of turns.
Constraints:
    1≤n≤2⋅10^5
    1≤xi≤10^9 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int 
main(){
    std::vector<int> vi;
    uint64_t count = 0;
    uint64_t value = 0;
    uint64_t n = 0;
    uint64_t x = 0;
    std::cin >> n;
    while(x != n){
        std::cin >> value;
        vi.push_back(value);
        x++;
    }
    for(uint64_t i = 0; i < vi.size() - 1;){
        if(vi[i] > vi[i + 1]){
            while(vi[i + 1] != vi[i]){
                vi[i + 1] = vi[i + 1] + 1;
                count++;
            }
            i++;
        }else{
            i++;
        }
    }
    std::cout << count << '\n';
    return 0;
} 