
#include "Ontology.h"
#include <iostream.h>

namespace protolayer
{

namespace ontology
{

Ontology::Ontology(ontologydto::DomainDTO& dto)
{
  std::set <ontologydto::DomainDTO*> dtos;
  dtos.insert(&dto);

  initialise(dtos);
}


Ontology::Ontology(std::set <ontologydto::DomainDTO*>& dtos)
{
  extractDomains(dtos);
  extractAssociations(dtos);
  extractGeneralisations(dtos);
  extractDependencies();

  detectMultipleTypeOwnership();

  if (getNumberDomains() == 0) {
    throw Exception("Ontology contains no domains.");
  }

  if (hasCyclicDomainDependencies()) {
    throw Exception("Ontology contains cyclic domain dependencies.");
  }

  if (hasCyclicTypeDependencies()) {
    throw Exception("Ontology contains cyclic type dependencies.");
  }

  identifyStructure();
}


void Ontology::extractDomains(std::set <ontologydto::DomainDTO*>& dtos)
  throw (Exception)
{
  // Ensure domain DTOs have unique name set
  std::set <int> domainIds;

  std::cout << "dtos.size() " << dtos.size() << std::endl;

  typedef std::set <ontologydto::DomainDTO*>::iterator IterType;
  for (IterType iter = dtos.begin(); iter != dtos.end(); iter++) {
    ontologydto::DomainDTO& domainDTO = **iter;

    int domainId = domainDTO.getId();

    // Note: we now permit at least one zero domainId for domains yet to be persisted
    // into the backend. Note this is only ever one in the supplied set of DTOs
    //    if (domainId == 0) {
    //      throw Exception("One or more Domains have an unspecified name");
    //    }

    std::string domainStringId = util::itoa(domainId);
    if (domainDTO.getTypes().size() == 0) {
      throw Exception("Invalid Domain " + domainStringId + " has no defined types");
    }
    
    domainIds.insert(domainId);
  }

  if (domainIds.size() != dtos.size()) {
    throw Exception("Domains in specified set have duplicate names");
  }

  // Construct data model instances graph from DTOs
  typedef std::set <ontologydto::DomainDTO*>::iterator IterType;
  for (IterType iter = dtos.begin(); iter != dtos.end(); iter++) {
    ontologydto::DomainDTO& domainDTO = **iter;
    ontology::Domain* domain = new Domain(domainDTO);
    _domainDictionary[domain->getId()] = domain;
    for (Domain::IteratorType typeIter = domain->getTypes(); typeIter.hasNext(); ) {
      Type& type = typeIter.next();
      std::cout << type.getId() << " " << &type << std::endl;
      _typeDictionary[type.getId()] = &type;
    }    
  }
}


void Ontology::extractAssociations(std::set <ontologydto::DomainDTO*>& dtos)
  throw (Exception)
{
  typedef std::set <ontologydto::DomainDTO*>::iterator IterType;

  for (IterType iter = dtos.begin(); iter != dtos.end(); iter++) {
    std::set <ontologydto::AssociationDTO*>& assocs = (*iter)->getAssociations(); 
    typedef std::set <ontologydto::AssociationDTO*>::iterator AssocIterType;
    for (AssocIterType assocIter = assocs.begin(); assocIter != assocs.end(); assocIter++) {
      ontologydto::AssociationDTO* assocDTO = *assocIter;
      Association* assoc = new Association(*assocDTO, _typeDictionary);
      _associations.insert(assoc);
      typedef std::pair <int, Association*> KeyValueType;
      _associationDictionary.insert(KeyValueType(assoc->getId(), assoc));
    }
  }

  AssociationIteratorType assocIter;
  AssociationIteratorType compareIter;
  for (assocIter = getAssociations(); assocIter.hasNext(); ) {
    Association& assoc = assocIter.next();
    for (compareIter = getAssociations(); compareIter.hasNext(); ) {
      Association& compAssoc = compareIter.next();
      if (&compAssoc != &assoc &&
	  compAssoc.isSimilar(assoc) &&
	  assoc.getName() == compAssoc.getName()) {
        throw Exception("Duplicate similar associations present.");
      }
    }
  }
}


void Ontology::extractGeneralisations(std::set <ontologydto::DomainDTO*>& dtos)
  throw (Exception)
{
  typedef std::set <ontologydto::DomainDTO*>::iterator IterType;
  
  for (IterType iter = dtos.begin(); iter != dtos.end(); iter++) {
    std::set <ontologydto::GeneralisationDTO*>& genDTOs = (*iter)->getGeneralisations(); 
    typedef std::set <ontologydto::GeneralisationDTO*>::iterator GenIterType;
    for (GenIterType genIter = genDTOs.begin(); genIter != genDTOs.end(); genIter++) {
      ontologydto::GeneralisationDTO* genDTO = *genIter;
      Generalisation* gen = new Generalisation(*genDTO, _typeDictionary);
      _generalisations.insert(gen);
    }
  }

  GeneralisationIteratorType genIter;
  GeneralisationIteratorType compareIter;
  for (genIter = getGeneralisations(); genIter.hasNext(); ) {
    Generalisation& gen = genIter.next();
    for (compareIter = getGeneralisations(); compareIter.hasNext(); ) {
      Generalisation& compGen = compareIter.next();
      if (&compGen != &gen && compGen.isSimilar(gen)) {
        throw Exception("Duplicate similar generalisations present.");
      }
    }
  }
}


void Ontology::initialise(std::set <ontologydto::DomainDTO*>& dtos)
  throw (Exception)
{
  extractDomains(dtos);
  extractAssociations(dtos);
  extractGeneralisations(dtos);
  extractDependencies();

  detectMultipleTypeOwnership();

  if (getNumberDomains() == 0) {
    throw Exception("Ontology contains no domains.");
  }

  if (hasCyclicDomainDependencies()) {
    throw Exception("Ontology contains cyclic domain dependencies.");
  }

  if (hasCyclicTypeDependencies()) {
    throw Exception("Ontology contains cyclic type dependencies.");
  }

  identifyStructure();
}


Ontology::~Ontology()
{
}


int Ontology::getNumberDomains()
{
  return _domainDictionary.size();
}


int Ontology::getNumberTypes()
{
  return _typeDictionary.size();
}


int Ontology::getNumberAssociations()
{
  return _associations.size();
}


int Ontology::getNumberGeneralisations()
{
  return _generalisations.size();
}


int Ontology::getNumberTypeDependencies()
{
  return _typeDependencies.size();
}


int Ontology::getNumberDomainDependencies()
{
  return _domainDependencies.size();
}

 
Domain* Ontology::getDomainById(const std::string& name)
{
  int domainId = atoi(name.c_str());
  std::map <int, Domain*>::iterator found = _domainDictionary.find(domainId);
  Domain* result = 0;
  if (found != _domainDictionary.end()) {
    result = found->second;
  }
  return result;  
}


Domain* Ontology::getDomainById(int id)
{
  std::map <int, Domain*>::iterator found = _domainDictionary.find(id);
  Domain* result = 0;
  if (found != _domainDictionary.end()) {
    result = found->second;
  }
  return result; 
}


Domain* Ontology::getDomain(Type& type)
{
  Domain* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    if (domain.contains(type)) {
      result = &domain;
    }
  }
  return result;
}


Type* Ontology::getTypeByScopedName(const std::string& scopedName)
{
  if (naming::isValidName(scopedName)) {
    throw Exception("Invalid scoped name supplied");
  }

  int domainId = naming::getScopeId(scopedName);

  Type* result = 0;
  if (_domainDictionary.count(domainId) != 0) {
    throw Exception("Specified scope does not match loaded domains");
  } else {
    Domain* domain = _domainDictionary[domainId];
    std::string unscopedName = naming::getUnscopedName(scopedName);
    result = domain->getTypeByUnscopedName(unscopedName);
  }
  return result;
}


Type* Ontology::getTypeByUnscopedName(const std::string& unscopedName)
{
  if (naming::isScoped(unscopedName)) {
    throw Exception("Invalid supplied name. Supplied Name is scoped.");
  }

  Type* result = 0;

  typedef Ontology::DomainIteratorType IterType;
  for (IterType iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    result = domain.getTypeByUnscopedName(unscopedName);
    if (result != 0) {
      break;
    }
  }
  return result;
}


Type* Ontology::getTypeById(const std::string& typeId)
{
  int typeIdInt = atoi(typeId.c_str());
  return getTypeById(typeIdInt);
}


Type* Ontology::getTypeById(int typeId)
{
  std::map <int, Type*>::iterator found = _typeDictionary.find(typeId);
  Type* result = 0;
  if (found != _typeDictionary.end()) {
    result = found->second;
  }
  return result;
}


TypeStack* Ontology::getTypeStack(Domain& domain)
{
  std::map <Domain*, TypeStack*>::iterator found =
    _domainStacks.find(&domain);
  TypeStack* result = 0;
  if (found != _domainStacks.end()) {
    result = found->second;
  }
  return result;
}


bool Ontology::containsDomainById(int domainId)
{
  return getDomainById(domainId) != 0;
}


bool Ontology::containsDomainById(const std::string& domainIdAsString)
{
  return getDomainById(domainIdAsString) != 0;
}


bool Ontology::containsType(const std::string& scopedName)
{
  return getTypeByScopedName(scopedName) != 0;
}


Type* Ontology::getType(char* scopedName)
{
  std::string scopedNameStr(scopedName);
  return getTypeByScopedName(scopedNameStr);
}


bool Ontology::containsDomainById(char* name)
{
  return containsDomainById(name);
}


bool Ontology::containsType(char* scopedName)
{
  std::string scopedNameStr(scopedName);
  return containsType(scopedNameStr);
}


/** TODO: Improve */
bool Ontology::contains(Domain& domain)
{
  int id = domain.getId();
  if (_domainDictionary.count(id) == 1) {
    return getDomainById(id) == &domain;
  }
  return false;
}


bool Ontology::contains(Type& type)
{
  bool result = false;
  typedef Ontology::DomainIteratorType IterType;
  for (IterType iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    if (domain.contains(type)) {
      result = true;
      break;
    }
  }
  return result;
}


bool Ontology::contains(Association& assoc)
{
  return _associations.count(&assoc) != 0;
}


bool Ontology::contains(Generalisation& gen)
{
  return _generalisations.count(&gen) != 0;
}


bool Ontology::contains(TypeDependency& dep)
{
  return _typeDependencies.count(&dep) != 0;
}


bool Ontology::contains(DomainDependency& dep)
{
  return _domainDependencies.count(&dep) != 0;
}


Ontology::DomainIteratorType Ontology::getDomains()
{
  return DomainIteratorType(_domainDictionary);
}


Ontology::TypeIteratorType Ontology::getTypes()
{
  return TypeIteratorType(_typeDictionary);
}


Ontology::AssociationIteratorType Ontology::getAssociations()
{
  return AssociationIteratorType(_associations);
}


std::set <Association*>
Ontology::getAssociations(Type& fromType, Type& toType)
{
  std::set <Association*> result;
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isFromType(fromType) && association.isToType(toType)) {
      result.insert(&association);
    }
  }
  return result;  
}


std::set <Association*>
Ontology::getAssociations(const std::string& fromScopedTypeName,
                          const std::string& toScopedTypeName)
{
  std::set <Association*> result;
  Type* fromType = getTypeByScopedName(fromScopedTypeName);
  Type* toType = getTypeByScopedName(toScopedTypeName);
  if (fromType != 0 && toType != 0) {
    result = getAssociations(*fromType, *toType);
  }
  return result;
}


bool Ontology::associationExists(Type& fromType, Type& toType)
{
  bool result = false;
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isFromType(fromType) && association.isToType(toType)) {
      result = true;
    }
  }
  return result;  
}


std::set <Association*> Ontology::getAssociationsTo(Type& type)
{
  std::set <Association*> result;
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isToType(type)) {
      result.insert(&association);
    }
  }
  return result;
}


std::set <Association*> Ontology::getAssociationsFrom(Type& type)
{
  std::set <Association*> result;
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isFromType(type)) {
      result.insert(&association);
    }
  }
  return result;
}


std::set <Association*>
Ontology::getInDomainAssociationsTo(Type& type)
{
  std::set <Association*> result;
  Domain* inDomain = getDomain(type);
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isToType(type)) {
      Type& fromType = association.getFromEnd().getType();
      if (inDomain == getDomain(fromType)) {
        result.insert(&association);
      }
    }
  }
  return result;
}


std::set <Association*>
Ontology::getInDomainAssociationsFrom(Type& type)
{
  std::set <Association*> result;
  Domain* inDomain = getDomain(type);
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& association = iter.next();
    if (association.isFromType(type)) {
      Type& toType = association.getToEnd().getType();
      if (inDomain == getDomain(toType)) {
        result.insert(&association);
      }
    }
  }
  return result;
}


Ontology::TypeDependencyIteratorType Ontology::getTypeDependencies()
{
  return TypeDependencyIteratorType(_typeDependencies);
}


Ontology::DomainDependencyIteratorType Ontology::getDomainDependencies()
{
  return DomainDependencyIteratorType(_domainDependencies);
}


Ontology::GeneralisationIteratorType Ontology::getGeneralisations()
{
  return GeneralisationIteratorType(_generalisations);
}


void Ontology::extractDependencies()
  throw (Exception)
{
  // Extract explicit type dependencies
  GeneralisationIteratorType genIter;
  for (genIter = getGeneralisations(); genIter.hasNext(); ) {
    Generalisation& gen = genIter.next();
    TypeDependency* dep = new TypeDependency(gen.getSubType(),
                                             gen.getSuperType());
    _typeDependencies.insert(dep);
  }

  AssociationIteratorType assocIter;
  for (assocIter = getAssociations(); assocIter.hasNext(); ) {
    Association& assoc = assocIter.next();
    TypeDependency* dep = new TypeDependency(assoc.getFromEnd().getType(),
                                             assoc.getToEnd().getType());
    _typeDependencies.insert(dep);
  }

  // Extract implicit domain dependencies
  TypeDependencyIteratorType depIter;
  for (depIter = getTypeDependencies(); depIter.hasNext(); ) {
    TypeDependency& dep = depIter.next();
    Type& fromType = dep.getFromType();
    Type& toType = dep.getToType();

    Domain* fromDomain = getDomain(fromType);
    Domain* toDomain = getDomain(toType);

    if (fromDomain != toDomain &&
        !containsDependency(*fromDomain, *toDomain)) {
      DomainDependency* dep = new DomainDependency(*fromDomain, *toDomain);
      _domainDependencies.insert(dep);
    }
  }

}


bool Ontology::containsDependency(Type& fromType, Type& toType)
{
  return getDependency(fromType, toType) != 0;
}


TypeDependency* Ontology::getDependency(Type& fromType, Type& toType)
{
  TypeDependency* result = 0;
  TypeDependencyIteratorType iter;
  for (iter = getTypeDependencies(); iter.hasNext(); ) {
    TypeDependency& dep = iter.next();
    if (dep.isFromType(fromType) && dep.isToType(toType)) {
      result = &dep;
    }
  }
  return result;
}


TypeDependency* Ontology::getTypeDependencyByScopedName(std::string& fromScopedName,
							std::string& toScopedName)
{
  TypeDependency* result = 0;
  Type* fromType = getTypeByScopedName(fromScopedName);
  Type* toType = getTypeByScopedName(toScopedName);
  if (fromType != 0 && toType != 0 && fromType != toType) {
    result = getDependency(*fromType, *toType);
  }
  return result;
}


TypeDependency* Ontology::getTypeDependencyById(int fromTypeId,
						int toTypeId)
{
  TypeDependency* result = 0;
  Type* fromType = getTypeById(fromTypeId);
  Type* toType = getTypeById(toTypeId);
  if (fromType != 0 && toType != 0 && fromType != toType) {
    result = getDependency(*fromType, *toType);
  }
  return result;
}


TypeDependency* Ontology::getTypeDependencyById(std::string& fromTypeId,
						std::string& toTypeId)
{
  TypeDependency* result = 0;
  Type* fromType = getTypeById(fromTypeId);
  Type* toType = getTypeById(toTypeId);
  if (fromType != 0 && toType != 0 && fromType != toType) {
    result = getDependency(*fromType, *toType);
  }
  return result;
}


TypeDependency* Ontology::getTypeDependencyByScopedName(char* fromScopedName,
							char* toScopedName)
{
  TypeDependency* result = 0;
  Type* fromType = getTypeByScopedName(fromScopedName);
  Type* toType = getTypeByScopedName(toScopedName);
  if (fromType != 0 && toType != 0 && fromType != toType) {
    result = getDependency(*fromType, *toType);
  }
  return result;
}


bool Ontology::containsTypeDependency(std::string& fromScopedName,
                                      std::string& toScopedName)
{
  return getTypeDependencyByScopedName(fromScopedName, toScopedName) != 0;
}


bool Ontology::containsDependency(Domain& fromDomain, Domain& toDomain)
{
  return getDependency(fromDomain, toDomain) != 0;
}


DomainDependency* Ontology::getDomainDependency(int fromDomainId,
                                                int toDomainId)
{
  DomainDependency* result = 0;
  Domain* fromDomain = getDomainById(fromDomainId);
  Domain* toDomain = getDomainById(toDomainId);
  if (fromDomain != 0 && toDomain != 0 && fromDomain != toDomain) {
    result = getDependency(*fromDomain, *toDomain);
  }
  return result;
}


DomainDependency* Ontology::getDomainDependency(std::string& fromName,
                                                std::string& toName)
{
  DomainDependency* result = 0;
  Domain* fromDomain = getDomainById(fromName);
  Domain* toDomain = getDomainById(toName);
  if (fromDomain != 0 && toDomain != 0 && fromDomain != toDomain) {
    result = getDependency(*fromDomain, *toDomain);
  }
  return result;
}


bool Ontology::containsDomainDependency(std::string& fromName,
                                        std::string& toName)
{
  return getDomainDependency(fromName, toName) != 0;
}


DomainDependency* Ontology::getDependency(Domain& fromDomain, Domain& toDomain)
{
  DomainDependency* result = 0;
  DomainDependencyIteratorType iter;
  for (iter = getDomainDependencies(); iter.hasNext(); ) {
    DomainDependency& dep = iter.next();
    if (dep.isFromDomain(fromDomain) && dep.isToDomain(toDomain)) {
      result = &dep;
    }
  }
  return result;
}


DomainDependency* Ontology::getDomainDependency(Domain& fromDomain, Domain& toDomain)
{
  return getDependency(fromDomain, toDomain);
}


void Ontology::resetTypeFlags()
{
  DomainIteratorType domainIter;
  for (domainIter = getDomains(); domainIter.hasNext(); ) {
    Domain& domain = domainIter.next();
    Domain::IteratorType typeIter;
    for (typeIter = domain.getTypes(); typeIter.hasNext(); ) {
      Type& type = typeIter.next();
      type._tag = false;
    }
  }
}


void Ontology::resetDomainFlags()
{
  DomainIteratorType iterator;
  for (iterator = getDomains(); iterator.hasNext(); ) {
    Domain& domain = iterator.next();
    domain._tag = false;
  }    
}


void Ontology::resetAssociationFlags()
{
  AssociationIteratorType iterator;
  for (iterator = getAssociations(); iterator.hasNext(); ) {
    Association& association = iterator.next();
    association._tag = false;
  }    
}


void Ontology::resetGeneralisationFlags()
{
  GeneralisationIteratorType iterator;
  for (iterator = getGeneralisations(); iterator.hasNext(); ) {
    Generalisation& generalisation = iterator.next();
    generalisation._tag = false;
  }    
}


void Ontology::resetDomainDependencyFlags()
{
  DomainDependencyIteratorType iterator;
  for (iterator = getDomainDependencies(); iterator.hasNext(); ) {
    DomainDependency& dependency = iterator.next();
    dependency._tag = false;
  }    
}


void Ontology::resetTypeDependencyFlags()
{
  TypeDependencyIteratorType iterator;
  for (iterator = getTypeDependencies(); iterator.hasNext(); ) {
    TypeDependency& dependency = iterator.next();
    dependency._tag = false;
  }    
}


void Ontology::detectMultipleTypeOwnership()
  throw (Exception)
{
  bool result = true;
  TypeIteratorType iter;
  for (iter = getTypes(); iter.hasNext(); ) {
    Type& type = iter.next();
    int count = 0;
    std::set <Association*> associations(getAssociationsTo(type));
    std::set <Association*>::iterator assocIter;
    std::set <Association*>::iterator end = associations.end();
    for (assocIter = associations.begin(); assocIter != end; assocIter++) {
      Association* assoc = *assocIter;
      if (assoc->getFromEnd().getLowerBound() > 0) {
        count++;
      }
    }

    if (count > 1) {
      std::string message("Instances of type ");
      message += type.getName();
      message += " owned by more than one type.";
      throw Exception(message);
    }
  }
}


bool Ontology::isOwned(Type& type)
{
  bool result = false;
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& assoc = iter.next();
    Type& toType = assoc.getToEnd().getType();
    if (&toType == &type) {
      int fromLowerBound =
        assoc.getFromEnd().getLowerBound();
      if (fromLowerBound != 0) {
        result = true;
        break;
      }
    }
  }
  return result;
}


bool Ontology::isOwnedInDomain(Type& type)
{
  bool result = false;
  Domain* inDomain = getDomain(type);
  AssociationIteratorType iter;
  for (iter = getAssociations(); iter.hasNext(); ) {
    Association& assoc = iter.next();
    Type& toType = assoc.getToEnd().getType();
    if (&toType == &type) {
      Type& fromType = assoc.getFromEnd().getType();
      Domain* fromDomain = getDomain(fromType);
      int fromLowerBound = assoc.getFromEnd().getLowerBound();
      if (fromDomain == inDomain && fromLowerBound != 0) {
        result = true;
        break;
      }
    }
  }
  return result;
}


bool Ontology::isToType(Type& toType, std::set <Type*>& fromTypes)
{
  bool result = false;
  std::set <Type*>::iterator iter;
  for (iter = fromTypes.begin(); iter != fromTypes.end(); ++iter) {
    Type& fromType = **iter;
    if (associationExists(fromType, toType)) {
      result = true;
      break;
    }
  }
  return result;
}


void Ontology::identifyStructure()
{
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    identifyStructure(domain);
  }
}


void Ontology::identifyStructure(Domain& domain)
{
  std::set <Type*> domainTypes;
  Domain::IteratorType typeIter;
  for (typeIter = domain.getTypes(); typeIter.hasNext(); ) {
    Type& type = typeIter.next();
    domainTypes.insert(&type);
  }

  std::set <Type*> types = getTopTypes(domainTypes);
  if (types.size() == 0) {
    throw Exception("There are no types to identify the layers.");
  }

  std::vector <TypeLayer*> topDownLayers;
  while (types.size() != 0) {
    TypeLayer* layer = new TypeLayer(types);
    topDownLayers.push_back(layer);
    std::set <Type*>::iterator iter;
    for (iter = types.begin(); iter != types.end(); ++iter) {
      domainTypes.erase(*iter);
    }
    types = getTopTypes(domainTypes);
  }

  TypeStack* stack = new TypeStack(topDownLayers);
  _domainStacks[&domain] = stack;
}


std::set <Type*> Ontology::getTopTypes(std::set <Type*>& types)
{
  std::set <Type*> result;
  std::set <Type*>::iterator iter;
  for (iter = types.begin(); iter != types.end(); iter++) {
    Type* type = *iter;
    if (!isToType(*type, types)) {
      result.insert(type);
    }
  }
  return result;
}


//void detectOrphanedTypes()
//void Ontology::detectMultipleInheritance()
//{
//}


//Type& Ontology::getSuperType()
//{
//}


//Type& Ontology::getRootSuperType()
//{
//}


bool Ontology::hasCyclicDomainDependencies()
{
  // Select current domain and commence walk of outbound dependencies
  DomainIteratorType iterator;
  for (iterator = getDomains(); iterator.hasNext(); ) {
    resetDomainFlags();
    resetDomainDependencyFlags();

    Domain& current = iterator.next();
    stepDependencies(current);
    if (current._tag) {
      resetDomainFlags();
      resetDomainDependencyFlags();
      return true;
    }
  }

  resetDomainFlags();
  resetDomainDependencyFlags();
  return false;
}


bool Ontology::hasCyclicTypeDependencies()
{
  // Select current type and commence walk of outbound dependencies
  TypeIteratorType typeIter;
  for (typeIter = getTypes(); typeIter.hasNext(); ) {
    resetTypeFlags();
    resetTypeDependencyFlags();

    Type& current = typeIter.next();
    stepDependencies(current);
    if (current._tag) {
      resetTypeFlags();
      resetTypeDependencyFlags();
      return true;
    }
  }

  resetTypeFlags();
  resetTypeDependencyFlags();
  return false;
}


void Ontology::stepDependencies(Domain& current)
{
  DomainDependencyIteratorType iterator;
  for (iterator = getDomainDependencies(); iterator.hasNext(); ) {
    DomainDependency& dependency = iterator.next();
    if (!dependency._tag && dependency.isFromDomain(current)) {
      Domain& toDomain = dependency.getToDomain();
      toDomain._tag = true;
      dependency._tag = true;
      stepDependencies(toDomain);
    }
  }
}


void Ontology::stepDependencies(Type& current)
{
  TypeDependencyIteratorType iterator;
  for (iterator = getTypeDependencies(); iterator.hasNext(); ) {
    TypeDependency& dependency = iterator.next();
    if (!dependency._tag && dependency.isFromType(current)) {
      Type& toType = dependency.getToType();
      toType._tag = true;
      dependency._tag = true;
      stepDependencies(toType);
    }
  }
}


/**
 * TODO: Documentation
 *
 */
//public boolean participates(Type type)
//{
// return participatesInAssociation(type) ||
//  participatesInGeneralisation(type);
//}

/**
 * TODO: Documentation
 *
 */
//public boolean participatesInGeneralisation(Type type)
//{
// for (Iterator iter = m_generalisations.iterator(); iter.hasNext(); ) {
//  Generalisation generalisation = (Generalisation) iter.next();
//  if (generalisation.involves(type)) {
//    return true;
//  }
//}
//return false;
//}

/**
 * TODO: Documentation
 *
 */
//public boolean participatesInAssociation(Type type)
//{
// for (Iterator iter = m_associations.iterator(); iter.hasNext(); ) {
//  Association association = (Association) iter.next();
//  if (association.involves(type)) {
//    return true;
//  }
//}
//return false;
//}

/**
 * TODO: Documentation
 *
 */
//public boolean participates(Domain domain)
//{
//if (!contains(domain)) {
//  return false;
//}

//for (Iterator iter = domain.getTypes(); iter.hasNext(); ) {
//  Type type = (Type) iter.next();
//  if (participates(type)) {
//    return true;
//  }
//}
//return false;
//}

}


}
