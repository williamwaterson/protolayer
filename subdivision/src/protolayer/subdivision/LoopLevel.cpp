#include "LoopLevel.h"

namespace protolayer
{

namespace subdivision
{

void LoopLevel::evaluatePositions(Mesh& subdivision)
{
  for (int i = 0; i < subdivision.getNumberVertices(); i++) {
    Vertex& vertex = subdivision.getVertex(i);
    Vertex* mapped = vertex.getMapping();

    int valence = mapped->_valency;

    if (vertex.isCorner()) {
      mapped->_beta = 0;
      mapped->_alpha = 1;

    } else if (vertex.isBoundary()) {
      mapped->_beta = 1;
      mapped->_beta /= 8;

      mapped->_alpha = 3;
      mapped->_alpha /= 4;

    } else {
      float factor = 2 * M_PI;
      factor /= valence;
      factor = cos(factor);
      factor /= 4;

      float factor2 = 3;
      factor2 /= 8;

      float factor3 = factor + factor2;
      factor3 *= factor3;

      float factor4 = 5;
      factor4 /= 8;

      mapped->_beta = factor4 - factor3;
      mapped->_beta /= valence;

      mapped->_alpha = 1 - valence * mapped->_beta;
    }

    mapped->_coordinates[0] = vertex._coordinates[0] * mapped->_alpha;
    mapped->_coordinates[1] = vertex._coordinates[1] * mapped->_alpha;
    mapped->_coordinates[2] = vertex._coordinates[2] * mapped->_alpha;
  }

  for (int i = 0; i < subdivision.getNumberEdges(); i++) {
    Edge& edge = subdivision.getEdge(i);
    HalfEdge& halfEdge = edge.getFirstHalf();

    Vertex& fromVertex = halfEdge.getFromVertex();
    Vertex& toVertex = halfEdge.getToVertex();

    Vertex* mappedFromVertex = fromVertex.getMapping();
    Vertex* mappedToVertex = toVertex.getMapping();

    Vertex* midpoint = halfEdge.getMidpoint();

    if (edge.isBoundary()) {

      midpoint->_coordinates[0] = fromVertex._coordinates[0] + toVertex._coordinates[0];
      midpoint->_coordinates[1] = fromVertex._coordinates[1] + toVertex._coordinates[1];
      midpoint->_coordinates[2] = fromVertex._coordinates[2] + toVertex._coordinates[2];

      midpoint->_coordinates[0] /= 2;
      midpoint->_coordinates[1] /= 2;
      midpoint->_coordinates[2] /= 2;

      if (!mappedFromVertex->isCorner()) {
	mappedFromVertex->_coordinates[0] += toVertex._coordinates[0] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[1] += toVertex._coordinates[1] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[2] += toVertex._coordinates[2] * mappedFromVertex->_beta;
      }

      if (!mappedToVertex->isCorner()) {
	mappedToVertex->_coordinates[0] += fromVertex._coordinates[0] * mappedToVertex->_beta;
	mappedToVertex->_coordinates[1] += fromVertex._coordinates[1] * mappedToVertex->_beta;
	mappedToVertex->_coordinates[2] += fromVertex._coordinates[2] * mappedToVertex->_beta;
      }

    } else {

      midpoint->_coordinates[0] = fromVertex._coordinates[0] + toVertex._coordinates[0];
      midpoint->_coordinates[1] = fromVertex._coordinates[1] + toVertex._coordinates[1];
      midpoint->_coordinates[2] = fromVertex._coordinates[2] + toVertex._coordinates[2];

      midpoint->_coordinates[0] *= 3;
      midpoint->_coordinates[1] *= 3;
      midpoint->_coordinates[2] *= 3;

      midpoint->_coordinates[0] /= 8;
      midpoint->_coordinates[1] /= 8;
      midpoint->_coordinates[2] /= 8;

      if (mappedFromVertex->isCorner()) {
	// Do nothing to mapped from vertex
      } else if (mappedFromVertex->isBoundary()) {
	// Do nothing to mapped from vertex
      } else {
	mappedFromVertex->_coordinates[0] += toVertex._coordinates[0] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[1] += toVertex._coordinates[1] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[2] += toVertex._coordinates[2] * mappedFromVertex->_beta;
      }

      if (mappedToVertex->isCorner()) {
	// Do nothing to mapped to vertex
      } else if (mappedToVertex->isBoundary()) {
	// Do nothing to mapped to vertex
      } else {
	mappedToVertex->_coordinates[0] += fromVertex._coordinates[0] * mappedToVertex->_beta;
	mappedToVertex->_coordinates[1] += fromVertex._coordinates[1] * mappedToVertex->_beta;
	mappedToVertex->_coordinates[2] += fromVertex._coordinates[2] * mappedToVertex->_beta;
      }

    }
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    Face& face = subdivision.getFace(i);

    {
      HalfEdge& halfEdge = face.getHalfEdge(0);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();
	Vertex& from = face.getHalfEdge(2).getFromVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 8;
	midpoint->_coordinates[1] += from._coordinates[1] / 8;
	midpoint->_coordinates[2] += from._coordinates[2] / 8;
      }
    }

    {
      HalfEdge& halfEdge = face.getHalfEdge(1);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();

	Vertex& from = face.getHalfEdge(0).getFromVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 8;
	midpoint->_coordinates[1] += from._coordinates[1] / 8;
	midpoint->_coordinates[2] += from._coordinates[2] / 8;
      }
    }

    {
      HalfEdge& halfEdge = face.getHalfEdge(2);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();
	Vertex& from = face.getHalfEdge(1).getFromVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 8;
	midpoint->_coordinates[1] += from._coordinates[1] / 8;
	midpoint->_coordinates[2] += from._coordinates[2] / 8;
      }
    }

  }
}


void LoopLevel::subdivideMesh(Mesh& subdivision)
{
  for (int i = 0; i < subdivision.getNumberVertices(); i++) {
    Vertex& vertex = subdivision.getVertex(i);
    Vertex* created = _mesh.createVertex();
    vertex.setMapping(*created);

    created->_isBoundary = vertex._isBoundary;
    created->_isCorner = vertex._isCorner;
  }

  for (int i = 0; i < subdivision.getNumberEdges(); i++) {
    Edge& edge = subdivision.getEdge(i);
    bool isBoundary = edge.isBoundary();

    HalfEdge& firstHalfEdge = edge.getFirstHalf();
    HalfEdge& secondHalfEdge = edge.getSecondHalf();
    
    Vertex& fromVertex = firstHalfEdge.getFromVertex();
    Vertex& toVertex = firstHalfEdge.getToVertex();

    Vertex* midpoint = _mesh.createVertex();
    if (isBoundary) {
      midpoint->setBoundary(true);
    }

    firstHalfEdge.setMidpoint(*midpoint);
    secondHalfEdge.setMidpoint(*midpoint);

    HalfEdge& halfEdge = edge.getFirstHalf();
    Vertex* mappedFromVertex = halfEdge.getFromVertex().getMapping();
    Vertex* mappedToVertex = halfEdge.getToVertex().getMapping();

    Edge* created = _mesh.createEdge(*mappedFromVertex, *midpoint);
    if (isBoundary) {
      created->setBoundary(true);
    }

    created = _mesh.createEdge(*midpoint, *mappedToVertex);
    if (isBoundary) {
      created->setBoundary(true);
    }

    mappedFromVertex->incrementValency();
    mappedToVertex->incrementValency();
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    Face& face = subdivision.getFace(i);

    HalfEdge& halfEdge0 = face.getHalfEdge(0);
    HalfEdge& halfEdge1 = face.getHalfEdge(1);
    HalfEdge& halfEdge2 = face.getHalfEdge(2);

    Vertex* subVertex0 = halfEdge0.getMidpoint();
    Vertex* subVertex1 = halfEdge1.getMidpoint();
    Vertex* subVertex2 = halfEdge2.getMidpoint();

    _mesh.createEdge(*subVertex0, *subVertex1);
    _mesh.createEdge(*subVertex1, *subVertex2);
    _mesh.createEdge(*subVertex2, *subVertex0);

    Face* createdFace = _mesh.createFace(*subVertex0, *subVertex1, *subVertex2);
    if (face.isTrackingPropagation()) {
      face.getPropagation()->addFace(*createdFace);
    }

    createdFace = _mesh.createFace(*(halfEdge0.getFromVertex().getMapping()), *subVertex0, *subVertex2);
    if (face.isTrackingPropagation()) {
      face.getPropagation()->addFace(*createdFace);
    }

    createdFace = _mesh.createFace(*(halfEdge1.getFromVertex().getMapping()), *subVertex1, *subVertex0);
    if (face.isTrackingPropagation()) {
      face.getPropagation()->addFace(*createdFace);
    }

    createdFace = _mesh.createFace(*(halfEdge2.getFromVertex().getMapping()), *subVertex2, *subVertex1);
    if (face.isTrackingPropagation()) {
      face.getPropagation()->addFace(*createdFace);
    }
  }  
}


LoopLevel::LoopLevel(Mesh& subdivision)
{
  subdivideMesh(subdivision);
  evaluatePositions(subdivision);
}


Mesh& LoopLevel::getMesh()
{
  return _mesh;
}


const Mesh& LoopLevel::getMesh() const
{
  return _mesh;
}


}


}
