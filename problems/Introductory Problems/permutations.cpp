/*  A permutation of integers 1,2,…,n is called beautiful if there are no adjacent 
    elements whose difference is 1.
    Given n, construct a beautiful permutation if such a permutation exists.
Input:
    The only input line contains an integer n.
Output:
    Print a beautiful permutation of integers 1,2,…,n. 
    If there are several solutions, you may print any of them. 
    If there are no solutions, print "NO SOLUTION".
Constraints:
    1≤n≤10^6 
*/

#include <iostream>
#include <vector>
#include <algorithm>

int
main(){
    uint64_t i = 0;
    uint64_t x = 0;
    std::cin >> i;
    if(i == 1){
        std::cout << i << '\n';
    }else if (i == 2 || i == 3){
        std::cout << "NO SOLUTION" << '\n';   
    }else if (i > 3){
        std::vector<int> vi(i);
        std::generate(vi.begin(),vi.end(),[n = 1]() mutable {return n++;});
        std::stable_partition(vi.begin(), vi.end(), [](int x) { return x % 2 == 0; });
        for(const auto &c : vi){
            std::cout << c << '\n';
        }
    }

    return 0;
}