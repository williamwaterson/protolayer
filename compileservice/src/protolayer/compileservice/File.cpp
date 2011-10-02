#include "File.h"


namespace protolayer
{

namespace compileservice
{

File::File(const char* name) :
  _name(name)
{
}


File::File(const std::string& name) :
  _name(name)
{
}


}


}
