#include "/home/christian/Programming/AC++/AC.h"

#include <iostream>

int main(){
  AC::System::String A;
  std::cout << A.GetID() << std::endl;

  AC::System::Time B = AC::System::Time::Now();
  std::cout << B.GetID() << std::endl;

  std::cout << B << std::endl;
  
  AC::System::Time C = B;
  C -= 20;
  C = B + 10;
  std::cout << C << std::endl;
  return 0;
}
