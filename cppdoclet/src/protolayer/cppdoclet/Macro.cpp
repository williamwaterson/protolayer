#include "Macro.h"


namespace protolayer
{

namespace cppdoclet
{

Macro::Macro(const std::string& buffer,
	     const std::string& componentName,
	     size_t& position)
{
  size_t start = position;
  size_t last = position;

  position = buffer.find("\n", position);
  _signature = buffer.substr(start, position - start);
  _componentName = componentName;

  size_t space = buffer.find_first_of("\n\t\r ", start);
  _type = buffer.substr(start, space - start);
  std::cout << _type << std::endl;
}


void Macro::serialise(std::string& output, const std::string& componentName)
{
  if (_componentName == componentName) {
    output += _signature + "\n";
  }
}


const std::string& Macro::getType() const
{
  return _type;
}


}


}
