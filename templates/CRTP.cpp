#include <iostream>

/* interface */
/* pointer type for D is required */
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


int main()
{
    Impl_class scl1;
    Impl_class scl2;
    func_working_with_impl_class(scl1);
    func_working_with_impl_class(scl2);
    return 0;
}
