#include "EdgeDirectionsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

EdgeDirectionsEvaluator::EdgeDirectionsEvaluator(subdivision::Mesh& mesh) :
  _mesh(&mesh)
{
  for (int i = 0; i < mesh.getNumberEdges(); i++) {
    subdivision::Edge& edge = mesh.getEdge(i);

    subdivision::HalfEdge& firstHalfEdge = edge.getFirstHalf();

    float* firstDirection = new float[4];
    firstDirection[0] =  firstHalfEdge.getToVertex()._coordinates[0] -
      firstHalfEdge.getFromVertex()._coordinates[0];
    firstDirection[1] = firstHalfEdge.getToVertex()._coordinates[1] -
      firstHalfEdge.getFromVertex()._coordinates[1];
    firstDirection[2] = firstHalfEdge.getToVertex()._coordinates[2] -
      firstHalfEdge.getFromVertex()._coordinates[2];
    firstDirection[3] = 1;

    _halfEdgeDirections[&firstHalfEdge] = firstDirection;

    subdivision::HalfEdge& secondHalfEdge = edge.getSecondHalf();

    float* secondDirection = new float[4];
    secondDirection[0] = -firstDirection[0];
    secondDirection[1] = -firstDirection[1];
    secondDirection[2] = -firstDirection[2];
    secondDirection[3] = 1;

    _halfEdgeDirections[&secondHalfEdge] = secondDirection;
  }
}


EdgeDirectionsEvaluator::~EdgeDirectionsEvaluator()
{
  HalfEdgeDirectionsMapType::iterator iter;
  for(iter = _halfEdgeDirections.begin(); iter != _halfEdgeDirections.end(); iter++) {
    delete[] iter->second;
  }
}


subdivision::Mesh& EdgeDirectionsEvaluator::getMesh()
{
  return *_mesh;
}


float* EdgeDirectionsEvaluator::getDirection(subdivision::HalfEdge& halfEdge)
{
  return _halfEdgeDirections[&halfEdge];
}


}


}
