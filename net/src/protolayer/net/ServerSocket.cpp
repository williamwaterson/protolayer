#include "ServerSocket.h"

namespace protolayer
{

namespace net
{


void ServerSocket::initSocketFileDescriptor()
{
  _sockFd = socket(AF_INET, SOCK_STREAM, 0);
  unsigned long arg = 1; // set to zero to disable reusing
  setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR, (char*) &arg, sizeof(unsigned long));

  if (_sockFd < 0) {
    perror("Failed to obtain socket");
    throw;
  }
}


ServerSocket::ServerSocket()
{
  initSocketFileDescriptor();
}


ServerSocket::ServerSocket(int port)
{
  initSocketFileDescriptor();
  bind(port);
}


ServerSocket::~ServerSocket()
{
}


void ServerSocket::bind(int port)
{
  _port = port;

  bzero(&_serverAddress, sizeof(_serverAddress));
  _serverAddress.sin_family = AF_INET;
  _serverAddress.sin_port = htons(_port);
  _serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

  if (::bind(_sockFd, (struct sockaddr *)&_serverAddress, sizeof(_serverAddress)) < 0) {
    perror("Failed to bind");
    throw;
  }
}


bool ServerSocket::listen()
{
  return ::listen(_sockFd, 5) >= 0;
}


bool ServerSocket::write(char* buffer, int length)
{
  return ::write(_connectFd, buffer, length) >= 0;
}


Socket& ServerSocket::accept()
{
  _connectFd = ::accept(_sockFd, (struct sockaddr *) NULL, NULL);
  if (_connectFd < 0) {
    perror("Failed to accept");
    throw;
  }

  return *(new Socket(_connectFd));
}

  
}


}
