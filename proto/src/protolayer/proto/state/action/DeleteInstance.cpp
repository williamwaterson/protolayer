#include "DeleteInstance.h"


namespace protolayer
{ 

namespace proto
{

DeleteInstance::DeleteInstance(StateLayer& stateLayer,
			       assembly::Instance& instance)
{
  _stateLayer = &stateLayer;
  _instance = &instance;
}


DeleteInstance::~DeleteInstance()
{
}


void DeleteInstance::doit()
{
  assembly::Assembly& assembly = _stateLayer->getAssembly();
  if (assembly.contains(*_instance)) {
    assembly.remove(*_instance);
  }
}


void DeleteInstance::undo()
{
  assembly::Assembly& assembly = _stateLayer->getAssembly();
  if (!assembly.contains(*_instance)) {
    assembly.add(*_instance);
  }
}


}


}
