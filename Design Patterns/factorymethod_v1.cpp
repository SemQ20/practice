#include <iostream>
#include <memory>
#include <string>
#include <vector>

class IClass{
public:
    ~IClass() {};
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
    ~CreatorObjects() {};
    static std::shared_ptr<IClass> createObject();
    
};

class CreatorClass_1 : CreatorObjects{
public:
    static std::shared_ptr<IClass> createObject() {
        return std::shared_ptr<Class_1>(new Class_1);
    }
};

class CreatorClass_2 : CreatorObjects{
public:
    static std::shared_ptr<IClass> createObject() {
        return std::shared_ptr<Class_2>(new Class_2);
    }
};

int main() {
    std::shared_ptr<IClass> cls = CreatorClass_2::createObject();
    cls->printName();
    return 0;
}