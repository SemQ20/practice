#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<std::pair<int, int>>> graph_mtx;
    graph_mtx.push_back({{1,5}});
    std::cout << graph_mtx[0][0].first << '\n';
    std::cout << graph_mtx[0][0].second << '\n';
    return 0;
}
