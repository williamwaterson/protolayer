#ifndef PROTOLAYER_ASSOCIATIONSERVICE_H
#define PROTOLAYER_ASSOCIATIONSERVICE_H

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
 * @stateless
 * @pooled
 */
class AssociationService
{
public:
  /**
   * TODO: Documentation
   *
   */
  AssociationService();

  /**
   * @remote
   */
  int add(protolayer::ontologydto::AssociationDTO& dto);

  /**
   * @remote
   */
  bool find(int associationId);

  /**
   * @remote
   */
  bool retrieve(int associationId, protolayer::ontologydto::AssociationDTO& dto);

  /**
   * @remote
   */
  bool retrieve(protolayer::ontologydto::AssociationDTO& dto);

  /**
   * @remote
   */
  void remove(int associationId);

private:
  /**
   * TODO: Documentation
   *
   */
  AssociationService(const AssociationService& service);

  /**
   * TODO: Documentation
   *
   */
  AssociationService& operator=(const AssociationService service);

};


}


}


#endif // PROTOLAYER_ASSOCIATIONSERVICE_SERVICE_H
