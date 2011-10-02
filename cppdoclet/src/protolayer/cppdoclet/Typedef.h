#ifndef PROTOLAYER_CPPDOCLET_TYPEDEF_H
#define PROTOLAYER_CPPDOCLET_TYPEDEF_H

#include <map>
#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Documentation.h"
#include "Scope.h"


namespace protolayer
{

namespace cppdoclet
{

// Forward declarations
class Class;


class Typedef : public Scope
{
  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _componentName;

  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _alias;

  /** TODO */
  std::string _typeName;

  /** TODO */
  std::string _scope;

  /** TODO */
  std::string _scopedAlias;

public:
  /**
   * TODO: Documentation
   *
   */
  Typedef(const std::string& buffer, const std::string& componentName, size_t& position, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getAlias() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getTypeName() const;

  /**
   * TODO: Documentation
   *
   */
  void propagateClasses(const std::set <Class*>& classes);

  /**
   * TODO: Documentation
   *
   */
  void propagateScope(const std::string& scope);

  /**
   * TODO: Documentation
   *
   */
  void backtrack();

private:
  /**
   * TODO: Documentation
   *
   */
  Typedef(const Typedef& instance);

  /**
   * TODO: Documentation
   *
   */
  Typedef& operator=(const Typedef& instance);

};


}


}


#endif // PROTOLAYER_TYPEDEF_H
