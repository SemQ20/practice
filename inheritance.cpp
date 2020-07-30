#include <iostream>
#include <memory>

class Base{
public:
    virtual ~Base() = default;
    Base() = default;
    Base(const Base&) = default;
    Base& operator=(const Base&) = default;
    Base(Base&&) = default;
    Base& operator=(Base&&) = default;

    virtual void do_anything() = 0;
};

class Derived : public Base {
public:
    void do_anything() override{
        std::cout << "Hello from derived class" << '\n';
    }
};

void print_base(Base *p){
    p->do_anything();
}

struct Int{
    Int(std::string &t_s) : ival(std::atoi(t_s.c_str())){}
    int val() const {
        return ival;
    }
    int ival;
};

int main()
{
    Derived dr;
    auto ptr = std::make_shared<Derived>();
    print_base(ptr.get());
    return 0;
}
