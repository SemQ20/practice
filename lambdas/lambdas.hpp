#ifndef LAMBDAS_HPP
#define LAMBDAS_HPP

#include <iostream>
#include <functional>
#include <sstream>
#include <exception>

std::function<int(int,int)> rlambda(){
        return [](int x, int y){return x*y;};
    };


auto add = [](auto x, auto y){ return x + y; };
auto inc = [](auto x){ return x + 1; };
auto mul = [](auto x, auto y){ return x * y; };

/* use: once(add)(3,4); */
auto once = [](auto binary){
      bool done = false;
      return [=](auto x, auto y) mutable{
          if(!done){
              return binary(x, y);
          }else{
              throw std::runtime_error("once");
          }
      };
};

/* use for example: binaryc(mul)(5, 6, inc) */
auto binaryc = [](auto binary){
    return [=](auto x, auto y, auto callbk){
        return callbk(binary(x, y));
    }
};

auto unit = [](auto x){
    return [=](){ return x; };
};

auto stringify = [](auto x){
    std::stringstream ss;
    ss << x;
    return unit(ss.str);
};

auto bind = [](auto u){
    return [=](auto callback){
        return callback(u());
    };
};

/* std::cout << "Left Identify"
          << stringify(15)()
          << "=="
          << bind(unit(15))(stringify)()
          << '\n';

std::cout << "Right Identify"
          << stringify(5)()
          << "=="
          << bind(stringify(5))(unit)()
          << '\n'; */

#endif
