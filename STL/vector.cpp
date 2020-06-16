#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    /* uniform initialization */
    std::vector<int> vec{1,3,4,5,6,7,8,9};
    
    vec.assign({1,3,4,5,6,7,8,9}); // initializer list
    

    return 0;
}
