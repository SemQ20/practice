#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Substract

#include <boost/test/unit_test.hpp>
#include "../t_class.hpp"
#include <cmath>

template<typename T>
T substract(T a, T b){
    return a - b;
}

float substract(float a, float b){
    return std::round(a - b);
}

BOOST_AUTO_TEST_CASE(substract_Test){
    BOOST_CHECK(substract(5, 3) == 2);
}

/* TODO Not work for floating point arithmetics? */
BOOST_AUTO_TEST_CASE(substract_Test_v1){
    BOOST_CHECK(substract(5.3f, 3.2f) == std::round(2.1f));
} 

BOOST_AUTO_TEST_CASE(substract_Test_v2){
    BOOST_CHECK(substract('z', 'a') == '\031');
}

BOOST_AUTO_TEST_CASE(Test_for_class){
    TClass tcl(100, 4.0, 10ll);
    BOOST_CHECK(tcl.rint == 100);
}
/* for compiling (linux):
    (g++)clang++ test.cpp -lboost_unit_test_framework */