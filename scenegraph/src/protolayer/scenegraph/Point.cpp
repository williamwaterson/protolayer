#include "Point.h"


namespace protolayer
{

namespace scenegraph
{

Point::Point()
{
  _coordinates = new float [4];
  setCoordinates(0, 0, 0, 1);
}


Point::Point(float* coordinates)
{
  _coordinates = coordinates;
}


Point::Point(float x, float y, float z)
{
  _coordinates = new float [4];
  setCoordinates(x, y, z, 1);
}


Point::Point(Point& point, bool copyFlag)
{
  _coordinates = new float [4];
  setCoordinates(point._coordinates[0], point._coordinates[1], point._coordinates[2], 1);
}


Point::~Point()
{
  delete[] _coordinates;
}


float* Point::getCoordinates()
{
  return _coordinates;
}


const float* Point::getCoordinates() const
{
  return _coordinates;
}


void Point::setCoordinates(float coordinates[4])
{
  _coordinates[0] = coordinates[0];
  _coordinates[1] = coordinates[1];
  _coordinates[2] = coordinates[2];
  _coordinates[3] = coordinates[3];
}


void Point::setCoordinates(float x, float y, float z, float w)
{
  _coordinates[0] = x;
  _coordinates[1] = y;
  _coordinates[2] = z;
  _coordinates[3] = w;
}


}


}
