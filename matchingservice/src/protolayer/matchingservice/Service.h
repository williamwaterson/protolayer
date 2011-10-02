#ifndef PROTOLAYER_MATCHINGSERVICE_SERVICE_H
#define PROTOLAYER_MATCHINGSERVICE_SERVICE_H

#include <map>
#include <arpa/inet.h>
#include <pthread.h>
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
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "AddressLoop.h"


namespace protolayer
{

namespace matchingservice
{

/**
 * This service provides a level of indirection, from supplied
 * URNs, to load-balanced remote addresses. The class makes
 * heavy use of pthread mutexes. The class holds a directory
 * of URNs mapped to sets of host:port addresses for name lookup
 * by clients. The current behaviour ensures that if a URN
 * has no available mapped host:port addresses to forward to,
 * then that entry is removed from the directory. This behaviour
 * might be reconsidered OR kept with the proviso that a pooling
 * of AddressLoops is kept rather then using crude deletion
 * AddressLoop instances on the removal of the related URN.
 */
class Service : public protolayer::server::Service
{
  /** TODO: Documentation */
  typedef std::map <std::string, AddressLoop*>::iterator IteratorType;

  /** TODO: Documentation */
  typedef std::map <std::string, AddressLoop*>::const_iterator ConstIteratorType;

  /** TODO: Documentation */
  typedef std::map <std::string, AddressLoop*> DirectoryType;

private:
  /** TODO: Documentation */
  static const int DEFAULT_ACCESS_PORT = 80001;

  /** TODO: Documentation */
  static const int DEFAULT_EDIT_PORT = 80002;

  /** Use pthreads mutex as pthreads spinlock unavailable in OS X 10.2 */
  //  pthread_spinlock_t _lock;
  mutable pthread_mutex_t _mutex;

  /** Use pthreads mutex as pthreads spinlock unavailable in OS X 10.2 */
  pthread_mutexattr_t _mutexattr;

  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  net::ServerSocket* _serviceSocket;

  /** TODO: Documentation */
  DirectoryType _directory;

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
  Service(xercesc::DOMElement& element) throw (Exception);

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

  /**
   * TODO: Documentation
   *
   */
  void addAddress(const std::string& name,
                  const std::string& result);

  /**
   * TODO: Documentation
   *
   */
  void removeAddress(const std::string& name,
                     const std::string& result);

  /**
   * TODO: Documentation
   *
   */
  bool getNextAddress(const std::string& name,
                      std::string& result) const;

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
  void addAddress(iostream::XdrInputStream& istream,
                  iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void removeAddress(iostream::XdrInputStream& istream,
                     iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void getNextAddress(iostream::XdrInputStream& istream,
                      iostream::XdrOutputStream& ostream) const;

  /**
   * TODO: Documentation
   *
   */
  void handleError(iostream::XdrInputStream& istream,
                   iostream::XdrOutputStream& ostream) const;

};


}


}


#endif // PROTOLAYER_MATCHINGSERVICE_SERVICE_H
