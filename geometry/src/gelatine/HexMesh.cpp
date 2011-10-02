#include "HexMesh.h"


namespace gelatine
{


const double HexMesh::ANGLE_RADIANS = (30.0 / 180.0) * M_PI;

const double HexMesh::DELTA_X = sin(ANGLE_RADIANS);

const double HexMesh::DELTA_Z = cos(ANGLE_RADIANS);

float*** HexMesh::EMPTY = new float** [0];


int HexMesh::evaluateNumberVertices(int order)
{
  int numberRows = order;
  int numberShortRows = order / 2;
  int numberLongRows = numberRows - numberShortRows;

  int numVerticesPerZigZag = 2 * order + 1;
  return 2 * numVerticesPerZigZag * numberLongRows;
}


HexMesh::HexMesh(float radius,
                 int order,
                 Appearance& appearance)
{
  _radius = radius;
  _order = order + order - 1;

  _lines = new gelatine::SpecificGeometry(::gelatine::SpecificGeometry::LINES);

  double centreOffsetX = 3 * order - 2;
  centreOffsetX /= 2;
  centreOffsetX *= radius;

  double centreOffsetZ = 2 * order - 1;
  centreOffsetZ *= DELTA_Z;

  _corner[0] = 0;
  _corner[1] = 0;
  _corner[2] = 0;

  _corner[0] += centreOffsetX;
  _corner[2] -= centreOffsetZ;

  evaluateUnitStructure();

  _edges = new Shape(*_lines, appearance);
  addChild(*_edges);
}


void
HexMesh::evaluateUnitStructure()
{
  // Evaluate the number of vertices
  int numberRows = _order;
  int numberShortRows = _order / 2;
  int numberLongRows = numberRows - numberShortRows;

  int numVerticesPerZigZag = 2 * _order + 1;
  int numberVertices = 2 * numVerticesPerZigZag * numberLongRows;

  float** _vertices = new float* [numberVertices];
  for (int i = 0; i < numberVertices; i++) {
    _vertices[i] = new float[4];
    _vertices[i][0] = 0;
    _vertices[i][1] = 0;
    _vertices[i][2] = 0;
    _vertices[i][3] = 1;
  }

  // Ensure all vertices have the same y-axis value
  for (int i = 0; i < numberVertices; i++) {
    _vertices[i][1] = _corner[1];
  }

  // Evaluate the number of edges
  int numEdgesPerZigZag = 2 * _order;
  int numCrossLinksPerLongRow = _order + 1;
  int numEdgesPerLongRow = numEdgesPerZigZag * 2 + numCrossLinksPerLongRow;
  int numCrossLinksPerShortRow = _order;
  int numberEdges = numEdgesPerLongRow * numberLongRows +
    numCrossLinksPerShortRow * numberShortRows;

  // Evaluate the coordinates of all vertices
  double x = (double) _corner[0];
  double z = (double) _corner[2];
  int vertIndex = 0;

  for (int i = 0; i < numberLongRows; i++) {
    x = (double) _corner[0] + (-i * 3);
    z = (double) _corner[2];
    for (int j = 0; j < _order; j++) {
      _vertices[vertIndex][0] = (float) x;
      _vertices[vertIndex][2] = (float) z;
      z += DELTA_Z;
      vertIndex++;

      _vertices[vertIndex][0] = (float) (x + DELTA_X);
      _vertices[vertIndex][2] = (float) z;
      z += DELTA_Z;
      vertIndex++;
    }

    _vertices[vertIndex][0] = (float) x;
    _vertices[vertIndex][2] = (float) z;
    vertIndex++;

    x -= 1;
    z =  (double) _corner[2];
    for (int j = 0; j < _order; j++) {
      _vertices[vertIndex][0] = (float) x;
      _vertices[vertIndex][2] = (float) z;
      z += DELTA_Z;
      vertIndex++;

      _vertices[vertIndex][0] = (float) (x - DELTA_X);
      _vertices[vertIndex][2] = (float) z;
      z += DELTA_Z;
      vertIndex++;
    }

    _vertices[vertIndex][0] = (float) x;
    _vertices[vertIndex][2] = (float) z;
    vertIndex++;
  }

  // Set up long-row zig-zag edges
  int edgeIndex = 0;
  vertIndex = 0;
  for (int i = 0; i < numberLongRows; i++) {
    vertIndex = i * 2 * numVerticesPerZigZag;
    for (int j = 0; j < numEdgesPerZigZag; j++) {
      _lines->addPoint(_vertices[vertIndex]);
      _lines->addPoint(_vertices[vertIndex + 1]);
      edgeIndex++;
      vertIndex++;
    }

    vertIndex = i * 2 * numVerticesPerZigZag + numVerticesPerZigZag;
    for (int j = 0; j < numEdgesPerZigZag; j++) {
      _lines->addPoint(_vertices[vertIndex]);
      _lines->addPoint(_vertices[vertIndex + 1]);
      edgeIndex++;
      vertIndex++;
    }
  }

  // Set up long-row cross-link edges
  for (int i = 0; i < numberLongRows; i++) {
    vertIndex = i * 2 * numVerticesPerZigZag;
    for (int j = 0; j < numCrossLinksPerLongRow; j++) {
      _lines->addPoint(_vertices[vertIndex]);
      _lines->addPoint(_vertices[vertIndex + numVerticesPerZigZag]);
      vertIndex += 2;
      edgeIndex++;
    }
  }

  // Set up short-row cross-link edges
  for (int i = 0; i <  numberShortRows; i++) {
    vertIndex = i * 2 * numVerticesPerZigZag + numVerticesPerZigZag + 1;
    for (int j = 0; j < numCrossLinksPerShortRow; j++) {
      _lines->addPoint(_vertices[vertIndex]);
      _lines->addPoint(_vertices[vertIndex + numVerticesPerZigZag]);
      vertIndex += 2;
      edgeIndex++;
    }
  }
}


Appearance& HexMesh::getAppearance()
{
  return _edges->getAppearance();
}


}
