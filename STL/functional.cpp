#include <functional>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

class Foo {
    public: 
    void printNum(int value) const { std::cout << value << '\n';};
    void operator()(int val) const { std::cout << val << '\n';};
    const int _cval = 12;
};

int someFunc(int value){
    return value;
}

void printFunc(int value){
    std::cout << value << '\n';
}

void printf1(int value, int val){
    std::cout << value << '\n' << val << '\n';
}

void _func(int& val){
    std::cout << val << '\n';
}

void _func(const int& val){
    std::cout << val << '\n';
}

void _ffunc(){
    std::cout << "Call std::invoke without args" << '\n';
}

int main()
{
    bool btrue = true;
    bool bfalse = false;

    int ivalue = 125;
    int ivalue_1 = 120;
    int isum = 0;

    float fvalue = 3.0f;
    float fvalue1 = 4.3f;
    float fsum = 0.0f;

    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";

    std::string sstr = "dol";

    /* typical initialization pointer for someFunc */
    // Variant 1:
    std::function<int(int)> printfunc1 = someFunc;
    int someVal1 = printfunc1(5);
    std::cout << someVal1 << '\n' << "\n";

    /* printFunc is a pointer to someFunc */
    std::function<int()> printfunc = std::bind(someFunc,205);
    int someVal = printfunc();
    std::cout << someVal << '\n';

    /* lambda store */
    std::function<int()> lmd1 = []() -> int { 
        int _ret = someFunc(278); return _ret;}; 
    int lambdaReturn = lmd1();
    std::cout << lambdaReturn << '\n';

    std::function<void()> lmd2 = []() { printFunc(345); };
    lmd2();

    /* call class method */
    std::function<void(const Foo&, int)> fooMethod = &Foo::printNum;
    const Foo foo;
    fooMethod(foo, 125);

    /* call class field */
    std::function<int(Foo const&)> foo_field = &Foo::_cval;
    int someV = foo_field(foo);
    std::cout << someV << '\n';

    std::function<void(int)> fooFunc = Foo();
    fooFunc(186);

    std::function<int()> f = nullptr;
    try {
        f();
    } catch(const std::bad_function_call& e) {
        std::cout << e.what() << '\n';
    }

    // for _1, _2, _3 ... arguments: std::bind(any_object, _1, _2); 
    // for objects call any_object(120, 20);
    // here _1 => 120, _2 => 20
    // without _1, _2 any_object(120.20) not called
    using namespace std::placeholders;

    auto f1 = std::bind(printf1, _1, _2);
    f1(10, 15);

    /* std::bind for lambda */
    auto _lambda = std::bind ([](){printf1(15,36);});
    _lambda();

    /* std::ref create reference wrapper */
    _func(std::ref(ivalue));

     /* std::cref create constant reference wrapper */
    _func(std::cref(ivalue));

    /* std::invoke call object with arguments */
    std::invoke(printf1, 123,12);

    /* std::invoke call object without arguments */
    std::invoke(_ffunc);

    /* any example use invoke for class method */
    std::invoke(&Foo::printNum, foo , 100);

    /* call overloaded operator in class Foo */
    std::invoke(Foo(),120);

/**************************************************************************************/
    /* ALL uses for STL algorithms  */
    /* Arithmetical operations  functors, comparators*/
    /* std::plus<>(args);
    return a substration of two arguments */
    isum = std::plus<>{}(ivalue, ivalue_1);
    std::cout << isum << '\n';

    /* std::minus<>{}(args);
    return a subtraction of two arguments */
    int result = 0;
    result = std::minus<>{}(ivalue, ivalue_1);
    std::cout << result << '\n';

    /* std::multiple<>{}(args);
    return a multiplication of two arguments */
    result = std::multiplies<>{}(ivalue, ivalue_1);
    std::cout << result << '\n';

    /* std::divides<>{}(args);
    return a divided of two arguments */
    result = std::divides<>{}(ivalue, ivalue_1);
    std::cout << result << '\n';

    /* std::modulus<>{}(args);
    return a divided of two arguments */
    result = std::modulus<>{}(ivalue, ivalue_1);
    std::cout << result << '\n';

    /* std::negate<>{}(args);
    return a negate of argument */
    result = std::negate<>{}(ivalue);
    std::cout << result << '\n';

    /* ********************************************************************* */
    /* Compare operators */
    bool bresult;
    bresult = std::equal_to<>{}(ivalue,ivalue_1);
    std::cout << std::boolalpha;
    std::cout << "val1 == val2 ?: "<< bresult << '\n';

    bresult = std::not_equal_to<>{}(ivalue,ivalue_1);
    std::cout << "val1 != val2 ?: " << bresult << '\n';

    bresult = std::greater<>{}(ivalue,ivalue_1);
    std::cout << "val1 > val2 ?: "<< bresult << '\n';

    bresult = std::greater<>{}(ivalue,ivalue_1);
    std::cout << "val1 > val2 ?: "<< bresult << '\n';

    bresult = std::less<>{}(ivalue,ivalue_1);
    std::cout << "val1 < val2 ?: "<< bresult << '\n';

    bresult = std::greater_equal<>{}(ivalue,ivalue_1);
    std::cout << "val1 >= val2 ?: "<< bresult << '\n';

    bresult = std::less_equal<>{}(ivalue,ivalue_1);
    std::cout << "val1 <= val2 ?: "<< bresult << '\n';

    bresult = std::logical_and<>{}(btrue, bfalse);
    std::cout << "val1 && val2 ?: "<< bresult << '\n';

    bresult = std::logical_or<>{}(btrue, bfalse);
    std::cout << "val1 || val2 ?: "<< bresult << '\n';

    bresult = std::logical_not<>{}(btrue);
    std::cout << "!val1(true): "<< bresult << '\n';

    int res = std::bit_and<>{}(3, 5);
    std::cout << "3 & 5 = " << res << '\n';

    res = std::bit_or<>{}(3, 5);
    std::cout << "3 | 5 = " << res << '\n';

    res = std::bit_xor<>{}(3, 5);
    std::cout << "3 ^ 5 = " << res << '\n';

    res = std::bit_not<>{}(5);
    std::cout << "~5 = " << res << '\n';

    /* Algorithms in <functional> for uses another algorithms in STL */
    /* std::default_searcher */
    auto strit = std::search(text.begin(),text.end(),std::default_searcher(sstr.begin(), sstr.end()));
    /* return of index string container: */
    std::cout << strit - text.begin()  << '\n';

    /* std::boyer_moore_searcher */
    strit = std::search(text.begin(),text.end(),std::boyer_moore_searcher(sstr.begin(), sstr.end()));
    std::cout << strit - text.begin()  << '\n';

    /* std::boyer_moore_horspool_searcher */
    strit = std::search(text.begin(),text.end(),std::boyer_moore_horspool_searcher(sstr.begin(), sstr.end()));
    std::cout << strit - text.begin()  << '\n';

    /* Use serching iterator */
    for(std::string::iterator it = text.begin(); it < strit; it++){
        std::cout << *it;
    }
    std::cout << '\n';
    
    return 0;
}
