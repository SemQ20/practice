#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

int frequencyPrimes (int n)                           
{
  int freq = n-1;
  for (int i = 2; i <= n; ++i)
      for (int j = sqrt( (float)i ); j > 1; --j)
          if (i % j == 0)
          {
            --freq;
            break;
          }
  return freq;
}


int main()
{
    std::time_t start;
    std::time_t end;
    char buf[80];
    /* standart struct std::tm for time manipulation*/
    std::tm stm;

    time(&start);
    int fnum = frequencyPrimes(1000000);
    time(&end);

    /* clock() */
    int i = clock();
    std::cout << fnum << '\n';
    std::cout << static_cast<float>(i)/CLOCKS_PER_SEC << '\n';

    std::time_t result = std::time(nullptr);
    std::cout << "Return time since start at 1970 in seconds: "<< result << '\n';
    std::cout << std::asctime(std::localtime(&result));
    std::cout << stm.tm_hour << '\n';
    /* std::time_t end - std::time_t start in seconds */
    std::cout << "Time passed: " << difftime(end, start) << " sec" << '\n';
    /* std::ctime() */
    std::cout << std::ctime(&result) << '\n';

    /* std::strftime() */
    stm = *(std::localtime(&result));
    std::strftime(buf,80,"Now %H:%M",&stm);
    std::cout << buf << '\n';

    /* std::put_time and std::gmtime */
    std::cout << "UTC " << std::put_time(std::gmtime(&result), "%c %Z") << '\n';
    std::cout << "UTC " << std::put_time(&stm, "%c %Z") << '\n';

    /* std::put_time and std::localtime */
    std::cout << "local " << std::put_time(std::localtime(&result),"%c %Z");

    return 0;
}
