#include "Configuration.h"

namespace protolayer
{

namespace compileservice
{

Configuration::Configuration(xercesc::DOMDocument& document)
{
}


Configuration::Configuration(std::string& nameserverAddress,
                             std::string& homePath,
                             int port) :
  _nameserverAddress(nameserverAddress),
  _homePath(homePath),
  _port(port)
{
}


Configuration::~Configuration()
{
}


int Configuration::getPort() const
{
  return _port;
}


const std::string& Configuration::getHomePath() const
{
  return _homePath;
}


const std::string& Configuration::getNameserverAddress() const
{
  return _nameserverAddress;
}


}


}
