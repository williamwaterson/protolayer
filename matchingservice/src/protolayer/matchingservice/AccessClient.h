#ifndef PROTOLAYER_MATCHINGSERVICE_ACCESSCLIENT_H
#define PROTOLAYER_MATCHINGSERVICE_ACCESSCLIENT_H

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

#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-net.h>

#include "Exception.h"


namespace protolayer
{

namespace matchingservice
{

/**
 * TODO: Documentation
 * <p>
 */
class AccessClient
{
  /** TODO: Documentation */
  net::Socket* _socket;

public:
  /**
   * TODO: Documentation
   *
   */
  AccessClient(int port);

  /**
   * TODO: Documentation
   *
   */
  iostream::XdrInputStream& getAvailableAddress(const std::string& name) throw (Exception);

private:
  /**
   * TODO: Documentation
   *
   */
  void checkResponse() throw (Exception);

};

}

}

#endif // PROTOLAYER_MATCHINGSERVICE_ACCESSCLIENT_H
