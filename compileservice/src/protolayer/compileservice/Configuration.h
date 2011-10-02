#ifndef PROTOLAYER_COMPILESERVICE_CONFIGURATION_H
#define PROTOLAYER_COMPILESERVICE_CONFIGURATION_H

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


namespace protolayer
{

namespace compileservice
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

  /** TODO: Documentation */
  std::string _homePath;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Configuration(xercesc::DOMDocument& document);

  /**
   * TODO: Documentation
   *
   */
  Configuration(std::string& nameserviceAddress,
                std::string& homePath,
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

  /**
   * TODO: Documentation
   *
   */
  const std::string& getHomePath() const;

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


#endif // PROTOLAYER_COMPILESERVICE_CONFIGURATION_H
