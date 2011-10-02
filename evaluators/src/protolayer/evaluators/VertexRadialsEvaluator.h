#ifndef PROTOLAYER_EVALUATORS_VERTEXRADIALSEVALUATOR_H
#define PROTOLAYER_EVALUATORS_VERTEXRADIALSEVALUATOR_H

#include <map>

#include <protolayer/protolayer-subdivision.h>

#include "EdgeRadialsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

class VertexRadialsEvaluator
{
private:
  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, float*> VertexRadialMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Face*, VertexRadialMapType*> FaceVertexRadialMapType;

private:
  /** TODO: Documentation */
  EdgeRadialsEvaluator* _edgeRadialsEvaluator;

  /** TODO: Documentation */
  FaceVertexRadialMapType _faceVertexRadials;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit VertexRadialsEvaluator(EdgeRadialsEvaluator& edgeRadialsEvaluator);

  /**
   * TODO: Documentation
   *
   */
  float* getRadial(subdivision::Face& face, subdivision::Vertex& vertex);

};


}


}


#endif // PROTOLAYER_EVALUATORS_VERTEXRADIALSEVALUATOR_H
