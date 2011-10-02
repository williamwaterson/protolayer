#include "Root.h"


namespace protolayer
{

namespace pforms
{

Root::Root(const char* message) :
  _message(message)
{
}


Root::Root(const ::std::string& message) :
  _message(message)
{
}


const std::string& Root::getMessage() const
{
  return _message;
}


Root::~Root()
{
}


Root::Root(const Root& exception)
{
  _message = exception._message;
}


Root& Root::operator=(const Root& ex)
{
  _message = ex._message;
  return *this;
}


}


}
