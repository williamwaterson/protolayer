#ifndef PROTOLAYER_CPPDOCLET_ARGUMENT_H
#define PROTOLAYER_CPPDOCLET_ARGUMENT_H

#include <map>
#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Type.h"


namespace protolayer
{

namespace cppdoclet
{

// Forward declarations
class Class;


class Argument : public Scope
{
  /** TODO */
  std::string _signature;

  /** TODO */
  Type* _type;

  /** TODO */
  std::string _name;

  /** TODO */
  std::string _scope;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Argument(const std::string& signature);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;
 
  /**
   * TODO: Documentation
   *
   */
  void backtrack();

  /**
   * TODO: Documentation
   *
   */
  const Type& getType() const;

  /**
   * TODO: Documentation
   *
   */
  void propagateScope(const std::string& scope);

  /**
   * TODO: Documentation
   *
   */
  void propagateClasses(const std::map <std::string, Class*>& classes);

  /**
   * TODO: Documentation
   *
   */
  void propagateTypedefs(const std::vector <Typedef*>& typedefs);

private:
  /**
   * TODO: Documentation
   *
   */
  Argument(const Argument& argument);

  /**
   * TODO: Documentation
   *
   */
  Argument& operator=(const Argument argument);

};


}


}


#endif // PROTOLAYER_ARGUMENT_H
