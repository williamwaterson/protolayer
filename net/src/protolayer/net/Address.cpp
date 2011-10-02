#include "Address.h"


namespace protolayer
{

namespace net
{

Address::Address(int port) :
  _port(port),
  _host("127.0.0.1")
{
  initLowLevelAddress();
}


void Address::initLowLevelAddress()
{
  bzero(&_sockaddr, sizeof(_sockaddr));
  _sockaddr.sin_family = AF_INET;
  _sockaddr.sin_port = htons(_port);
  inet_pton(AF_INET, const_cast <char*> (_host.c_str()), &_sockaddr.sin_addr);
}


Address::Address(const std::string& host, int port) :
  _port(port),
  _host(host)
{
  initLowLevelAddress();
}


Address::Address(const Address& address) :
  _port(address._port),
  _host(address._host)
{
  initLowLevelAddress();
}


const std::string& Address::getHost()
{
  return _host;
}


int Address::getPort()
{
  return _port;
}


Address& Address::operator=(const Address& address)
{
  _host = address._host;
  _port = address._port;
  return *this;
}

  
}


}
