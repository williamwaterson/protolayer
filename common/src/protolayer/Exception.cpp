#include "Exception.h"

#include <iostream>


namespace protolayer
{

Exception::Exception(const char* message) :
  _message(message)
{
  std::cout << message << std::endl;
}


Exception::Exception(const ::std::string& message) :
  _message(message)
{
  std::cout << message << std::endl;
}


const std::string& Exception::getMessage() const
{
  return _message;
}


Exception::~Exception()
{
}


Exception::Exception(const Exception& exception)
{
  _message = exception._message;
}


Exception& Exception::operator=(const Exception& ex)
{
  _message = ex._message;
  return *this;
}


}
