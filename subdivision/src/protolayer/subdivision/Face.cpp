#include "Face.h"


namespace protolayer
{

namespace subdivision
{

void Face::setCenter(Vertex& center)
{
  _center = &center;
}


Vertex* Face::getCenter()
{
  return _center;
}


void Face::setTrackPropagation(bool flag)
{
  if (flag && _propagation == 0) {
    _propagation = new Propagation();
  } else if (!flag && _propagation != 0) {
    delete _propagation;
  }
}


bool Face::isTrackingPropagation() const
{
  return _propagation != 0;
}


Propagation* Face::getPropagation()
{
  return _propagation;
}


void Face::extractHalfEdge(EdgeVectorType& edges,
                           VertexVectorType& vertices,
                           int fromVertex,
                           int toVertex)
{
  Vertex* fromVert = vertices[fromVertex];
  Vertex* toVert = vertices[toVertex];

  HalfEdge* result = 0;
  for (int i = 0; i < edges.size(); i++) {
    Edge* edge = edges[i];
    if (edge->getFirstHalf().isEquivalent(*fromVert, *toVert)) {
      result = &(edge->getFirstHalf());
      _halfEdges.push_back(result);
      break;
    } else if (edge->getSecondHalf().isEquivalent(*fromVert, *toVert)) {
      result = &(edge->getSecondHalf());
      _halfEdges.push_back(result);
      break;
    }
  }

  assert(result != 0);
}


void Face::extractHalfEdge(EdgeVectorType& edges,
                           Vertex& fromVertex,
                           Vertex& toVertex)
{
  HalfEdge* result = 0;
  for (int i = 0; i < edges.size(); i++) {
    Edge* edge = edges[i];
    if (edge->getFirstHalf().isEquivalent(fromVertex, toVertex)) {
      result = &(edge->getFirstHalf());
      _halfEdges.push_back(result);
      break;
    } else if (edge->getSecondHalf().isEquivalent(fromVertex, toVertex)) {
      result = &(edge->getSecondHalf());
      _halfEdges.push_back(result);
      break;
    }
  }

  assert(result != 0);
}


void Face::evaluateRelativePositions()
{
  Vertex& start = getHalfEdge(0).getFromVertex();
  for (int i = 1; i < getNumberHalfEdges(); i++) {
    _relativePositions[i - 1][0] =
      getHalfEdge(i).getFromVertex()._coordinates[0] - start._coordinates[0];
    _relativePositions[i - 1][1] =
      getHalfEdge(i).getFromVertex()._coordinates[1] - start._coordinates[1];
    _relativePositions[i - 1][2] =
      getHalfEdge(i).getFromVertex()._coordinates[2] - start._coordinates[2];
  }
}


void Face::evaluateVertexRadials()
{
  /*
  float* vertexRadial = 0;
  for (int i = 0; i < getNumberHalfEdges(); i++) {
    Vertex& vertex = getHalfEdge(i).getFromVertex();

    vertexRadial = new float [4];
    _vertexRadials[&vertex] = vertexRadial;

    vertexRadial[0] = 0;
    vertexRadial[1] = 0;
    vertexRadial[2] = 0;
    vertexRadial[3] = 1;
  }

  float* halfEdgeRadial = 0;
  for (int i = 0; i < getNumberHalfEdges(); i++) {
    HalfEdge& halfEdge = getHalfEdge(i);
    halfEdgeRadial = _halfEdgeRadials[&halfEdge];

    Vertex& fromVertex = halfEdge.getFromVertex();
    Vertex& toVertex = halfEdge.getToVertex();

    vertexRadial = _vertexRadials[&fromVertex];
    vertexRadial[0] += halfEdgeRadial[0];
    vertexRadial[1] += halfEdgeRadial[1];
    vertexRadial[2] += halfEdgeRadial[2];

    vertexRadial = _vertexRadials[&toVertex];
    vertexRadial[0] += halfEdgeRadial[0];
    vertexRadial[1] += halfEdgeRadial[1];
    vertexRadial[2] += halfEdgeRadial[2];
  }

  for (int i = 0; i < getNumberHalfEdges(); i++) {
    Vertex& vertex = getHalfEdge(i).getFromVertex();
    vertexRadial = _vertexRadials[&vertex];
    linearalgebra::normalise(vertexRadial, 3);
  }
  */
}


void Face::evaluateEdgeRadials()
{
  /*
  float* radial = 0;
  for (int i = 0; i < getNumberHalfEdges(); i++) {
    radial = new float[4];
    HalfEdge& halfEdge = getHalfEdge(i);
    linearalgebra::crossProduct(_normal, halfEdge._direction, radial);
    linearalgebra::normalise(radial, 3);
    _halfEdgeRadials[&halfEdge] = radial;
  }
  */
}


void Face::evaluateNormal()
{
  updateNormal();
}


void Face::updateRelativePositions()
{
  subdivision::Vertex& start = getHalfEdge(0).getFromVertex();
  for (int i = 1; i < getNumberHalfEdges(); i++) {
    _relativePositions[i][0] =
      getHalfEdge(i).getFromVertex()._coordinates[0] - start._coordinates[0];
    _relativePositions[i][1] =
      getHalfEdge(i).getFromVertex()._coordinates[1] - start._coordinates[1];
    _relativePositions[i][2] =
      getHalfEdge(i).getFromVertex()._coordinates[2] - start._coordinates[2];
  }
}


void Face::updateNormal()
{
  _normal[0] = 0;
  _normal[1] = 0;
  _normal[2] = 0;
  _normal[3] = 1;

  float temp[3];
  for (int i = 2; i < getNumberHalfEdges(); i++) {
    linearalgebra::crossProduct(_relativePositions[i - 2],
                                _relativePositions[i - 1],
                                temp);
    _normal[0] += temp[0];
    _normal[1] += temp[1];
    _normal[2] += temp[2];
  }
}


void Face::initNormals()
{
  _relativePositions = new float* [getNumberHalfEdges() - 1];
  for (int i = 0; i < getNumberHalfEdges(); i++) {
    _relativePositions[i] = new float[4];
  }

  updateRelativePositions();
  updateNormal();
}


void Face::updateVertexNormals()
{
  for (int i = 0; i < getNumberHalfEdges(); i++) {
    HalfEdge& halfEdge = getHalfEdge(i);
    Vertex& vertex = halfEdge.getFromVertex();
    vertex._normal[0] += _normal[0];
    vertex._normal[1] += _normal[1];
    vertex._normal[2] += _normal[2];
  }  
}


Face::Face(EdgeVectorType& edges,
           VertexVectorType& vertices,
           int a,
           int b,
           int c)
{
  extractHalfEdge(edges, vertices, a, b);
  extractHalfEdge(edges, vertices, b, c);
  extractHalfEdge(edges, vertices, c, a);

  for (int i = 0; i < _halfEdges.size(); i++) {
    HalfEdge* halfEdge = _halfEdges[i];
    halfEdge->incrementFaceCount();
  }

  for (int i = 0; i < getNumberVertices(); i++) {
    Vertex& vertex = getVertex(i);
    vertex.incrementFaceCount();
  }

  initNormals();

  _propagation = 0;
  _object = 0;
}


Face::Face(EdgeVectorType& edges,
           VertexVectorType& vertices,
           int a,
           int b,
           int c,
           int d)
{
  extractHalfEdge(edges, vertices, a, b);
  extractHalfEdge(edges, vertices, b, c);
  extractHalfEdge(edges, vertices, c, d);
  extractHalfEdge(edges, vertices, d, a);

  for (int i = 0; i < _halfEdges.size(); i++) {
    HalfEdge* halfEdge = _halfEdges[i];
    halfEdge->incrementFaceCount();
  }

  for (int i = 0; i < getNumberVertices(); i++) {
    Vertex& vertex = getVertex(i);
    vertex.incrementFaceCount();
  }

  initNormals();

  _propagation = 0;
  _object = 0;
}


Face::Face(EdgeVectorType& edges,
           Vertex& vertexA,
           Vertex& vertexB,
           Vertex& vertexC)
{
  extractHalfEdge(edges, vertexA, vertexB);
  extractHalfEdge(edges, vertexB, vertexC);
  extractHalfEdge(edges, vertexC, vertexA);

  initNormals();

  for (int i = 0; i < _halfEdges.size(); i++) {
    HalfEdge* halfEdge = _halfEdges[i];
    halfEdge->incrementFaceCount();
  }

  for (int i = 0; i < getNumberVertices(); i++) {
    Vertex& vertex = getVertex(i);
    vertex.incrementFaceCount();
  }

  _propagation = 0;
  _object = 0;
}


Face::Face(EdgeVectorType& edges,
           Vertex& vertexA,
           Vertex& vertexB,
           Vertex& vertexC,
           Vertex& vertexD)
{
  extractHalfEdge(edges, vertexA, vertexB);
  extractHalfEdge(edges, vertexB, vertexC);
  extractHalfEdge(edges, vertexC, vertexD);
  extractHalfEdge(edges, vertexD, vertexA);

  initNormals();

  for (int i = 0; i < _halfEdges.size(); i++) {
    HalfEdge* halfEdge = _halfEdges[i];
    halfEdge->incrementFaceCount();
  }

  for (int i = 0; i < getNumberVertices(); i++) {
    Vertex& vertex = getVertex(i);
    vertex.incrementFaceCount();
  }

  _propagation = 0;
  _object = 0;
}


Face::~Face()
{
  for (int i = 0; i < _halfEdges.size(); i++) {
    HalfEdge* halfEdge = _halfEdges[i];
    halfEdge->decrementFaceCount();
  }

  for (int i = 0; i < getNumberVertices(); i++) {
    Vertex& vertex = getVertex(i);
    vertex.decrementFaceCount();
  }
}


void Face::setObject(void* object)
{
  _object = object;
}


void* Face::getObject()
{
  return _object;
}


int Face::getNumberVertices() const
{
  return _halfEdges.size();
}


int Face::getNumberHalfEdges() const
{
  return _halfEdges.size();
}


HalfEdge& Face::getHalfEdge(int index)
{
  return *(_halfEdges[index]);
}


Vertex& Face::getVertex(int index)
{
  return getHalfEdge(index).getFromVertex();
}


const float* Face::getNormal() const
{
  return _normal;
}


}


}
