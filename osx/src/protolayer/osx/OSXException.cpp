#include "OSXException.h"


namespace protolayer
{

namespace osx
{

OSXException::OSXException(const char* message)
{
}


OSXException::OSXException(const ::std::string& message)
{
}


OSXException::~OSXException()
{
}


OSXException::OSXException(const OSXException& ex)
{
}


OSXException&
OSXException::operator=(const OSXException& exception)
{
  return *this;
}


}


}
