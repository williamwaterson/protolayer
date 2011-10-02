#ifndef PROTOLAYER_SUBDIVISION_PROPAGATION_H
#define PROTOLAYER_SUBDIVISION_PROPAGATION_H

#include <stdio.h>
#include <vector.h>

#include "protolayer/protolayer-linearalgebra.h"

#include "forward.h"


namespace protolayer
{

namespace subdivision
{

class Propagation
{
  /** TODO: Documentation */
  friend class LoopSubdivision;

  /** TODO: Documentation */
  typedef std::vector <Face*> FaceVectorType;

private:
  /** TODO: Documentation */
  FaceVectorType _faces;

public:
  /**
   * TODO: Documentation
   *
   */
  Propagation();

  /**
   * TODO: Documentation
   *
   */
  int getNumberFaces() const;

  /**
   * TODO: Documentation
   *
   */
  Face& getFace(int index);

  /**
   * TODO: Documentation
   *
   */
  void addFace(Face& face);

};


}


}


#endif // PROTOLAYER_SUBDIVISION_PROPAGATION_H
