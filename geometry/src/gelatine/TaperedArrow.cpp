#include "TaperedArrow.h"


namespace gelatine
{


float TaperedArrow::_headUnitVertices[5][4] =
  { { -1, -A,  0, 1 },
    { -1, -B,  0, 1 },
    {  0,  0,  0, 1 },
    { -1,  B,  0, 1 },
    { -1,  A,  0, 1 }
  };


TaperedArrow::TaperedArrow(float startX,
                           float startY,
                           float startZ,
                           float endX,
                           float endY,
                           float endZ,
                           Appearance& edgeAppearance,
                           Appearance& faceAppearance)
{
  _lines = new SpecificGeometry(SpecificGeometry::LINES);
  _triangles = new SpecificGeometry(gelatine::SpecificGeometry::TRIANGLES);

  _scale = 0.5f;

  _vertices = new float* [NUMBER_VERTICES];  
  for (int i = 0; i < NUMBER_VERTICES; i++) {
    _vertices[i] = new float [4];
    _vertices[i][0] = 0;
    _vertices[i][1] = 0;
    _vertices[i][2] = 0;
    _vertices[i][3] = 1;
  }

  _midpoint[0] = 0.0f;
  _midpoint[1] = 0.0f;
  _midpoint[2] = 0.0f;

  _normal[0] = 0.0f;
  _normal[1] = 1.0f;
  _normal[2] = 0.0f;

  _vertices[0][0] = startX;
  _vertices[0][1] = startY;
  _vertices[0][2] = startZ;

  _vertices[3][0] = endX;
  _vertices[3][1] = endY;
  _vertices[3][2] = endZ;

  _xaxis[0] = 1;
  _xaxis[1] = 0;
  _xaxis[2] = 0;

  _yaxis[0] = 0;
  _yaxis[1] = 1;
  _yaxis[2] = 0;

  _zaxis[0] = 0;
  _zaxis[1] = 0;
  _zaxis[2] = 1;

  recalculateVertices();
  evaluatePosition();

  _lines->addPoint(_vertices[0]);
  _lines->addPoint(_vertices[1]);

  _lines->addPoint(_vertices[1]);
  _lines->addPoint(_vertices[2]);

  _lines->addPoint(_vertices[2]);
  _lines->addPoint(_vertices[3]);

  _lines->addPoint(_vertices[3]);
  _lines->addPoint(_vertices[4]);

  _lines->addPoint(_vertices[4]);
  _lines->addPoint(_vertices[5]);

  _lines->addPoint(_vertices[5]);
  _lines->addPoint(_vertices[0]);

  _triangles->addPoint(_vertices[0]);
  _triangles->addPoint(_vertices[1]);
  _triangles->addPoint(_vertices[5]);

  _triangles->addPoint(_vertices[1]);
  _triangles->addPoint(_vertices[2]);
  _triangles->addPoint(_vertices[3]);

  _triangles->addPoint(_vertices[1]);
  _triangles->addPoint(_vertices[3]);
  _triangles->addPoint(_vertices[5]);

  _triangles->addPoint(_vertices[3]);
  _triangles->addPoint(_vertices[4]);
  _triangles->addPoint(_vertices[5]);

  _faces = new Shape(*_triangles, faceAppearance);
  _edges = new Shape(*_lines, edgeAppearance);

  _edges->compile();
  _faces->compile();

  addChild(*_faces);
  addChild(*_edges);
}


void
TaperedArrow::setOrthonormalBasis(float xaxis[3],
                                  float yaxis[3],
                                  float zaxis[3])
{
  _xaxis[0] = xaxis[0];
  _xaxis[1] = xaxis[1];
  _xaxis[2] = xaxis[2];

  _yaxis[0] = yaxis[0];
  _yaxis[1] = yaxis[1];
  _yaxis[2] = yaxis[2];

  _zaxis[0] = zaxis[0];
  _zaxis[1] = zaxis[1];
  _zaxis[2] = zaxis[2];
}


void
TaperedArrow::setStart(float x,
                       float y,
                       float z)
{
  _vertices[0][0] = x;
  _vertices[0][1] = y;
  _vertices[0][2] = z;

  recalculateVertices();
  evaluatePosition();
}


void
TaperedArrow::setEnd(float x,
                     float y,
                     float z)
{
  _vertices[3][0] = x;
  _vertices[3][1] = y;
  _vertices[3][2] = z;

  recalculateVertices();
  evaluatePosition();
}


Shape& TaperedArrow::getEdges()
{
  return *_edges;
}


Shape& TaperedArrow::getFaces()
{
  return *_faces;
}


float*
TaperedArrow::getStart()
{
  return _vertices[0];
}


float*
TaperedArrow::getEnd()
{
  return _vertices[3];
}


float*
TaperedArrow::getPosition()
{
  return _midpoint;
}


int
TaperedArrow::getNumberEdges()
{
  return NUMBER_VERTICES;
}


int
TaperedArrow::getNumberTriangles()
{
  return 4;
}


void
TaperedArrow::evaluatePosition()
{
  _midpoint[0] = _vertices[0][0] - _vertices[3][0];
  _midpoint[1] = _vertices[0][1] - _vertices[3][1];
  _midpoint[2] = _vertices[0][2] - _vertices[3][2];

  _midpoint[0] /= 2;
  _midpoint[1] /= 2;
  _midpoint[2] /= 2;

  _midpoint[0] += _vertices[3][0];
  _midpoint[1] += _vertices[3][1];
  _midpoint[2] += _vertices[3][2];
}


void
TaperedArrow::recalculateVertices()
{
  for (int i = 0; i < 5; i++) {
      _vertices[i+1][0] =
      _headUnitVertices[i][0] * _xaxis[0] * _scale +
      _headUnitVertices[i][1] * _yaxis[0] * _scale +
      _headUnitVertices[i][2] * _zaxis[0] * _scale +
      _vertices[3][0];

    _vertices[i+1][1] =
      _headUnitVertices[i][0] * _xaxis[1] * _scale +
      _headUnitVertices[i][1] * _yaxis[1] * _scale +
      _headUnitVertices[i][2] * _zaxis[1] * _scale +
      _vertices[3][1];

    _vertices[i+1][2] =
      _headUnitVertices[i][0] * _xaxis[2] * _scale +
      _headUnitVertices[i][1] * _yaxis[2] * _scale +
      _headUnitVertices[i][2] * _zaxis[2] * _scale +
      _vertices[3][2];

  }

}


}
