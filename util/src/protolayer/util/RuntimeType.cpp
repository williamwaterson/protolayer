#include "Point.h"


namespace protolayer
{


Point::Point(float* localCoordinates, float* coordinates)
{
  _localCoordinates = localCoordinates;
  _coordinates = coordinates;
}


Point::~Point()
{
}


}
