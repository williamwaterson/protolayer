#ifndef PROTOLAYER_SUBDIVISION_NONMANIFOLDLEVEL_H
#define PROTOLAYER_SUBDIVISION_NONMANIFOLDLEVEL_H

#include <assert.h>
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

class NonmanifoldLevel
{
private:
  /** TODO: Documentation */
  typedef std::vector <subdivision::Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Face*> FaceVectorType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, float*> VertexPositionMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, int> VertexEdgeCountMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, VertexVectorType*> VertexAdjacencyMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::Vertex*, subdivision::Vertex*> VertexVertexMapType;

  /** TODO: Documentation */
  typedef std::map <subdivision::HalfEdge*, subdivision::Vertex*> HalfEdgeVertexMapType;;

  /** TODO: Documentation */
  typedef std::map <subdivision::Face*, subdivision::Vertex*> FaceVertexMapType;;

private:
  /** TODO: Documentation */
  subdivision::Mesh _subdivision;

  /** TODO: Documentation */
  HalfEdgeVertexMapType _midpointMappings;

  /** TODO: Documentation */
  FaceVertexMapType _centerMappings;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit NonmanifoldLevel(subdivision::Mesh& subdivision);

  /**
   * TODO: Documentation
   * <p>
   */
  subdivision::Mesh& getMesh();

  /**
   * TODO: Documentation
   * <p>
   */
  const subdivision::Mesh& getMesh() const;

private:
  /**
   * TODO: Documentation
   *
   */
  subdivision::Vertex& createVertex(subdivision::Vertex& copyFromVertex);

  /**
   * TODO: Documentation
   *
   */
  subdivision::HalfEdge& getHalfEdge(subdivision::Vertex& from,
                                  subdivision::Vertex& to);

};


}


}


#endif // PROTOLAYER_SUBDIVISION_NONMANIFOLDLEVEL_H
