#ifndef POLICY_HPP
#define POLICY_HPP

struct SubPolicy{
    template<typename T1, typename T2>
    static void accumulate(T1& total, T2 const& value){
        total += value;
    }

};

struct MulPolicy
{
    template<typename T1, typename T2>
    static void accumulate(T1& total, T2 const& value){
        total *= value;
    }
};

template<typename T1, typename T2>
struct SubPolicy1{
    static void accumulate(T1& total, T2 const& value){
        total += value;
    }
};

template<typename T1, typename T2>
struct MulPolicy1
{
    static void accumulate(T1& total, T2 const& value){
        total *= value;
    }
};

#endif