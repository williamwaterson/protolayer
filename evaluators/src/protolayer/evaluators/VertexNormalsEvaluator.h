#ifndef PROTOLAYER_EVALUATORS_VERTEXNORMALSEVALUATOR_H
#define PROTOLAYER_EVALUATORS_VERTEXNORMALSEVALUATOR_H

#include <map>

#include <protolayer/protolayer-subdivision.h>

#include "FaceNormalsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

class VertexNormalsEvaluator
{
private:
  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, float*> VertexNormalsMapType;

private:
  /** TODO: Documentation */
  FaceNormalsEvaluator* _faceNormalsEvaluator;

  /** TODO: Documentation */
  VertexNormalsMapType _vertexNormals;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit VertexNormalsEvaluator(FaceNormalsEvaluator& evaluator);

  /**
   * TODO: Documentation
   *
   */
  ~VertexNormalsEvaluator();

  /**
   * TODO: Documentation
   *
   */
  float* getNormal(subdivision::Vertex& vertex);

};


}


}


#endif // PROTOLAYER_EVALUATORS_VERTEXNORMALSEVALUATOR_H
