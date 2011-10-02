#ifndef PROTOLAYER_PUBLISHINGSERVICE_SERVICE_H
#define PROTOLAYER_PUBLISHINGSERVICE_SERVICE_H

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
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer.h>
#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>
#include <protolayer/protolayer-nameservice.h>

#include <protolayer/protolayer-containerservice.h>

#include "Configuration.h"


namespace protolayer
{

namespace publishingservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Service : public server::Service
{
private:
  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  Configuration& _configuration;

  /** TODO: Documentation */
  //  namingservice::Client* _namingClient;

  /** TODO: Documentation */
  containerservice::Service* _containerService;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Service(containerservice::Service& containerService,
		   Configuration& configuration);

  /**
   * TODO: Documentation
   *
   */
  virtual ~Service();

  /**
   * TODO: Documentation
   *
   */
  Configuration& getConfiguration();

  /**
   * TODO: Documentation
   *
   */
  containerservice::Service& getContainerService();

  /**
   * TODO: Documentation
   *
   */
  void startup();

  /**
   * TODO: Documentation
   *
   */
  void run();

  /**
   * TODO: Documentation
   *
   */
  void suspend();

  /**
   * TODO: Documentation
   *
   */
  void resume();

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
  Service(const Service& service);

  /**
   * TODO: Documentation
   *
   */
  Service operator=(const Service& service);

};


}


}


#endif // PROTOLAYER_PUBLISHINGSERVICE_SERVICE_H
