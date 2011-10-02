#ifndef PROTOLAYER_CPPDOCLET_SCOPE_H
#define PROTOLAYER_CPPDOCLET_SCOPE_H

#include <map>
#include <string>
#include <vector>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>


namespace protolayer
{

namespace cppdoclet
{

class Scope
{
  /** TODO */
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
  const std::string& getName() const;

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

};


}


}


#endif // PROTOLAYER_SCOPE_H
