#include "Configuration.h"

namespace protolayer
{

namespace publishingservice
{

Configuration::Configuration(xercesc::DOMElement& element)
{
}


Configuration::Configuration(std::string& nameserverAddress,
			     int port) :
  _nameserverAddress(nameserverAddress),
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


const std::string& Configuration::getNameserverAddress() const
{
  return _nameserverAddress;
}


}


}
