
#include <iostream>
#include <string>
#include <chrono>
#include "Clock.h"

namespace AC{
namespace System{
  
Clock::Clock():AObject(), _IsRunning(false){}

int Clock::Start(){
  if(_IsRunning){
    std::cerr << "warning - clock is already running\n";
    return -1;
  } else {
    _IsRunning = true;
    _Start = std::chrono::high_resolution_clock::now();
  }
  return 0;
}
int Clock::Stop(){
  if(not _IsRunning){
    std::cerr << "warning - clock is not running, can not stop.\n";
    return -1;
  } else {
    _IsRunning = false;
    _Stop = std::chrono::high_resolution_clock::now();
  }
}

std::string ToString() const;


bool IsRunning() const{ return _IsRunning; }

std::string String::GetID() const{ return "AC_SYSTEM_CLOCK"; }

friend std::ostream& operator<<(std::ostream& out, const Clock& rhs){
  //std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()
  return out;
}
  
}}