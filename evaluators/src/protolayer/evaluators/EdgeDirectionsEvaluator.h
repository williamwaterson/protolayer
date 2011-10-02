#ifndef PROTOLAYER_EVALUATORS_EDGEDIRECTIONSEVALUATOR_H
#define PROTOLAYER_EVALUATORS_EDGEDIRECTIONSEVALUATOR_H

#include <map>

#include <protolayer/protolayer-subdivision.h>


namespace protolayer
{

namespace evaluators
{

class EdgeDirectionsEvaluator
{
private:
  /** TODO: Documentation */
  typedef std::map <subdivision::HalfEdge*, float*> HalfEdgeDirectionsMapType;

private:
  /** TODO: Documentation */
  subdivision::Mesh* _mesh;

  /** TODO: Documentation */
  HalfEdgeDirectionsMapType _halfEdgeDirections;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit EdgeDirectionsEvaluator(subdivision::Mesh& mesh);

  /**
   * TODO: Documentation
   *
   */
  ~EdgeDirectionsEvaluator();

  /**
   * TODO: Documentation
   *
   */
  subdivision::Mesh& getMesh();

  /**
   * TODO: Documentation
   *
   */
  float* getDirection(subdivision::HalfEdge& halfEdge);

};


}


}


#endif // PROTOLAYER_EVALUATORS_EDGEDIRECTIONSEVALUATOR_H
