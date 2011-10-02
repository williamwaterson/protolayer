#ifndef PROTOLAYER_ADMINSERVICE_SERVER_H
#define PROTOLAYER_ADMINSERVICE_SERVER_H

#include <config.h>

#include <map>
#include <set>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "Exception.h"
#include "Service.h"

namespace protolayer
{

namespace server
{

/**
 * TODO: Documentation
 * <p>
 */
class Server
{
  /** TODO: Documentation */
  typedef std::set <Service*> ServiceSetType;

  /** TODO: Documentation */
  static const int DEFAULT_PORT = 80000;

  /** TODO: Documentation */
  pthread_mutex_t _adminMutex;

  /** TODO: Documentation */
  pthread_mutexattr_t _adminMutexAttributes;

  /** TODO: Documentation */
  net::ServerSocket* _rootSocket;

  /** TODO: Documentation */
  std::map <pthread_t, Service*> _threadServiceMap;

  /** TODO: Documentation */
  ServiceSetType _services;

public:
  /**
   * TODO: Documentation
   *
   */
  Server(int port);

  /**
   * TODO: Documentation
   *
   */
  Server(xercesc::DOMElement& element) throw (Exception);

  /**
   * Not thread safe or concurrently safe. Must only
   * be called prior to calling "run".
   */
  void add(Service& service);

  /**
   * TODO: Documentation
   *
   */
  void run();

private:
  /**
   * TODO: Documentation
   *
   */
  Server(const Server& server);

  /**
   * TODO: Documentation
   *
   */
  Server operator=(const Server& server);

  /**
   * TODO: Documentation
   *
   */
  void runServices();

  /**
   * TODO: Documentation
   *
   */
  void suspendServices();

  /**
   * TODO: Documentation
   *
   */
  void resumeServices();

  /**
   * TODO: Documentation
   *
   */
  void shutdownServices();

  /**
   * TODO: Documentation
   *
   */
  void handleError(iostream::XdrInputStream& istream,
                   iostream::XdrOutputStream& ostream);

};

}

}

#endif // PROTOLAYER_ADMINSERVICE_SERVER_H
