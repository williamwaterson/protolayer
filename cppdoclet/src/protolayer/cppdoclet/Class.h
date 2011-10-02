#ifndef PROTOLAYER_CPPDOCLET_CLASS_H
#define PROTOLAYER_CPPDOCLET_CLASS_H

#include <vector>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Attribute.h"
#include "Documentation.h"
#include "Method.h"
#include "Typedef.h"
#include "Scope.h"


namespace protolayer
{

namespace cppdoclet
{

class Class : public Scope
{
  /** TODO */
  bool _isForwardDeclaration;

  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _name;

  /** TODO */
  std::string _scope;

  /** TODO */
  std::string _scopedName;

  /** TODO */
  std::string _componentName;

  /** TODO */
  std::vector <Parsable*> _order;

  /** TODO */
  std::vector <Typedef*> _typedefs;

  /** TODO */
  std::vector <Attribute*> _attributes;

  /** TODO */
  std::vector <Method*> _methods;

public:
  /**
   * TODO: Documentation
   *
   */
  Class(const std::string& buffer, const std::string& componentName, size_t& position, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  ~Class();

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  bool isForwardDeclaration() const
  {
    return _isForwardDeclaration;;
  }

  bool isParsableOf(const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  void recoverMethods(std::map <std::string, Method*>& methods);

  /**
   * TODO: Documentation
   *
   */
  bool containsParsableOf(const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  void propagateScope(const std::string& scope);

  /**
   * TODO: Documentation
   *
   */
  void propagateTypedefs(const std::vector <Typedef*>& typedefs);

  /**
   * TODO: Documentation
   *
   */
  void propagateClasses(const std::map <std::string, Class*>& classes);

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
  std::vector <Parsable*>& getParsables();

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
  const std::string& getComponentName() const
  {
    return _componentName;
  }

  /**
   * TODO: Documentation
   *
   */
  std::vector <Attribute*>& getAttributes()
  {
    return _attributes;
  }

  /**
   * TODO: Documentation
   *
   */
  std::vector <Method*>& getMethods()
  {
    return _methods;
  }

  /**
   * TODO: Documentation
   *
   */
  std::vector <Typedef*>& getTypedefs();

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
  void addMethod(const std::string& visibility,
		 const std::string& signature,
		 Documentation* documentation)
  {
    Method* created = new Method(visibility, signature, documentation);
    _methods.push_back(created);
  }

  /**
   * TODO: Documentation
   *
   */
  void addMethod(const std::string& visibility,
		 const std::string& signature,
		 const std::string& implementation,
		 Documentation* documentation)
  {
    Method* created = new Method(visibility, signature, implementation, documentation);
    _methods.push_back(created);
  }

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
  bool hasAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  bool containsAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  bool containsMethodAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  bool containsAttributeAnnotation(const std::string& name);

private:
  /**
   * TODO: Documentation
   *
   */
  Class(const Class& instance);

  /**
   * TODO: Documentation
   *
   */
  Class& operator=(const Class& instance);

};


}


}


#endif // PROTOLAYER_CLASS_H
