#include "Property.h"


namespace protolayer
{

namespace dimensional
{

Property::Property(const char* message) :
  _message(message)
{
}


Property::Property(const ::std::string& message) :
  _message(message)
{
}


const std::string& Property::getMessage() const
{
  return _message;
}


Property::~Property()
{
}


Property::Property(const Property& exception)
{
  _message = exception._message;
}


Property& Property::operator=(const Property& ex)
{
  _message = ex._message;
  return *this;
}


}


}
