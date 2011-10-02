#ifndef PROTOLAYER_CONTAINERSERVICE_SERVICE_H
#define PROTOLAYER_CONTAINERSERVICE_SERVICE_H

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

#include "Configuration.h"
#include "RootConceptInstanceImpl.h"
#include "ImmutableConceptInstanceImpl.h"


namespace protolayer
{

namespace containerservice
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
  concurrency::Mutex _mutex;

  /** TODO: Documentation */
  net::ServerSocket* _serviceSocket;

  /** TODO: Documentation */
  Configuration& _configuration;

  /** TODO: Documentation */
  std::map <std::string, TechniqueService*> _deployedTechniqueServices;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Service(Configuration& configuration);

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
  void publishLocations();

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
  void deploy(TechniqueService& technique);

  /**
   * TODO: Documentation
   *
   */
  void undeploy(TechniqueService& technique);

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

  /**
   * TODO: Documentation
   *
   */
  void populate(iostream::XdrInputStream& istream,
		iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void validate(iostream::XdrInputStream& istream,
		iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void evaluate(iostream::XdrInputStream& istream,
		iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void handleError(iostream::XdrInputStream& istream,
                   iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void handleSuccess(iostream::XdrInputStream& istream,
		     iostream::XdrOutputStream& ostream);

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
  TechniqueService* handleTechniqueLookup(iostream::XdrInputStream& istream,
					  iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void handleFailedLookup(iostream::XdrInputStream& istream,
			  iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  RootConceptInstance* extractSubgraph(iostream::XdrInputStream& istream,
				       iostream::XdrOutputStream& ostream);

  /**
   * TODO: Documentation
   *
   */
  void releaseSubgraph(RootConceptInstance& instance);

  /**
   * TODO: Documentation
   *
   */
  TechniqueService* getTechniqueService(const std::string& urn);

};


}


}


#endif // PROTOLAYER_CONTAINERSERVICE_SERVICE_H
