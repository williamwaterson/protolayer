#include "Implementation.h"


namespace protolayer
{

namespace cppdoclet
{

Implementation::Implementation(const std::string& body) :
  _body(body)
{
}


void Implementation::serialise(std::string& output)
{
}


const std::string& Implementation::getBody() const
{
  return _body;
}


}


}
