#include "Domain.h"


namespace protolayer
{

namespace ontology
{

Domain::Domain(ontologydto::DomainDTO& dto)
  throw (Exception)
{
  _id = dto.getId();
  _title = dto.getTitle();
  _description = dto.getDescription();

  typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
  for (IterType iter = dto.getTypes().begin(); iter != dto.getTypes().end(); iter++) {
    Type* type = new Type(**iter);
    _types[type->getName()] = type;
  }
}


Domain::~Domain()
{
}


int Domain::getId() const
{
  return _id;
}


int Domain::getNumberTypes() const
{
  return _types.size();
}


Domain::IteratorType Domain::getTypes()
{
  return IteratorType(_types);
}


const std::string& Domain::getTitle() const
{
  return _title;
}


const std::string& Domain::getDescription() const
{
  return _description;
}


Type* Domain::getTypeByUnscopedName(const std::string& unscopedName)
{
  std::map <std::string, Type*>::const_iterator found = _types.find(unscopedName);
  Type* result = 0;
  if (found != _types.end()) {
    result = found->second;
  }
  return result;
}


Type* Domain::getTypeByUnscopedName(char* unscopedName)
{
  std::string nameStr(unscopedName);
  std::map <std::string, Type*>::iterator found = _types.find(nameStr);
  Type* result = 0;
  if (found != _types.end()) {
    result = found->second;
  }
  return result;
}


bool Domain::contains(const Type& type)
{
  // Work around const returned string we know will never get moded in getType
  return getTypeByUnscopedName(const_cast <std::string&> (type.getName())) == &type;
}


}


}
