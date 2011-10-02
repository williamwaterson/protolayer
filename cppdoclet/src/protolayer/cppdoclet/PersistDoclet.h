#ifndef PROTOLAYER_CPPDOCLET_PERSISTDOCLET_H
#define PROTOLAYER_CPPDOCLET_PERSISTDOCLET_H

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

class PersistDoclet
{
  /**   */
  int _count;

  /**   */
  bool _hasClassAnnotationMatch;

  /**   */
  bool _hasAttributeAnnotationMatch;

  /**   */
  bool _hasMethodAnnotationMatch;

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

public:
  PersistDoclet(Dependencies& dependencies, const std::string& outputDir = "./");

  void process(Namespace& instance);

  void process(Include& instance);

  void process(Class& instance);

  void process(Class& instance, Attribute& attribute);

};


}


}


#endif
