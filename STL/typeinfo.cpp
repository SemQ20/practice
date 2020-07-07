#include <iostream>
#include <string>
#include <typeinfo>
#include <queue>
#include <deque>


int main()
{
   std::queue<int> q;
   std::priority_queue<int> d;
   int i;
   int di;
   double bL;
   std::string str;
   bool compare;
   if(typeid(q) == typeid(d)){
      while(!q.empty()){
         std::cout << q.front() << '\n';
         q.pop();
      }
   }else{
      std::cout << "this not work" << '\n';
   }
   std::cout<< typeid(i).name() << "\n";
   std::cout<< typeid(i).hash_code() << "\n";
   std::cout<< typeid(bL).name() << "\n";
   std::cout<< typeid(str).name() << "\n";
   return 0;
}
