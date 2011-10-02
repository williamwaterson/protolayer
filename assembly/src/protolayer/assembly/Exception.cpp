#include "Exception.h"


namespace protolayer
{

namespace assembly
{

Exception::Exception(const char* message) :
  ::protolayer::Exception::Exception(message)
{
}


Exception::Exception(const std::string& message) :
  ::protolayer::Exception::Exception(message)
{
}


Exception::~Exception()
{
}


Exception::Exception(const Exception& exception) :
  ::protolayer::Exception::Exception(exception)
{
}


Exception& Exception::operator=(const Exception& ex)
{
  ::protolayer::Exception::operator=(ex);
  return *this;
}


}


}
