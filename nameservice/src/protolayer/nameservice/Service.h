#ifndef PROTOLAYER_NAMESERVICE_SERVICE_H
#define PROTOLAYER_NAMESERVICE_SERVICE_H

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

#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-concurrency.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "Record.h"
#include "InMemoryService.h"


namespace protolayer
{

namespace nameservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Service : public protolayer::server::Service
{
  /** TODO: Documentation */
  static const int DEFAULT_ACCESS_PORT = 80003;

  /** TODO: Documentation */
  static const int DEFAULT_EDIT_PORT = 80004;

  /** TODO: Documentation */
  typedef std::set <std::string> StringSetType;

  /** TODO: Documentation */
  typedef std::set <ontology::Ontology*> OntologySetType;

  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  net::ServerSocket* _serviceSocket;

  /** TODO: Documentation */
  concurrency::Mutex _mutex;

  /** TODO: Documentation */
  InMemoryService* _impl;

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
  explicit Service(xercesc::DOMElement& element) throw (Exception);

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
  void registerDomain(iostream::XdrInputStream& istream,
		      iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void registerTechnique(iostream::XdrInputStream& istream,
			 iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void addLocation(iostream::XdrInputStream& istream,
                   iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void removeLocation(iostream::XdrInputStream& istream,
                      iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void unregister(iostream::XdrInputStream& istream,
                  iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void getNames(iostream::XdrInputStream& istream,
                iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void getRecord(iostream::XdrInputStream& istream,
		 iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void getDomain(iostream::XdrInputStream& istream,
		 iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void getTechniques(iostream::XdrInputStream& istream,
		     iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void nextLocation(iostream::XdrInputStream& istream,
		    iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void handleSuccess(iostream::XdrInputStream& istream,
		     iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void handleError(iostream::XdrInputStream& istream,
                   iostream::XdrOutputStream& ostream,
		   const std::string& message);
};

}

}

#endif // PROTOLAYER_NAMESERVICE_SERVICE_H
