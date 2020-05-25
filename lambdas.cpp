#include <iostream>
#include <functional>

std::function<int(int,int)> rlambda(){
        return [](int x, int y){return x*y;};
    };

int main()
{
    int x_pos = 45;
    int y_pos = 0;

    auto z = [&]() mutable {
        return ++x_pos;
    };

    auto multp = rlambda();
    std::cout << multp(6,7) << '\n';

    y_pos = z();
    std::cout << y_pos << '\n';

    return 0;
}
