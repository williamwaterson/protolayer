#include "Dimensions.h"


namespace gelatine
{


Dimensions::Dimensions()
{
  _width = 0;
  _height = 0;
}


Dimensions::Dimensions(int width, int height)
{
  _width = width;
  _height = height;
}


void
Dimensions::setDimensions(int width, int height)
{
  _width = width;
  _height = height;
}


int
Dimensions::getWidth()
{
  return _width;
}


int
Dimensions::getHeight()
{
  return _height;
}


float
Dimensions::getAspectRatio()
{
  return (float) _width / (float) _height;
}


}
