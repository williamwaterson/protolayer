#include "Reference.h"


namespace protolayer
{

namespace assembly
{

Reference::Reference(ontology::Association& association,
                     Instance& fromInstance,
                     Instance& toInstance) throw (Exception)
{
  _association = &association;
  _fromInstance = &fromInstance;
  _toInstance = &toInstance;

  ontology::Type& fromType = fromInstance.getType();
  ontology::Type& toType = toInstance.getType();

  if (&(association.getFromEnd().getType()) != &fromType) {
    throw Exception("Association end type conflict with supplied from-instance type.");
  }

  if (&(association.getToEnd().getType()) != &toType) {
    throw Exception("Association end type conflict with supplied to-instance type.");
  }

  Instance::InstanceSetType& references = _fromInstance->_references[_association];
  references.insert(_toInstance);
}


Reference::Reference(iostream::XdrInputStream& stream,
                     std::map <int, void*>& addressMappings)
{
  int id;

  stream.read(id);
  _association = reinterpret_cast <ontology::Association*> (addressMappings[id]);

  stream.read(id);
  _fromInstance = reinterpret_cast <Instance*> (addressMappings[id]);

  stream.read(id);
  _toInstance = reinterpret_cast <Instance*> (addressMappings[id]);
}


Reference::~Reference()
{
}


void Reference::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) &_association);
  stream.write((int) &_fromInstance);
  stream.write((int) &_toInstance);
}


void Reference::encode(xercesc::DOMElement& element)
{
}

ontology::Association& Reference::getAssociation()
{
  return *_association;
}


Instance& Reference::getFromInstance()
{
  return *_fromInstance;
}


Instance& Reference::getToInstance()
{
  return *_toInstance;
}


bool Reference::isAssociation(ontology::Association& association)
{
  return _association == &association;
}


bool Reference::isFromInstance(Instance& instance)
{
  return _fromInstance == &instance;
}


bool Reference::isToInstance(Instance& instance)
{
  return _toInstance == &instance;
}


bool Reference::involves(Instance& instance)
{
  return isToInstance(instance) || isFromInstance(instance);
}


bool Reference::involves(Instance& someInstance, Instance& anotherInstance)
{
  return involves(someInstance) && involves(anotherInstance);
}


bool Reference::matches(Instance& fromInstance, Instance& toInstance)
{
  return isFromInstance(fromInstance) && isToInstance(toInstance);
}


bool Reference::isEquivalent(Reference& reference)
{
  return isAssociation(reference.getAssociation()) &&
    isFromInstance(reference.getFromInstance()) &&
    isToInstance(reference.getToInstance());
}


}


}
