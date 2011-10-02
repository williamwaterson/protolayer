#ifndef PROTOLAYER_CPPDOCLET_DEPENDENCIES_H
#define PROTOLAYER_CPPDOCLET_DEPENDENCIES_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Namespace.h"
#include "Component.h"


namespace protolayer
{

namespace cppdoclet
{

class Dependencies
{
  /** TODO */
  std::string _targetFileName;

  /** TODO */
  std::string _dependenciesFileName;

  /** TODO */
  std::vector <std::string> _fileNames;

  /** TODO */
  Component* _targetComponent;

  /** TODO */
  std::map <std::string, Component*> _components;

  /** TODO */
  std::map <std::string, Class*> _classes;

  /** TODO */
  std::map <std::string, Namespace*> _namespaces;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Dependencies(const std::string& dependenciesFileName);

  /**
   * TODO: Documentation
   *
   */
  std::string serialise(Component& component);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getTargetFileName() const;

  /**
   * TODO: Documentation
   *
   */
  Component& getTargetComponent();

  /**
   * TODO: Documentation
   *
   */
  void backtrack();

  /**
   * TODO: Documentation
   *
   */ 
  const std::string& getSignature() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getDependenciesFileName() const;

  /**
   * TODO: Documentation
   *
   */
  const std::map <std::string, Component*>& getComponents() const;

  /**
   * TODO: Documentation
   *
   */
  const std::map <std::string, Class*>& getClasses() const;

private:
  /**
   * TODO: Documentation
   *
   */
  Dependencies(const Dependencies& dependencies);

  /**
   * TODO: Documentation
   *
   */
  Dependencies& operator=(const Dependencies dependencies);

};


}


}


#endif

