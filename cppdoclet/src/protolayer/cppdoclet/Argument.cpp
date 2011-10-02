#include "Argument.h"


namespace protolayer
{

namespace cppdoclet
{

Argument::Argument(const std::string& signature)
{
  _signature = util::trim(signature);

  //  std::size_t position = _signature.find(";");
  //  if (position != std::string::npos) {
  //    _signature.erase(position);
  //  }

  _signature = util::trim(_signature);

  std::size_t last = _signature.find_last_of("\t\n\r ");
  std::string typeName = util::trim(_signature.substr(0, last));
  std::string _name = util::trim(_signature.substr(last));

  _type = new Type(typeName);
  _type->setScope(_type->getName(), *this);
  getEncapsulatedScopes()[_type->getName()] = _type;
  _type->setType("type");
}


void Argument::backtrack()
{
  if (_type != 0) {
    _type->backtrack();
  }  
}


const std::string& Argument::getName() const
{
  return _name;
}


const Type& Argument::getType() const
{
  return *_type;
}


void Argument::propagateScope(const std::string& scope)
{
  _scope = scope;

  if (_type != 0) {
    _type->propagateScope(scope);
  }
}


void Argument::propagateClasses(const std::map <std::string, Class*>& classes)
{
  int count = 0;
  std::string scopedName;

  if (_type != 0) {
    _type->propagateClasses(classes);
  }
}


void Argument::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
}


}


}
