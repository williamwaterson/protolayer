#include "Target.h"


namespace protolayer
{

namespace geometry
{

namespace
{

float radius = 1;
float A = radius * cos(M_PI/4);
float B = radius * sin(M_PI/4);

float innerRadius = 0.7 * radius;
float C = innerRadius * cos(M_PI/4);
float D = innerRadius * sin(M_PI/4);

float innerRadius2 = 0.5 * radius;
float E = innerRadius2 * cos(-M_PI/6);
float F = innerRadius2 * sin(-M_PI/6);

float unitVertices[Target::NUMBER_VERTICES][4] =
  { {  A,  B,  0 , 1 },
    {  0,  radius,  0 , 1 },
    { -A,  B,  0 , 1 },
    { -radius,  0,  0 , 1 },
    { -A, -B,  0 , 1 },
    {  0, -radius,  0 , 1 },
    {  A, -B,  0 , 1 },
    {  radius,  0,  0 , 1 },
    {  C,  D,  0 , 1 },
    {  0,  innerRadius,  0 , 1 },
    { -C,  D,  0 , 1 },
    { -innerRadius,  0,  0 , 1 },
    { -C, -D,  0 , 1 },
    {  0, -innerRadius,  0 , 1 },
    {  C, -D,  0 , 1 },
    {  innerRadius,  0,  0 , 1 },
    {  E,  F,  0 , 1 },
    {  0,  innerRadius2,  0 , 1 },
    { -E,  F,  0 , 1 },
    { -innerRadius2,  0,  0 , 1 },
    { -E, -F,  0 , 1 },
    {  0, -innerRadius2,  0 , 1 },
    {  E, -F,  0 , 1 },
    {  innerRadius2,  0,  0 , 1 },
    {  0,  0,  0 , 1 } };

}

void Target::subdivide()
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


void Target::initialiseBaseGeometry()
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
  _mesh.createEdge(3, 4);
  _mesh.createEdge(4, 5);
  _mesh.createEdge(5, 6);
  _mesh.createEdge(6, 7);
  _mesh.createEdge(7, 0);

  _mesh.createEdge(8, 9);
  _mesh.createEdge(9, 10);
  _mesh.createEdge(10, 11);
  _mesh.createEdge(11, 12);
  _mesh.createEdge(12, 13);
  _mesh.createEdge(13, 14);
  _mesh.createEdge(14, 15);
  _mesh.createEdge(15, 8);

  _mesh.createEdge(16, 17);
  _mesh.createEdge(17, 18);
  _mesh.createEdge(18, 19);
  _mesh.createEdge(19, 20);
  _mesh.createEdge(20, 21);
  _mesh.createEdge(21, 22);
  _mesh.createEdge(22, 23);
  _mesh.createEdge(23, 16);

  _mesh.createEdge(0, 8);
  _mesh.createEdge(1, 9);
  _mesh.createEdge(2, 10);
  _mesh.createEdge(3, 11);
  _mesh.createEdge(4, 12);
  _mesh.createEdge(5, 13);
  _mesh.createEdge(6, 14);
  _mesh.createEdge(7, 15);

  _mesh.createEdge(16, 24);
  _mesh.createEdge(18, 24);
  _mesh.createEdge(20, 24);
  _mesh.createEdge(22, 24);

  _mesh.createFace(0, 1, 9, 8);
  _mesh.createFace(1, 2, 10, 9);
  _mesh.createFace(2, 3, 11, 10);
  _mesh.createFace(3, 4, 12, 11);
  _mesh.createFace(4, 5, 13, 12);
  _mesh.createFace(5, 6, 14, 13);
  _mesh.createFace(6, 7, 15, 14);
  _mesh.createFace(7, 0, 8, 15);

  _mesh.createFace(16, 17, 18, 24);
  _mesh.createFace(18, 19, 20, 24);
  _mesh.createFace(20, 21, 22, 24);
  _mesh.createFace(22, 23, 16, 24);

}


Target::Target(float radius,
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


void Target::initialiseOutlineFaces()
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


float Target::getRadius()
{
  return _radius;
}


void Target::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void Target::recalculateVertices()
{
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
  }  
}


void Target::initialiseVertices()
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


void Target::initialiseEdges()
{
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberEdges = level->getMesh().getNumberEdges();
  for (int i = 0; i < numberEdges; i++) {
    subdivision::Edge& edge = level->getMesh().getEdge(i);
    _lines->addPoint(edge.getFirstHalf().getFromVertex()._coordinates);
    _lines->addPoint(edge.getFirstHalf().getToVertex()._coordinates);
  }
}


void Target::initialiseFaces()
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


renderer::LegacyShape& Target::getEdges()
{
  return *_edges;
}


renderer::LegacyShape& Target::getFaces()
{
  return *_faces;
}


}


}
