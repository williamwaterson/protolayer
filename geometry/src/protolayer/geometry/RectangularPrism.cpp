#include "RectangularPrism.h"


namespace protolayer
{

namespace geometry
{

float RectangularPrism::H = (float) 1 / (float) 2;


float RectangularPrism::_unitVertices[8][4] =
  { {  H,  H,  H,  1 },
    { -H,  H,  H,  1 },
    { -H, -H,  H,  1 },
    {  H, -H,  H,  1 },
    {  H,  H, -H,  1 },
    { -H,  H, -H,  1 },
    { -H, -H, -H,  1 },
    {  H, -H, -H,  1 } };


RectangularPrism::RectangularPrism(float length,
                                   float height,
                                   float width,
                                   style::Appearance& edgeAppearance,
                                   style::Appearance& faceAppearance)
{
  _length = length;
  _height = height;
  _width = width;

  _quads = new renderer::Geometry(renderer::Geometry::QUADS);
  _lines = new renderer::Geometry(renderer::Geometry::LINES);

  initialiseVertices();
  initialiseEdges();
  initialiseQuads();

  _edges = new renderer::LegacyShape(*_lines, edgeAppearance);
  _faces = new renderer::LegacyShape(*_quads, faceAppearance);

  _edges->setSelectable(false);
  _faces->setSelectable(false);
  setSelectable(true);

  addChild(*_edges);
  addChild(*_faces);
}


void RectangularPrism::initialiseVertices()
{
  _points = new float* [NUMBER_VERTICES];
  for (int i = 0; i < NUMBER_VERTICES; ++i) {
    _points[i] = new float[4];
    _points[i][0] = _unitVertices[i][0] * _length;
    _points[i][1] = _unitVertices[i][1] * _height;
    _points[i][2] = _unitVertices[i][2] * _width;
    _points[i][3] = _unitVertices[i][3];
  }
}


void RectangularPrism::initialiseEdges()
{
  _lines->addPoint(_points[0]);
  _lines->addPoint(_points[1]);

  _lines->addPoint(_points[1]);
  _lines->addPoint(_points[2]);

  _lines->addPoint(_points[2]);
  _lines->addPoint(_points[3]);

  _lines->addPoint(_points[3]);
  _lines->addPoint(_points[0]);

  _lines->addPoint(_points[4]);
  _lines->addPoint(_points[5]);

  _lines->addPoint(_points[5]);
  _lines->addPoint(_points[6]);

  _lines->addPoint(_points[6]);
  _lines->addPoint(_points[7]);

  _lines->addPoint(_points[7]);
  _lines->addPoint(_points[4]);

  _lines->addPoint(_points[0]);
  _lines->addPoint(_points[4]);

  _lines->addPoint(_points[1]);
  _lines->addPoint(_points[5]);

  _lines->addPoint(_points[2]);
  _lines->addPoint(_points[6]);

  _lines->addPoint(_points[3]);
  _lines->addPoint(_points[7]);

  _edges->compile();
}


void RectangularPrism::initialiseQuads()
{
  _quads->addPoint(_points[0]);
  _quads->addPoint(_points[1]);
  _quads->addPoint(_points[2]);
  _quads->addPoint(_points[3]);

  _quads->addPoint(_points[4]);
  _quads->addPoint(_points[5]);
  _quads->addPoint(_points[6]);
  _quads->addPoint(_points[7]);

  _quads->addPoint(_points[0]);
  _quads->addPoint(_points[4]);
  _quads->addPoint(_points[5]);
  _quads->addPoint(_points[1]);

  _quads->addPoint(_points[1]);
  _quads->addPoint(_points[5]);
  _quads->addPoint(_points[6]);
  _quads->addPoint(_points[2]);

  _quads->addPoint(_points[2]);
  _quads->addPoint(_points[6]);
  _quads->addPoint(_points[7]);
  _quads->addPoint(_points[3]);

  _quads->addPoint(_points[3]);
  _quads->addPoint(_points[7]);
  _quads->addPoint(_points[4]);
  _quads->addPoint(_points[0]);

  _faces->compile();
}


renderer::LegacyShape& RectangularPrism::getFaces()
{
  return *_faces;
}


int
RectangularPrism::getNumberEdges()
{
  return NUMBER_EDGES;
}


int
RectangularPrism::getNumberTriangles()
{
  return 0;
}


int
RectangularPrism::getNumberQuads()
{
  return NUMBER_QUADS;
}


void
RectangularPrism::setDimensions(float length,
                                float height,
                                float width)
{
  _length = length;
  _height = height;
  _width = width;

  recalculateVertices();
}


float RectangularPrism::getLength() const
{
  return _length;
}


float RectangularPrism::getHeight() const
{
  return _height;
}


float RectangularPrism::getWidth() const
{
  return _width;
}


void
RectangularPrism::recalculateVertices() {
  for (int i = 0; i < 8; i++) {
    _points[i][0] = _unitVertices[i][0] * _length;
    _points[i][1] = _unitVertices[i][1] * _height;
    _points[i][2] = _unitVertices[i][2] * _width;
  }
}


}


}
