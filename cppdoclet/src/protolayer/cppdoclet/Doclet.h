#ifndef PROTOLAYER_CPPDOCLET_DOCLET_H
#define PROTOLAYER_CPPDOCLET_DOCLET_H

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

namespace protolayer
{

namespace cppdoclet
{

class Doclet
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
  std::string _buffer;

  /**   */
  std::string _macroGuard;

  /**   */
  std::string _outputBuffer;

  /** */
  Namespace* _root;

public:
  Doclet(Namespace& root, const std::string& outputDir);

  void Doclet::createOpeningMacros();

 void Doclet::createClosingMacros();

  void prewalk(Namespace& instance);

  void prewalk(Include& instance);

  void prewalk(Class& instance);

  void prewalk(Attribute& instance);

  void prewalk(Method& instance);

  void process(Namespace& instance);

  void process(Include& instance);

  void process(Class& instance);

  void process(Method& instance);

  void process(Attribute& instance);

};


}


}


#endif
