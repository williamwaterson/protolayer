#ifndef PROTOLAYER_PROTO_PROJECT_H
#define PROTOLAYER_PROTO_PROJECT_H

#include <iostream.h>
#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "../forward.h"

#include <protolayer/protolayer-ontologydto.h>


namespace protolayer
{

namespace proto
{

class Project
{
  /** TODO: Documentation */
  assembly::Assembly* _assembly;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Project();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Project();

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Assembly& getAssembly();

};


}


}


#endif // PROTOLAYER_PROTO_PROJECT_H
