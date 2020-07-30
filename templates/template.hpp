#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

namespace TemplateTest{
    template<typename T1, typename T2>
    auto max_test(T1 a, T2 b) -> decltype(true? a : b){
        return b < a ? a : b;
    }
}

#endif