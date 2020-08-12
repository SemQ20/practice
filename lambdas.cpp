#include <iostream>
#include <functional>

std::function<int(int,int)> rlambda(){
        return [](int x, int y){return x*y;};
    };

int main()
{
    
    return 0;
}
