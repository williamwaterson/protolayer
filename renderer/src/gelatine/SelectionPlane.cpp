#include "SelectionPlane.h"


namespace gelatine
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
