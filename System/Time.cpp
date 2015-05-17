#ifndef AC_SYSTEM_TIME
#define AC_SYSTEM_TIME

#include <time.h>
#include "Time.h"

namespace AC{
namespace System{
  // public
    Time::Time(const Time& other):AObject(),_Time(other._Time){}
    Time::Time(Time&& other):AObject(), _Time(std::move(other._Time)){}
    
    Time::~Time(){}
    
    Time& Time::operator=(const Time& rhs){
      if(this != &rhs) _Time = rhs._Time;
      
      return *this;
    }
    
    Time Time::Now(){
      time_t tmp = time(NULL);
      return Time(tmp);
    }
    
    std::string Time::ToString(){
      std::string sResult = "";
      sResult += _Time;
      return sResult;
    }
    
    std::string Time::GetID() const{
      return "AC_TIME";
    }
  // protected
    Time::Time(const time_t& TimeStamp):AObject(), _Time(TimeStamp){}
    
  std::ostream& operator<<(std::ostream& out, const Time& rhs){
    out << rhs._Time;
    return out;
  }
    
}}


#endif
