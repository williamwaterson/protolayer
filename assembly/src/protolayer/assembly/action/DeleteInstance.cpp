#include "DeleteInstance.h"


namespace protolayer
{ 

namespace assembly
{

DeleteInstance::DeleteInstance(Assembly& assembly,
			       assembly::Instance& instance)
{
  _assembly = &assembly;
  _instance = &instance;
}


DeleteInstance::~DeleteInstance()
{
}


void DeleteInstance::doit()
{
  if (_assembly->contains(*_instance)) {
    _assembly->remove(*_instance);
  }
}


void DeleteInstance::undo()
{
  if (!_assembly->contains(*_instance)) {
    _assembly->add(*_instance);
  }
}


}


}
