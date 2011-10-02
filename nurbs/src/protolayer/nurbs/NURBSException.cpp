#include "NURBSException.h"


namespace protolayer
{

namespace nurbs
{


NURBSException::NURBSException(const char* message)
{
}


NURBSException::NURBSException(const ::std::string& message)
{
}


NURBSException::~NURBSException()
{
}


NURBSException::NURBSException(const NURBSException& exception)
{
}


NURBSException& NURBSException::operator=(const NURBSException& exception)
{
  return *this;
}


}


}
