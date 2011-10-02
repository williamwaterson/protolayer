#include "CreateInstance.h"


namespace protolayer
{ 

namespace assembly
{

CreateInstance::CreateInstance(Assembly& assembly,
			       ontology::Type& type)
{
  _assembly = &assembly;
  _type = &type;

  _instance = 0;
}


CreateInstance::~CreateInstance()
{
}


void CreateInstance::doit()
{
  _instance = new assembly::Instance(*_type);
  _assembly->add(*_instance);
}



void CreateInstance::undo()
{
  _assembly->remove(*_instance);
}


}


}
