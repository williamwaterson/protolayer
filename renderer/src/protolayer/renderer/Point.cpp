#include "Point.h"


namespace protolayer
{

namespace renderer
{

Point::Point()
{
  _id = util::IDGenerator::getInstance().obtainID();
  _globalCoordinates = new float [4];
  _localCoordinates = new float [4];
  setLocalCoordinates(0, 0, 0, 1);
  setCoordinates(0, 0, 0, 1);
}


Point::Point(float* localCoordinates)
{
  _id = util::IDGenerator::getInstance().obtainID();
  _localCoordinates = localCoordinates;
  _globalCoordinates = new float [4];
  //  setLocalCoordinates(localCoordinates);
  setCoordinates(0, 0, 0, 1);
}


Point::Point(float* localCoordinates, float* coordinates)
{
  _id = util::IDGenerator::getInstance().obtainID();
  //  _localCoordinates = new float [4];
  //  _globalCoordinates = new float [4];
  _localCoordinates = localCoordinates;
  _globalCoordinates = coordinates;
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
  glVertex3fv(getGlobalCoordinates());
  glEnd();
}


float* Point::getLocalCoordinates()
{
  return _localCoordinates;
}


//float* Point::getGlobalCoordinates()
//{
//  return _globalCoordinates;
//}


const float* Point::getLocalCoordinates() const
{
  return _localCoordinates;
}


const float* Point::getGlobalCoordinates() const
{
  return _globalCoordinates;
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
  _globalCoordinates[0] = coordinates[0];
  _globalCoordinates[1] = coordinates[1];
  _globalCoordinates[2] = coordinates[2];
  _globalCoordinates[3] = coordinates[3];
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
  _globalCoordinates[0] = x;
  _globalCoordinates[1] = y;
  _globalCoordinates[2] = z;
  _globalCoordinates[3] = w;
}


}


}
