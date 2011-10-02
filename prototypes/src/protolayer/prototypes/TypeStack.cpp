#include "TypeStack.h"


namespace protolayer
{

namespace ontology
{

TypeStack::TypeStack(::std::vector <TypeLayer*>& topDownLayers) :
  _topDownLayers(topDownLayers)
{
  extractTypeLayerMap();
}


TypeStack::TypeStack(iostream::XdrInputStream& stream,
                     std::map <int, void*>& addressMappings)
{
  extractTypeLayerMap();
}


TypeStack::~TypeStack()
{
}


void TypeStack::encode(iostream::XdrOutputStream& stream)
{
  TypeLayer* layer = 0;
  stream.write(getNumberLayers());
  for (IteratorType iter = getTopDownLayers(); iter.hasNext(); ) {
    layer = &(iter.next());
    stream.write((int) layer);
  }
}


TypeStack::IteratorType TypeStack::getTopDownLayers()
{
  return IteratorType(_topDownLayers);
}


TypeStack::IteratorType TypeStack::getTopDownLayers(TypeLayer& from)
{
  return IteratorType(_topDownLayers, from);
}


int TypeStack::getNumberLayers() const
{
  return _topDownLayers.size();
}


TypeLayer& TypeStack::getLayer(int index)
{
  if (index >= _topDownLayers.size()) {
    throw;
  }
  return *(_topDownLayers[index]);
}


void TypeStack::extractTypeLayerMap()
{
  for (IteratorType iter = getTopDownLayers(); iter.hasNext(); ) {
    TypeLayer& layer = iter.next();
    for (TypeLayer::IteratorType typeIter = layer.getTypes(); typeIter.hasNext(); ) {
      Type& type = typeIter.next();
      _typeLayerMap[&type] = &layer;
    }
  }
}


}


}
