#include <iostream>
#include <queue>

template<typename Container>
struct is_queue{
    using value_type = typename Container::value_type;
    using true_type = typename std::queue<value_type>;
    static const bool value = std::is_same_v<Container, true_type>;
}; 

template<typename Container, bool = is_queue<Container>::value>
struct Helper;

template<typename Container>
struct Helper<Container,true>
{
    static void print(Container& cont){
        while(!cont.empty()){
            std::cout << cont.front() << '\n';
            cont.pop();
        }
    }
};

template<typename Container>
struct Helper<Container,false>
{
    static void print(Container& cont){
        while(!cont.empty()){
            std::cout << cont.top() << '\n';
            cont.pop();
        }
    }
};

template<typename Cont>
void print_sequence_container(Cont& q){
    Helper<Cont>::print(q);
}


template<typename Container,
        typename = std::enable_if_t<is_queue<Container>::value>>
void print(Container& cont) noexcept {
    while(!cont.empty()){
        std::cout << cont.front() << '\n';
        cont.pop();
    }
}
template<typename T>
void print(std::priority_queue<T>& cont) noexcept {
    while(!cont.empty()){
        std::cout << cont.top() << '\n';
        cont.pop();
    }
}


int main()
{
    std::queue<int> q{{1,3,4,5,6,7,8}};
    std::priority_queue<int> q1;
    auto ilst = {1,3,4,5,6,7,8};
    for(auto const& i: ilst){
        q1.push(i);
    }

    print(q1);
    
    return 0;
}
