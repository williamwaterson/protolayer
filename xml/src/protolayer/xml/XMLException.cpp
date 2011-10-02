#include "XMLException.h"


namespace protolayer
{

namespace xml
{

XMLException::XMLException(const char* message)
{
}


XMLException::XMLException(const ::std::string& message)
{
}


XMLException::~XMLException()
{
}


XMLException::XMLException(const XMLException& exception)
{
}


XMLException& XMLException::operator=(const XMLException& exception)
{
  return *this;
}


}


}
