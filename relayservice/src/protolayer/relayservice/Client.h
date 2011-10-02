#ifndef PROTOLAYER_RELAYSERVICE_CLIENT_H
#define PROTOLAYER_RELAYSERVICE_CLIENT_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <map>

#include <protolayer/protolayer-net.h>

#include "Exception.h"


namespace protolayer
{

namespace relayservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Client
{
  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  net::Socket* _socket;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Client(int port);

  /**
   * Appends a subsequent location for an existing technique URN.
   * Method intended for remote invocation.
   */
  void addLocation(int techniqueId, const std::string& location)
    throw (Exception, net::Exception);

  /**
   * Returns the next load-balanced URL that matches the location
   * for the technique URN specified. The URN implicitly must be compliant
   * with the technique URN specification.
   */
  std::string nextLocation(int techniqueId);

};

}

}

#endif // PROTOLAYER_RELAYSERVICE_CLIENT_H
