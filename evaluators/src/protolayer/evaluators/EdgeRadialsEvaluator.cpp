#include "EdgeRadialsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

EdgeRadialsEvaluator::EdgeRadialsEvaluator(FaceNormalsEvaluator& faceNormalsEvaluator,
                                           EdgeDirectionsEvaluator& edgeDirectionsEvaluator) :
  _faceNormalsEvaluator(&faceNormalsEvaluator),
  _edgeDirectionsEvaluator(&edgeDirectionsEvaluator)
{
  subdivision::Mesh& firstMesh = faceNormalsEvaluator.getMesh();
  subdivision::Mesh& secondMesh = edgeDirectionsEvaluator.getMesh();

  assert(&firstMesh == &secondMesh);

  
}


subdivision::Mesh& EdgeRadialsEvaluator::getMesh()
{
  return _faceNormalsEvaluator->getMesh();
}


float* EdgeRadialsEvaluator::getRadial(subdivision::Face& face,
                                       subdivision::Edge& edge)
{
  EdgeRadialMapType& radialMap = *(_faceEdgeRadials[&face]);
  return radialMap[&edge];
}


}


}
