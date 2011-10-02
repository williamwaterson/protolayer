#ifndef PROTOLAYER_SUBDIVISION_GROUP_H
#define PROTOLAYER_SUBDIVISION_GROUP_H

#include <stdio.h>
#include <map.h>

#include "protolayer/protolayer-linearalgebra.h"

#include "Vertex.h"
#include "Propagation.h"
#include "HalfEdge.h"
#include "Edge.h"

namespace protolayer
{

namespace subdivision
{

class Group
{
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
  Group();

  /**
   * TODO: Documentation
   *
   */
  ~Group();

  /**
   * TODO: Documentation
   *
   */
  int getNumberFaces() const;

  /**
   * TODO: Documentation
   *
   */
  void addFace(Face& face);

  /**
   * TODO: Documentation
   *
   */
  Face& getFace(int index);

  /**
   * TODO: Documentation
   *
   */
  void walk();

};


}


}


#endif // PROTOLAYER_SUBDIVISION_GROUP_H
