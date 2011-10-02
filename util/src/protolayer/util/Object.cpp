#include "Object.h"
#include <iostream.h>

namespace protolayer
{

namespace util
{

namespace
{
  // Start from 1 to prevent various issues for third party libraries depending
  // on 0 as a special call or NULL.
  unsigned int nextId = 1;

  std::set <unsigned int> freedIds;

  std::map <unsigned int, Object*> allObjects;
}


Object* Object::getObject(unsigned int id)
{
  Object* result = 0;

  if (allObjects.count(id) != 0) {
    result = allObjects[id];
  }

  return result;
}


Object::Object()
{
  if (freedIds.size() > 0) {
    _id = *(freedIds.begin());
    freedIds.erase(_id);
  } else {
    _id = nextId;
    nextId++;
  }

  allObjects[_id] = this;
}


Object::~Object()
{
  allObjects.erase(_id);
  freedIds.erase(_id);
}


unsigned int Object::getId()
{
  return _id;
}



}


}
