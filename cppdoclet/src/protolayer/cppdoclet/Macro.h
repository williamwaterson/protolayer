#ifndef PROTOLAYER_CPPDOCLET_MACRO_H
#define PROTOLAYER_CPPDOCLET_MACRO_H

#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Parsable.h"


namespace protolayer
{

namespace cppdoclet
{

// Forward declaration
class Class;


class Macro : public Parsable
{
  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _type;

  /** TODO */
  std::string _componentName;

public:
  /**
   * TODO: Documentation
   *
   */
  Macro(const std::string& buffer, const std::string& componentName, size_t& position);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getType() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string getSignature() const
  {
    return _signature;
  }

private:
  /**
   * TODO: Documentation
   *
   */
  Macro(const Macro& instance);

  /**
   * TODO: Documentation
   *
   */
  Macro& operator=(const Macro& instance);

};


}


}


#endif // PROTOLAYER_MACRO_H
