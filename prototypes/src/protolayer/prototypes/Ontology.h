#ifndef PROTOLAYER_ONTOLOGY_ONTOLOGY_H
#define PROTOLAYER_ONTOLOGY_ONTOLOGY_H

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-naming.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "Association.h"
#include "Domain.h"
#include "DomainDependency.h"
#include "Generalisation.h"
#include "Exception.h"
#include "Type.h"
#include "TypeDependency.h"
#include "TypeLayer.h"
#include "TypeStack.h"


namespace protolayer
{

namespace ontology
{

class Ontology
{
public:
  /** TODO: Documentation */
  typedef util::MapIterator <int, Type> TypeIteratorType;

  /** TODO: Documentation */
  typedef util::MapIterator <int, Domain> DomainIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Generalisation> GeneralisationIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Association> AssociationIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <TypeDependency> TypeDependencyIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <DomainDependency> DomainDependencyIteratorType;

private:
  /** TODO: Documentation */
  std::map <int, Type*> _typeDictionary;

  /** TODO: Documentation */
  std::map <int, Domain*> _domainDictionary;

  /** TODO: Documentation */
  std::multimap <int, Association*> _associationDictionary;

  /** TODO: Documentation */
  std::set <Generalisation*> _generalisations;

  /** TODO: Documentation */
  std::set <Association*> _associations;

  /** TODO: Documentation */
  std::set <TypeDependency*> _typeDependencies;

  /** TODO: Documentation */
  std::set <DomainDependency*> _domainDependencies;

  /** TODO: Documentation */
  std::map <Domain*, TypeStack*> _domainStacks;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Ontology(ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  explicit Ontology(std::set <ontologydto::DomainDTO*>& dtos);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Ontology();

  /**
   * TODO: Documentation
   *
   */
  int getNumberDomains();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTypes();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberAssociations();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberGeneralisations();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTypeDependencies();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberDomainDependencies();

  /**
   * TODO: Documentation
   *
   */
  DomainIteratorType getDomains();

  /**
   * TODO: Documentation
   * <p>
   */
  TypeIteratorType getTypes();

  /**
   * TODO: Documentation
   * <p>
   */
  AssociationIteratorType getAssociations();

  /**
   * TODO: Documentation
   * <p>
   */
  bool associationExists(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getAssociations(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getAssociations(const std::string& fromScopedTypeName,
                                          const std::string& toScopedTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getAssociationsTo(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getAssociationsFrom(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getInDomainAssociationsTo(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <Association*> getInDomainAssociationsFrom(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  GeneralisationIteratorType getGeneralisations();

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependencyIteratorType getTypeDependencies();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependencyIteratorType getDomainDependencies();

  /**
   * TODO: Documentation
   * <p>
   */
  Domain* getDomainById(int domainId);
  
  /**
   * TODO: Documentation
   * <p>
   */
  Domain* getDomainById(const std::string& domainId);

  /**
   * TODO: Documentation
   * <p>
   */
  Domain* getDomain(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeById(int typeId);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeById(const std::string& typeId);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeByScopedName(const std::string& scopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getTypeByUnscopedName(const std::string& unscopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeStack* getTypeStack(Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDomainById(int domainId);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDomainById(const std::string& domainId);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsType(const std::string& scopedMame);

  /**
   * TODO: Documentation
   * <p>
   */
  Type* getType(char* scopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDomainById(char* name);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsType(char* scopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Association& assoc);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Generalisation& gen);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(TypeDependency& dep);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(DomainDependency& dep);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDependency(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency* getDependency(Type& fromType, Type& toType);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency* getTypeDependencyByScopedName(char* fromScopedName,
						char* toScopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency* getTypeDependencyByScopedName(std::string& fromScopedName,
						std::string& toScopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency* getTypeDependencyById(int fromTypeId,
					int toTypeId);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeDependency* getTypeDependencyById(std::string& fromTypeId,
					std::string& toTypeId);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsTypeDependency(std::string& fromScopedName,
                              std::string& toScopedName);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDependency(Domain& fromDomain, Domain& toDomain);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency* Ontology::getDomainDependency(int fromDomainId,
						  int toDomainId);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency* getDomainDependency(std::string& fromName,
                                        std::string& toName);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency* getDependency(Domain& fromDomain, Domain& toDomain);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency* getDomainDependency(Domain& fromDomain, Domain& toDomain);

  /**
   * TODO: Documentation
   * <p>
   */
  bool containsDomainDependency(std::string& fromName,
                                std::string& toName);

  /**
   * Iterates through the types to check that there are
   * single cases of ownership defined in the set of 
   * associations.
   */
  void detectMultipleTypeOwnership()
    throw (Exception);

  /**
   * Walks the type dependencies to search for cyclic dependencies.
   *
   */
  bool hasCyclicTypeDependencies();

  /**
   * Walks the domain dependencies to search for cyclic dependencies.
   *
   */
  bool hasCyclicDomainDependencies();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Ontology(const Ontology& ontology);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Ontology& operator=(const Ontology& ontology);

  /**
   * TODO: Documentation
   *
   */
  void initialise(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void initialise(std::set <ontologydto::DomainDTO*>& dtos)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractDomains(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractAssociations(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractGeneralisations(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractDependencies(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractDomains(std::set <ontologydto::DomainDTO*>& dtos)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractGeneralisations(std::set <ontologydto::DomainDTO*>& dtos)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractAssociations(std::set <ontologydto::DomainDTO*>& dtos)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void extractDependencies()
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  bool isOwned(Type& type);

  /**
   * TODO: Documentation
   *
   */
  bool isOwnedInDomain(Type& type);

  /**
   * TODO: Documentation
   *
   */
  bool isToType(Type& type, std::set <Type*>& fromTypes);

  /**
   * TODO: Documentation
   *
   */
  void resetTypeFlags();

  /**
   * TODO: Documentation
   *
   */
  std::set <Type*> getTopTypes(std::set <Type*>& types);

  /**
   * Reset flag for all domains.
   *
   */
  void resetDomainFlags();

  /**
   * TODO: Documentation
   *
   */
  void resetAssociationFlags();

  /**
   * TODO: Documentation
   *
   */
  void resetGeneralisationFlags();

  /**
   * Reset flag for all domains
   *
   */
  void resetDomainDependencyFlags();

  /**
   * Reset flag for all types
   *
   */
  void resetTypeDependencyFlags();

  /**
   * TODO: Documentation
   *
   */
  void stepDependencies(Type& current);

  /**
   * TODO: Documentation
   *
   */
  void stepDependencies(Domain& current);

  /**
   * TODO: Documentation
   *
   */
  void identifyStructure();

  /**
   * TODO: Documentation
   *
   */
  void identifyStructure(Domain& domain);

  /**
   * TODO: Documentation
   *
   */
  void decode(iostream::XdrInputStream& stream,
              std::map <int, void*>& addressMappings);

};


}


}


#endif 
