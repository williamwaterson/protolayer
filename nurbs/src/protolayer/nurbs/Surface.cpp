#include "Surface.h"


namespace protolayer
{

namespace nurbs
{

Surface::Surface(int m, int n)
{
  _m = m;
  _n = n;

  _points = new ControlPoint* [n];
  for (int i = 0; i < m; i++) {
    //    _points[i] = new ControlPoint [m];
  }
}


Surface::~Surface()
{
}


void Surface::evaluate(float u, float v, float result[3])
{
  float basis, ibasis;
  for (int i = 1; i < _n + 1; i++) {
    ibasis = basisFunction(_n + 1, i, u, _uKnots);
    for (int j = 1; j < _m + 1; j++) {
      basis = ibasis * basisFunction(_m + 1, j, v, _vKnots);
      result[0] += _points[i][j].getCoordinates()[0] * basis;
      result[1] += _points[i][j].getCoordinates()[1] * basis;
      result[2] += _points[i][j].getCoordinates()[2] * basis;
    }
  }
}


float Surface::basisFunction(int i, int k, float t, float* knots)
{
  if (k = 1) {
    if (knots[i] <= t < knots[i+1]) {
      return 1;
    } else {
      return 0;
    }
  }

  float a = t - knots[i];
  a *= basisFunction(i, k-1, t, knots);
  a /= knots[i+k-1] - knots[i];

  float b = knots[i+k] - t;
  b *= basisFunction(i+1, k-1, t, knots);
  b /= knots[i+k] - knots[i+1];

  return a + b;
}


}


}
