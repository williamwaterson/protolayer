#include "Service.h"

namespace protolayer
{

namespace server
{


Service::Service(const std::string& name) :
  _name(name)
{
}


Service::Service(const char* name) :
  _name(name)
{
}


Service::~Service()
{
}


const std::string& Service::getName() const
{
  return _name;
}


logger::Logger& Service::getLogger()
{
  return logger::Logger::getSingleton();
}


}


}
