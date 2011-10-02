#include "CreateInstance.h"


namespace protolayer
{ 

namespace proto
{

CreateInstance::CreateInstance(StateLayer& stateLayer,
			       ontology::Type& type)
{
  _stateLayer = &stateLayer;
  _type = &type;

  _instance = 0;
}


CreateInstance::~CreateInstance()
{
}


void CreateInstance::doit()
{
  _instance = new assembly::Instance(*_type);
  _stateLayer->getAssembly().add(*_instance);
}



void CreateInstance::undo()
{
  _stateLayer->getAssembly().remove(*_instance);
}


}


}
