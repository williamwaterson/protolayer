#ifndef PROTOLAYER_ADMINSERVICE_SERVICE_H
#define PROTOLAYER_ADMINSERVICE_SERVICE_H

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

#include "protolayer/protolayer-logger.h"


namespace protolayer
{

namespace server
{

/**
 * TODO: Documentation
 * <p>
 */
class Service
{
public:
  /** TODO: Documentation */
  static logger::Logger& getLogger();

private:
  /** TODO: Documentation */
  std::string _name;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Service(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  explicit Service(const char* name);

  /**
   * TODO: Documentation
   *
   */
  virtual ~Service() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void startup() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void run() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void suspend() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void resume() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void shutdown() = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual const std::string& getName() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Service(const Service& server);

  /**
   * TODO: Documentation
   *
   */
  Service& operator=(const Service& server);

};

}

}

#endif // PROTOLAYER_ADMINSERVICE_SERVICE_H
