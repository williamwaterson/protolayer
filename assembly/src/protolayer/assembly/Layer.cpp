#include "Layer.h"


namespace protolayer
{

namespace assembly
{

Layer::Layer(ontology::TypeLayer& typeLayer) :
  _typeLayer(&typeLayer)
{
}


Layer::Layer(iostream::XdrInputStream& stream,
             std::map <int, void*> addressMappings)
{
  int id = 0;
  stream.read(id);
  _typeLayer = reinterpret_cast <ontology::TypeLayer*> (addressMappings[id]);

  int numberOf = 0;
  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Instance* instance = new Instance(stream, addressMappings);
    _instances.insert(instance);
    addressMappings[id] = reinterpret_cast <void*> (instance);
  }
}


Layer::~Layer()
{
}


void Layer::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) _typeLayer);

  Instance* instance = 0;
  stream.write(getNumberInstances());
  for (IteratorType iter = getInstances(); iter.hasNext(); ) {
    instance = &(iter.next());
    stream.write((int) instance);
    instance->encode(stream);
  }
}


void Layer::encode(xercesc::DOMElement& element)
{
}


ontology::TypeLayer& Layer::getTypeLayer()
{
  return *_typeLayer;
}


bool Layer::instantiates(ontology::TypeLayer& typeLayer)
{
  return _typeLayer == &typeLayer;
}


void Layer::add(Instance& instance)
  throw (Exception)
{
  if (!_typeLayer->involves(instance.getType())) {
    throw Exception("Specified instance is not of Type used by Layer.");
  }

  _instances.insert(&instance);
}


int Layer::getNumberInstances() const
{
  return _instances.size();
}


Layer::IteratorType Layer::getInstances()
{
  return IteratorType(_instances);
}


void Layer::remove(Instance& instance)
  throw (Exception)
{
  if (contains(instance)) {
    _instances.erase(&instance);
  } else {
    throw Exception("Instance not part of layer.");
  }
}


bool Layer::contains(Instance& instance)
{
  return _instances.find(&instance) != _instances.end();
}


//void Layer::add(Instance& instance)
//{
  //  if (!instance.isOwned()) {
  //    if (_instances.insert(&instance).second) {
      //    instance._isOwned = true;
  //    }
  //  }
//}


//void Layer::remove(Instance& instance)
//{
//  if (_instances.erase(&instance) > 0) {
  //  instance._isOwned = false;
//  }
//}


}


}
