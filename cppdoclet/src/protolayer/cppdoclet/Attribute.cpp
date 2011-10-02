#include "Attribute.h"


namespace protolayer
{

namespace cppdoclet
{

void Attribute::backtrack()
{
  if (_type != 0) {
    _type->backtrack();
  }
}


void Attribute::propagateScope(const std::string& scope)
{
  _scope = scope;
  _scopedName = _scope + _name;
}


void Attribute::propagateClasses(const std::map <std::string, Class*>& classes)
{
  if (_type != 0) {
    _type->propagateClasses(classes);
  }
}


void Attribute::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
  if (_type != 0) {
    _type->propagateTypedefs(typedefs);
  }
}


const std::string& Attribute::getScopedName() const
{
  return _scopedName;
}


void Attribute::serialise(std::string& output, const std::string& componentName)
{
  if (hasDocumentation()) {
    _documentation->serialise(output, componentName);
  }
  output += _visibility + ": " + _signature + ";\n\n";
}


Attribute::Attribute(const std::string& visibility,
		     const std::string& signature,
		     Documentation* documentation)
{
  _type = 0;
  _documentation = documentation;
  _signature = util::trim(signature);
  _visibility = visibility;

  _isStatic = false;

  std::size_t position = _signature.find(";");
  if (position != std::string::npos) {
    _signature.erase(position);
  }

  _signature = util::trim(_signature);

  std::size_t last = _signature.find_last_of("\t\n\r ");
  std::string typeName = util::trim(_signature.substr(0, last));
  _name = util::trim(_signature.substr(last));

  _type = new Type(typeName);
}


bool Attribute::hasAnnotation(const std::string& name)
{
  bool flag = false;
  if (hasDocumentation()) {
    if (_documentation->containsAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


const std::string& Attribute::getSignature() const
{
  return _signature;
}


}


}
