#ifndef BRIDGE_HPP
#define BRIDE_HPP

#include <iostream>

/* interface */
template<typename R, typename... Args>
class IFunctorBridge{
    public:
        virtual ~IFunctorBridge(){}
        virtual IFunctorBridge* clone() const = 0;
        virtual R invoke(Args... args) const = 0;
};

template<typename Signature>
class FunctionPtr;

template<typename R, typename... Args>
class FunctionPtr<R(Args...)>{
    IFunctorBridge<R, Args...>* bridge;
    public:
        FunctionPtr() : bridge(nullptr) {}
        FunctionPtr(FunctionPtr const& other){}
        FunctionPtr(FunctionPtr& other) :
            FunctionPtr(static_cast<FunctionPtr const&>(other)){}
        FunctionPtr(FunctionPtr&& other) : bridge(other.bridge){
            other.bridge = nullptr;
        }

        template<typename T>
        FunctionPtr(T&& f);

        friend void swap(FunctionPtr&& fp1, FunctionPtr&& fp2){
            std::swap(fp1.bridge, fp2.bridge);
        }

        FunctionPtr& operator=(FunctionPtr const& other){
            FunctionPtr tmp(other);
            swap(*this, tmp);
            return *this;
        }

        FunctionPtr& operator=(FunctionPtr&& other){
            delete bridge;
            bridge = other.bridge;
            other.bridge = nullptr;
            return *this;
        }

        template<typename F>
        FunctionPtr& operator=(F&& f){
            FunctionPtr tmp(std::forward<F>(f));
            swap(*this, tmp);
            return *this;
        }

        ~FunctionPtr(){
            delete bridge;
        }

        explicit operator bool() const{
            return bridge == nullptr;
        }

        R operator()(Args... args) const;
};


template<typename R, typename... Args>
FunctionPtr<R(Args...)>::FunctionPtr(FunctionPtr const& other) : bridge(nullptr){
    if(other.bridge){
        bridge = other.bridge->clone();
    }
}

template<typename R, typename... Args>
R FunctionPtr<R(Args...)>::operator()(Args... args) const {
    return bridge->invoke(std::forward<Args>(args)...);
}

#endif