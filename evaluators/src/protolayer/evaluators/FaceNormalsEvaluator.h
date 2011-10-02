#ifndef PROTOLAYER_EVALUATORS_FACENORMALSEVALUATOR_H
#define PROTOLAYER_EVALUATORS_FACENORMALSEVALUATOR_H

#include <map>

#include <protolayer/protolayer-subdivision.h>

#include "FaceIntermediates.h"


namespace protolayer
{

namespace evaluators
{

class FaceNormalsEvaluator
{
private:
  /** TODO: Documentation */
  typedef std::map <subdivision::Face*, FaceIntermediates*> FaceIntermediatesMapType;

private:
  /** TODO: Documentation */
  subdivision::Mesh* _mesh;

  /** TODO: Documentation */
  FaceIntermediatesMapType _faceIntermediates;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit FaceNormalsEvaluator(subdivision::Mesh& mesh);

  /**
   * TODO: Documentation
   *
   */
  subdivision::Mesh& getMesh();

  /**
   * TODO: Documentation
   *
   */
  float* getNormal(subdivision::Face& face);

};


}


}


#endif // PROTOLAYER_EVALUATORS_FACENORMALSEVALUATOR_H
