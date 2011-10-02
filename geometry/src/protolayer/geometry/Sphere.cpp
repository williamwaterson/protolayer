#include "Sphere.h"


namespace protolayer
{

namespace geometry
{

namespace
{

const float PHI = 1.618033989f;

const float A = (float) 1 / (float) 2;

const float B = (float) 1 / (2 * PHI);

float unitVertices[12][4] =
  { {  0,  B,  A , 1 },
    {  0, -B,  A , 1 },
    {  0,  B, -A , 1 },
    {  0, -B, -A , 1 },
    {  B,  A,  0 , 1 },
    {  B, -A,  0 , 1 },
    { -B,  A,  0 , 1 },
    { -B, -A,  0 , 1 },
    {  A,  0,  B , 1 },
    { -A,  0,  B , 1 },
    {  A,  0, -B , 1 },
    { -A,  0, -B , 1 } };

}

void Sphere::subdivide()
{
  subdivision::LoopLevel* level = 0;

  if (_subdivisions.size() == 0) {
    level = new subdivision::LoopLevel(_mesh);
  } else {
    subdivision::LoopLevel* superLevel = *(_subdivisions.rbegin());
    subdivision::Mesh& mesh = superLevel->getMesh();
    level = new subdivision::LoopLevel(mesh);
  }

  assert(level != 0);

  _subdivisions.push_back(level);
}


void Sphere::initialiseBaseGeometry()
{
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    subdivision::Vertex* vertex = _mesh.createVertex();
    vertex->_coordinates[0] = unitVertices[i][0] * _radius;
    vertex->_coordinates[1] = unitVertices[i][1] * _radius;
    vertex->_coordinates[2] = unitVertices[i][2] * _radius;
    vertex->_coordinates[3] = unitVertices[i][3];
  }

  //  _mesh.getVertex(0).setCorner(true);
  //    _mesh.getVertex(4).setCorner(true);
  //    _mesh.getVertex(6).setCorner(true);

  _mesh.createEdge(4, 0);
  _mesh.getEdge(0).setBoundary(true);

  _mesh.createEdge(4, 2);
  _mesh.createEdge(4, 6);
  _mesh.getEdge(2).setBoundary(true);

  _mesh.createEdge(4, 8);
  _mesh.createEdge(4, 10);
  _mesh.createEdge(2, 6);
  _mesh.createEdge(6, 0);
  _mesh.getEdge(6).setBoundary(true);

  _mesh.createEdge(0, 8);
  _mesh.createEdge(8, 10);
  _mesh.createEdge(10, 2);
  _mesh.createEdge(7, 1);
  _mesh.createEdge(7, 3);
  _mesh.createEdge(7, 5);
  _mesh.createEdge(7, 9);
  _mesh.createEdge(7, 11);
  _mesh.createEdge(1, 5);
  _mesh.createEdge(5, 3);
  _mesh.createEdge(3, 11);
  _mesh.createEdge(11, 9);
  _mesh.createEdge(9, 1);
  _mesh.createEdge(2, 3);
  _mesh.createEdge(3, 10);
  _mesh.createEdge(10, 5);
  _mesh.createEdge(5, 8);
  _mesh.createEdge(8, 1);
  _mesh.createEdge(1, 0);
  _mesh.createEdge(0, 9);
  _mesh.createEdge(9, 6);
  _mesh.createEdge(6, 11);
  _mesh.createEdge(11, 2);

  _mesh.createFace(4, 2, 6);
  _mesh.createFace(4, 6, 0);
  _mesh.createFace(4, 8, 10);
  _mesh.createFace(4, 10, 2);
  _mesh.createFace(4, 0, 8);
  _mesh.createFace(7, 11, 9);
  _mesh.createFace(7, 1, 5);
  _mesh.createFace(7, 3, 11);
  _mesh.createFace(7, 5, 3);
  _mesh.createFace(7, 9, 1);
  _mesh.createFace(1, 0, 9);
  _mesh.createFace(0, 9, 6);
  _mesh.createFace(9, 6, 11);
  _mesh.createFace(6, 11, 2);
  _mesh.createFace(11, 2, 3);
  _mesh.createFace(2, 3, 10);
  _mesh.createFace(3, 10, 5);
  _mesh.createFace(10, 5, 8);
  _mesh.createFace(5, 8, 1);
  _mesh.createFace(8, 1, 0);
}


Sphere::Sphere(float radius,
               int recursionLevel,
               style::Appearance& edgeAppearance,
               style::Appearance& faceAppearance)
{
  _radius = radius;

  initialiseBaseGeometry();
  for (int i = 0; i < recursionLevel; i++) {
    subdivide();
  }

  _triangles = new renderer::Geometry(renderer::Geometry::TRIANGLES);
  _lines = new renderer::Geometry(renderer::Geometry::LINES);

  initialiseVertices();
  initialiseEdges();
  initialiseFaces();

  _faces = new renderer::LegacyShape(*_triangles, faceAppearance);
  _edges = new renderer::LegacyShape(*_lines, edgeAppearance);

  _edges->setSelectable(false);
  _faces->setSelectable(false);

  setSelectable(true);

  addChild(*_edges);
  addChild(*_faces);
}


float Sphere::getRadius()
{
  return _radius;
}


void Sphere::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void Sphere::recalculateVertices()
{
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
  }  
}


void Sphere::initialiseVertices()
{
  _points = new float* [12];
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i] = new float[4];
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
    _points[i][3] = unitVertices[i][3];
  }

  
}


void Sphere::initialiseEdges()
{
  subdivision::LoopLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberEdges = level->getMesh().getNumberEdges();
  for (int i = 0; i < numberEdges; i++) {
    subdivision::Edge& edge = level->getMesh().getEdge(i);
    _lines->addPoint(edge.getFirstHalf().getFromVertex()._coordinates);
    _lines->addPoint(edge.getFirstHalf().getToVertex()._coordinates);
  }
}


void
Sphere::initialiseFaces()
{
  subdivision::LoopLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberFaces = level->getMesh().getNumberFaces();
  for (int i = 0; i < numberFaces; i++) {
    subdivision::Face& face = level->getMesh().getFace(i);
    _triangles->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _triangles->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _triangles->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
  }
}


renderer::LegacyShape& Sphere::getEdges()
{
  return *_edges;
}


renderer::LegacyShape& Sphere::getFaces()
{
  return *_faces;
}


}


}
