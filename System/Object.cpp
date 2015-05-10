#ifndef AC_SYSTEM_OBJECT
#define AC_SYSTEM_OBJECT

#include <string>

#include "Object.h"

namespace AC{
namespace System{

Object::Object(){}
//std::string Object::GetName() const{ return Name;}
std::string Object::GetName() const{
  std::string Result;
  Result = ObjectName;
  return Result;
}

}
}


#endif
