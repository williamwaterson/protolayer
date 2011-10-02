#ifndef PROTOLAYER_SUBDIVISION_LOFTINGLEVEL_H
#define PROTOLAYER_SUBDIVISION_LOFTINGLEVEL_H

#include <stdio.h>
#include <map.h>

#include "protolayer/protolayer-linearalgebra.h"

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include "Mesh.h"


namespace protolayer
{

namespace subdivision
{

class LoftingLevel
{
private:
  /** TODO: Documentation */
  typedef std::vector <Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <Face*> FaceVectorType;

  /** TODO: Documentation */
  typedef std::map <HalfEdge*, Vertex*> HalfEdgeVertexMapType;;

private:
  /** TODO: Documentation */
  Mesh _mesh;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit LoftingLevel(Mesh& subdivision);

  /**
   * TODO: Documentation
   * <p>
   */
  Mesh& getMesh();

  /**
   * TODO: Documentation
   * <p>
   */
  const Mesh& getMesh() const;

private:
  /**
   * TODO: Documentation
   *
   */
  void evaluatePositions(Mesh& mesh);

  /**
   * TODO: Documentation
   *
   */
  void subdivideMesh(Mesh& mesh);

};


}


}


#endif // PROTOLAYER_SUBDIVISION_LOFTINGLEVEL_H
