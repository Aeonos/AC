#ifndef AC_SYSTEM_TIME
#define AC_SYSTEM_TIME

#include <time.h>
#include <iostream>
#include "Time.h"

namespace AC{
namespace System{
    Time::Time(const Time& other):AObject(), _Time(other._Time){}
    Time::Time(struct tm*& TimeStamp):AObject(), _Time(mktime(TimeStamp)){}
    Time::Time(const time_t& TimeStamp):AObject(), _Time(TimeStamp){}
    Time::Time(Time&& other):AObject(), _Time(std::move(other._Time)){}
  
    Time& Time::operator=(const Time& rhs){
      if(this != &rhs) _Time = rhs._Time;
      
      return *this;
    }
    
    Time Time::Now(){
      time_t tmp = time(NULL);
      return Time(tmp);
    }
    
    std::string Time::GetID() const{
      return "AC_TIME";
    }
    
    int Time::GetSeconds() const{
      return localtime(&_Time)->tm_sec;
    }
    int Time::GetMinutes() const{
      return localtime(&_Time)->tm_min;
    }
    int Time::GetHours() const{
      return localtime(&_Time)->tm_hour;
    }
    int Time::GetDayOfMonth() const{
      return localtime(&_Time)->tm_mday;
    }
    int Time::GetMonth() const{
      return localtime(&_Time)->tm_mon;
    }
    int Time::GetYears() const{
      return localtime(&_Time)->tm_year + 1900;
    }
    int Time::GetDayOfWeek() const{
      return localtime(&_Time)->tm_wday;
    }
    int Time::GetDayOfYear() const{
      return localtime(&_Time)->tm_yday;
    }
    bool Time::IsDaylightSaving() const{
      return (localtime(&_Time)->tm_isdst > 0 ? true : false);
    }
    
    std::string Time::ToString(const char* Format){
      std::string sResult = "";
      
      char buffer[AC_SYSTEM_TIME_FORMAT_STRING_BUFFERSIZE];
      try{
	int iResult = strftime(buffer, AC_SYSTEM_TIME_FORMAT_STRING_BUFFERSIZE, Format, localtime(&_Time));
	if( iResult == 0 ) 
	  throw "error - resulting formated time string was to long for buffer size\n";
      }
      catch (const char* e)
      {
	std::cerr << e;
	return sResult;
      }
      return std::string(buffer);
    }
    
    std::ostream& operator<<(std::ostream& out, Time& rhs){
      out << rhs.ToString();
      return out;
    }
    
    Time& Time::operator-=(const Time& rhs){
      _Time -= difftime(_Time, rhs._Time);
      return *this;
    }
    Time& Time::operator-=(int rhs){
      _Time -= rhs;
      return *this;
    }
    Time& Time::operator+=(int rhs){
      _Time += rhs;
      return *this;
    }
    
    Time operator+(const Time& lhs, const Time& rhs){
      return Time(lhs._Time + rhs._Time);
    }
    Time operator-(const Time& lhs, const Time& rhs){
       return Time(lhs._Time- rhs._Time);
    }
    Time operator+(const Time& lhs, int rhs){
      return Time(lhs._Time + rhs);
    }
    Time operator+(int lhs, const Time& rhs){
      return Time(lhs + rhs._Time);
    }
    Time operator-(const Time& lhs, int rhs){
      return Time(lhs._Time - rhs);
    }
    Time operator-(int lhs, const Time& rhs){
      return Time(lhs - rhs._Time);
    }
    
}}

#endif
