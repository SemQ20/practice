#ifndef FOLD_EXPRESSIONS_HPP
#define FOLD_EXPRESSIONS_HPP

#include <utility>

/* std::conjunction_v united expression with && */
template<typename T1, 
         typename T2,
         typename... TN,
         typename = std::enable_if_t<std::conjunction_v<
         std::is_same<T1, T2>, 
         std::is_same<T1, TN>...>>>
bool EqualsAnyOf(const T1& t1, const T2& t2, const TN&... tn){
    return ((t1 == t2) || ... || (t1 == tn));
}


#endif