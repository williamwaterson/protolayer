#ifndef PROTOLAYER_CPPDOCLET_NAMESPACE_H
#define PROTOLAYER_CPPDOCLET_NAMESPACE_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Class.h"
#include "Documentation.h"
#include "Typedef.h"
#include "Macro.h"
#include "Include.h"
#include "Scope.h"
#include "Method.h"


namespace protolayer
{

namespace cppdoclet
{

class Namespace : public Scope
{
  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _name;

  /** TODO */
  std::vector <Parsable*> _order;

  /** TODO */
  std::vector <Namespace*> _namespaces;

  /** TODO */
  std::vector <Include*> _includes;

  /** TODO */
  std::vector <Macro*> _macros;

  /** TODO */
  std::vector <Class*> _classes;

  /** TODO */
  std::vector <Method*> _nonMemberMethods;

  /** TODO */
  std::vector <Typedef*> _typedefs;

public:
  /**
   * TODO: Documentation
   *
   */
  Namespace(const std::string& buffer, const std::string& componentName, std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   *
   */
  bool hasDocumentation() const;

  /**
   * TODO: Documentation
   *
   */
  bool containsParsableOf(const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  bool containsAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  bool containsNamespaceAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  bool containsClassAnnotation(const std::string& name);

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

  /**
   * TODO: Documentation
   *
   */
  Documentation* getDocumentation();

  /**
   * TODO: Documentation
   *
   */
  Namespace(const std::string& buffer, const std::string& componentName, size_t& position, const std::string& scope, std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  void process(const std::string& buffer,
	       const std::string& componentName,
	       size_t& position,
	       const std::string& scope,
	       std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  void recoverMethods(std::map <std::string, Method*>& methods);

  /**
   * TODO: Documentation
   *
   */
  void recoverClasses(std::map <std::string, Class*>& classes);

  /**
   * TODO: Documentation
   *
   */
  void recoverTypedefs(std::vector <Typedef*>& typedefs);

  /**
   * TODO: Documentation
   *
   */
  std::vector <Namespace*>& getNamespaces();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Parsable*>& getParsables();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Macro*>& getMacros();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Include*>& getIncludes();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Class*>& getClasses();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Typedef*>& getTypedefs();

  /**
   * TODO: Documentation
   *
   */
  std::vector <Method*>& getMethods();

  /**
   * TODO: Documentation
   *
   */
  bool containsClasses();

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

private:
  /**
   * TODO: Documentation
   *
   */
  Namespace(const Namespace& instance);

  /**
   * TODO: Documentation
   *
   */
  Namespace& operator=(const Namespace instance);

};


}


}


#endif // PROTOLAYER_NAMESPACE_H
