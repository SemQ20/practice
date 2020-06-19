#include <iostream>
#include <deque>
#include <queue>

template<class T>
struct Test{
    typedef void(T::*P)(void);

    template<class U, P = &U::top>
    struct True{char dummy[2];};

    typedef char False;

    static False detect(...);

    template<class U>
    static True<U> detect(U*);

    static const bool exists = (sizeof(False) != sizeof(detect(static_cast<T*>(0))));
};

template<class T, bool check = Test<T>::exists>
struct Print{};

template<class T>
struct Print<T,true>{
    static void print_queue(const T& cont){
        while(!cont.empty()){
            std::cout << cont.top() << '\n';
            cont.pop();
        }
    }
};

template<class T>
struct Print<T,false>{
    static void print_queue(const T& cont){
        while(!cont.empty()){
            std::cout << cont.front() << '\n';
            cont.pop();
        }
    }
};

int main()
{
    std::deque<int> deq{1,3,5,6,7,8,9};

    for(auto &el : deq){
        std::cout << el << '\n';
    }

    std::cout << "deque size(): " << deq.size() << '\n';
    deq.push_front(9);
    std::cout << "deque push_front(): " << deq[0] << '\n';
    deq.push_back(123);
    /* because size() == deq.end() and for access to last element in container need substracting of size()-1 one value */
    std::cout << "deque push_back(): " << deq[deq.size()-1] << '\n'; 
    std::cout << *(deq.end()-1) << '\n';
    std::cout << "deque at(): " << deq.at(0) << '\n';
    std::cout << "deque front(): " << deq.front() << '\n';
    std::cout << "deque back(): " << deq.back() << '\n';
    deq.emplace(deq.cbegin()+3, 11);
    std::cout << "emplace in position for deque: "<< *(deq.cbegin()+3) << '\n';

    /* queue */
    std::queue<int> q;
    auto lst = {5,1,3,4,0,7};
    auto flst = {1.1f, 5.3f, 4.3f, 5.4f, 3.6f};
    for(auto &n : lst){
        q.push(n);
    }
    /* insert element in end */
    q.emplace(10);

    /* while(!q.empty()){
        std::cout << q.front() << '\n';
        std::cout << "queue size: "<< q.size() << '\n';
        q.pop();
    } */

    print_queue(q);
    std::cout << '\n';

    /* priority_queue */
    std::priority_queue<float> pq;
    /* queue with custom priority: */
    std::priority_queue<float, std::vector<float> , std::greater<float>> fpq;
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
    for(auto &n : flst){
        pq.push(n);
    }
    std::cout << "priority_queue:" << '\n';
    print_queue(pq);

    for(auto &n : flst){
        fpq.push(n);
    }
    print_queue(fpq);

    return 0;
}
