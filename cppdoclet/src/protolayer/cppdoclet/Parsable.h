#ifndef PROTOLAYER_CPPDOCLET_PARSABLE_H
#define PROTOLAYER_CPPDOCLET_PARSABLE_H

#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>


namespace protolayer
{

namespace cppdoclet
{

class Parsable
{
public:
  /**
   * TODO: Documentation
   *
   */
  Parsable();

  /**
   * TODO: Documentation
   *
   */
  virtual ~Parsable();

  /**
   * TODO: Documentation
   *
   */
  virtual void serialise(std::string& output, const std::string& componentName) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual bool isParsableOf(const std::string& componentName)
  {
    return false;
  }

  /**
   * TODO: Documentation
   *
   */
  virtual bool containsParsableOf(const std::string& componentName)
  {
    return false;
  }

private:
  /**
   * TODO: Documentation
   *
   */
  Parsable(const Parsable& instance);

  /**
   * TODO: Documentation
   *
   */
  Parsable& operator=(const Parsable& instance);

};


}


}


#endif // PROTOLAYER_PARSABLE_H
