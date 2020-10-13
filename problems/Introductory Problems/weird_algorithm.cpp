/*  Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
    3→10→5→16→8→4→2→1
Your task is to simulate the execution of the algorithm for a given value of n.
Input:
    The only input line contains an integer n.
Output:
    Print a line that contains all values of n during the algorithm.
Constraints:
    1≤n≤10^6
*/

#include <iostream>

bool is_even_number(uint64_t value){
    return ((value % 2 == 0)? true : false); 
}
 
void f(uint64_t& value){
    std::cout << value << " ";
    while(value != 1){
        if(is_even_number(value)){
            value /= 2;
            std::cout << value << " ";
        }else{
            value = (value * 3) + 1;
            std::cout << value << " ";
        }
    }
}
 
int main(){
    uint64_t value;
    std::cin >> value;
    f(value);
    return 0;
}