#include "QuadSphere.h"


namespace protolayer
{

namespace geometry
{

namespace
{

const float A = (float) 1 / (float) 2;

float unitVertices[8][4] =
  { {  A,  A,  A , 1 },
    {  A,  A, -A , 1 },
    { -A,  A, -A , 1 },
    { -A,  A,  A , 1 },
    {  A, -A,  A , 1 },
    {  A, -A, -A , 1 },
    { -A, -A, -A , 1 },
    { -A, -A,  A , 1 } };

}

void QuadSphere::subdivide()
{
  subdivision::CatmullClarkLevel* level = 0;

  if (_subdivisions.size() == 0) {
    level = new subdivision::CatmullClarkLevel(_mesh);
  } else {
    subdivision::CatmullClarkLevel* superLevel = *(_subdivisions.rbegin());
    subdivision::Mesh& mesh = superLevel->getMesh();
    level = new subdivision::CatmullClarkLevel(mesh);
  }

  assert(level != 0);

  _subdivisions.push_back(level);
}


void QuadSphere::initialiseBaseGeometry()
{
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    subdivision::Vertex* vertex = _mesh.createVertex();
    vertex->_coordinates[0] = unitVertices[i][0] * _radius;
    vertex->_coordinates[1] = unitVertices[i][1] * _radius;
    vertex->_coordinates[2] = unitVertices[i][2] * _radius;
    vertex->_coordinates[3] = unitVertices[i][3];
  }

  _mesh.createEdge(0, 1);
  _mesh.createEdge(1, 2);
  _mesh.createEdge(2, 3);
  _mesh.createEdge(3, 0);
  _mesh.createEdge(4, 5);
  _mesh.createEdge(5, 6);
  _mesh.createEdge(6, 7);
  _mesh.createEdge(7, 4);
  _mesh.createEdge(0, 4);
  _mesh.createEdge(1, 5);
  _mesh.createEdge(2, 6);
  _mesh.createEdge(3, 7);

  _mesh.createFace(0, 1, 2, 3);
  _mesh.createFace(7, 6, 5, 4);
  _mesh.createFace(5, 6, 2, 1);
  _mesh.createFace(6, 7, 3, 2);
  _mesh.createFace(0, 3, 7, 4);
  _mesh.createFace(0, 4, 5, 1);
}


QuadSphere::QuadSphere(float radius,
                       int recursionLevel,
                       style::Appearance& edgeAppearance,
                       style::Appearance& faceAppearance)
{
  _radius = radius;

  initialiseBaseGeometry();
  for (int i = 0; i < recursionLevel; i++) {
    subdivide();
  }

  _triangles = new renderer::Geometry(renderer::Geometry::QUADS);
  _outlineQuads = new renderer::Geometry(renderer::Geometry::QUADS);
  _lines = new renderer::Geometry(renderer::Geometry::LINES);

  initialiseVertices();
  //  initialiseEdges();
  initialiseFaces();

  initialiseOutlineFaces();

  _faces = new renderer::LegacyShape(*_triangles, faceAppearance);
  _edges = new renderer::LegacyShape(*_lines, edgeAppearance);

  style::Appearance* outlineAppearance = new style::Appearance();
  outlineAppearance->getColor()[0] = 0.0f;
  outlineAppearance->getColor()[1] = 0.0f;
  outlineAppearance->getColor()[2] = 0.0f;
  outlineAppearance->getColor()[3] = 1.0f;

  _outlineFaces = new renderer::LegacyShape(*_outlineQuads, *outlineAppearance);
  _outlineFaces->setSelectable(false);
  _outlineFaces->enableFrontFaceCulling();

  //  _edges->setSelectable(false);
  _faces->setSelectable(false);
  _faces->enableBackFaceCulling();

  setSelectable(true);

  //  addChild(*_edges);
  addChild(*_outlineFaces);
  addChild(*_faces);

  //  renderer::Font* font = new renderer::Font();
  //  addChild(*(new renderer::Text(*font)));
}


void QuadSphere::initialiseOutlineFaces()
{
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];
  level->getMesh().evaluateFaceNormals();
  level->getMesh().evaluateVertexNormals();

  int numberFaces = level->getMesh().getNumberFaces();
  for (int i = 0; i < numberFaces; i++) {
    subdivision::Face& face = level->getMesh().getFace(i);
    _outlineQuads->addPoint(face.getHalfEdge(0).getFromVertex()._offsetCoordinates);
    _outlineQuads->addPoint(face.getHalfEdge(1).getFromVertex()._offsetCoordinates);
    _outlineQuads->addPoint(face.getHalfEdge(2).getFromVertex()._offsetCoordinates);
    _outlineQuads->addPoint(face.getHalfEdge(3).getFromVertex()._offsetCoordinates);
  }
}


float QuadSphere::getRadius()
{
  return _radius;
}


void QuadSphere::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void QuadSphere::recalculateVertices()
{
  //  for (int i = 0; i < NUMBER_VERTICES; ++i) {
  //    _points[i][0] = unitVertices[i][0] * _radius;
  //    _points[i][1] = unitVertices[i][1] * _radius;
  //    _points[i][2] = unitVertices[i][2] * _radius;
  //  }  
}


void QuadSphere::initialiseVertices()
{
  //  _points = new float* [NUMBER_VERTICES];
  //  for (int i = 0; i < NUMBER_VERTICES; ++i) {
  //    _points[i] = new float[4];
  //    _points[i][0] = unitVertices[i][0] * _radius;
  //    _points[i][1] = unitVertices[i][1] * _radius;
  //    _points[i][2] = unitVertices[i][2] * _radius;
  //    _points[i][3] = unitVertices[i][3];
  //  }
}


void QuadSphere::initialiseEdges()
{
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberEdges = level->getMesh().getNumberEdges();
  for (int i = 0; i < numberEdges; i++) {
    subdivision::Edge& edge = level->getMesh().getEdge(i);
    _lines->addPoint(edge.getFirstHalf().getFromVertex()._coordinates);
    _lines->addPoint(edge.getFirstHalf().getToVertex()._coordinates);
  }
}


void QuadSphere::initialiseFaces()
{
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberFaces = level->getMesh().getNumberFaces();
  for (int i = 0; i < numberFaces; i++) {
    subdivision::Face& face = level->getMesh().getFace(i);
    _triangles->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _triangles->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _triangles->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _triangles->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
}


renderer::LegacyShape& QuadSphere::getEdges()
{
  return *_edges;
}


renderer::LegacyShape& QuadSphere::getFaces()
{
  return *_faces;
}


}


}
