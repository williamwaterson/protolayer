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
class DomainService
{
public:
  /**
   * TODO: Documentation
   *
   */
  DomainService();

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool find(int domainId);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  void remove(int domainId);

};


}


}


#endif // PROTOLAYER_REGISTRATION_SERVICE_H
