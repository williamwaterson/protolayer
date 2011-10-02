#include "Geometry.h"


namespace gelatine
{


Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}


int Geometry::getNumberPoints() const
{
  return _points.size();
}


Geometry::PointIteratorType Geometry::getPoints()
{
  return _points.begin();
}


Geometry::PointIteratorType Geometry::getLastPoint()
{
  return _points.end();
}


void Geometry::addPoint(float* point)
{
  _points.push_back(point);
}


void Geometry::removePoint(PointIteratorType iterator)
{
  _points.erase(iterator);
}


void Geometry::clearPoints()
{
  _points.clear();
}


int Geometry::getType()
{
  return 0;
}


}
