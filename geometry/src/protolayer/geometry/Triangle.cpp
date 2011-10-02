#include "Triangle.h"


namespace protolayer
{

namespace geometry
{

namespace
{

float unitVertices[4][4] =
  { {  1,  1,  0 , 1 },
    {  0,  1,  0 , 1 },
    { -1,  1,  0 , 1 },
    {  0.7,  0.7,  0, 1 } };

}

void Triangle::subdivide()
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


void Triangle::initialiseBaseGeometry()
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

  _mesh.getEdge(0).setBoundary(true);  
  _mesh.getEdge(1).setBoundary(true);  
  _mesh.getEdge(2).setBoundary(true);  
  _mesh.getEdge(3).setBoundary(true);  

  _mesh.getVertex(0).setCorner(true);
  _mesh.getVertex(1).setCorner(true);
  _mesh.getVertex(2).setCorner(true);
  _mesh.getVertex(3).setCorner(true);

  _mesh.createFace(0, 1, 2, 3);
}


Triangle::Triangle(float radius,
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
  //  _outlineQuads = new renderer::Geometry(renderer::Geometry::QUADS);
  _lines = new renderer::Geometry(renderer::Geometry::LINES);

  initialiseVertices();
  initialiseEdges();
  initialiseFaces();

  //  initialiseOutlineFaces();

  _faces = new renderer::LegacyShape(*_triangles, faceAppearance);
  _edges = new renderer::LegacyShape(*_lines, edgeAppearance);

  //  style::Appearance* outlineAppearance = new style::Appearance();
  //  outlineAppearance->getColor()[0] = 0.0f;
  //  outlineAppearance->getColor()[1] = 0.0f;
  //  outlineAppearance->getColor()[2] = 0.0f;
  //  outlineAppearance->getColor()[3] = 1.0f;

  //  _outlineFaces = new renderer::LegacyShape(*_outlineQuads, *outlineAppearance);
  //  _outlineFaces->enableFrontFaceCulling();

  _edges->setSelectable(false);
  _faces->setSelectable(false);

  setSelectable(true);

  addChild(*_edges);
  addChild(*_faces);
  //  addChild(*_outlineFaces);

  //  renderer::Font* font = new renderer::Font();
  //  addChild(*(new renderer::Text(*font)));
}


void Triangle::initialiseOutlineFaces()
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


float Triangle::getRadius()
{
  return _radius;
}


void Triangle::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void Triangle::recalculateVertices()
{
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
  }  
}


void Triangle::initialiseVertices()
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


void Triangle::initialiseEdges()
{
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberEdges = level->getMesh().getNumberEdges();
  for (int i = 0; i < numberEdges; i++) {
    subdivision::Edge& edge = level->getMesh().getEdge(i);
    _lines->addPoint(edge.getFirstHalf().getFromVertex()._coordinates);
    _lines->addPoint(edge.getFirstHalf().getToVertex()._coordinates);
  }
}


void Triangle::initialiseFaces()
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


renderer::LegacyShape& Triangle::getEdges()
{
  return *_edges;
}


renderer::LegacyShape& Triangle::getFaces()
{
  return *_faces;
}


}


}
