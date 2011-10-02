#ifndef PROTOLAYER_NET_SOCKET_H
#define PROTOLAYER_NET_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#include <protolayer/protolayer-iostream.h>

#include "Address.h"
#include "Exception.h"


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
  Socket() throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  explicit Socket(int connectFd) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  explicit Socket(const Address& address) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  Socket(const std::string& host, int port) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  ~Socket();

  /**
   * TODO: Documentation
   *
   */
  void connect() throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void connect(const Address& address) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void connect(std::string& host, int port) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  bool read(char* bytes, int length);

  /**
   * TODO: Documentation
   *
   */
  void write(char* bytes, int length) throw (Exception);

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
  void close() throw (Exception);

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
  void initSocketFileDescriptor() throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void initStreams();

};

}

}

#endif // PROTOLAYER_NET_SOCKET_H
