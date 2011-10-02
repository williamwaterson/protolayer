#ifndef PROTOLAYER_REGISTRATION_SERVICE_H
#define PROTOLAYER_REGISTRATION_SERVICE_H

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

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-persistence.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-xml.h>

#include <protolayer/protolayer-database.h>


namespace protolayer
{

namespace registration
{

/**
 * TODO: Documentation
 * <p>
 */
class Service : public protolayer::server::Service
{
  /** TODO: Documentation */
  static const int DEFAULT_PORT = 80002;

  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  util::IDGenerator _idGenerator;

  /** TODO: Documentation */
  net::ServerSocket* _serviceSocket;

public:
  /**
   * TODO: Documentation
   *
   */
  Service(int port);

  /**
   * TODO: Documentation
   *
   */
  Service(xercesc::DOMElement& element) throw (server::Exception);

  /**
   * TODO: Documentation
   *
   */
  virtual void startup();

  /**
   * TODO: Documentation
   *
   */
  virtual void run();

  /**
   * TODO: Documentation
   *
   */
  virtual void resume();

  /**
   * TODO: Documentation
   *
   */
  virtual void suspend();

  /**
   * TODO: Documentation
   *
   */
  virtual void shutdown();

private:
  /**
   * TODO: Documentation
   *
   */
  Service(const Service& service);

  /**
   * TODO: Documentation
   *
   */
  Service operator=(const Service& service);

};


}


}


#endif // PROTOLAYER_REGISTRATION_SERVICE_H
