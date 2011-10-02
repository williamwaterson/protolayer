#include "CarbonException.h"


namespace protolayer
{

namespace carbon
{

CarbonException::CarbonException(const char* message)
{
}


CarbonException::CarbonException(const ::std::string& message)
{
}


CarbonException::~CarbonException()
{
}


CarbonException::CarbonException(const CarbonException& exception)
{
}


CarbonException& CarbonException::operator=(const CarbonException& ex)
{
  return *this;
}


}


}
