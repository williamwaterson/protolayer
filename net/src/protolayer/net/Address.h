#ifndef PROTOLAYER_NET_ADDRESS_H
#define PROTOLAYER_NET_ADDRESS_H

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

namespace protolayer
{

namespace net
{

// Forward declarations
class Socket;
class ServerSocket;

/**
 * TODO: Documentation
 * <p>
 */
class Address
{
public:
  /** TODO: Documentation */
  friend class Socket;
  friend class ServerSocket;

private:
  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  std::string _host;

  /** TODO: Documentation */
  struct sockaddr_in _sockaddr;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Address(int port);

  /**
   * TODO: Documentation
   *
   */
  Address(const std::string& host, int port);

  /**
   * TODO: Documentation
   *
   */
  Address(const Address& address);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getHost();

  /**
   * TODO: Documentation
   *
   */
  int getPort();

  /**
   * TODO: Documentation
   *
   */
  Address& operator=(const Address& address);

private:
  /**
   * TODO: Documentation
   *
   */
  void initLowLevelAddress();

};


}


}


#endif // PROTOLAYER_NET_ADDRESS_H
