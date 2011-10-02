#include "DomainDependency.h"


namespace protolayer
{

namespace ontology
{

DomainDependency::DomainDependency(Domain& fromDomain, Domain& toDomain) :
  _tag(false), _fromDomain(&fromDomain), _toDomain(&toDomain)
{
}


DomainDependency::DomainDependency(iostream::XdrInputStream& stream,
                                   std::map <int, void*>& addressMappings)
{
  int id;

  stream.read(id);
  _fromDomain = reinterpret_cast <Domain*> (addressMappings[id]);

  stream.read(id);
  _toDomain = reinterpret_cast <Domain*> (addressMappings[id]);  
}


DomainDependency::~DomainDependency()
{
}


void DomainDependency::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) _fromDomain);
  stream.write((int) _toDomain);
}


Domain& DomainDependency::getFromDomain()
{
  return *_fromDomain;
}


Domain& DomainDependency::getToDomain()
{
  return *_toDomain;
}


bool DomainDependency::isFromDomain(Domain& instance)
{
  return _fromDomain == &instance;
}


bool DomainDependency::isToDomain(Domain& instance)
{
  return _toDomain == &instance;
}


}


}
