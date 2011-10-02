#ifndef PROTOLAYER_CPPDOCLET_ANNOTATION_H
#define PROTOLAYER_CPPDOCLET_ANNOTATION_H

#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>


namespace protolayer
{

namespace cppdoclet
{

class Annotation
{
  /** TODO */
  std::string _name;

  /** TODO */
  std::string _signature;

  /** TODO */
  std::set <std::string> _parameters;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Annotation(const std::string& signature);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;

  /**
   *
   *
   */
  void serialise(std::string& buffer);

private:
  /**
   * TODO: Documentation
   *
   */
  Annotation(const Annotation& annotation);

  /**
   * TODO: Documentation
   *
   */
  Annotation& operator=(const Annotation annotation);

};


}


}


#endif

