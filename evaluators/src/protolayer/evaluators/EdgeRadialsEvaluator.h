#ifndef PROTOLAYER_EVALUATORS_EDGERADIALSEVALUATOR_H
#define PROTOLAYER_EVALUATORS_EDGERADIALSEVALUATOR_H

#include <map>
#include <assert.h>

#include <protolayer/protolayer-subdivision.h>

#include "FaceNormalsEvaluator.h"
#include "EdgeDirectionsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

class EdgeRadialsEvaluator
{
private:
  /** TODO: Documentation */
  typedef std::map <subdivision::Edge*, float*> EdgeRadialMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Face*, EdgeRadialMapType*> FaceEdgeRadialMapType;

private:
  /** TODO: Documentation */
  FaceNormalsEvaluator* _faceNormalsEvaluator;

  /** TODO: Documentation */
  EdgeDirectionsEvaluator* _edgeDirectionsEvaluator;

  /** TODO: Documentation */
  FaceEdgeRadialMapType _faceEdgeRadials;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit EdgeRadialsEvaluator(FaceNormalsEvaluator& faceNormalsEvaluator,
                                EdgeDirectionsEvaluator& edgeDirectionsEvaluator);

  /**
   * TODO: Documentation
   *
   */
  subdivision::Mesh& getMesh();

  /**
   * TODO: Documentation
   *
   */
  float* getRadial(subdivision::Face& face, subdivision::Edge& edge);

};


}


}


#endif // PROTOLAYER_EVALUATORS_EDGERADIALSEVALUATOR_H
