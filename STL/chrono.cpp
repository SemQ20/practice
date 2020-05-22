#include <iostream>
#include <chrono>
#include <thread>
#include <ratio>

using namespace std::literals::chrono_literals;

/* timer with platform specific 
time and used threads
undifined thread system (main or helper thread)*/
void timer(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

/* overloaded version std::to_string 
for timepoint type
Ofcourse it's more useful for output results*/
template <typename TimePoint>
std::string to_string(const TimePoint& time_point) //overloaded version std::to_string for timepoint type
{
    return std::to_string(time_point.time_since_epoch().count());
}

int main()
{
    std::chrono::duration<uint64_t,std::nano> timer_ms; //variable for measuring runtime algorithm/programm

    auto _ms{5560ms}; //chrono literals type like: operator""ms
 
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp_ms(_ms); //time point for compile time, time functions
    
    auto t1 = std::chrono::high_resolution_clock::now(); // time point 1 this point increased time of a start measure of this programm
    timer(5); // sleep for 5 seconds
    auto t2 = std::chrono::high_resolution_clock::now(); // time point 2 this point increased time of a end measure of this programm

    /* result of measure run time with point t1 to point t2 
    used arithmetic spcific for time pointers*/
    timer_ms = t2 - t1;

    int result = std::chrono::duration_cast<std::chrono::seconds>(timer_ms).count();
    std::cout << result << '\n';
    
    std::cout << "std::ratio::milli::num "<< std::milli::num << '\n'; // return a numerator of std::ratio<>
    std::cout << "std::ratio::milli::den "<< std::milli::den << '\n'; // return a denominator of std::ratio<>

    auto tp_sec = std::chrono::floor<std::chrono::seconds>(tp_ms); // floor, ceil, round, abs return's a timepoint type value
    int64_t tp_tsec = tp_sec.time_since_epoch().count(); // we take result in integer type of result floor function

    std::cout << tp_tsec << '\n'; //round 5560 ms => 5 sec without std::to_string return integer type
    std::cout << to_string(std::chrono::ceil<std::chrono::seconds>(tp_ms)) << '\n'; //round 5560 ms => 6 sec with using custom to_string

    /* time point for work with measuring variables
    initialization after masure
    if you initialization time point for duration variable like std::chrono::duration<uint64_t,std::nano>
    it's doest'n work */
    std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::nanoseconds> _tp_ms(timer_ms); // time_point (std::chrono::duration<uint64_t,std::nano>)

    auto tp_n_sec = std::chrono::floor<std::chrono::nanoseconds>(_tp_ms); // round result in std::chrono::time_point type
    uint64_t _tp_sec = tp_n_sec.time_since_epoch().count(); 

    auto timep = std::chrono::time_point_cast<std::chrono::seconds>(tp_n_sec);
    uint64_t timep_sec = timep.time_since_epoch().count(); // we take reuslt of lesser extent like: 5650ms => 5 sec

    /* Output result of working with time points
    std::chrono::high_resolution_clock::now() like:
    timer_ms = t2 - t1 */
    std::cout << _tp_sec <<" ns" << '\n';
    std::cout << timep_sec << " sec" << '\n';

    return 0;
}