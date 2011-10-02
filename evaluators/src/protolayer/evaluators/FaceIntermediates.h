#ifndef PROTOLAYER_EVALUATORS_FACEINTERMEDIATES_H
#define PROTOLAYER_EVALUATORS_FACEINTERMEDIATES_H

#include <map>

#include <protolayer/protolayer-subdivision.h>


namespace protolayer
{

namespace evaluators
{

class FaceIntermediates
{
private:
  /** TODO: Documentation */
  subdivision::Face* _face;

  /** TODO: Documentation */
  float** _relativePositions;

  /** TODO: Documentation */
  float* _normal;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit FaceIntermediates(subdivision::Face& face);

  /**
   * TODO: Documentation
   *
   */
  ~FaceIntermediates();

  /**
   * TODO: Documentation
   *
   */
  float* getNormal();

  /**
   * TODO: Documentation
   *
   */
  subdivision::Face& getFace();

  /**
   * TODO: Documentation
   *
   */
  void updateRelativePositions();

  /**
   * TODO: Documentation
   *
   */
  void updateNormal();

};


}


}


#endif // PROTOLAYER_EVALUATORS_FACEINTERMEDIATES_H
