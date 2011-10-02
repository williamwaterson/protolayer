#include "CreateReference.h"


namespace protolayer
{ 

namespace assembly
{

CreateReference::CreateReference(Assembly& assembly,
				 ontology::Association& association,
				 assembly::Instance& fromInstance,
				 assembly::Instance& toInstance)
{
  _assembly = &assembly;
  _association = &association;
  _fromInstance = &fromInstance;
  _toInstance = &toInstance;

  _reference = 0;
}


CreateReference::~CreateReference()
{
}


void CreateReference::doit()
{
  if (_reference == 0) {
    _reference = new assembly::Reference(*_association,
					 *_fromInstance,
					 *_toInstance);
    _assembly->add(*_reference);
  } else {
    throw "Cannot call doit twice";
  }
}



void CreateReference::undo()
{
  if (_reference != 0) {
    _assembly->remove(*_reference);
  }
}


}


}
