#ifndef PROTOLAYER_SUBDIVISION_LOFTEDSUBDIVISION_H
#define PROTOLAYER_SUBDIVISION_LOFTEDSUBDIVISION_H

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

class LoftedSubdivision
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
  subdivision::Mesh* _polylineNetwork;

  /** TODO: Documentation */
  subdivision::BicubicLevel* _curveNetwork;

  /** TODO: Documentation */
  subdivision::Mesh* _baseMesh;

  /** TODO: Documentation */
  subdivision::CatmullClarkMesh* _limitSurface;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit LoftedSubdivision();

  /**
   * TODO: Documentation
   * <p>
   */
  subdivision::Mesh& getPolylineMesh();

  /**
   * TODO: Documentation
   * <p>
   */
  const subdivision::BicubicLevel& getCurveNetwork() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const subdivision::Mesh& getBaseMesh() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const subdivision::CatmullClarkLevel& getLimitSurface() const;

};


}


}


#endif // PROTOLAYER_SUBDIVISION_LOFTEDSUBDIVISION_H
