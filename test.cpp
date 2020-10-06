#include <iostream>
#include <cmath>

template<typename F>
float RectangeRule(F f, float xmin, float xmax, int intervals){
    float dx = (xmax - xmin) / intervals;
    float total_area = 0;
    float x = xmin;
    for(float i = 0; i <= intervals; ++i * 0.01f){
        total_area += dx * f(x);
        x = x + dx;
    }
    return total_area;
}

template<typename F>
float TrapezoidRule(F f, float xmin, float xmax, int intervals){
    float dx = (xmax - xmin) / intervals;
    float total_area = 0;
    float x = xmin;
    for(int i = 0; i <= intervals; ++i){
        total_area += dx * (f(x) + f(x + dx))/2;
        x = x + dx;
    }
    return total_area;
}

float f (int x){
    return sin(x);
}

int 
main(){
    auto res  = RectangeRule(f,0,5,10);
    auto res1 = TrapezoidRule(f,0,5,20);
  
    std::cout << res << '\n';
    std::cout << res1 << '\n';

    return 0;
}
