#ifndef PROTOLAYER_GENERALISATION_H
#define PROTOLAYER_GENERALISATION_H

#include <string>

#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontologydto.h>

#include "Exception.h"
#include "Type.h"

namespace protolayer
{

namespace ontology
{

/** TODO: Documentation */
class Ontology;

/**
 * @prototype serialise persist
 */
class Generalisation
{
  /** TODO: Documentation */
  friend class Ontology;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /**  */
  int _id;

  /** */
  int _superTypeId;

  /** TODO: Documentation */
  int _superTypeDomainId;

  /** TODO: Documentation */
  std::string _superTypeName;

  /** TODO: Documentation */
  int _subTypeId;

  /** TODO: Documentation */
  int _subTypeDomainId;

  /** TODO: Documentation */
  std::string _subTypeName;

  /** TODO: Documentation */
  Type* _superType;

  /** TODO: Documentation */
  Type* _subType;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Generalisation(ontologydto::GeneralisationDTO& generalisationDto,
                 std::map <int, Type*>& typeDictionary);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Generalisation();

  /**
   * TODO: Documentation
   * <p>
   */
  int getId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getSuperTypeId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getSuperTypeDomainId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  std::string getSuperTypeName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getSubTypeId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getSubTypeDomainId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  std::string getSubTypeName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  Type& getSubType();

  /**
   * TODO: Documentation
   * <p>
   */
  Type& getSuperType();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSuperType(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSubType(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(Type& someType, Type& anotherType);

  /**
   * TODO: Documentation
   * <p>
   */
  bool matches(Type& superType, Type& subType);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isEquivalent(Generalisation& gen);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isReverse(Generalisation& gen);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSimilar(Generalisation& gen);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Generalisation(const Generalisation& generalisation);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Generalisation& operator=(const Generalisation& generalisation);

};


}


}


#endif // PROTOLAYER_GENERALISATION_H
