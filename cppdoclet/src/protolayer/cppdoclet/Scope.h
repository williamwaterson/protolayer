#ifndef PROTOLAYER_CPPDOCLET_SCOPE_H
#define PROTOLAYER_CPPDOCLET_SCOPE_H

#include <map>
#include <string>
#include <vector>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Parsable.h"


namespace protolayer
{

namespace cppdoclet
{

class Scope : public Parsable
{
  /** Todo */
  std::string _type;

  /** TODO */
  std::string _name;

  /** TODO */
  std::string _qualifiedName;

  /** TODO */
  Scope* _parent;

  /** TODO */
  std::map <std::string, Scope*> _encapsulatedScopes;

public:
  /**
   * TODO: Documentation
   *
   */
  Scope();

  /**
   * TODO: Documentation
   *
   */
  virtual ~Scope();

  /**
   * TODO: Documentation
   *
   */
  explicit Scope(const std::string& name, Scope& parent);

  /**
   * TODO: Documentation
   *
   */
  virtual void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  Scope* recursiveFind(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   *
   */
  Scope* recursivefind(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  Scope* find(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  Scope* reverseFind(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  Scope* forwardFind(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getType() const;

  /**
   * TODO: Documentation
   *
   */
  void setType(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getQualifiedName() const;

  /**
   * TODO: Documentation
   *
   */
  Scope* getParent();

  /**
   * TODO: Documentation
   *
   */
  bool hasParent() const;

  /**
   * TODO: Documentation
   *
   */
  std::map <std::string, Scope*>& getEncapsulatedScopes();

  /**
   * TODO: Documentation
   *
   */
  void setScope(const std::string& name, Scope& parent);

private:
  /**
   * TODO: Documentation
   *
   */
  Scope(const Scope& instance);

  /**
   * TODO: Documentation
   *
   */
  Scope& operator=(const Scope instance);

  /**
   * TODO: Documentation
   *
   */
  bool isScoped(const std::string& name)
  {
    return std::string::npos != name.find("::");
  }

  /**
   * TODO: Documentation
   *
   */
  std::string getTopScope(const std::string& name)
  {
    std::size_t position = name.find("::");
    if (position == std::string::npos) {
      throw;
    }

    return name.substr(0, position);
  }

  /**
   * TODO: Documentation
   *
   */
  std::string getRemainingScope(const std::string& name)
  {
    std::size_t position = name.find("::");
    if (position == std::string::npos) {
      throw;
    }

    return name.substr(position + 2);
  }

};


}


}


#endif // PROTOLAYER_SCOPE_H
