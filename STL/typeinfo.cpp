#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
   int i;
   int di;
   double bL;
   std::string str;
   bool compare;
   if(typeid(i) == typeid(di)){
      std::cout<< typeid(i).name() << " are equal " << typeid(di).name() << "\n";
   }
   std::cout<< typeid(i).name() << "\n";
   std::cout<< typeid(i).hash_code() << "\n";
   std::cout<< typeid(bL).name() << "\n";
   std::cout<< typeid(str).name() << "\n";
   return 0;
}
