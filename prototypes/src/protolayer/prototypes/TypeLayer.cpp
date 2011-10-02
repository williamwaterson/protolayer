#include "TypeLayer.h"


namespace protolayer
{

namespace ontology
{

TypeLayer::TypeLayer(Type& type)
{
  _types.insert(&type);
}


TypeLayer::TypeLayer(std::set <Type*>& types) :
  _types(types)
{
}


TypeLayer::TypeLayer(iostream::XdrInputStream& stream,
                     std::map <int, void*>& addressMappings)
{
}


TypeLayer::~TypeLayer()
{
}


void TypeLayer::encode(iostream::XdrOutputStream& stream)
{
}


TypeLayer::IteratorType TypeLayer::getTypes()
{
  return IteratorType(_types);
}


bool TypeLayer::involves(Type& type)
{
  return _types.find(&type) != _types.end();
}


bool TypeLayer::involves(const std::string& conceptTypeUrn)
{
  bool result = false;
  for (IteratorType iter(_types); iter.hasNext(); ) {
    if (conceptTypeUrn == iter.next().getName()) {
      result = true;
    }
  }
  return result;
}


}


}
