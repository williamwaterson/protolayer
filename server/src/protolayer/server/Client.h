#ifndef PROTOLAYER_ADMINSERVICE_CLIENT_H
#define PROTOLAYER_ADMINSERVICE_CLIENT_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include <set>

#include <protolayer/protolayer-net.h>


namespace protolayer
{

namespace server
{

/**
 * TODO: Documentation
 * <p>
 */
class Client
{
private:
  /** TODO: Documentation */
  net::Socket* _socket;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Client(int port);

  /**
   * TODO: Documentation
   *
   */
  void shutdown();

private:
  /**
   * TODO: Documentation
   *
   */
  void checkResponse();

};

}

}

#endif // PROTOLAYER_ADMINSERVICE_CLIENT_H
