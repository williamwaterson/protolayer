#ifndef PROTOLAYER_CPPDOCLET_TYPE_H
#define PROTOLAYER_CPPDOCLET_TYPE_H

#include <map>
#include <set>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Scope.h"
#include "Typedef.h"


namespace protolayer
{

namespace cppdoclet
{

// Forward declaration
class Class;


class Type : public Scope
{
  /** TODO */
  bool _isReference;

  /** TODO */
  bool _isPointer;

  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _scope;

  /** TODO */
  std::string _className;

  /** TODO */
  Class* _class;

  /** TODO */
  std::map <std::string, Type*> _templateParameterTypes;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Type(const std::string signature);

  /**
   * TODO: Documentation
   *
   */
  const std::string& getSignature() const;

  /**
   * TODO: Documentation
   *
   */
  Class& getClass() const;

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
  virtual void serialise(std::string& output, const std::string& componentName);

  /**
   *  TODO: Documentation
   *
   */
  void backtrack();

  /**
   * TODO: Documentation
   *
   */
  bool isPointer() const;

  /**
   * TODO: Documentation
   *
   */
  bool isTemplate() const;

  /**
   * TODO: Documentation
   *
   */
  bool isReference() const;

  /**
   * TODO: Documentation
   *
   */
  bool isConst() const;

  /**
   * TODO: Documentation
   *
   */
  void extractTemplateParameters();

private:
  /**
   * TODO: Documentation
   *
   */
  Type(const Type& instance);

  /**
   * TODO: Documentation
   *
   */
  Type& operator=(const Type& instance);

};


}


}


#endif // PROTOLAYER_TYPE_H
