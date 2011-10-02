#include "Point.h"


namespace protolayer
{

namespace util
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


}
