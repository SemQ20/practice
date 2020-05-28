#include <variant>
#include <iostream>
#include <complex>
#include <utility>
#include <string>

union tun  {
  float _fval;
  int _ival;
};

int main()
{
    std::variant<int, float> v, w;
    v = 12;
    w = 3.5f;

    std::cout << "size of v: "<< std::variant_size_v<decltype(v)> << '\n';

    /* return value in union space */
    int i = std::get<int>(v);
    float fval = std::get<float>(w);

    std::cout << "i = "<< i << ", ";
    std::cout <<"fval = "<< fval << '\n';
    /* return position of std::variant<T... types> value{} in union space */
    std::cout << v.index() << ", "; 
    std::cout << w.index() << '\n';

    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line
 
//  std::get<double>(v); // error: no double in [int, float]
//  std::get<3>(v);      // error: valid index values are 0 and 1
 
    std::variant<std::complex<double>> _cval{std::in_place_index<0>,3.0,4.0};
    std::cout << *std::get_if<0>(&_cval) << '\n';

    using namespace std::literals;
 
    std::variant<std::string> x{"abc"};
    // converting constructors work when usnambiguous
    x = "def"; // converting assignment also works when unambiguous
    std::cout <<"take value from std::get: "<< std::get<std::string>(x) << '\n';

    auto val = std::visit([](const auto &val){
        std::cout << "take value from lambda: "<< val << '\n';
        return val;
    },x);

    std::cout << "std::visit return value: "<< val << '\n';
    std::cout << "get value from pointer: " << *std::get_if<0>(&x) << '\n';

    std::variant<std::string, void const*> y{"abc"};
    // casts to void const * when passed a char const *
    std::string ch;
    try
    {
      ch = std::get<std::string> (y);
    }
    catch(const std::bad_variant_access& e)
    {
      std::cerr << e.what() << '\n';
    }
    std::cout << ch << '\n';
    return 0;
}
