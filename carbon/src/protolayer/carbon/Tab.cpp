#include "Tab.h"


namespace protolayer
{

namespace carbon
{

Tab::Tab(const char* name, bool enabled)
{
  _name = name;
  _enabled = enabled;
}


Tab::~Tab()
{
}


const std::string& Tab::getName() const
{
  return _name;
}


bool Tab::isEnabled() const
{
  return _enabled;
}


}


}
