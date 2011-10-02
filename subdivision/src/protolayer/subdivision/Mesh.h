#ifndef PROTOLAYER_SUBDIVISION_MESH_H
#define PROTOLAYER_SUBDIVISION_MESH_H

#include <stdio.h>
#include <map.h>

#include "Vertex.h"
#include "Face.h"
#include "HalfEdge.h"
#include "Edge.h"
#include "Face.h"
#include "Flower.h"


namespace protolayer
{

namespace subdivision
{

class Mesh
{
private:
  /** TODO: Documentation */
  typedef std::vector <Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <Face*> FaceVectorType;

  /** TODO: Documentation */
  typedef std::map <Vertex*, Flower*> VertexFlowerMapType;

  /** TODO: Documentation */
  typedef std::map <Vertex*, float*> VertexNormalMapType;

  /** TODO: Documentation */
  typedef std::map <HalfEdge*, float*> HalfEdgeDirectionMapType;

  /** TODO: Documentation */
  typedef std::map <Face*, float*> FaceNormalMapType;

private:
  /** TODO: Documentation */
  bool _evaluateVertexNormals;

  /** TODO: Documentation */
  VertexVectorType _vertices;

  /** TODO: Documentation */
  EdgeVectorType _edges;

  /** TODO: Documentation */
  FaceVectorType _faces;

  /** TODO: Documentation */
  VertexFlowerMapType _vertexFlowerMap;

  /** TODO: Documentation */
  VertexNormalMapType _vertexNormalMap;

  /** TODO: Documentation */
  HalfEdgeDirectionMapType _halfEdgeDirectionMap;

  /** TODO: Documentation */
  FaceNormalMapType _faceNormalMap;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Mesh();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Mesh();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluateVertexNormals();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluateFaceNormals();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluateEdgeDirections();

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex* createVertex();

  /**
   * TODO: Documentation
   * <p>
   */
  Edge* createEdge(int firstVertexIndex, int secondVertexIndex);

  /**
   * TODO: Documentation
   * <p>
   */
  Edge* createEdge(Vertex& firstVertex, Vertex& secondVertex);

  /**
   * TODO: Documentation
   * <p>
   */
  Face* createFace(int vertexIndex0, int vertexIndex1, int vertexIndex2);

  /**
   * TODO: Documentation
   * <p>
   */
  Face* createFace(int vertexIndex0, int vertexIndex1, int vertexIndex2, int vertexIndex3);

  /**
   * TODO: Documentation
   * <p>
   */
  Face* createFace(Vertex& vertex0, Vertex& vertex1, Vertex& vertex2);

  /**
   * TODO: Documentation
   * <p>
   */
  Face* createFace(Vertex& vertex0, Vertex& vertex1, Vertex& vertex2, Vertex& vertex3);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Vertex& vertex);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Edge& edge);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Face& face);

  /**
   * TODO: Documentation
   * <p>
   */
  const VertexVectorType& getVertices() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const EdgeVectorType& getEdges() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const FaceVectorType& getFaces() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberVertices() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberEdges() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberFaces() const;

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex& getVertex(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  Edge& getEdge(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  Face& getFace(int index);

  /**
   * TODO: Documentation
   *
   */
  HalfEdge& getHalfEdge(Vertex& from, Vertex& to);

  /**
   * TODO: Documentation
   * <p>
   */
  void detectBoundaries();

  /**
   * TODO: Documentation
   * <p>
   */
  void detectFlowers();

private:
  /**
   * TODO: Documentation
   *
   */
  Mesh(const Mesh& mesh);

  /**
   * TODO: Documentation
   *
   */
  Mesh& operator=(const Mesh& mesh);

};


}


}


#endif // PROTOLAYER_SUBDIVISION_MESH_H
