#ifndef PROTOLAYER_CPPDOCLET_METHOD_H
#define PROTOLAYER_CPPDOCLET_METHOD_H

#include <vector>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Annotation.h"
#include "Argument.h"
#include "Documentation.h"
#include "Implementation.h"
#include "Type.h"
#include "Typedef.h"
#include "Scope.h"


namespace protolayer
{

namespace cppdoclet
{


// Forward declarations
class Class;


class Method : public Scope
{
  /** TODO */
  std::string _visibility;

  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _rawSignature;

  /** TODO */
  std::string _strippedSignature;

  /** TODO */
  std::string _returnTypeName;

  /** TODO */
  Type* _returnType;

  /** TODO */
  std::vector <Argument*> _arguments;

  /** TODO */
  std::vector <Type*> _exceptions;

  /** TODO */
  std::string _scope;

  /** TODO */
  std::string _scopedName;

  /** TODO */
  std::string _name;

  /** TODO */
  Implementation* _implementation;

public:
  /**
   * TODO: Documentation
   *
   */
  Method(const std::string& visibility, const std::string& signature, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  Method(const std::string& visibility, const std::string& signature, const std::string& body, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  ~Method();

  /**
   * TODO: Documentation
   *
   */
  void serialise(std::string& output, const std::string& componentName);

  /**
   * TODO: Documentation
   *
   */
  void setImplementation(const std::string& body);

  /**
   * TODO: Documentation
   *
   */
  bool isDeclaration() const;

  /**
   * TODO: Documentation
   *
   */
  bool isDefinition() const;

  /**
   * TODO: Documentation
   *
   */
  bool isConstructor() const;

  /**
   * TODO: Documentation
   *
   */
  bool isAbstract() const;

  /**
   * TODO: Documentation
   *
   */
  bool isDestructor() const;

  /**
   * TODO: Documentation
   *
   */
  bool isVirtual() const;

  /**
   * TODO: Documentation
   *
   */
  bool isStatic() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getReturnTypeName() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getVisibility() const;

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
  bool hasAnnotation(const std::string& name);

  /**
   * TODO: Documentation
   *
   */
  Documentation* getDocumentation();

  /**
   * TODO: Documentation
   *
   */
  const std::string& getSignature() const;

  /**
   * TODO: Documentation
   *
   */

  const std::string& getRawSignature() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getStrippedSignature() const;

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

private:
  /**
   * TODO: Documentation
   *
   */
  void extractExceptions(const std::string& exceptions);

  /**
   * TODO: Documentation
   *
   */
  void extractOpening(const std::string& arguments);

  /**
   * TODO: Documentation
   *
   */
  void extractArguments(const std::string& arguments);

  /**
   * TODO: Documentation
   *
   */
  Method(const Method& service);

  /**
   * TODO: Documentation
   *
   */
  Method& operator=(const Method service);

};


}


}


#endif // PROTOLAYER_METHOD_H
