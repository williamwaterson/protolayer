#include "Entity.h"


namespace protolayer
{

namespace glrep
{

Entity::Entity(Entity::Type type, float size)
{
  _type = type;
  _size = size;
}


Entity::~Entity()
{
}


Entity::Type Entity::getType() const
{
  return _type;
}


float Entity::getSize() const
{
  return _size;
}


int Entity::getNumberPoints() const
{
  return _points.size();
}


Entity::PointIteratorType Entity::getPoints()
{
  return _points.begin();
}


Entity::PointIteratorType Entity::getLastPoint()
{
  return _points.end();
}


void Entity::addPoint(scenegraph::Point& point)
{
  _points.push_back(&point);
}


void Entity::setSize(float size)
{
  _size = size;
}


void Entity::removePoint(PointIteratorType iterator)
{
  _points.erase(iterator);
}


void Entity::clearPoints()
{
  _points.clear();
}


}


}
