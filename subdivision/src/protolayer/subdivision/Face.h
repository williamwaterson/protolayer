#ifndef PROTOLAYER_SUBDIVISION_FACE_H
#define PROTOLAYER_SUBDIVISION_FACE_H

#include <assert.h>
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

class Face
{
  /** TODO: Documentation */
  typedef std::vector <Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <HalfEdge*> HalfEdgeVectorType;

  /** TODO: Documentation */
  typedef std::map <Vertex*, float*> VertexRadialMapType;

  /** TODO: Documentation */
  typedef std::map <HalfEdge*, float*> HalfEdgeRadialMapType;

  /** TODO: Documentation */
  typedef std::map <Vertex*, float*> VertexRelativePositionMapType;

  /** TODO: Documentation */
  void* _object;

private:
  /** TODO: Documentation */
  float _normal[4];

  /** TODO: Documentation */
  float** _relativePositions;

  /** TODO: Documentation */
  Vertex* _center;

  /** TODO: Documentation */
  HalfEdgeVectorType _halfEdges;

  /** TODO: Documentation */
  VertexRadialMapType _vertexRadials;

  /** TODO: Documentation */
  VertexRelativePositionMapType _relativePositionMap;

  /** TODO: Documentation */
  HalfEdgeRadialMapType _halfEdgeRadials;

  /** TODO: Documentation */
  Propagation* _propagation;

public:
  /**
   * TODO: Documentation
   *
   */
  Face(EdgeVectorType& edges,
       VertexVectorType& vertices,
       int a,
       int b,
       int c);

  /**
   * TODO: Documentation
   *
   */
  Face(EdgeVectorType& edges,
       VertexVectorType& vertices,
       int a,
       int b,
       int c,
       int d);

  /**
   * TODO: Documentation
   *
   */
  Face(EdgeVectorType& edges,
       Vertex& vertexA,
       Vertex& vertexB,
       Vertex& vertexC);

  /**
   * TODO: Documentation
   *
   */
  Face(EdgeVectorType& edges,
       Vertex& vertexA,
       Vertex& vertexB,
       Vertex& vertexC,
       Vertex& vertexD);

  /**
   * TODO: Documentation
   *
   */
  ~Face();

  /**
   * TODO: Documentation
   *
   */
  int getNumberVertices() const;

  /**
   * TODO: Documentation
   *
   */
  int getNumberHalfEdges() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getNormal() const;

  /**
   * TODO: Documentation
   *
   */
  Vertex& getVertex(int index);

  /**
   * TODO: Documentation
   *
   */
  HalfEdge& getHalfEdge(int index);

  /**
   * TODO: Documentation
   *
   */
  bool isEvaluatesNormal() const;

  /**
   * TODO: Documentation
   *
   */
  bool isEvaluatesVertexRadials() const;

  /**
   * TODO: Documentation
   *
   */
  bool isEvaluatesEdgeRadials() const;

  /**
   * TODO: Documentation
   *
   */
  void setEvaluateNormal(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setCenter(Vertex& vertex);

  /**
   * TODO: Documentation
   *
   */
  Vertex* getCenter();

  /**
   * TODO: Documentation
   *
   */
  void setEvaluateVertexRadials(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setEvaluateEdgeRadials(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setObject(void* object);

  /**
   * TODO: Documentation
   *
   */
  void* getObject();

  /**
   * TODO: Documentation
   *
   */
  void evaluateNormal();

  /**
   * TODO: Documentation
   *
   */
  void updateVertexNormals();

  /**
   * TODO: Documentation
   *
   */
  void setTrackPropagation(bool flag);

  /**
   * TODO: Documentation
   *
   */
  bool isTrackingPropagation() const;

  /**
   * TODO: Documentation
   *
   */
  Propagation* getPropagation();

  /**
   * TODO: Documentation
   *
   */
  void updateNormal();

  /**
   * TODO: Documentation
   *
   */
  void updateRelativePositions();

private:
  /**
   * TODO: Documentation
   *
   */
  void initNormals();

  /**
   * TODO: Documentation
   *
   */
  void evaluateVertexRadials();

  /**
   * TODO: Documentation
   *
   */
  void evaluateEdgeRadials();

  /**
   * TODO: Documentation
   *
   */
  void extractHalfEdge(EdgeVectorType& edges,
                       VertexVectorType& vertices,
                       int fromVertex,
                       int toVertex);

  /**
   * TODO: Documentation
   *
   */
  void extractHalfEdge(EdgeVectorType& edges,
                       Vertex& fromVertex,
                       Vertex& toVertex);

  /**
   * TODO: Documentation
   *
   */
  void evaluateRelativePositions();

};


}


}


#endif // PROTOLAYER_SUBDIVISION_FACE_H
