#ifndef PROTOLAYER_CPPDOCLET_PROTOTYPEDOCLET_H
#define PROTOLAYER_CPPDOCLET_PROTOTYPEDOCLET_H

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
#include "Component.h"
#include "Dependencies.h"


namespace protolayer
{

namespace cppdoclet
{

class PrototypeDoclet
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
  PrototypeDoclet(Dependencies& dependencies, const std::string& outputDir = "./");

  void process(Namespace& instance, const std::string& outputDir);

  void process(Include& instance, const std::string& outputDir);

  void process(Class& instance, const std::string& outputDir);

  void process(Class& instance, Attribute& attribute, const std::string& outputDir);

};


}


}


#endif
