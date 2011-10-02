#ifndef PROTOLAYER_PUBLISHINGSERVICE_CONFIGURATION_H
#define PROTOLAYER_PUBLISHINGSERVICE_CONFIGURATION_H

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

#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-xml.h>
//#include <protolayer/protolayer-xul.h>


namespace protolayer
{

namespace publishingservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Configuration
{
private:
  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  std::string _nameserverAddress;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Configuration(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   *
   */
  Configuration(std::string& nameserviceAddress,
		int port);

  /**
   * TODO: Documentation
   *
   */
  virtual ~Configuration();

  /**
   * TODO: Documentation
   *
   */
  int getPort() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getNameserverAddress() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Configuration(const Configuration& configuration);

  /**
   * TODO: Documentation
   *
   */
  Configuration operator=(const Configuration& configuration);

};


}


}


#endif // PROTOLAYER_PUBLISHINGSERVICE_CONFIGURATION_H
