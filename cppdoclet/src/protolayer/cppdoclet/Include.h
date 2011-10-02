#ifndef PROTOLAYER_CPPDOCLET_INCLUDE_H
#define PROTOLAYER_CPPDOCLET_INCLUDE_H

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


class Include
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
  Include(const std::string& buffer, const std::string& componentName, size_t& position);

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
  Include(const Include& instance);

  /**
   * TODO: Documentation
   *
   */
  Include& operator=(const Include& instance);

};


}


}


#endif // PROTOLAYER_INCLUDE_H
