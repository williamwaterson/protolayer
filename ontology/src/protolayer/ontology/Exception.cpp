#include "Exception.h"

#include <iostream>

namespace protolayer
{

namespace ontology
{

Exception::Exception(const char* message) :
  ::protolayer::Exception::Exception(message)
{
  std::cout << message << std::endl;
}


Exception::Exception(const std::string& message) :
  ::protolayer::Exception::Exception(message)
{
  std::cout << message << std::endl;
}


Exception::~Exception()
{
}


Exception::Exception(const Exception& exception) :
  protolayer::Exception::Exception(exception)
{
}


Exception& Exception::operator=(const Exception& ex)
{
  protolayer::Exception::operator=(ex);
  return *this;
}


}


}
