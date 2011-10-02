#include "RectangularPrism.h"


namespace gelatine
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
                                   Appearance& edgeAppearance,
                                   Appearance& faceAppearance) :
  _lines(::gelatine::SpecificGeometry::LINES),
  _quads(::gelatine::SpecificGeometry::QUADS),
  _edges(_lines, edgeAppearance),
  _faces(_quads, faceAppearance)
{
  _length = length;
  _height = height;
  _width = width;

  initialise();
}


void
RectangularPrism::initialise()
{
  //  _localVertices = new float* [NUMBER_VERTICES];
  //  _vertices = new float* [NUMBER_VERTICES];
  _vertices = new float* [NUMBER_VERTICES];

  for (int i = 0; i < NUMBER_VERTICES; i++) {
    _vertices[i] = new float [4];
    for (int j = 0; j < 4; j++) {
      _vertices[i][j] = _unitVertices[i][j];
    }
  }

  for (int i = 0; i < NUMBER_VERTICES; i++) {
    _vertices[i][0] = _unitVertices[i][0] * _length;
    _vertices[i][1] = _unitVertices[i][1] * _height;
    _vertices[i][2] = _unitVertices[i][2] * _width;
  }

  _lines.addPoint(_vertices[0]);
  _lines.addPoint(_vertices[1]);

  _lines.addPoint(_vertices[1]);
  _lines.addPoint(_vertices[2]);

  _lines.addPoint(_vertices[2]);
  _lines.addPoint(_vertices[3]);

  _lines.addPoint(_vertices[3]);
  _lines.addPoint(_vertices[0]);

  _lines.addPoint(_vertices[4]);
  _lines.addPoint(_vertices[5]);

  _lines.addPoint(_vertices[5]);
  _lines.addPoint(_vertices[6]);

  _lines.addPoint(_vertices[6]);
  _lines.addPoint(_vertices[7]);

  _lines.addPoint(_vertices[7]);
  _lines.addPoint(_vertices[4]);

  _lines.addPoint(_vertices[0]);
  _lines.addPoint(_vertices[4]);

  _lines.addPoint(_vertices[1]);
  _lines.addPoint(_vertices[5]);

  _lines.addPoint(_vertices[2]);
  _lines.addPoint(_vertices[6]);

  _lines.addPoint(_vertices[3]);
  _lines.addPoint(_vertices[7]);

  _quads.addPoint(_vertices[0]);
  _quads.addPoint(_vertices[1]);
  _quads.addPoint(_vertices[2]);
  _quads.addPoint(_vertices[3]);

  _quads.addPoint(_vertices[4]);
  _quads.addPoint(_vertices[5]);
  _quads.addPoint(_vertices[6]);
  _quads.addPoint(_vertices[7]);

  _quads.addPoint(_vertices[0]);
  _quads.addPoint(_vertices[4]);
  _quads.addPoint(_vertices[5]);
  _quads.addPoint(_vertices[1]);

  _quads.addPoint(_vertices[1]);
  _quads.addPoint(_vertices[5]);
  _quads.addPoint(_vertices[6]);
  _quads.addPoint(_vertices[2]);

  _quads.addPoint(_vertices[2]);
  _quads.addPoint(_vertices[6]);
  _quads.addPoint(_vertices[7]);
  _quads.addPoint(_vertices[3]);

  _quads.addPoint(_vertices[3]);
  _quads.addPoint(_vertices[7]);
  _quads.addPoint(_vertices[4]);
  _quads.addPoint(_vertices[0]);

  _faces.compile();
}


int
RectangularPrism::getNumberEdges()
{
  return 12;
}


int
RectangularPrism::getNumberTriangles()
{
  return 0;
}


int
RectangularPrism::getNumberQuads()
{
  return 6;
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


void
RectangularPrism::recalculateVertices() {
  for (int i = 0; i < 8; i++) {
    _vertices[i][0] = _unitVertices[i][0] * _length;
    _vertices[i][1] = _unitVertices[i][1] * _height;
    _vertices[i][2] = _unitVertices[i][2] * _width;
  }
}


}
