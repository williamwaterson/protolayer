#ifndef PROTOLAYER_DOMAIN_H
#define PROTOLAYER_DOMAIN_H

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

#include "Exception.h"
#include "Type.h"


namespace protolayer
{

namespace ontology
{

// Forward declarations
class Ontology;

/**
 * @prototype serialise persist
 */
class Domain : public util::Object
{
public:
  /** TODO: Documentation */
  friend class Ontology;

  /** TODO: Documentation */
  typedef util::MapIterator <std::string, Type> IteratorType;

private:
  /** The name of this domain */  
  mutable bool _tag;

  /** @persistid */
  int _id;

  /** Title of the domain */
  std::string _title;

  /** The name of this domain */  
  std::string _scope;

  /** The set of keywords for this domain */
  std::string _description;

  /** The set of types owned by this domain */
  std::map <std::string, Type*> _types;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Domain(ontologydto::DomainDTO& dto)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Domain();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTypes() const;

  /**
   * TODO: Improve
   * <p>
   */
  Type* getTypeById(int typeId);

  /**
   * TODO: Improve
   * <p>
   */
  Type* getTypeById(const std::string& typeId);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeByUnscopedName(const std::string& unscopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeByUnscopedName(char* unscopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getTypes();

  /**
   * TODO: Documentation
   * <p>
   */
  int getId() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getTitle() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getDescription() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(const Type& type);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Domain(const Domain& domain);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Domain& operator=(const Domain& domain);

};


}


}


#endif // PROTOLAYER_DOMAIN_H
