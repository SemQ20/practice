#ifndef CRTP_HPP
#define CRTP_HPP

#include <iostream>

/* interface */
/* pointer type for D is required */
/*  Use:
    Impl_class scl1;
    Impl_class scl2;
    func_working_with_impl_class(scl1);
    func_working_with_impl_class(scl2); */

template<typename D>
struct Base{
    void work(){static_cast<D*>(this)->work_impl();}
    void prepare(){static_cast<D*>(this)->prepare_impl();}
    int ivalue = static_cast<D*>(this) -> ival;
};

/* class implementation */
struct Impl_class : public Base<Impl_class>{
    void work_impl();
    void prepare_impl();
    int  ival = 102;
};

/* function for working */
template<typename WClass>
void func_working_with_impl_class(WClass wclass){
    wclass.work();
    wclass.prepare();
}

void Impl_class::prepare_impl(){
    std::cout << "Prepare to work " << '\n';
}

void Impl_class::work_impl(){
    std::cout << "Working " << '\n';
}


/* Use:
    template<typename CharT>
    class MyString : public ObjectCounter<MyString<CharT>>{};

    MyString<char> s1, s2;
    MyString<wchar_t> ws;
    std::cout << "Nubers of MyString<char>: " << MyString<char>::live() << '\n';
    std::cout << "Nubers of MyString<wchar_t>: " << ws.live() << '\n'; */

template<typename CountedType>
class ObjectCounter{
    /* before C++17
       need implementation this value after difinition behind the class:

       template<typename CountedType>
       class ObjectCounter{
           static std::size_t count;
       };

       template<typename CountedType>
       std::size_t ObjectCounter<CountedType>::count = 0;  */

    inline static std::size_t count = 0;
protected:
    ObjectCounter(){
        ++count;
    }

    ObjectCounter(ObjectCounter<CountedType> const&){
        ++count;
    }

    ObjectCounter(ObjectCounter<CountedType>&&){
        ++count;
    }

    ~ObjectCounter(){
        --count;
    }
public:
    static std::size_t live(){
        return count;
    }

};


/* Use for example:
    Compare c1(10), c2(10);
    if(c1 != c2){
        std::cout << "c1 != c2" << '\n';
    }else{
        std::cout << "c1 == c2" << '\n';
    } */
    
template<typename Derived>
class EqualityComparable{
    public:
        friend bool operator!=(Derived const& x1, Derived const& x2){
            return !(x1 == x2);
        }
};

class Compare : EqualityComparable<Compare>{
    int value = 0;
    public:

        Compare(int x) : value(x){}

        friend bool operator==(Compare const& C1, Compare const& C2){
            if(C1.value == C2.value){
                return true;
            }else{
                return false;
            }
        }
};

#endif