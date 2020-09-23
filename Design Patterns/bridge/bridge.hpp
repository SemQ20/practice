#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <iostream>
#include "isequalitycomparable.hpp"

/* interface */
template<typename R, typename... Args>
class IFunctorBridge{
    public:
        virtual ~IFunctorBridge(){}
        virtual IFunctorBridge* clone() const = 0;
        virtual R invoke(Args... args) const = 0;
        virtual bool equals(IFunctorBridge const* fb) const = 0;
};

/* primary template class */
template<typename Signature>
class FunctionPtr;

template<typename Functor, typename R, typename... Args>
class SpecificFunctorBridge : public IFunctorBridge<R, Args...>{
    Functor functor;
    public:
        template<typename FunctorFwd>
        SpecificFunctorBridge(FunctorFwd&& functor) :
            functor(std::forward<FunctorFwd>(functor)){}

        virtual SpecificFunctorBridge* clone() const override {
            return new SpecificFunctorBridge(functor);
        }

        virtual R invoke(Args... args) const override {
            return functor(std::forward<Args>(args)...);
        }

        virtual bool equals(IFunctorBridge<R, Args...> const* fb) const override{
            if(auto specFb = dynamic_cast<SpecificFunctorBridge const*>(fb)){
                return TryEquals<Functor>::equals(functor, specFb->functor);
            }
            return false;
        }
};

/* partional specialization */
template<typename R, typename... Args>
class FunctionPtr<R(Args...)>{
    IFunctorBridge<R, Args...>* bridge;
    public:
        FunctionPtr() : bridge(nullptr) {}
        FunctionPtr(FunctionPtr const& other);
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

        friend bool
        operator==(FunctionPtr const& f1, FunctionPtr const& f2){
            if(!f1 || !f2){
                return !f1 && !f2;
            }
            return f1.bridge->equals(f2.bridge);
        }

        friend bool
        operator!=(FunctionPtr const& f1, FunctionPtr const& f2){
            return !(f1 == f2);
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

template<typename R, typename... Args>
template<typename F>
FunctionPtr<R(Args...)>::FunctionPtr(F&& f)
    : bridge(nullptr){
        using Functor = std::decay_t<F>;
        using Bridge = SpecificFunctorBridge<Functor, R, Args...>;
        bridge = new Bridge(std::forward<F>(f));
}



#endif