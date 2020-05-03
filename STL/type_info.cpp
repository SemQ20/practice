#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
   int i;
   double bL;
   std::string str;
   std::cout<< typeid(i).name() << "\n";
   std::cout<< typeid(i).hash_code() << "\n";
   std::cout<< typeid(bL).name() << "\n";
   std::cout<< typeid(str).name() << "\n";
   return 0;
}
