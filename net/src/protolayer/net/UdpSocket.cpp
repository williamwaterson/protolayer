#include "Socket.h"

namespace protolayer
{

namespace net
{

Socket::Socket() :
  _address(80)
{
  initSocketFileDescriptor();
  unsigned long arg = 1; // set to zero to disable reusing
  setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR, (char*) &arg, sizeof(unsigned long));
  initStreams();
}


Socket::Socket(int socketFd) :
  _address(80)
{
  _sockFd = socketFd;
  initStreams();
}


Socket::Socket(const Address& address) :
  _address(address)
{
  initSocketFileDescriptor();
  connect();
  initStreams();
}


Socket::Socket(std::string& host, int port) :
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

  close();
}


void Socket::initSocketFileDescriptor()
{
  _sockFd = socket(AF_INET, SOCK_STREAM, 0);
  if (_sockFd < 0) {
    perror("Failed to obtain socket");
    throw std::exception();
  }
}


bool Socket::connect(std::string& host, int port)
{
  _address = Address(host, port);
  return connect();
}


bool Socket::connect(const Address& address)
{
  _address = address;
  return connect();
}


bool Socket::connect()
{
  return ::connect(_sockFd, (struct sockaddr *) &(_address._sockaddr), sizeof(_address._sockaddr)) == 0;
}


bool Socket::close()
{
  return ::close(_sockFd) >= 0;
}


bool Socket::read(char* buffer, int n)
{
  int val;
  while ((val = ::read(_sockFd, buffer, n))) {
    buffer[val] = 0;
  }
  return val >= 0;
}


bool Socket::write(char* buffer, int n)
{
  return ::write(_sockFd, buffer, n) >= 0;
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
