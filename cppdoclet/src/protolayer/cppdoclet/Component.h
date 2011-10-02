#ifndef PROTOLAYER_CPPDOCLET_COMPONENT_H
#define PROTOLAYER_CPPDOCLET_COMPONENT_H

#include <set>
#include <map>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Namespace.h"
#include "Parsable.h"


namespace protolayer
{

namespace cppdoclet
{

class Component
{
  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _name;

  /** TODO */
  Namespace* _tree;

  /** TODO */
  std::map <std::string, Class*> _classes;

  /** TODO */
  std::vector <Typedef*> _typedefs;

public:
  /**
   * TODO: Documentation
   *
   */
  Component(const std::string& fileName,
	    std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  explicit Component(const std::string& fileName);

  /**
   * TODO: Documentation
   *
   */
  bool isRoot(const Namespace& instance) const;

  /**
   * TODO: Documentation
   *
   */
  void recoverClasses(std::map <std::string, Class*>& classes);

  /**
   * TODO: Documentation
   *
   */
  void recoverMethods(std::map <std::string, Method*>& methods);

  /**
   * TODO: Documentation
   *
   */
  void process(std::string& buffer, std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  void propagateClasses(const std::map <std::string, Class*>& classes);

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

  /**
   * TODO: Documentation
   *
   */
  bool containsClassAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  std::map <std::string, Class*>& getAllClasses();

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getSignature() const;

  /**
   * TODO: Documentation
   *
   */
  Namespace& getTree();

  /**
   * TODO: Documentation
   *
   */
  void fold();

  /**
   * TODO: Documentation
   *
   */
  void backtrack();

  /**
   * TODO: Documentation
   *
   */
  void fold(std::map <std::string, Namespace*>& namespaces);

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output);

private:
  /**
   * TODO: Documentation
   *
   */
  Component(const Component& component);

  /**
   * TODO: Documentation
   *
   */
  Component& operator=(const Component component);

};


}


}


#endif

