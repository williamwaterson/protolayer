#ifndef PROTOLAYER_CPPDOCLET_IMPLEMENTATION_H
#define PROTOLAYER_CPPDOCLET_IMPLEMENTATION_H

#include <vector>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Annotation.h"
#include "Argument.h"
#include "Documentation.h"
#include "Type.h"
#include "Typedef.h"
#include "Scope.h"


namespace protolayer
{

namespace cppdoclet
{


// Forward declarations
class Class;


class Implementation
{
  /** TODO */
  std::string _body;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Implementation(const std::string& body);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getBody() const;

private:
  /**
   *
   *
   */
  Implementation(const Implementation& service);

  /**
   * TODO: Documentation
   *
   */
  Implementation& operator=(const Implementation service);

};


}


}


#endif // PROTOLAYER_IMPLEMENTATION_H
