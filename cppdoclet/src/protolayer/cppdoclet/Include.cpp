#include "Include.h"


namespace protolayer
{

namespace cppdoclet
{

Include::Include(const std::string& buffer, const std::string& componentName, size_t& position)
{
  size_t start = position;
  position = buffer.find("\n", position);
  _signature = buffer.substr(start, position - start);
  _componentName = componentName;
}


void Include::serialise(std::string& output, const std::string& componentName)
{
  if (_componentName == componentName) {
    output += _signature + "\n";
  }
}


}


}
