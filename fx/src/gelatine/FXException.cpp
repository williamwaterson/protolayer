#include "FXException.h"


namespace protolayer
{


FXException::FXException(const char* message)
{
}


FXException::FXException(const ::std::string& message)
{
}


FXException::~FXException()
{
}


FXException::FXException(const FXException& exception)
{
}


FXException& FXException::operator=(const FXException& exception)
{
  return *this;
}


}
