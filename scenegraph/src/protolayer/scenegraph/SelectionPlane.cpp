#include "SelectionPlane.h"


namespace protolayer
{

namespace scenegraph
{

SelectionPlane::SelectionPlane()
{
  _positionY = 0.0f;
}


float SelectionPlane::getPositionY()
{
  return _positionY;
}


void SelectionPlane::setPositionY(float value)
{
  _positionY = value;
}


}


}
