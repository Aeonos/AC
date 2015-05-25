#ifndef AC_SYSTEM_STRING
#define AC_SYSTEM_STRING

#include <string>
#include <sstream>
#include "String.h"

namespace AC{
namespace System{
// PRIVATE

String::String():AObject(), _Primitive(""){}
String::String(double Value):AObject(), _Primitive(std::to_string(Value)){}
String::String(int Value):AObject(), _Primitive(std::to_string(Value)){}
String::String(const char* c_String):AObject(), _Primitive(c_String){}
String::String(const std::string& stdString):AObject(), _Primitive(stdString){}
String::String(const String & other):AObject(), _Primitive(other._Primitive){}

String::~String(){}

std::string String::GetID() const{ return "AC_STRING"; }

String String::operator=(const String& other){return String(other); }

String& String::operator +=(const String& other){
  _Primitive.append(other._Primitive);
  return *this;
}
String& String::operator +=(const std::string& other){
  _Primitive.append(other);
  return *this;
}
String& String::operator +=(int other){
  _Primitive.append(_FromNumber(other));
  return *this;
}
String& String::operator +=(double other){
  _Primitive.append(_FromNumber(other));
  return *this;
}
// String& String::operator *=(int other);
// String& String::operator *=(double other);

std::string String::_FromNumber(int Value){
  std::stringstream ss;
  ss << Value;
  return ss.str();
}
std::string String::_FromNumber(double Value){
  std::stringstream ss;
  ss << Value;
  return ss.str();
}

String String::FromNumber(int Value){
  return String(_FromNumber(Value));
}
String String::FromNumber(double Value){
  return String(_FromNumber(Value));
}

}}

#endif
