#ifndef PROTOLAYER_NET_SOCKET_H
#define PROTOLAYER_NET_SOCKET_H

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

#include <protolayer/protolayer-iostream.h>

#include "Address.h"


namespace protolayer
{

namespace net
{

/**
 * TODO: Documentation
 * <p>
 */
class Socket
{
  /** TODO: Documentation */
  int _listenFd;

  /** TODO: Documentation */
  int _connectFd;

  /** TODO: Documentation */
  int _sockFd;

  /** TODO: Documentation */
  bool _isStream;

  /** TODO: Documentation */
  Address _address;

  /** TODO: Documentation */
  struct sockaddr_in _serverAddress;

  /** TODO: Documentation */
  iostream::XdrInputStream* _xdrInputStream;

  /** TODO: Documentation */
  iostream::XdrOutputStream* _xdrOutputStream;

public:
  /**
   * TODO: Documentation
   *
   */
  Socket();

  /**
   * TODO: Documentation
   *
   */
  Socket(int connectFd);

  /**
   * TODO: Documentation
   *
   */
  explicit Socket(const Address& address);

  /**
   * TODO: Documentation
   *
   */
  Socket(std::string& host, int port);

  /**
   * TODO: Documentation
   *
   */
  ~Socket();

  /**
   * TODO: Documentation
   *
   */
  bool connect();

  /**
   * TODO: Documentation
   *
   */
  bool connect(const Address& address);

  /**
   * TODO: Documentation
   *
   */
  bool connect(std::string& host, int port);

  /**
   * TODO: Documentation
   *
   */
  bool read(char* bytes, int length);

  /**
   * TODO: Documentation
   *
   */
  bool write(char* bytes, int length);

  /**
   * TODO: Documentation
   *
   */
  iostream::XdrInputStream& getXdrInputStream();

  /**
   * TODO: Documentation
   *
   */
  iostream::XdrOutputStream& getXdrOutputStream();

  /**
   * TODO: Documentation
   *
   */
  bool close();

private:
  /**
   * TODO: Documentation
   *
   */
  Socket(const Socket& socket);

  /**
   * TODO: Documentation
   *
   */
  Socket& operator=(const Socket& socket);

  /**
   * TODO: Documentation
   *
   */
  void initSocketFileDescriptor();

  /**
   * TODO: Documentation
   *
   */
  void initStreams();

};

}

}

#endif // PROTOLAYER_NET_SOCKET_H
