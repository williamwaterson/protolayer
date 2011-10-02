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


void Scope::serialise(std::string& output, const std::string& componentName)
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


Scope* Scope::recursiveFind(const std::string& name)
{
  Scope* result = find(name);

  if (result == 0) {
    typedef std::map <std::string, Scope*>::iterator IterType;
    for (IterType iter = _encapsulatedScopes.begin(); iter != _encapsulatedScopes.end(); iter++) {      
      result = iter->second->recursiveFind(name);
      if (result != 0) {
	break;
      }
    }
  }

  return result;
}


Scope* Scope::find(const std::string& name)
{
  Scope* result = 0;

  typedef std::map <std::string, Scope*>::iterator IterType;

  if (isScoped(name)) {
    std::string scopeName = getTopScope(name);
    if (_encapsulatedScopes.count(scopeName) > 0) {
      Scope* scope = _encapsulatedScopes[scopeName];
      std::string remainingName = getRemainingScope(name);
      result = scope->find(remainingName);
    }

  } else {
    for (IterType iter = _encapsulatedScopes.begin(); iter != _encapsulatedScopes.end(); iter++) {
      if (iter->first == name) {
	result = iter->second;
	break;
      }
    }

  }

  return result;
}


Scope* Scope::reverseFind(const std::string& name)
{
  Scope* result = recursiveFind(name);

  if (result == 0 && hasParent()) {
    result = _parent->reverseFind(name);
  }

  return result;
}


Scope* Scope::forwardFind(const std::string& name)
{
  Scope* result = 0;

  if (hasParent()) {
    result = _parent->forwardFind(name);
  }

  if (result == 0) {
    result = find(name);
  }

  return result;
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


bool Scope::hasParent() const
{
  return _parent != 0;
}


std::map <std::string, Scope*>& Scope::getEncapsulatedScopes()
{
  return _encapsulatedScopes;
}


}


}
