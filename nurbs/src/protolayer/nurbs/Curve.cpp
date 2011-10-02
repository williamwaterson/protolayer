#include "Curve.h"

namespace protolayer
{

namespace nurbs
{

Curve::Curve(int order)
{
}


Curve::~Curve()
{
}


void Curve::evaluate(float t, float result[3])
{
  int n = _points.size();
  float basis;
  for (int i = 1; i < n + 1; i++) {
    basis = basisFunction(n + 1, i, t);
    result[0] += _points[i]->getCoordinates()[0] * basis;
    result[1] += _points[i]->getCoordinates()[1] * basis;
    result[2] += _points[i]->getCoordinates()[2] * basis;
  }
}


float Curve::basisFunction(int i, int k, float t)
{
  if (k = 1) {
    if (_knots[i] <= t < _knots[i+1]) {
      return 1;
    } else {
      return 0;
    }
  }

  float a = t - _knots[i];
  a *= basisFunction(i, k-1, t);
  a /= _knots[i+k-1] - _knots[i];

  float b = _knots[i+k] - t;
  b *= basisFunction(i+1, k-1, t);
  b /= _knots[i+k] - _knots[i+1];

  return a + b;
}


}


}
