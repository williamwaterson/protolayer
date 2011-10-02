#include "NonmanifoldLevel.h"


namespace protolayer
{

namespace subdivision
{

subdivision::HalfEdge& NonmanifoldLevel::getHalfEdge(subdivision::Vertex& from,
					   subdivision::Vertex& to)
{
  subdivision::HalfEdge* result = 0;
  for (int i = 0; i < _subdivision.getNumberEdges(); i++) {
    subdivision::Edge& edge = _subdivision.getEdge(i);
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


subdivision::Vertex& NonmanifoldLevel::createVertex(subdivision::Vertex& copyFromVertex)
{
    subdivision::Vertex* created = new subdivision::Vertex();
    _subdivision.add(*created);

    created->_coordinates[0] = copyFromVertex._coordinates[0];
    created->_coordinates[1] = copyFromVertex._coordinates[1];
    created->_coordinates[2] = copyFromVertex._coordinates[2];
    created->_coordinates[3] = copyFromVertex._coordinates[3];

    return *created;
}


NonmanifoldLevel::NonmanifoldLevel(subdivision::Mesh& subdivision)
{
  VertexPositionMapType averagedCenters;
  VertexPositionMapType averagedMidpoints;

  VertexEdgeCountMapType valencies;

  VertexAdjacencyMapType cornerAdjacentMaps;
  VertexAdjacencyMapType midpointAdjacentMaps;

  VertexVectorType corners;
  VertexVertexMapType vertexMap;

  for (int i = 0; i < subdivision.getNumberVertices(); i++) {
    subdivision::Vertex& vertex = subdivision.getVertex(i);
    subdivision::Vertex& created = createVertex(vertex);
    corners.push_back(&created);
    vertexMap[&vertex] = &created;
    valencies[&created] = 0;

    float* averagedCenter = new float[3];
    averagedCenters[&created] = averagedCenter;
    averagedCenter[0] = 0;
    averagedCenter[1] = 0;
    averagedCenter[2] = 0;

    float* averagedEnd = new float[3];
    averagedMidpoints[&created] = averagedEnd;
    averagedEnd[0] = 0;
    averagedEnd[1] = 0;
    averagedEnd[2] = 0;
  }

  VertexVectorType midpoints;
  for (int i = 0; i < subdivision.getNumberEdges(); i++) {
    subdivision::Edge& edge = subdivision.getEdge(i);

    subdivision::HalfEdge& firstHalfEdge = edge.getFirstHalf();
    subdivision::HalfEdge& secondHalfEdge = edge.getSecondHalf();
    
    subdivision::Vertex& fromVertex = firstHalfEdge.getFromVertex();
    subdivision::Vertex& toVertex = firstHalfEdge.getToVertex();

    subdivision::Vertex* midpoint = new subdivision::Vertex();
    midpoints.push_back(midpoint);
    _subdivision.add(*midpoint);

    float* averagedCenter = new float[3];
    averagedCenters[midpoint] = averagedCenter;
    averagedCenter[0] = 0;
    averagedCenter[1] = 0;
    averagedCenter[2] = 0;

    _midpointMappings[&firstHalfEdge] = midpoint;
    _midpointMappings[&secondHalfEdge] = midpoint;

    subdivision::Vertex* mappedFromVertex = vertexMap[&fromVertex];
    subdivision::Vertex* mappedToVertex = vertexMap[&toVertex];

    valencies[mappedFromVertex]++;
    valencies[mappedToVertex]++;

    _subdivision.createEdge(*mappedFromVertex, *midpoint);
    _subdivision.createEdge(*midpoint, *mappedToVertex);

    midpoint->_coordinates[0] = fromVertex._coordinates[0] + toVertex._coordinates[0];
    midpoint->_coordinates[1] = fromVertex._coordinates[1] + toVertex._coordinates[1];
    midpoint->_coordinates[2] = fromVertex._coordinates[2] + toVertex._coordinates[2];
    midpoint->_coordinates[3] = 1;

    averagedMidpoints[mappedFromVertex][0] += midpoint->_coordinates[0];
    averagedMidpoints[mappedFromVertex][1] += midpoint->_coordinates[1];
    averagedMidpoints[mappedFromVertex][2] += midpoint->_coordinates[2];
    
    averagedMidpoints[mappedToVertex][0] += midpoint->_coordinates[0];
    averagedMidpoints[mappedToVertex][1] += midpoint->_coordinates[1];
    averagedMidpoints[mappedToVertex][2] += midpoint->_coordinates[2];
  }

  VertexVectorType centers;
  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    subdivision::Face& face = subdivision.getFace(i);

    subdivision::Vertex* center = new subdivision::Vertex();
    centers.push_back(center);

    _centerMappings[&face] = center;
    _subdivision.add(*center);

    for (int j = 0; j < face.getNumberHalfEdges(); j++) {
      subdivision::HalfEdge& halfEdge = face.getHalfEdge(j);
      subdivision::Vertex* midpoint = _midpointMappings[&halfEdge];
      subdivision::Edge* edge = _subdivision.createEdge(*midpoint, *center);
    }

    center->_coordinates[0] = 0;
    center->_coordinates[1] = 0;
    center->_coordinates[2] = 0;
    center->_coordinates[3] = 1;

    for (int j = 0; j < face.getNumberVertices(); j++) {
      subdivision::Vertex& vertex = face.getVertex(j);
      center->_coordinates[0] += vertex._coordinates[0];
      center->_coordinates[1] += vertex._coordinates[1];
      center->_coordinates[2] += vertex._coordinates[2];      
    }

    center->_coordinates[0] /= face.getNumberVertices();
    center->_coordinates[1] /= face.getNumberVertices();
    center->_coordinates[2] /= face.getNumberVertices();
  }

  for (int i = 0; i < subdivision.getNumberFaces(); i++) {
    subdivision::Face& face = subdivision.getFace(i);
    subdivision::Vertex* center = _centerMappings[&face];

    int numberEdges = face.getNumberHalfEdges();
    subdivision::HalfEdge& lastHalfEdge = face.getHalfEdge(numberEdges - 1);

    subdivision::Vertex* last = _midpointMappings[&lastHalfEdge];
    for (int j = 0; j < face.getNumberHalfEdges(); j++) {
      subdivision::HalfEdge& halfEdge = face.getHalfEdge(j);
      subdivision::Vertex& oldCorner = halfEdge.getFromVertex();
      subdivision::Vertex* corner = vertexMap[&oldCorner];
      subdivision::Vertex* next = _midpointMappings[&halfEdge];

      _subdivision.createFace(*corner, *next, *center, *last);

      averagedCenters[next][0] += center->_coordinates[0];
      averagedCenters[next][1] += center->_coordinates[1];
      averagedCenters[next][2] += center->_coordinates[2];

      averagedCenters[corner][0] += center->_coordinates[0];
      averagedCenters[corner][1] += center->_coordinates[1];
      averagedCenters[corner][2] += center->_coordinates[2];

      last = next;
    }
  }

  for (int i = 0; i < corners.size(); i++) {
    subdivision::Vertex* corner = corners[i];

    int valence = valencies[corner];

    corner->_coordinates[0] *= (valence - 3) / 3;
    corner->_coordinates[1] *= (valence - 3) / 3;
    corner->_coordinates[2] *= (valence - 3) / 3;

    corner->_coordinates[0] += averagedMidpoints[corner][0] / (valence * 3);
    corner->_coordinates[1] += averagedMidpoints[corner][1] / (valence * 3);
    corner->_coordinates[2] += averagedMidpoints[corner][2] / (valence * 3);

    corner->_coordinates[0] += averagedCenters[corner][0] / (valence * 3);
    corner->_coordinates[1] += averagedCenters[corner][1] / (valence * 3);
    corner->_coordinates[2] += averagedCenters[corner][2] / (valence * 3);
  }

  for (int i = 0; i < midpoints.size(); i++) {
    subdivision::Vertex* midpoint = midpoints[i];

    midpoint->_coordinates[0] += averagedCenters[midpoint][0];
    midpoint->_coordinates[1] += averagedCenters[midpoint][1];
    midpoint->_coordinates[2] += averagedCenters[midpoint][2];

    midpoint->_coordinates[0] /= 4;
    midpoint->_coordinates[1] /= 4;
    midpoint->_coordinates[2] /= 4;
  }
}


subdivision::Mesh& NonmanifoldLevel::getMesh()
{
  return _subdivision;
}


const subdivision::Mesh& NonmanifoldLevel::getMesh() const
{
  return _subdivision;
}


}


}
