#ifndef PROTOLAYER_CONTAINERSERVICE_CLIENT_H
#define PROTOLAYER_CONTAINERSERVICE_CLIENT_H

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

#include <protolayer/protolayer.h>
#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-util.h>

#include "Exception.h"


namespace protolayer
{

namespace containerservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Client
{
  /** TODO: Documentation */
  net::Socket* _socket;

  /** TODO: Documentation */
  int _port;

public:
  /**
   * TODO: Documentation
   *
   */
  Client(int port);

  /**
   * TODO: Documentation
   *
   */
  void populate(const std::string& address,
		assembly::Instance& instance)
    throw (Exception, net::Exception);

  /**
   * TODO: Documentation
   *
   */
  void validate(const std::string& address,
		assembly::Instance& instance)
    throw (Exception, net::Exception);

  /**
   * TODO: Documentation
   *
   */
  void evaluate(const std::string& address,
		assembly::Instance& instance)
    throw (Exception, net::Exception);

  /**
   * TODO: Documentation
   *
   */
  void checkResponse() throw (Exception);

};


}


}


#endif // PROTOLAYER_CONTAINERSERVICE_CLIENT_H
