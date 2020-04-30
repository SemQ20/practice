#include <iostream>
#include <memory>
#include <string>
#include <vector>

class IClass{
public:
    virtual ~IClass() {};
    virtual void printName() = 0;
};

class Class_1 : public IClass{
public:
    void printName(){
        std::cout<< "Hello from Class_1\n";
    }
};

class Class_2 : public IClass{
public:
    void printName(){
        std::cout<< "Hello from Class_2\n";
    }
};

class CreatorObjects{
public:
    virtual ~CreatorObjects() {};
    virtual IClass * createObject() = 0;
    
};

class CreatorClass_1 : CreatorObjects{
public:
    IClass* createObject() {
        return new Class_1();
    }
};

class CreatorClass_2 : CreatorObjects{
public:
    IClass* createObject() {
        return new Class_2();
    }
};


int main() {
    IClass* cls;
    
    CreatorClass_2 *class_1 = new CreatorClass_2;
    cls = class_1->createObject();
    cls->printName();
    return 0;
}