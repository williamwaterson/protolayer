#include "Domain.h"


namespace protolayer
{

namespace assembly
{

Domain::Domain(ontology::Ontology& ontology, ontology::Domain& domain) :
  _domain(&domain)
{
  assert(ontology.contains(domain));

  ontology::TypeStack& stack = *(ontology.getTypeStack(domain));
  ontology::TypeStack::IteratorType iter;
  for (iter = stack.getTopDownLayers(); iter.hasNext(); ) {
    ontology::TypeLayer& typeLayer = iter.next();
    Layer* layer = new Layer(typeLayer);
    _topDownLayers.push_back(layer);
  }
}


Domain::Domain(iostream::XdrInputStream& stream,
                               std::map <int, void*>& addressMappings)
{
  int id = 0;
  stream.read(id);
  _domain = reinterpret_cast <ontology::Domain*> (addressMappings[id]);

  int numberOf = 0;
  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Layer* layer = new Layer(stream, addressMappings);
    _topDownLayers.push_back(layer);
    addressMappings[id] = layer;
  }
}


Domain::~Domain()
{
}


void Domain::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) _domain);

  Layer* layer = 0;
  stream.write(getNumberLayers());
  for (LayerIteratorType iter = getTopDownLayers(); iter.hasNext(); ) {
    layer = &(iter.next());
    stream.write((int) layer);
    layer->encode(stream);
  }  
}


void Domain::encode(xercesc::DOMElement& element)
{
}


ontology::Domain& Domain::getDomain()
{
  return *_domain;
}


bool Domain::instantiates(ontology::Domain& domain)
{
  return _domain == &domain;
}


int Domain::getNumberLayers() const
{
  return _topDownLayers.size();
}


Layer& Domain::getLayer(int index)
{
  if (index >= _topDownLayers.size()) {
    throw Exception("Outside of layer indices");
  }
  return *(_topDownLayers[index]);
}


Domain::LayerIteratorType Domain::getTopDownLayers()
{
  return LayerIteratorType(_topDownLayers);
}


Domain::LayerIteratorType Domain::getTopDownLayers(Layer& from)
{
  return LayerIteratorType(_topDownLayers, from);
}


bool Domain::contains(Layer& layer)
{
  return find(_topDownLayers.begin(), _topDownLayers.end(), &layer) !=
    _topDownLayers.end();
}


bool Domain::contains(Instance& instance)
{
  return getLayer(instance) != 0;
}


Layer* Domain::getLayer(Instance& instance)
{
  Layer* result = 0;
  LayerIteratorType iter;
  for (iter = getTopDownLayers(); iter.hasNext(); ) {
    Layer& layer = iter.next();
    if (layer.contains(instance)) {
      result = &layer;
      break;
    }
  }
  return result;  
}


Layer* Domain::getLayer(ontology::Type& type)
{
  Layer* result = 0;
  LayerIteratorType iter;
  for (iter = getTopDownLayers(); iter.hasNext(); ) {
    Layer& layer = iter.next();
    if (layer.getTypeLayer().involves(type)) {
      result = &layer;
      break;
    }
  }
  return result;  
}


Layer* Domain::getLayer(ontology::TypeLayer& typeLayer)
{
  Layer* result = 0;
  LayerIteratorType iter;
  for (iter = getTopDownLayers(); iter.hasNext(); ) {
    Layer& layer = iter.next();
    if (layer.instantiates(typeLayer)) {
      result = &layer;
      break;
    }
  }
  return result;  
}


}


}
