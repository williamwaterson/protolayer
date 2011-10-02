#ifndef PROTOLAYER_CPPDOCLET_DEFINE_H
#define PROTOLAYER_CPPDOCLET_DEFINE_H

#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>


namespace protolayer
{

namespace cppdoclet
{

// Forward declaration
class Class;


class Define
{
  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _componentName;

public:
  /**
   * TODO: Documentation
   *
   */
  Define(const std::string& buffer, const std::string& componentName, size_t& position);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

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
  Define(const Define& instance);

  /**
   * TODO: Documentation
   *
   */
  Define& operator=(const Define& instance);

};


}


}


#endif // PROTOLAYER_DEFINE_H
