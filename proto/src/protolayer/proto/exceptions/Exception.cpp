#include "Exception.h"


namespace protolayer
{

namespace proto
{

Exception::Exception(const char* message)
{
}


Exception::Exception(const ::std::string& message)
{
}


Exception::~Exception()
{
}


Exception::Exception(const Exception& exception)
{
}


Exception& Exception::operator=(const Exception& exception)
{
  return *this;
}


}


}
