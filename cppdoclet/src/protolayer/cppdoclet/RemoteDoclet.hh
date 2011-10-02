#ifndef PROTOLAYER_CPPDOCLET_REMOTEDOCLET_H
#define PROTOLAYER_CPPDOCLET_REMOTEDOCLET_H

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
#include <rpc/rpc.h>
#include <iostream.h>
#include <errno.h>

#include "protolayer/protolayer-util.h"
#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer.h"

#include "Namespace.h"
#include "Dependencies.h"


namespace protolayer
{

namespace cppdoclet
{

class RemoteDoclet
{
  /**   */
  std::string _outputDir;

  /**   */
  std::string _fileName;

  /**   */
  std::string _className;

  /**   */
  std::string _outputBuffer;

  /** */
  Component* _component;

  /** */
  std::map <Method*, std::string> _clientProtocol;

  /** */
  std::map <std::string, Method*> _serviceProtocol;

public:
  /**
   * TODO: Documentation
   *
   */
  RemoteDoclet(Dependencies& dependencies, const std::string& outputDir = "./");

private:
  /**
   * TODO: Documentation
   *
   */
  void generateProtocol(Component& component);

  /**
   * TODO: Documentation
   *
   */
  void generateProtocol(Namespace& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateProtocol(Class& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateProtocol(Method& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Component& component);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Namespace& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Include& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Class& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Class& instance, Method& method);

  /**
   * TODO: Documentation
   *
   */
  void generateClientCall(Method& method);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Component& component);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Namespace& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Include& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Class& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Class& instance, Method& method);

};


}


}


#endif
