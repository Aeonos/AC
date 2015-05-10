#include "/home/christian/Programming/AC++/AC.h"

#include <iostream>

int main(){
  AC::System::String A; //<- is not supposed to work; using abstract base class
  std::cout << A.GetID();
  return 0;
}
