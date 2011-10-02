#ifndef PROTOLAYER_REGISTRATION_ENDSERVICE_H
#define PROTOLAYER_REGISTRATION_ENDSERVICE_H

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
class EndService
{
public:
  /**
   * TODO: Documentation
   *
   */
  EndService();

private:
  /**
   * TODO: Documentation
   *
   */
  EndService(const EndService& endService);

  /**
   * TODO: Documentation
   *
   */
  EndService operator=(const EndService& endService);

};


}


}


#endif // PROTOLAYER_REGISTRATION_ENDSERVICE_H
