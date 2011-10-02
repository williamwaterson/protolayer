#include "Sphere.h"


namespace protolayer
{

namespace geometry
{

namespace
{
  float factor = sqrt(2) / 2;
}


Sphere::Sphere(float radius)
{
  style::Appearance* appearance = new style::Appearance();
  _surface = new renderer::Surface(*appearance, 8, 12, 5, 9, 3, 3);

  float curve[5][4];
  float circle[9][4];

  _surface->getTKnots()[0] = 0;
  _surface->getTKnots()[1] = 0;
  _surface->getTKnots()[2] = 0;
  _surface->getTKnots()[3] = 1;
  _surface->getTKnots()[4] = 1;
  _surface->getTKnots()[5] = 2;
  _surface->getTKnots()[6] = 2;
  _surface->getTKnots()[7] = 3;
  _surface->getTKnots()[8] = 3;
  _surface->getTKnots()[9] = 4;
  _surface->getTKnots()[10] = 4;
  _surface->getTKnots()[11] = 4;

  _surface->getSKnots()[0] = 0;
  _surface->getSKnots()[1] = 0;
  _surface->getSKnots()[2] = 0;
  _surface->getSKnots()[3] = 1;
  _surface->getSKnots()[4] = 1;
  _surface->getSKnots()[5] = 2;
  _surface->getSKnots()[6] = 2;
  _surface->getSKnots()[7] = 3;


  curve[0][0] = 0;
  curve[0][1] = 1;
  curve[0][2] = 0;
  curve[0][3] = 1;

  curve[1][0] = 1 * factor;
  curve[1][1] = 1 * factor;
  curve[1][2] = 0;
  curve[1][3] = 1;

  curve[2][0] = 1;
  curve[2][1] = 0;
  curve[2][2] = 0;
  curve[2][3] = 1;

  curve[3][0] = 1 * factor;
  curve[3][1] = -1 * factor;
  curve[3][2] = 0;
  curve[3][3] = 1;

  curve[4][0] = 0;
  curve[4][1] = -1;
  curve[4][2] = 0;
  curve[4][3] = 1;


  circle[0][0] = 1;
  circle[0][1] = 0;
  circle[0][2] = 0;
  circle[0][3] = 1;

  circle[1][0] = 1 * factor;
  circle[1][1] = 0;
  circle[1][2] = -1 * factor;
  circle[1][3] = 1;

  circle[2][0] = 0;
  circle[2][1] = 0;
  circle[2][2] = -1;
  circle[2][3] = 1;

  circle[3][0] = -1 * factor;
  circle[3][1] = 0;
  circle[3][2] = -1 * factor;
  circle[3][3] = 1;

  circle[4][0] = -1;
  circle[4][1] = 0;
  circle[4][2] = 0;
  circle[4][3] = 1;

  circle[5][0] = -1 * factor;
  circle[5][1] = 0;
  circle[5][2] = 1 * factor;
  circle[5][3] = 1;

  circle[6][0] = 0;
  circle[6][1] = 0;
  circle[6][2] = 1;
  circle[6][3] = 1;

  circle[7][0] = 1 * factor;
  circle[7][1] = 0;
  circle[7][2] = 1 * factor;
  circle[7][3] = 1;

  circle[8][0] = 1;
  circle[8][1] = 0;
  circle[8][2] = 0;
  circle[8][3] = 1;

  int index = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      float* localCoords = _surface->getControlPoint(index).getLocalCoordinates();
      localCoords[0] = curve[i][0] * circle[j][0];
      localCoords[1] = curve[i][1];
      localCoords[2] = curve[i][0] * circle[j][2];
      localCoords[3] = 1;

      float* globalCoords = _surface->getControlPoint(index).getGlobalCoordinates();
      globalCoords[0] = curve[i][0] * circle[j][0];
      globalCoords[1] = curve[i][1];
      globalCoords[2] = curve[i][0] * circle[j][2];
      globalCoords[3] = 1;

      index++;
    }
  }

  addChild(*_surface);
  update();
}


float Sphere::getRadius()
{
  return _radius;
}


void Sphere::setRadius(float radius)
{
  _radius = radius;
}


renderer::Surface& Sphere::getSurface()
{
  return *_surface;
}


}


}
