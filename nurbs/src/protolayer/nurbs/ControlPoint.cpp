#include "ControlPoint.h"

namespace protolayer
{

namespace nurbs
{

ControlPoint::ControlPoint(float* localCoordinates, float* coordinates) :
  util::Point::Point(localCoordinates, coordinates)
{
}


ControlPoint::~ControlPoint()
{
}


}


}
