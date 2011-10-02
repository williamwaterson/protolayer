#ifndef PROTOLAYER_MATCHINGSERVICE_MODIFYINGCLIENT_H
#define PROTOLAYER_MATCHINGSERVICE_MODIFYINGCLIENT_H

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
class ModifyingClient
{
  /** TODO: Documentation */
  net::Socket* _socket;

public:
  /**
   * TODO: Documentation
   *
   */
  ModifyingClient(int port);

  /**
   * TODO: Documentation
   *
   */
  void addAddress(const std::string& name,
                  const std::string& address) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void removeAddress(const std::string& name,
                     const std::string& address) throw (Exception);

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

#endif // PROTOLAYER_MATCHINGSERVICE_MODIFYINGCLIENT_H
