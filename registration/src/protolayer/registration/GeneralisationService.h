#ifndef PROTOLAYER_REGISTRATION_GENERALISATIONSERVICE_H
#define PROTOLAYER_REGISTRATION_GENERALISATIONSERVICE_H

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
class GeneralisationService
{
public:
  /**
   * TODO: Documentation
   *
   */
  GeneralisationService();

private:
  /**
   * TODO: Documentation
   *
   */
  GeneralisationService(const GeneralisationService& generalisationService);

  /**
   * TODO: Documentation
   *
   */
  GeneralisationService operator=(const GeneralisationService& generalisationService);

};


}


}


#endif // PROTOLAYER_REGISTRATION_GENERALISATIONSERVICE_H
