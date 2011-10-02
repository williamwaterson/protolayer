#ifndef PROTOLAYER_CPPDOCLET_DOCUMENTATION_H
#define PROTOLAYER_CPPDOCLET_DOCUMENTATION_H

#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Annotation.h"
#include "Parsable.h"


namespace protolayer
{

namespace cppdoclet
{

class Documentation : public Parsable
{
  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _description;

  /** TODO */
  std::set <Annotation*> _annotations;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Documentation(const std::string& signature);

  /**
   *
   *
   */
  virtual void serialise(std::string& output, const std::string& componentName);

  /**
   *
   *
   */
  std::set <Annotation*>& getAnnotations();

  /**
   *
   *
   */
  bool containsAnnotation(const std::string& name);

private:
  /**
   * TODO: Documentation
   *
   */
  Documentation(const Documentation& instance);

  /**
   * TODO: Documentation
   *
   */
  Documentation& operator=(const Documentation& instance);

};


}


}


#endif // PROTOLAYER_DOCUMENTATION_H
