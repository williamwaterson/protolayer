#include "Socket.h"

namespace protolayer
{

namespace net
{

Socket::Socket() throw (Exception):
  _address(80)
{
  initSocketFileDescriptor();

  unsigned long arg = 1; // set to zero to disable reusing
  if (-1 == setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR, (char*) &arg, sizeof(unsigned long))) {
    throw Exception(strerror(errno));
  }

  initStreams();
}


Socket::Socket(int socketFd) throw (Exception):
  _address(80)
{
  _sockFd = socketFd;
  initStreams();
}


Socket::Socket(const Address& address) throw (Exception) :
  _address(address)
{
  initSocketFileDescriptor();
  connect();
  initStreams();
}


Socket::Socket(const std::string& host, int port) throw (Exception) :
  _address(host, port)
{
  initSocketFileDescriptor();
  connect();
  initStreams();
}


void Socket::initStreams()
{
  _xdrInputStream = new iostream::XdrInputStream(_sockFd);
  _xdrOutputStream = new iostream::XdrOutputStream(_sockFd);
}


Socket::~Socket()
{
  delete _xdrInputStream;
  delete _xdrOutputStream;

  try {
    close();
  } catch (Exception& ex) {
    // Avoid rethrowing as always fail quietly during destruction
  }

}


void Socket::initSocketFileDescriptor()
  throw (Exception)
{
  _sockFd = socket(AF_INET, SOCK_STREAM, 0);
  if (_sockFd == -1) {
    throw Exception(strerror(errno));
  }
}


void Socket::connect(std::string& host, int port) throw (Exception)
{
  _address = Address(host, port);
  connect();
}


void Socket::connect(const Address& address) throw (Exception)
{
  _address = address;
  connect();
}


void Socket::connect() throw (Exception)
{
  if (::connect(_sockFd, (struct sockaddr *) &(_address._sockaddr), sizeof(_address._sockaddr)) != 0) {
    throw Exception(strerror(errno));
  }
}


void Socket::close() throw (Exception)
{
  if (::close(_sockFd) == -1) {
    throw Exception(strerror(errno));
  }
}


bool Socket::read(char* buffer, int n)
{
  int val;
  while ((val = ::read(_sockFd, buffer, n))) {
    buffer[val] = 0;
  }
  return val >= 0;
}


void Socket::write(char* buffer, int n) throw (Exception)
{
  if (::write(_sockFd, buffer, n) == -1) {
    throw Exception(strerror(errno));
  }
}


iostream::XdrInputStream& Socket::getXdrInputStream()
{
  return *_xdrInputStream;
}


iostream::XdrOutputStream& Socket::getXdrOutputStream()
{
  return *_xdrOutputStream;
}

  
}


}
