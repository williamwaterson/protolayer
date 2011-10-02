#include "Typedef.h"


namespace protolayer
{

namespace cppdoclet
{

Typedef::Typedef(const std::string& buffer, const std::string& componentName, size_t& position, Documentation* documentation)
{
  _documentation = documentation;
  _componentName = componentName;

  std::size_t start = position;
  position = buffer.find_first_of(";", start);
  _signature = buffer.substr(start, position - start);

  std::string typedefStr("typedef");
  start = _signature.find(typedefStr);
  if (start != std::string::npos) {
    _signature.erase(start, typedefStr.length());
  }

  _signature = util::trim(_signature);

  std::size_t last = _signature.find_last_of("\t\n\r ");
  std::string _alias = util::trim(_signature.substr(last));

  _typeName = util::trim(_signature.substr(0, last));
}


void Typedef::serialise(std::string& output, const std::string& componentName)
{
  if (_componentName == componentName) {
    output += _signature + "\n\n";
  }
}


const std::string& Typedef::getAlias() const
{
  return _alias;
}


const std::string& Typedef::getTypeName() const
{
  return _typeName;
}


void Typedef::propagateClasses(const std::set <Class*>& classes)
{
}


void Typedef::backtrack()
{
}


void Typedef::propagateScope(const std::string& scope)
{
  _scope = scope;
  _scopedAlias = _scope + _alias;
}


}


}
