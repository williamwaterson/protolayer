#include "Scope.h"


namespace protolayer
{

namespace cppdoclet
{

Scope::Scope()
{
  _name = "::";
  _parent = 0;
}


Scope::~Scope()
{
}


void Scope::setScope(const std::string& name, Scope& parent)
{
  _name = name;
  _parent = &parent;
  _qualifiedName = parent._name + _name + "::";
}


Scope::Scope(const std::string& name, Scope& parent)
{
  setScope(name, parent);
}


const std::string& Scope::getName() const
{
  return _name;
}


const std::string& Scope::getType() const
{
  return _type;
}


void Scope::setType(const std::string& name)
{
  _type = name;
}


const std::string& Scope::getQualifiedName() const
{
  return _qualifiedName;
}


Scope* Scope::getParent()
{
  return _parent;
}


std::map <std::string, Scope*>& Scope::getEncapsulatedScopes()
{
  return _encapsulatedScopes;
}


}


}
