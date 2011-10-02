#include "Geometry.h"


namespace protolayer
{

namespace renderer
{

Geometry::Geometry(GeometryTypeEnum geometryType)
{
  _geometryType = geometryType;
  _lineWidth = 50.0f;
}


Geometry::~Geometry()
{
}


int Geometry::getType()
{
  return _geometryType;
}


int Geometry::getNumberPoints() const
{
  return _points.size();
}


float Geometry::getLineWidth() const
{
  return _lineWidth;
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


}


}
