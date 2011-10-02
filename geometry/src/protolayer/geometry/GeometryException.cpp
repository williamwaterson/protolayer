#include "GeometryException.h"


namespace protolayer
{

namespace geometry
{


GeometryException::GeometryException(const char* message)
{
}


GeometryException::GeometryException(const ::std::string& message)
{
}


GeometryException::~GeometryException()
{
}


GeometryException::GeometryException(const GeometryException& exception)
{
}


GeometryException& GeometryException::operator=(const GeometryException& ex)
{
  return *this;
}


}


}

