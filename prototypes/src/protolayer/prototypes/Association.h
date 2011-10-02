#ifndef PROTOLAYER_ASSOCIATION_H
#define PROTOLAYER_ASSOCIATION_H

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-util.h>

#include "End.h"
#include "Exception.h"

namespace protolayer
{

namespace ontology
{

/** TODO: Documentation */
class Ontology;

/**
 * @prototype serialise persist
 */
class Association : public util::Object
{
  /** TODO: Documentation */
  friend class Ontology;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  std::string _name;

  /** TODO: Documentation */
  End* _fromEnd;

  /** TODO: Documentation */
  End* _toEnd;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Association(ontologydto::AssociationDTO& dto,
	      std::map <int, Type*>& typeDictionary);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Association();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isName(const std::string& name) const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getUrn() const;

  /**
   * TODO: Documentation
   * <p>
   */
  End& getFromEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  End& getToEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromEnd(End& end);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isFromType(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToEnd(End& end);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isToType(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(End& end);

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
  bool involves(End& someEnd, End& anotherEnd);

  /**
   * TODO: Documentation
   * <p>
   */
  bool matches(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  bool matches(End& fromEnd, End& toEnd);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isEquivalent(Association& association);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isReverse(Association& association);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSimilar(Association& association);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Association(const Association& association);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Association& operator=(const Association& association);

};


}


}


#endif // PROTOLAYER_ASSOCIATION_H
