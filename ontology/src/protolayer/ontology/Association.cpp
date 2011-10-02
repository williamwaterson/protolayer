#include "Association.h"


namespace protolayer
{

namespace ontology
{

Association::Association(ontologydto::AssociationDTO& dto,
			 std::map <int, Type*>& typeDictionary) :
  _tag(false)
{
  _id = dto.getId();
  _name = dto.getName();

  std::cout << dto.getFromEnd().getTypeName() << " " << dto.getToEnd().getTypeName() << std::endl;

  _fromEnd = new End(dto.getFromEnd(), typeDictionary);
  _toEnd = new End(dto.getToEnd(), typeDictionary);

  std::cout << _fromEnd->getType().getName() << " " << _toEnd->getType().getName() << std::endl;

  if (&(_toEnd->getType()) == &(_fromEnd->getType())) {
    throw Exception("Identical types specified for association ends.");
  }
}


Association::~Association()
{
  delete _fromEnd;
  delete _toEnd;
}


bool Association::isName(const std::string& name) const
{
  return _name == name;
}


int Association::getId() const
{
  return _id;
}


const std::string& Association::getName() const
{
  return _name;
}


End& Association::getFromEnd()
{
  return *_fromEnd;
}


End& Association::getToEnd()
{
  return *_toEnd;
}


bool Association::isFromEnd(End& end)
{
  return _fromEnd == &end;
}


bool Association::isFromType(Type& type)
{
  return _fromEnd->isType(type);
}


bool Association::isToEnd(End& end)
{
  return _toEnd == &end;
}


bool Association::isToType(Type& type)
{
  return _toEnd->isType(type);
}


bool Association::involves(End& end)
{
  return involves(end.getType());
}


bool Association::involves(Type& type)
{
  return isFromType(type) || isToType(type);
}


bool Association::involves(Type& someType, Type& anotherType)
{
  return matches(someType, anotherType) || matches(anotherType, someType);
}


bool Association::involves(End& someEnd, End& anotherEnd)
{
  return matches(someEnd, anotherEnd) || matches(anotherEnd, someEnd);
}


bool Association::matches(Type& fromType, Type& toType)
{
  return isFromType(fromType) && isToType(toType);
}


bool Association::matches(End& fromEnd, End& toEnd)
{
  return isFromEnd(fromEnd) && isToEnd(toEnd);
}


bool Association::isEquivalent(Association& association)
{
  return matches(association.getFromEnd().getType(),
                 association.getToEnd().getType());
}


bool Association::isReverse(Association& association)
{
  return matches(association.getToEnd().getType(),
                 association.getFromEnd().getType());
}


bool Association::isSimilar(Association& association)
{
  return isEquivalent(association) || isReverse(association);
}


}


}
