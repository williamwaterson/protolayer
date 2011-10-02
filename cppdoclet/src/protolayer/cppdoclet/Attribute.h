#ifndef PROTOLAYER_CPPDOCLET_ATTRIBUTE_H
#define PROTOLAYER_CPPDOCLET_ATTRIBUTE_H

#include <set>
#include <map>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

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


class Attribute : public Scope
{
private:
  /** TODO */
  bool _isStatic;

  /** TODO */
  std::string _visibility;

  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _signature;

  /** TODO */
  Type* _type;

  /** TODO */
  std::string _name;

  /** TODO */
  std::string _scope;

  /** TODO */
  std::string _scopedName;

public:
  /**
   * TODO: Documentation
   *
   */
  Attribute(const std::string& visibility, const std::string& signature, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

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

  /**
   * TODO: Documentation
   *
   */
  void backtrack();

  /**
   * TODO: Documentation
   *
   */
  const std::string& getScopedName() const;  

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const
  {
    return _name;
  }

  /**
   * TODO: Documentation
   *
   */
  Type& getType()
  {
    return *_type;
  }

  /**
   * TODO: Documentation
   *
   */
  bool hasDocumentation() const
  {
    return _documentation != 0;
  }

  /**
   * TODO: Documentation
   *
   */
  bool hasAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  Documentation* getDocumentation()
  {
    return _documentation;
  }

  /**
   * TODO: Documentation
   *
   */
  const std::string& getVisibility() const
  {
    return _visibility;
  }

  /**
   * TODO: Documentation
   *
   */
  const std::string& getSignature() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Attribute(const Attribute& instance);

  /**
   * TODO: Documentation
   *
   */
  Attribute& operator=(const Attribute& instance);

};


}


}


#endif // PROTOLAYER_ATTRIBUTE_H
