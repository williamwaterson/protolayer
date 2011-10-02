#ifndef PROTOLAYER_SUBDIVISION_PETAL_H
#define PROTOLAYER_SUBDIVISION_PETAL_H

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

class Petal
{
  /** TODO: Documentation */
  typedef std::vector <Face*> FaceVectorType;

private:
  /** TODO: Documentation */
  Vertex* _vertex;

  /** TODO: Documentation */
  FaceVectorType _faces;

public:
  /**
   * TODO: Documentation
   *
   */
  Petal(Vertex& vertex);

  /**
   * TODO: Documentation
   *
   */
  ~Petal();

  /**
   * TODO: Documentation
   *
   */
  int getNumberFaces() const;

  /**
   * TODO: Documentation
   *
   */
  Vertex& getVertex();

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

  /**
   * TODO: Documentation
   *
   */
  void removeFace(Face& face);

  /**
   * TODO: Documentation
   *
   */
  void clear();

};


}


}


#endif // PROTOLAYER_SUBDIVISION_PETAL_H
