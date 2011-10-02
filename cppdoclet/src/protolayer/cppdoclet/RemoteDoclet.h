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
  /** TODO: Documentation  */
  std::string _className;

  /** TODO: Documentation  */
  Component& _component;

  /** TODO: Documentation  */
  std::map <int, Method*> idMethodMap;

  /** TODO: Documentation  */
  std::map <Method*, int> methodIdMap;

  /** TODO: Documentation  */
  Class* _client;

  /** TODO: Documentation  */
  Class* _service;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit RemoteDoclet(Dependencies& dependencies);

private:
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
  void generateClient(Class& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateClient(Method& method);

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
  void generateService(Class& instance);

  /**
   * TODO: Documentation
   *
   */
  void generateService(Method& method);

};


}


}


#endif
