#ifndef PROTOLAYER_TYPE_H
#define PROTOLAYER_TYPE_H

#include <map>
#include <set>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

namespace protolayer
{

namespace ontology
{

// Forward declarations
class Ontology;

/**
 * @prototype serialise persist
 */
class Type : public util::Object
{
public:
  /** TODO: Documentation */
  friend class Ontology;

  /** TODO: Documentation */
  typedef util::SetIterator <Type> IteratorType;

private:
  /** TODO: Documentation */
  mutable bool _tag;

  /** TODO: Documentation */
  bool _isLeaf;

  /** TODO: Documentation */
  bool _isAbstract;

  /** TODO: Documentation */
  bool _isSingleton;

  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _domainId;

  /** TODO: Documentation */
  std::string _name;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  //  Type(std::string& scope,
  //       xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Type(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Type(ontologydto::TypeDTO& typeDTO);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Type();

  /**
   * TODO: Documentation
   * <p>
   */
  int getId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getDomainId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getName() const;

  /**
   * Todo: Documentation
   * <p>
   */
  bool isLeaf() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isAbstract() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSingleton() const;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Type(const Type& type);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Type& operator=(const Type& type);

};


}


}


#endif // PROTOLAYER_TYPE_H
