#ifndef PROTOLAYER_NET_SERVERSOCKET_H
#define PROTOLAYER_NET_SERVERSOCKET_H

#include <map>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include "Socket.h"

namespace protolayer
{

namespace net
{

/**
 * TODO: Documentation
 * <p>
 */
class ServerSocket
{
  /** TODO: Documentation */
  int _connectFd;

  /** TODO: Documentation */
  int _sockFd;

  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  bool _isStream;

  /** TODO: Documentation */
  std::string _host;

  /** TODO: Documentation */
  struct sockaddr_in _serverAddress;

public:
  /**
   * TODO: Documentation
   *
   */
  ServerSocket();

  /**
   * TODO: Documentation
   *
   */
  ServerSocket(int port);

  /**
   * TODO: Documentation
   *
   */
  ~ServerSocket();

  /**
   * TODO: Documentation
   *
   */
  void bind(int port);

  /**
   * TODO: Documentation
   *
   */
  bool listen();

  /**
   * TODO: Documentation
   *
   */
  Socket& accept();

  /**
   * TODO: Documentation
   *
   */
  bool write(char* buffer, int length);

  /**
   * TODO: Documentation
   *
   */
  void close();

private:
  /**
   * TODO: Documentation
   *
   */
  ServerSocket(const ServerSocket& serverSocket);

  /**
   * TODO: Documentation
   *
   */
  ServerSocket operator=(const ServerSocket& serverSocket);

  /**
   * TODO: Documentation
   *
   */
  void initSocketFileDescriptor();

};

}

}

#endif // PROTOLAYER_NET_SERVERSOCKET_H
