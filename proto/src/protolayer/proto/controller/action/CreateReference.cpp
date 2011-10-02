#include "CreateReference.h"


namespace protolayer
{ 

namespace proto
{

CreateReference::CreateReference(StateLayer& stateLayer,
				 ontology::Association& association,
				 assembly::Instance& fromInstance,
				 assembly::Instance& toInstance)
{
  _stateLayer = &stateLayer;
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
    _stateLayer->getAssembly().add(*_reference);
  } else {
    throw "Cannot call doit twice";
  }
}



void CreateReference::undo()
{
  if (_reference != 0) {
    _stateLayer->getAssembly().remove(*_reference);
  }
}


}


}
