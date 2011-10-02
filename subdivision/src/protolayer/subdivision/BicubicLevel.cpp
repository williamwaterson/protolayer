#include "CatmullClarkLevel.h"


namespace protolayer
{

namespace subdivision
{

void CatmullClarkLevel::evaluatePositions(Mesh& subdivision)
{
  for (int i = 0; i < subdivision.getNumberVertices(); i++) {
    Vertex& vertex = subdivision.getVertex(i);
    Vertex* mapping = vertex.getMapping();

    if (vertex.isCorner()) {
      mapping->_gamma = 0;
      mapping->_beta = 0;
      mapping->_alpha = 1;

    } else if (vertex.isBoundary()) {
      mapping->_gamma = 0;
      mapping->_gamma = 0;

      mapping->_beta = 1;
      mapping->_beta /= 8;

      mapping->_alpha = 3;
      mapping->_alpha /= 4;

    } else {
      mapping->_beta = 3;
      mapping->_beta /= 2;
      mapping->_beta /= mapping->_valency;
 
      mapping->_gamma = 1;
      mapping->_gamma /= 4;
      mapping->_gamma /= mapping->_valency;

      mapping->_alpha = 1 - mapping->_gamma - mapping->_beta;

      mapping->_beta /= mapping->_valency;
      mapping->_gamma /= mapping->_valency;
    }

    mapping->_coordinates[0] = vertex._coordinates[0] * mapping->_alpha;
    mapping->_coordinates[1] = vertex._coordinates[1] * mapping->_alpha;
    mapping->_coordinates[2] = vertex._coordinates[2] * mapping->_alpha;
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    Face& face = subdivision.getFace(i);
    Vertex* center = face.getCenter();

    float factor = 1;
    factor /= face.getNumberVertices();

    for (int j = 0; j < face.getNumberVertices(); j++) {
      center->_coordinates[0] += face.getVertex(j)._coordinates[0] * factor;
      center->_coordinates[1] += face.getVertex(j)._coordinates[1] * factor;
      center->_coordinates[2] += face.getVertex(j)._coordinates[2] * factor;
    }

    center->_coordinates[3] = 1;
  }

  for (int i = 0; i < subdivision.getNumberEdges(); i++) {
    Edge& edge = subdivision.getEdge(i);
    HalfEdge& halfEdge = edge.getFirstHalf();
    Vertex* midpoint = halfEdge.getMidpoint();

    Vertex& fromVertex = edge.getFirstHalf().getFromVertex();
    Vertex& toVertex = edge.getFirstHalf().getToVertex();

    Vertex* mappedFromVertex = fromVertex.getMapping();
    Vertex* mappedToVertex = toVertex.getMapping();

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

      float factor = 3;
      factor /= 8;

      midpoint->_coordinates[0] += halfEdge.getFromVertex()._coordinates[0] * factor;
      midpoint->_coordinates[1] += halfEdge.getFromVertex()._coordinates[1] * factor;
      midpoint->_coordinates[2] += halfEdge.getFromVertex()._coordinates[2] * factor;

      midpoint->_coordinates[0] += halfEdge.getToVertex()._coordinates[0] * factor;
      midpoint->_coordinates[1] += halfEdge.getToVertex()._coordinates[1] * factor;
      midpoint->_coordinates[2] += halfEdge.getToVertex()._coordinates[2] * factor;

      if (mappedFromVertex->isCorner()) {
	// Do nothing to mapped from vertex
      } else if (mappedFromVertex->isBoundary() && !mappedToVertex->isBoundary()) {
	// Do nothing to mapped from vertex
      } else {
	mappedFromVertex->_coordinates[0] += toVertex._coordinates[0] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[1] += toVertex._coordinates[1] * mappedFromVertex->_beta;
	mappedFromVertex->_coordinates[2] += toVertex._coordinates[2] * mappedFromVertex->_beta;
      }

      if (mappedToVertex->isCorner()) {
	// Do nothing to mapped to vertex
      } else if (!mappedFromVertex->isBoundary() && mappedToVertex->isBoundary()) {
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
	Vertex& to = face.getHalfEdge(2).getToVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 16;
	midpoint->_coordinates[1] += from._coordinates[1] / 16;
	midpoint->_coordinates[2] += from._coordinates[2] / 16;

	midpoint->_coordinates[0] += to._coordinates[0] / 16;
	midpoint->_coordinates[1] += to._coordinates[1] / 16;
	midpoint->_coordinates[2] += to._coordinates[2] / 16;
      }
    }

    {
      HalfEdge& halfEdge = face.getHalfEdge(1);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();
	Vertex& from = face.getHalfEdge(3).getFromVertex();
	Vertex& to = face.getHalfEdge(3).getToVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 16;
	midpoint->_coordinates[1] += from._coordinates[1] / 16;
	midpoint->_coordinates[2] += from._coordinates[2] / 16;

	midpoint->_coordinates[0] += to._coordinates[0] / 16;
	midpoint->_coordinates[1] += to._coordinates[1] / 16;
	midpoint->_coordinates[2] += to._coordinates[2] / 16;
      }
    }

    {
      HalfEdge& halfEdge = face.getHalfEdge(2);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();
	Vertex& from = face.getHalfEdge(0).getFromVertex();
	Vertex& to = face.getHalfEdge(0).getToVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 16;
	midpoint->_coordinates[1] += from._coordinates[1] / 16;
	midpoint->_coordinates[2] += from._coordinates[2] / 16;

	midpoint->_coordinates[0] += to._coordinates[0] / 16;
	midpoint->_coordinates[1] += to._coordinates[1] / 16;
	midpoint->_coordinates[2] += to._coordinates[2] / 16;
      }
    }

    {
      HalfEdge& halfEdge = face.getHalfEdge(3);
      if (!halfEdge.isBoundary()) {
	Vertex* midpoint = halfEdge.getMidpoint();
	Vertex& from = face.getHalfEdge(1).getFromVertex();
	Vertex& to = face.getHalfEdge(1).getToVertex();

	midpoint->_coordinates[0] += from._coordinates[0] / 16;
	midpoint->_coordinates[1] += from._coordinates[1] / 16;
	midpoint->_coordinates[2] += from._coordinates[2] / 16;

	midpoint->_coordinates[0] += to._coordinates[0] / 16;
	midpoint->_coordinates[1] += to._coordinates[1] / 16;
	midpoint->_coordinates[2] += to._coordinates[2] / 16;
      }
    }

    {
      Vertex& vertex = face.getVertex(0);
      if (!vertex.isBoundary()) {
	Vertex* mapping = vertex.getMapping();
	Vertex& opposite = face.getVertex(2);

	mapping->_coordinates[0] += opposite._coordinates[0] * mapping->_gamma;
	mapping->_coordinates[1] += opposite._coordinates[1] * mapping->_gamma;
	mapping->_coordinates[2] += opposite._coordinates[2] * mapping->_gamma;
      }
    }

    {
      Vertex& vertex = face.getVertex(1);
      if (!vertex.isBoundary()) {
	Vertex* mapping = vertex.getMapping();
	Vertex& opposite = face.getVertex(3);

	mapping->_coordinates[0] += opposite._coordinates[0] * mapping->_gamma;
	mapping->_coordinates[1] += opposite._coordinates[1] * mapping->_gamma;
	mapping->_coordinates[2] += opposite._coordinates[2] * mapping->_gamma;
      }
    }

    {
      Vertex& vertex = face.getVertex(2);
      if (!vertex.isBoundary()) {
	Vertex* mapping = vertex.getMapping();
	Vertex& opposite = face.getVertex(0);

	mapping->_coordinates[0] += opposite._coordinates[0] * mapping->_gamma;
	mapping->_coordinates[1] += opposite._coordinates[1] * mapping->_gamma;
	mapping->_coordinates[2] += opposite._coordinates[2] * mapping->_gamma;
      }
    }

    {
      Vertex& vertex = face.getVertex(3);
      if (!vertex.isBoundary()) {
	Vertex* mapping = vertex.getMapping();
	Vertex& opposite = face.getVertex(1);

	mapping->_coordinates[0] += opposite._coordinates[0] * mapping->_gamma;
	mapping->_coordinates[1] += opposite._coordinates[1] * mapping->_gamma;
	mapping->_coordinates[2] += opposite._coordinates[2] * mapping->_gamma;
      }
    }

  }

}


void CatmullClarkLevel::subdivideMesh(Mesh& subdivision)
{
  for (int i = 0; i < subdivision.getNumberVertices(); i++) {
    Vertex& vertex = subdivision.getVertex(i);
    Vertex& created = createVertex(vertex);
    vertex.setMapping(created);
  }

  for (int i = 0; i < subdivision.getNumberEdges(); i++) {
    Edge& edge = subdivision.getEdge(i);
    bool isBoundary = edge.isBoundary();

    HalfEdge& firstHalfEdge = edge.getFirstHalf();
    HalfEdge& secondHalfEdge = edge.getSecondHalf();
    
    Vertex& fromVertex = firstHalfEdge.getFromVertex();
    Vertex& toVertex = firstHalfEdge.getToVertex();

    Vertex* midpoint = new Vertex();
    if (isBoundary) {
      midpoint->setBoundary(isBoundary);
    }
    _subdivision.add(*midpoint);

    firstHalfEdge.setMidpoint(*midpoint);
    secondHalfEdge.setMidpoint(*midpoint);

    Vertex* mappedFromVertex = fromVertex.getMapping();
    Vertex* mappedToVertex = toVertex.getMapping();

    Edge* created = _subdivision.createEdge(*mappedFromVertex, *midpoint);
    if (isBoundary) {
      created->setBoundary(true);
    }

    created = _subdivision.createEdge(*midpoint, *mappedToVertex);
    if (isBoundary) {
      created->setBoundary(true);
    }

    mappedFromVertex->incrementValency();
    mappedToVertex->incrementValency();
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    Face& face = subdivision.getFace(i);
    Vertex* center = new Vertex();
    face.setCenter(*center);
    _subdivision.add(*center);

    for (int j = 0; j < face.getNumberHalfEdges(); j++) {
      HalfEdge& halfEdge = face.getHalfEdge(j);
      Vertex* midpoint = halfEdge.getMidpoint();
      Edge* edge = _subdivision.createEdge(*midpoint, *center);
    }
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    Face& face = subdivision.getFace(i);
    Vertex* center = face.getCenter();

    int numberEdges = face.getNumberHalfEdges();
    HalfEdge& lastHalfEdge = face.getHalfEdge(numberEdges - 1);
    Vertex* last = lastHalfEdge.getMidpoint();

    for (int j = 0; j < face.getNumberHalfEdges(); j++) {
      HalfEdge& halfEdge = face.getHalfEdge(j);
      Vertex& oldCorner = halfEdge.getFromVertex();
      Vertex* corner = oldCorner.getMapping();
      Vertex* next = halfEdge.getMidpoint();

      Face* createdFace = _subdivision.createFace(*corner, *next, *center, *last);
      if (face.isTrackingPropagation()) {
	face.getPropagation()->addFace(*createdFace);
      }

      last = next;
    }
  }
}


HalfEdge& CatmullClarkLevel::getHalfEdge(Vertex& from,
					 Vertex& to)
{
  HalfEdge* result = 0;
  for (int i = 0; i < _subdivision.getNumberEdges(); i++) {
    Edge& edge = _subdivision.getEdge(i);
    if (edge.getFirstHalf().isEquivalent(from, to)) {
      result = &(edge.getFirstHalf());
      break;
    } else if (edge.getSecondHalf().isEquivalent(from, to)) {
      result = &(edge.getSecondHalf());
      break;
    }
  }

  assert(result != 0);

  return *result;
}


Vertex& CatmullClarkLevel::createVertex(Vertex& copyFromVertex)
{
  Vertex* created = new Vertex();
  _subdivision.add(*created);

  created->_coordinates[0] = copyFromVertex._coordinates[0];
  created->_coordinates[1] = copyFromVertex._coordinates[1];
  created->_coordinates[2] = copyFromVertex._coordinates[2];
  created->_coordinates[3] = copyFromVertex._coordinates[3];

  created->_isBoundary = copyFromVertex._isBoundary;
  created->_isCorner = copyFromVertex._isCorner;

  return *created;
}


CatmullClarkLevel::CatmullClarkLevel(Mesh& mesh)
{
  subdivideMesh(mesh);
  evaluatePositions(mesh);
}


Mesh& CatmullClarkLevel::getMesh()
{
  return _subdivision;
}


const Mesh& CatmullClarkLevel::getMesh() const
{
  return _subdivision;
}


}


}
