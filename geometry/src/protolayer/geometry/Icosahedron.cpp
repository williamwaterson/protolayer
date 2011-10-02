#include "Icosahedron.h"


namespace protolayer
{

namespace geometry
{

namespace {


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

Icosahedron::Icosahedron(float radius,
                         style::Appearance& edgeAppearance,
                         style::Appearance& faceAppearance)
{
  _radius = radius;

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


float Icosahedron::getRadius()
{
  return _radius;
}


void Icosahedron::setRadius(float radius)
{
  _radius = radius;
  recalculateVertices();
}


void Icosahedron::recalculateVertices()
{
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i][0] = unitVertices[i][0] * _radius;
    _points[i][1] = unitVertices[i][1] * _radius;
    _points[i][2] = unitVertices[i][2] * _radius;
  }  
}


void Icosahedron::initialiseVertices()
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


void Icosahedron::initialiseEdges()
{
  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[0]);

  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[2]);

  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[6]);

  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[8]);

  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[10]);

  _lines->addPoint(_points[2]);
  _lines->addPoint(_points[6]);

  _lines->addPoint(_points[6]);
  _lines->addPoint(_points[0]);

  _lines->addPoint(_points[0]);
  _lines->addPoint(_points[8]);

  _lines->addPoint(_points[8]);
  _lines->addPoint(_points[10]);

  _lines->addPoint(_points[10]);
  _lines->addPoint(_points[2]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[1]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[3]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[5]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[9]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[11]);

  _lines->addPoint(_points[1]);
  _lines->addPoint(_points[5]);

  _lines->addPoint(_points[5]);
  _lines->addPoint(_points[3]);

  _lines->addPoint(_points[3]);
  _lines->addPoint(_points[11]);

  _lines->addPoint(_points[11]);
  _lines->addPoint(_points[9]);

  _lines->addPoint(_points[9]);
  _lines->addPoint(_points[1]);

  _lines->addPoint(_points[2]);
  _lines->addPoint(_points[3]);

  _lines->addPoint(_points[3]);
  _lines->addPoint(_points[10]);

  _lines->addPoint(_points[10]);
  _lines->addPoint(_points[5]);

  _lines->addPoint(_points[5]);
  _lines->addPoint(_points[8]);

  _lines->addPoint(_points[8]);
  _lines->addPoint(_points[1]);

  _lines->addPoint(_points[1]);
  _lines->addPoint(_points[0]);

  _lines->addPoint(_points[0]);
  _lines->addPoint(_points[9]);

  _lines->addPoint(_points[9]);
  _lines->addPoint(_points[6]);

  _lines->addPoint(_points[6]);
  _lines->addPoint(_points[11]);

  _lines->addPoint(_points[11]);
  _lines->addPoint(_points[2]);

  _edges->compile();
}


void
Icosahedron::initialiseFaces()
{
  _triangles->addPoint(_points[4]);
  _triangles->addPoint(_points[2]);
  _triangles->addPoint(_points[6]);

  _triangles->addPoint(_points[4]);
  _triangles->addPoint(_points[6]);
  _triangles->addPoint(_points[0]);

  _triangles->addPoint(_points[4]);
  _triangles->addPoint(_points[8]);
  _triangles->addPoint(_points[10]);

  _triangles->addPoint(_points[4]);
  _triangles->addPoint(_points[10]);
  _triangles->addPoint(_points[2]);

  _triangles->addPoint(_points[4]);
  _triangles->addPoint(_points[0]);
  _triangles->addPoint(_points[8]);

  _triangles->addPoint(_points[7]);
  _triangles->addPoint(_points[11]);
  _triangles->addPoint(_points[9]);

  _triangles->addPoint(_points[7]);
  _triangles->addPoint(_points[1]);
  _triangles->addPoint(_points[5]);

  _triangles->addPoint(_points[7]);
  _triangles->addPoint(_points[3]);
  _triangles->addPoint(_points[11]);

  _triangles->addPoint(_points[7]);
  _triangles->addPoint(_points[5]);
  _triangles->addPoint(_points[3]);

  _triangles->addPoint(_points[7]);
  _triangles->addPoint(_points[9]);
  _triangles->addPoint(_points[1]);

  _triangles->addPoint(_points[1]);
  _triangles->addPoint(_points[0]);
  _triangles->addPoint(_points[9]);

  _triangles->addPoint(_points[0]);
  _triangles->addPoint(_points[9]);
  _triangles->addPoint(_points[6]);

  _triangles->addPoint(_points[9]);
  _triangles->addPoint(_points[6]);
  _triangles->addPoint(_points[11]);

  _triangles->addPoint(_points[6]);
  _triangles->addPoint(_points[11]);
  _triangles->addPoint(_points[2]);

  _triangles->addPoint(_points[11]);
  _triangles->addPoint(_points[2]);
  _triangles->addPoint(_points[3]);

  _triangles->addPoint(_points[2]);
  _triangles->addPoint(_points[3]);
  _triangles->addPoint(_points[10]);

  _triangles->addPoint(_points[3]);
  _triangles->addPoint(_points[10]);
  _triangles->addPoint(_points[5]);

  _triangles->addPoint(_points[10]);
  _triangles->addPoint(_points[5]);
  _triangles->addPoint(_points[8]);

  _triangles->addPoint(_points[5]);
  _triangles->addPoint(_points[8]);
  _triangles->addPoint(_points[1]);

  _triangles->addPoint(_points[8]);
  _triangles->addPoint(_points[1]);
  _triangles->addPoint(_points[0]);

  _faces->compile();
}


renderer::LegacyShape& Icosahedron::getEdges()
{
  return *_edges;
}


renderer::LegacyShape& Icosahedron::getFaces()
{
  return *_faces;
}


}


}
