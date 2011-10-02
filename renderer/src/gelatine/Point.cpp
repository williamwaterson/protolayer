#include "Point.h"


namespace gelatine
{


// Explicit Instantiations
template class HitListener <Point>;


Point::Point()
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
  _coordinates = new float [4];
  _localCoordinates = new float [4];
  setLocalCoordinates(0, 0, 0, 1);
  setCoordinates(0, 0, 0, 1);
}


Point::Point(float* localCoordinates)
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
  _localCoordinates = localCoordinates;
  _coordinates = new float [4];
  //  setLocalCoordinates(localCoordinates);
  setCoordinates(0, 0, 0, 1);
}


Point::Point(float* localCoordinates, float* coordinates)
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
  _localCoordinates = new float [4];
  _coordinates = new float [4];
  setLocalCoordinates(localCoordinates);
  setCoordinates(coordinates);
}


Point::~Point()
{
}


void Point::render(float alpha, Appearance& appearance)
{
  glPointSize(5.0);
  glColor4f(0.0, 0.0, 0.0, 1.0f);
  glBegin(GL_POINTS);
  glVertex3fv(getCoordinates());
  glEnd();
}


float* Point::getLocalCoordinates()
{
  return _localCoordinates;
}


float* Point::getCoordinates()
{
  return _coordinates;
}


const float* Point::getLocalCoordinates() const
{
  return _localCoordinates;
}


const float* Point::getCoordinates() const
{
  return _coordinates;
}


void Point::setLocalCoordinates(float coordinates[4])
{
  _localCoordinates[0] = coordinates[0];
  _localCoordinates[1] = coordinates[1];
  _localCoordinates[2] = coordinates[2];
  _localCoordinates[3] = coordinates[3];
}


void Point::setCoordinates(float coordinates[4])
{
  _coordinates[0] = coordinates[0];
  _coordinates[1] = coordinates[1];
  _coordinates[2] = coordinates[2];
  _coordinates[3] = coordinates[3];
}


void Point::setLocalCoordinates(float x, float y, float z, float w)
{
  _localCoordinates[0] = x;
  _localCoordinates[1] = y;
  _localCoordinates[2] = z;
  _localCoordinates[3] = w;
}


void Point::setCoordinates(float x, float y, float z, float w)
{
  _coordinates[0] = x;
  _coordinates[1] = y;
  _coordinates[2] = z;
  _coordinates[3] = w;
}


}
