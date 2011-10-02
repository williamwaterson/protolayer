#include "Disk.h"


namespace protolayer
{

namespace geometry
{


Disk::Disk(float radius)
{
  _surface = new renderer::Surface(*(new style::Appearance), 6, 6, 3, 3, 3, 3);

  _surface->getSKnots()[0] = 0;
  _surface->getSKnots()[1] = 0;
  _surface->getSKnots()[2] = 1;
  _surface->getSKnots()[3] = 1;
  _surface->getSKnots()[4] = 2;
  _surface->getSKnots()[5] = 2;

  _surface->getTKnots()[0] = 0;
  _surface->getTKnots()[1] = 0;
  _surface->getTKnots()[2] = 1;
  _surface->getTKnots()[3] = 1;
  _surface->getTKnots()[4] = 2;
  _surface->getTKnots()[5] = 2;

  typedef renderer::Surface::ControlPointIteratorType IterType;
  IterType iter = _surface->getControlPoints();

  float* globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0;
  globalCoords[1] = 0;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0.5;
  globalCoords[1] = 0;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 1;
  globalCoords[1] = 0;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0;
  globalCoords[1] = 0;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0.5 * 0.707;
  globalCoords[1] = 0.5 * 0.707;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0.707;
  globalCoords[1] = 0.707;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0;
  globalCoords[1] = 0;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0;
  globalCoords[1] = 0.5;
  globalCoords[2] = 0;
  globalCoords[3] = 1;

  iter++;
  globalCoords = (*iter)->getGlobalCoordinates();
  globalCoords[0] = 0;
  globalCoords[1] = 1;
  globalCoords[2] = 0;
  globalCoords[3] = 1;
}


float Disk::getRadius()
{
  return _radius;
}


void Disk::setRadius(float radius)
{
  _radius = radius;
}


renderer::Surface& Disk::getSurface()
{
  return *_surface;
}


}


}
