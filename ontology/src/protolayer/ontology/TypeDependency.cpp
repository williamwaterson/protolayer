#include "TypeDependency.h"


namespace protolayer
{

namespace ontology
{

TypeDependency::TypeDependency(Type& fromType, Type& toType) :
  _tag(false), _fromType(&fromType), _toType(&toType)
{
}


TypeDependency::TypeDependency(iostream::XdrInputStream& stream,
                               std::map <int, void*>& addressMappings)
{
  int id;

  stream.read(id);
  _fromType = reinterpret_cast <Type*> (addressMappings[id]);

  stream.read(id);
  _toType = reinterpret_cast <Type*> (addressMappings[id]);
}


TypeDependency::~TypeDependency()
{
}


void TypeDependency::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) _fromType);
  stream.write((int) _toType);
}


Type& TypeDependency::getFromType()
{
  return *_fromType;
}


Type& TypeDependency::getToType()
{
  return *_toType;
}


bool TypeDependency::isFromType(Type& instance)
{
  return _fromType == &instance;
}


bool TypeDependency::isToType(Type& instance)
{
  return _toType == &instance;
}


}


}
