#ifndef PROTOLAYER_RELAYSERVICE_SERVICE_H
#define PROTOLAYER_RELAYSERVICE_SERVICE_H

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

//#include "mysql/mysql.h"

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "AddressLoop.h"


namespace protolayer
{

namespace relayservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Service : public protolayer::server::Service
{
  /** TODO: Documentation */
  static const int DEFAULT_ACCESS_PORT = 80006;

  /** TODO: Documentation */
  static const int DEFAULT_EDIT_PORT = 80005;

  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  pthread_mutex_t _mutex;

  /** TODO: Documentation */
  pthread_mutexattr_t _mutexAttributes;

  /** TODO: Documentation */
  net::ServerSocket* _serviceSocket;

  /** Maps single URNs to sets of IP locations providing the related technique */
  std::map <int, AddressLoop*> _locationsDirectory;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Service(int port);

  /**
   * TODO: Documentation
   *
   */
  explicit Service(xercesc::DOMElement& element) throw (server::Exception);

  /**
   * TODO: Documentation
   *
   */
  ~Service();

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

  /**
   * TODO: Documentation
   *
   */
  void addLocation(net::Socket& socket);

  /**
   * TODO: Documentation
   *
   */
  void nextLocation(net::Socket& socket);

  /**
   * TODO: Documentation
   *
   */
  bool isValidTechniqueId(int id);

  
  //  void exiterr(MYSQL& handle, int exitcode);

  //  void executeConnect(MYSQL& handle);

  //  void executeQuery(MYSQL& handle, std::string& query);

};


}


}


#endif // PROTOLAYER_RELAYSERVICE_SERVICE_H
