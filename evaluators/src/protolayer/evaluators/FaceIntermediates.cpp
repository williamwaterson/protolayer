#include "FaceIntermediates.h"


namespace protolayer
{

namespace evaluators
{

FaceIntermediates::FaceIntermediates(subdivision::Face& face) :
  _face(&face)
{
  _normal = new float[4];

  _relativePositions = new float* [_face->getNumberHalfEdges() - 1];
  for (int i = 0; i < _face->getNumberHalfEdges(); i++) {
    _relativePositions[i] = new float[4];
  }

  updateRelativePositions();
  updateNormal();
}


FaceIntermediates::~FaceIntermediates()
{
}


float* FaceIntermediates::getNormal()
{
  return _normal;
}


subdivision::Face& FaceIntermediates::getFace()
{
  return *_face;
}


void FaceIntermediates::updateRelativePositions()
{
  subdivision::Vertex& start = _face->getHalfEdge(0).getFromVertex();
  for (int i = 1; i < _face->getNumberHalfEdges(); i++) {
    _relativePositions[i][0] =
      _face->getHalfEdge(i).getFromVertex()._coordinates[0] - start._coordinates[0];
    _relativePositions[i][1] =
      _face->getHalfEdge(i).getFromVertex()._coordinates[1] - start._coordinates[1];
    _relativePositions[i][2] =
      _face->getHalfEdge(i).getFromVertex()._coordinates[2] - start._coordinates[2];
  }
}


void FaceIntermediates::updateNormal()
{
  _normal[0] = 0;
  _normal[1] = 0;
  _normal[2] = 0;
  _normal[3] = 1;

  float temp[3];
  for (int i = 2; i < _face->getNumberHalfEdges(); i++) {
    linearalgebra::crossProduct(_relativePositions[i - 2],
                                _relativePositions[i - 1],
                                temp);
    _normal[0] += temp[0];
    _normal[1] += temp[1];
    _normal[2] += temp[2];
  }
}


}


}
