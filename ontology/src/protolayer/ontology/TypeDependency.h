#ifndef PROTOLAYER_TYPEDEPENDENCY_H
#define PROTOLAYER_TYPEDEPENDENCY_H

#include <protolayer/protolayer-iostream.h>

#include "Type.h"

namespace protolayer
{

namespace ontology
{

/** TODO: Documentation */
class Ontology;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TypeDependency
{
public:
  /** TODO: Documentation */
  friend class Ontology;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /** TODO: Documentation */
  Type* _fromType;

  /** TODO: Documentation */
  Type* _toType;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency(iostream::XdrInputStream& stream,
                 std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  ~TypeDependency();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  Type& getFromType();

  /**
   * TODO: Documentation
   * <p>
   */
  Type& getToType();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromType(Type& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToType(Type& instance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeDependency(const TypeDependency& typeDependency);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeDependency& operator=(const TypeDependency& typeDependency);

};


}


}


#endif // PROTOLAYER_TYPEDEPENDENCY_H
