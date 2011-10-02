#include "LVertex.h"


namespace protolayer
{


LVertex::LVertex() :
  Point(new float[4], new float[4])
{
  setCoordinates(0, 0, 0, 1);
  setLocalCoordinates(0, 0, 0, 1);
}


LVertex::LVertex(float x, float y, float z) :
  Point(new float[4], new float[4])
{
  setCoordinates(x, y, z, 1);
  setLocalCoordinates(x, y, z, 1);
}


LVertex::LVertex(float coordinates[3]) :
  Point(new float[4], new float[4])
{
  setCoordinates(coordinates);
  setLocalCoordinates(coordinates);
}


LVertex::~LVertex()
{
}


}
