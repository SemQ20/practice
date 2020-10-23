/*  You are given a DNA sequence: a string consisting of characters A, C, G, and T.
    Your task is to find the longest repetition in the sequence. 
    This is a maximum-length substring containing only one type of character.
Input:
    The only input line contains a string of n characters.
Output:
    Print one integer: the length of the longest repetition.
Constraints:
    1≤n≤10^6 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int 
main(){
    std::string s = "";
    uint64_t x = 1;
    uint64_t y = 1;
    std::cin >> s;
    for(uint64_t i = 1; i <= s.size(); ++i){
        if(s[i - 1] == s[i]){
            x++;
        }else{
            if(y > x){
                x = 1;
            }else{
                y = x;
                x = 1;
            }
        }
    }
    std::cout << y << '\n';
    return 0;
} 