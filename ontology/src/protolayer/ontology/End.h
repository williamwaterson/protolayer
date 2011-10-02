#ifndef PROTOLAYER_END_H
#define PROTOLAYER_END_H

#include <string>

#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontologydto.h>

#include "Type.h"


namespace protolayer
{

namespace ontology
{

/**
 * @prototype serialise persist
 */
class End
{
public:
  /** TODO: Documentation */
  static const int UNBOUNDED = -1;

private:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _conceptId;

  /** TODO: Documentation */
  int _domainId;

  /** TODO: Documentation */
  int _lowerBound;

  /** TODO: Documentation */
  int _upperBound;

  /** TODO: Documentation */
  std::string _title;

  /** TODO: Documentation */
  Type* _type;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  End(ontologydto::EndDTO& endDto,
      std::map <int, Type*>& typeDictionary);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~End();

  /**
   * TODO: Documentation
   * <p>
   */
  //  const std::string& getName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getConceptId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getDomainId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  Type& getType();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isType(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  int getLowerBound() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getUpperBound() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void checkBounds() throw (Exception);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  End(const End& end);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  End& operator=(const End& end);

  /**
   * TODO: Documentation
   * <p>
   */
  void handleWithDoubleDot(std::string& multiplicity)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void handleWithoutDoubleDot(std::string& multiplicity)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void handleSingleChar(std::string& multiplicity)
    throw (Exception);

};


}


}


#endif // PROTOLAYER_END_H
