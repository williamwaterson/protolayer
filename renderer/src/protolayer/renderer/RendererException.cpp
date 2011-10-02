#include "RendererException.h"


namespace protolayer
{

namespace renderer
{

RendererException::RendererException(const char* message)
{
}


RendererException::RendererException(const ::std::string& message)
{
}


RendererException::~RendererException()
{
}


RendererException::RendererException(const RendererException& exception)
{
}


RendererException& RendererException::operator=(const RendererException& ex)
{
  return *this;
}


}


}
