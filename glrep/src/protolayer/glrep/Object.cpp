#include "Object.h"


namespace protolayer
{

namespace glrep
{

Object::Object(Object::Type type, float size)
{
  _type = type;
  _size = size;
}


Object::~Object()
{
}


Object::Type Object::getType() const
{
  return _type;
}


float Object::getSize() const
{
  return _size;
}


int Object::getNumberPoints() const
{
  return _points.size();
}


Object::PointIteratorType Object::getPoints()
{
  return _points.begin();
}


Object::PointIteratorType Object::getLastPoint()
{
  return _points.end();
}


void Object::addPoint(scenegraph::Point& point)
{
  _points.push_back(&point);
}


void Object::setSize(float size)
{
  _size = size;
}


void Object::removePoint(PointIteratorType iterator)
{
  _points.erase(iterator);
}


void Object::clearPoints()
{
  _points.clear();
}


}


}
