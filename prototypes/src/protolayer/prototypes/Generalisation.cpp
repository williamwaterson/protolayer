#include "Generalisation.h"


namespace protolayer
{

namespace ontology
{

Generalisation::Generalisation(ontologydto::GeneralisationDTO& dto,
			       std::map <int, Type*>& typeDictionary)
{
  _id = dto.getId();
  _superTypeId = dto.getSuperTypeId();
  _superTypeDomainId = dto.getSuperTypeDomainId();
  _superTypeName = dto.getSuperTypeName();
  _subTypeId = dto.getSubTypeId();
  _subTypeDomainId = dto.getSubTypeDomainId();
  _subTypeName = dto.getSubTypeName();

  int id = dto.getSubTypeId();
  if (typeDictionary.count(id) == 1) {
    _subType = typeDictionary[id];
  } else {
    throw Exception("Generalisation supertype specifies an undefined type " + id);
  }

  id = dto.getSuperTypeId();
  if (typeDictionary.count(id) == 1) {
    _superType = typeDictionary[id];
  } else {
    throw Exception("Generalisation subtype specifies an undefined type " + id);
  }
}


Generalisation::~Generalisation()
{
}


int Generalisation::getId() const
{
  return _id;
}


int Generalisation::getSuperTypeId() const
{
  return _superTypeId;
}


int Generalisation::getSuperTypeDomainId() const
{
  return _superTypeDomainId;
}


std::string Generalisation::getSuperTypeName() const
{
  return _superTypeName;
}


int Generalisation::getSubTypeId() const
{
  return _subTypeId;
}


int Generalisation::getSubTypeDomainId() const
{
  return _subTypeDomainId;
}


std::string Generalisation::getSubTypeName() const
{
  return _subTypeName;
}


Type& Generalisation::getSubType()
{
  return *_subType;
}


Type& Generalisation::getSuperType()
{
  return *_superType;
}


bool Generalisation::isSuperType(Type& type)
{
  return _superType == &type;
}


bool Generalisation::isSubType(Type& type)
{
  return _subType == &type;
}


bool Generalisation::involves(Type& type)
{
  return isSubType(type) || isSuperType(type);
}


bool Generalisation::involves(Type& someType, Type& anotherType)
{
  return matches(someType, anotherType) || matches(anotherType, someType);
}


bool Generalisation::matches(Type& superType, Type& subType)
{
  return isSuperType(superType) && isSubType(subType);
}


bool Generalisation::isEquivalent(Generalisation& gen)
{
  return isSuperType(gen.getSuperType()) && isSubType(gen.getSubType());
}


bool Generalisation::isReverse(Generalisation& gen)
{
  return isSuperType(gen.getSubType()) && isSubType(gen.getSuperType());
}


bool Generalisation::isSimilar(Generalisation& gen)
{
  return isEquivalent(gen) || isReverse(gen);
}


}


}
