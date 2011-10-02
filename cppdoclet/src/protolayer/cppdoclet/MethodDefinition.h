#ifndef PROTOLAYER_CPPDOCLET_METHODDEFINITION_H
#define PROTOLAYER_CPPDOCLET_METHODDEFINITION_H

#include <vector>
#include <string>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-util.h>

#include "Type.h"
#include "Argument.h"
#include "Documentation.h"
#include "Annotation.h"


namespace protolayer
{

namespace cppdoclet
{


// Forward declarations
class Class;


class MethodDefinition
{
  /** TODO */
  std::string _visibility;

  /** TODO */
  Documentation* _documentation;

  /** TODO */
  std::string _signature;

  /** TODO */
  std::string _strippedSignature;

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

public:
  /**
   * TODO: Documentation
   *
   */
  MethodDefinition(const std::string& visibility, const std::string& signature, Documentation* documentation);

  /**
   * TODO: Documentation
   *
   */
  bool isDeclaration() const;

  /**
   * TODO: Documentation
   *
   */
  bool isConstructor() const;

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
  bool isDefinition() const;

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
  MethodDefinition(const MethodDefinition& service);

  /**
   * TODO: Documentation
   *
   */
  MethodDefinition& operator=(const MethodDefinition service);

};


}


}


#endif // PROTOLAYER_METHODDEFINITION_H
