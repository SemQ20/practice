#ifndef FACADE_HPP
#define FACADE_HPP

#include <utility>
#include <iterator>
#include <iostream>

template<typename Derived, typename Value, typename Category,
         typename Reference = Value&,
         typename Distance = std::ptrdiff_t>
class IteratorFacade{

    Derived& asDerived() {
        return static_cast<Derived&>(*this);
    }

    public:
        using value_type = typename std::remove_const_t<Value>;
        using reference = Reference;
        using pointer = Value*;
        using different_type = Distance;
        using iterator_category = Category;

        /* interface of input iterator */
    reference const operator*() {
        return asDerived().dereference();
    }

    pointer operator->() const {}

    Derived& operator++() {
        asDerived().increment();
        return asDerived();
    }

    Derived operator++(int) {
        Derived result(asDerived());
        asDerived().increment();
        return result;
    }

    friend bool operator==(IteratorFacade const& lhs,
                           IteratorFacade const& rhs){
        return lhs.asDerived().equals(rhs.asDerived());
    }

    /* interface of bidirectional iterator */
    Derived& operator--() {}
    Derived& operator--(int) {}

    /* interface of random access iterator */
    reference operator[](different_type n) const {
        
    }
    Derived& operator+=(different_type n) {}
    friend different_type operator-(IteratorFacade const& ihs,
                                    IteratorFacade const& rhs){

    }

    friend bool operator<(IteratorFacade const& ihs,
                                    IteratorFacade const& rhs){

    }

};


/* Example: class for uses CRTP for facade trought ListNodeIterator*/

template<typename T>
class ListNode {
    public:
        ListNode(T ivalue) : value(ivalue){}
        T value;
        ListNode<T>* next = nullptr;
        ~ListNode(){
            delete next;
        }
};

/* Example use:
    ListNode<int> *ptr;
    ptr->value = 10;
    ListNodeIterator iter(ptr);
    std::cout << *iter << '\n'; */
/* CRTP in action: */
template<typename T>
class ListNodeIterator 
      : public IteratorFacade<ListNodeIterator<T>, T, std::forward_iterator_tag>{

    /* for access of private section class ListNodeIterator */
    template<typename Derived, typename Value, typename Category,
             typename Reference, typename Distance>
    friend class IteratorFacade;

    ListNode<T>* current = nullptr;

    T& dereference(){
        return current->value;
    }
    
    void increment(){
        return current->next;
    }

    bool equals(ListNodeIterator const& other) const{
        return current == other.current;
    }

public:
    
    ListNodeIterator(ListNode<T>* current = nullptr) : current(current){}
};



#endif