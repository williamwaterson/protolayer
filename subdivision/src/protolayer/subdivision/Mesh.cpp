#include "Mesh.h"


namespace protolayer
{

namespace subdivision
{

HalfEdge& Mesh::getHalfEdge(Vertex& from, Vertex& to)
{
  HalfEdge* result = 0;
  for (int i = 0; i < _edges.size(); i++) {
    Edge* edge = _edges[i];
    if (edge->getFirstHalf().isEquivalent(from, to)) {
      result = &(edge->getFirstHalf());
      break;
    } else if (edge->getSecondHalf().isEquivalent(from, to)) {
      result = &(edge->getSecondHalf());
      break;
    }
  }

  assert(result != 0);

  return *result;
}


Mesh::Mesh()
{
}


Mesh::~Mesh()
{
  for (int i = 0; i < _faces.size(); i++) {
    //    delete (_faces[i]);
  }

  for (int i = 0; i < _edges.size(); i++) {
    //    delete (_edges[i]);
  }

  for (int i = 0; i < _vertices.size(); i++) {
    //    delete (_vertices[i]);
  }
}


void Mesh::detectBoundaries()
{
  for (int i = 0; i < _edges.size(); i++) {
    if (_edges[i]->getFaceCount() < 2) {
      _edges[i]->setBoundary(true);
    }
  }  
}


void Mesh::detectFlowers()
{
  for (int i = 0; i < _vertices.size(); i++) {
    Vertex* vertex = _vertices[i];
    _vertexFlowerMap[vertex] = new Flower(*vertex);
  }

  for (int i = 0; i < _faces.size(); i++) {
    Face* face = _faces[i];
    for (int j = 0; j < face->getNumberVertices(); j++) {
      Vertex& vertex = face->getVertex(j);
      _vertexFlowerMap[&vertex]->addFace(*face);
    }
  }
}


void Mesh::evaluateEdgeDirections()
{
  //  for (int i = 0; i < _edges.size(); i++) {
  //    _edges[i]->evaluateDirections();
  //  }
}


void Mesh::evaluateFaceNormals()
{
  for (int i = 0; i < _faces.size(); i++) {
    _faces[i]->updateRelativePositions();
    _faces[i]->evaluateNormal();
  }
}


void Mesh::evaluateVertexNormals()
{
  for (int i = 0; i < _vertices.size(); i++) {
    Vertex* vertex = _vertices[i];
    vertex->_normal[0] = 0;
    vertex->_normal[1] = 0;
    vertex->_normal[2] = 0;
    vertex->_normal[3] = 1;
  }

  for (int i = 0; i < _faces.size(); i++) {
    getFace(i).updateVertexNormals();
  }

  for (int i = 0; i < _vertices.size(); i++) {
    linearalgebra::normalise(_vertices[i]->_normal, 3);
  }

  for (int i = 0; i < _vertices.size(); i++) {
    _vertices[i]->evaluateOffset();
  }
}


Vertex* Mesh::createVertex()
{
  Vertex* createdVertex = new Vertex();
  _vertices.push_back(createdVertex);

  return createdVertex;
}


Edge* Mesh::createEdge(Vertex& firstVertex, Vertex& secondVertex)
{
  Edge* createdEdge = new Edge(firstVertex, secondVertex);
  _edges.push_back(createdEdge);

  return createdEdge;
}


Edge* Mesh::createEdge(int firstVertexIndex, int secondVertexIndex)
{
  Vertex* firstVertex = _vertices[firstVertexIndex];
  Vertex* secondVertex = _vertices[secondVertexIndex];

  Edge* createdEdge = new Edge(*firstVertex, *secondVertex);
  _edges.push_back(createdEdge);

  return createdEdge;
}


Face* Mesh::createFace(Vertex& vertex0,
		       Vertex& vertex1,
		       Vertex& vertex2)
{
  Face* createdFace = new Face(_edges, vertex0, vertex1, vertex2);
  _faces.push_back(createdFace);

  return createdFace;
}


Face* Mesh::createFace(Vertex& vertex0,
		       Vertex& vertex1,
		       Vertex& vertex2,
		       Vertex& vertex3)
{
  Face* createdFace = new Face(_edges, vertex0, vertex1, vertex2, vertex3);
  _faces.push_back(createdFace);

  return createdFace;
}


Face* Mesh::createFace(int vertexIndex0,
                           int vertexIndex1,
                           int vertexIndex2)
{
  Face* createdFace = new Face(_edges, _vertices, vertexIndex0, vertexIndex1, vertexIndex2);
  _faces.push_back(createdFace);

  return createdFace;
}


Face* Mesh::createFace(int vertexIndex0,
                           int vertexIndex1,
                           int vertexIndex2,
                           int vertexIndex3)
{
  Face* createdFace = new Face(_edges, _vertices, vertexIndex0, vertexIndex1, vertexIndex2, vertexIndex3);
  _faces.push_back(createdFace);

  return createdFace;
}


void Mesh::add(Vertex& vertex)
{
  _vertices.push_back(&vertex);
}


void Mesh::add(Edge& edge)
{
  _edges.push_back(&edge);
}


void Mesh::add(Face& face)
{
  _faces.push_back(&face);
}


const Mesh::VertexVectorType& Mesh::getVertices() const
{
  return _vertices;
}


const Mesh::EdgeVectorType& Mesh::getEdges() const
{
  return _edges;
}


const Mesh::FaceVectorType& Mesh::getFaces() const
{
  return _faces;
}


int Mesh::getNumberVertices() const
{
  return _vertices.size();
}


int Mesh::getNumberEdges() const
{
  return _edges.size();
}


int Mesh::getNumberFaces() const
{
  return _faces.size();
}


Vertex& Mesh::getVertex(int index)
{
  return *(_vertices[index]);
}


Edge& Mesh::getEdge(int index)
{
  return *(_edges[index]);
}


Face& Mesh::getFace(int index)
{
  return *(_faces[index]);
}


}


}
