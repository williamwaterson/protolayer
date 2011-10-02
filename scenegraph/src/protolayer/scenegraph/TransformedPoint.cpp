#include "TransformedPoint.h"


namespace protolayer
{

namespace scenegraph
{

TransformedPoint::TransformedPoint(Point& localPoint) :
  Point::Point(localPoint, true)
{
  _localPoint = &localPoint;
}


TransformedPoint::~TransformedPoint()
{
}


bool TransformedPoint::isLocalPoint(Point& point)
{
  return _localPoint == &point;
}


Point& TransformedPoint::getLocalPoint()
{
  return *_localPoint;
}


void TransformedPoint::update(float quaternion[4][4])
{
  float* local = _localPoint->getCoordinates();
  float* global = getCoordinates();

  global[0] =  quaternion[0][0] * local[0];
  global[0] += quaternion[0][1] * local[1];
  global[0] += quaternion[0][2] * local[2];
  global[0] += quaternion[0][3] * local[3];

  global[1] =  quaternion[1][0] * local[0];
  global[1] += quaternion[1][1] * local[1];
  global[1] += quaternion[1][2] * local[2];
  global[1] += quaternion[1][3] * local[3];

  global[2] =  quaternion[2][0] * local[0];
  global[2] += quaternion[2][1] * local[1];
  global[2] += quaternion[2][2] * local[2];
  global[2] += quaternion[2][3] * local[3];

  global[3] =  quaternion[3][0] * local[0];
  global[3] += quaternion[3][1] * local[1];
  global[3] += quaternion[3][2] * local[2];
  global[3] += quaternion[3][3] * local[3];
}


}


}
