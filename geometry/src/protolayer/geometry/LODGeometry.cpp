#include "ArrowDisk.h"


namespace protolayer
{

namespace geometry
{

namespace
{

float radius = 1;
float A = radius * cos(M_PI/4);
float B = radius * sin(M_PI/4);

float innerRadius = 0.9 * radius;
float C = innerRadius * cos(M_PI/4);
float D = innerRadius * sin(M_PI/4);

float triangleRadius = 0.5 * radius;
float E = triangleRadius * cos(-M_PI/6);
float F = triangleRadius * sin(-M_PI/6);

float unitVertices[ArrowDisk::NUMBER_VERTICES][4] =
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
    {  0,  triangleRadius,  0 , 1 },
    {  0,  triangleRadius,  0 , 1 },
    {  E,  F,  0 , 1 },
    { -E,  F,  0 , 1 } };

}

void ArrowDisk::subdivide()
{
  subdivision::CatmullClarkLevel* level = 0;

  if (_subdivisions.size() == 0) {
    level = new subdivision::CatmullClarkLevel(_controlMesh);
  } else {
    subdivision::CatmullClarkLevel* superLevel = *(_subdivisions.rbegin());
    subdivision::Mesh& mesh = superLevel->getMesh();
    level = new subdivision::CatmullClarkLevel(mesh);
  }

  assert(level != 0);

  _subdivisions.push_back(level);
}


void ArrowDisk::initialiseBaseGeometry()
{
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    subdivision::Vertex* vertex = _controlMesh.createVertex();
    vertex->_coordinates[0] = unitVertices[i][0] * _radius;
    vertex->_coordinates[1] = unitVertices[i][1] * _radius;
    vertex->_coordinates[2] = unitVertices[i][2] * _radius;
    vertex->_coordinates[3] = unitVertices[i][3];
  }

  _controlMesh.createEdge(0, 1);
  _controlMesh.createEdge(1, 2);
  _controlMesh.createEdge(2, 3);
  _controlMesh.createEdge(3, 4);
  _controlMesh.createEdge(4, 5);
  _controlMesh.createEdge(5, 6);
  _controlMesh.createEdge(6, 7);
  _controlMesh.createEdge(7, 0);

  _controlMesh.createEdge(8, 9)->setBoundary(true);
  _controlMesh.createEdge(9, 10)->setBoundary(true);
  _controlMesh.createEdge(10, 11)->setBoundary(true);
  _controlMesh.createEdge(11, 12)->setBoundary(true);
  _controlMesh.createEdge(12, 13)->setBoundary(true);
  _controlMesh.createEdge(13, 14)->setBoundary(true);
  _controlMesh.createEdge(14, 15)->setBoundary(true);
  _controlMesh.createEdge(15, 8)->setBoundary(true);

  _controlMesh.createEdge(16, 17)->setBoundary(true);
  _controlMesh.createEdge(17, 18)->setBoundary(true);
  _controlMesh.createEdge(18, 19)->setBoundary(true);
  _controlMesh.createEdge(19, 16)->setBoundary(true);

  _controlMesh.createEdge(0, 8);
  _controlMesh.createEdge(1, 9);
  _controlMesh.createEdge(2, 10);
  _controlMesh.createEdge(3, 11);
  _controlMesh.createEdge(4, 12);
  _controlMesh.createEdge(5, 13);
  _controlMesh.createEdge(6, 14);
  _controlMesh.createEdge(7, 15);

  _controlMesh.getVertex(16).setCorner(true);  
  _controlMesh.getVertex(17).setCorner(true);  
  _controlMesh.getVertex(18).setCorner(true);  
  _controlMesh.getVertex(19).setCorner(true);

  subdivision::Face* face = _controlMesh.createFace(0, 1, 9, 8);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(1, 2, 10, 9);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(2, 3, 11, 10);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(3, 4, 12, 11);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(4, 5, 13, 12);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(5, 6, 14, 13);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(6, 7, 15, 14);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(7, 0, 8, 15);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(16, 17, 18, 19);
  face->setTrackPropagation(true);

  _controlMesh.createEdge(8, 17);
  _controlMesh.createEdge(15, 16);
  _controlMesh.createEdge(9, 18);
  _controlMesh.createEdge(11, 18);
  _controlMesh.createEdge(12, 19);
  _controlMesh.createEdge(14, 19);

  face = _controlMesh.createFace(8, 15, 16, 17);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(8, 9, 18, 17);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(9, 10, 11, 18);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(11, 12, 19, 18);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(12, 13, 14, 19);
  face->setTrackPropagation(true);

  face = _controlMesh.createFace(14, 15, 16, 19);
  face->setTrackPropagation(true);
}


ArrowDisk::ArrowDisk(float radius,
		     int recursionDepth,
		     style::Appearance& edgeAppearance,
		     style::Appearance& faceAppearance)
{
  _levelOfDetail = 1;
  _maximumRecursionDepth = recursionDepth;

  _radius = radius;

  initialiseBaseGeometry();
  for (int i = 0; i < _maximumRecursionDepth; i++) {
    subdivide();
  }

  _outlineGeometry = new renderer::Geometry(renderer::Geometry::QUADS);
  _arrowGeometry = new renderer::Geometry(renderer::Geometry::QUADS);
  _fillerGeometry = new renderer::Geometry(renderer::Geometry::QUADS);

  //  initialiseVertices();
  initialiseOutline();
  initialiseArrow();
  initialiseFiller();

  _outline = new renderer::LegacyShape(*_outlineGeometry, faceAppearance);
  _arrow = new renderer::LegacyShape(*_arrowGeometry, faceAppearance);
  _filler = new renderer::LegacyShape(*_fillerGeometry, edgeAppearance);

  _outline->setSelectable(true);
  _arrow->setSelectable(true);
  _filler->setSelectable(true);

  setSelectable(true);

  addChild(*_outline);
  addChild(*_arrow);
  addChild(*_filler);


  //  renderer::Font* font = new renderer::Font();
  //  addChild(*(new renderer::Text(*font)));
}


int ArrowDisk::getLevelOfDetail() const
{
  return _levelOfDetail;
}


int ArrowDisk::getMaximumRecursionDepth() const
{
  return _maximumRecursionDepth;
}


float ArrowDisk::getRadius()
{
  return _radius;
}


void ArrowDisk::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void ArrowDisk::recalculateVertices()
{
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
  }  
}


void ArrowDisk::initialiseVertices()
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


void ArrowDisk::initialiseFiller()
{
  //  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];
  /*  subdivision::CatmullClarkLevel* level = _subdivisions[0];

  int numberFaces = level->getMesh().getNumberFaces();
  for (int i = 9; i < 15; i++) {
    subdivision::Face& face = level->getMesh().getFace(i);
    _fillerGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
*/

  std::vector <subdivision::Face*> faces;
  for (int i = 9; i < 15; i++) {
    faces.push_back(&(_controlMesh.getFace(i)));
  }

  subdivision::Level levelOne(faces);
  subdivision::Level levelTwo(faces);
  subdivision::Level levelThree(faces);
  

  for (int i = 0; i < levelThree.getNumberFaces(); i++) {
    subdivision::Face& face = levelThree.getFace(i);
    _fillerGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _fillerGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
}


void ArrowDisk::initialiseOutline()
{
  /*
  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];

  int numberFaces = level->getMesh().getNumberFaces();
  std::cout << _subdivisions[0]->getMesh().getNumberFaces() << std::endl;
  std::cout << _subdivisions[_subdivisions.size() - 1]->getMesh().getNumberFaces() << std::endl;
  for (int i = 0; i < numberFaces; i++) {
    subdivision::Face& face = level->getMesh().getFace(i);
    _outlineGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
  */

  std::vector <subdivision::Face*> faces;
  for (int i = 0; i < 8; i++) {
    faces.push_back(&(_controlMesh.getFace(i)));
  }

  subdivision::Level levelOne(faces);
  subdivision::Level levelTwo(faces);
  subdivision::Level levelThree(faces);
  

  for (int i = 0; i < levelThree.getNumberFaces(); i++) {
    subdivision::Face& face = levelThree.getFace(i);
    _outlineGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _outlineGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
}


void ArrowDisk::initialiseArrow()
{
  //  subdivision::CatmullClarkLevel* level = _subdivisions[_subdivisions.size() - 1];
  //  subdivision::CatmullClarkLevel* level = _subdivisions[0];

  //  subdivision::Face& face = level->getMesh().getFace(0);
  //  _arrowGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
  //  _arrowGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
  // _arrowGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
  //  _arrowGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);

  subdivision::Face& face = _controlMesh.getFace(8);

  subdivision::Level levelOne(face);
  subdivision::Level levelTwo(face);
  subdivision::Level levelThree(face);
  
  for (int i = 0; i < levelThree.getNumberFaces(); i++) {
    subdivision::Face& face = levelThree.getFace(i);
    _arrowGeometry->addPoint(face.getHalfEdge(0).getFromVertex()._coordinates);
    _arrowGeometry->addPoint(face.getHalfEdge(1).getFromVertex()._coordinates);
    _arrowGeometry->addPoint(face.getHalfEdge(2).getFromVertex()._coordinates);
    _arrowGeometry->addPoint(face.getHalfEdge(3).getFromVertex()._coordinates);
  }
}


renderer::LegacyShape& ArrowDisk::getOutline()
{
  return *_outline;
}


renderer::LegacyShape& ArrowDisk::getFiller()
{
  return *_filler;
}


renderer::LegacyShape& ArrowDisk::getArrow()
{
  return *_arrow;
}


}


}
