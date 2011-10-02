#include "Model.h"


namespace protolayer
{

namespace glrep
{

Model::Model()
{
}


Model::~Model()
{
}


void Model::add(Object& object)
{
  _objects.insert(&object);
}


void Model::remove(Object& object)
{
  _objects.erase(&object);
}


Model::ObjectIteratorType Model::getObjects()
{
  return _objects.begin();
}


Model::ObjectIteratorType Model::getLastObject()
{
  return _objects.end();
}


}


}
