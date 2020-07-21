#include <iostream>

int main()
{
    void *b;
    void *tmp;
    int offset = 1;
    int ilist1 = {5};
    int ilist3 = 123;
    int ilist4 = 512;
    b = &ilist1;
    tmp = *(&b + 1);
    tmp = &ilist3;

    auto q = *static_cast<decltype(ilist1)*>(b);
    auto q1 = *static_cast<decltype(ilist3)*>(tmp);
    std::cout << q << '\n';
    std::cout << q1 << '\n';
    return 0;
}
