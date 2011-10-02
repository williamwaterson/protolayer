#include "Vertex.h"


namespace protolayer
{

namespace nurbs
{

Vertex::Vertex() :
  util::Point::Point(new float[4], new float[4])
{
  _parametricCoordinates[0] = 0;
  _parametricCoordinates[1] = 0;

  setCoordinates(0, 0, 0, 1);
  setLocalCoordinates(0, 0, 0, 1);
}


Vertex::Vertex(float x, float y, float z) :
  Point::Point(new float[4], new float[4])
{
  _parametricCoordinates[0] = 0;
  _parametricCoordinates[1] = 0;

  setCoordinates(x, y, z, 1);
  setLocalCoordinates(x, y, z, 1);
}


Vertex::Vertex(float coordinates[3]) :
  Point::Point(new float[4], new float[4])
{
  _parametricCoordinates[0] = 0;
  _parametricCoordinates[1] = 0;

  setCoordinates(coordinates);
  setLocalCoordinates(coordinates);
}


Vertex::~Vertex()
{
  delete[] getLocalCoordinates();
  delete[] getCoordinates();
}


float* Vertex::getParametricCoordinates()
{
  return _parametricCoordinates;
}


}


}
