#ifndef AC_SYSTEM_STRING
#define AC_SYSTEM_STRING

#include <string>
#include "String.h"

namespace AC{
namespace System{

String::String():AObject(), _Primitive(""){}
String::String(const char* c_String):AObject(), _Primitive(c_String){}
String::String(const std::string& stdString):AObject(), _Primitive(stdString){}
String::String(const String & other):AObject(), _Primitive(other._Primitive){}

String::~String(){}

std::string String::GetID() const{ return "AC_STRING"; }

String String::operator=(const String& other){return String(other); }

}}

#endif
