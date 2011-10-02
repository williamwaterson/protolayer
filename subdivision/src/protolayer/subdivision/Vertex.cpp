#include "Vertex.h"
#include <iostream.h>

namespace protolayer
{

namespace subdivision
{

Vertex::Vertex()
{
  _edgeCount = 0;
  _faceCount = 0;
  _petalCount = 0;
  _flowerCount = 0;

  _isCorner = false;
  _isBoundary = false;
  _isNonmanifold = false;

  _offset = 0.02;

  _coordinates[0] = 0;
  _coordinates[1] = 0;
  _coordinates[2] = 0;
  _coordinates[3] = 1;

  _normal[0] = 0;
  _normal[1] = 0;
  _normal[2] = 0;
  _normal[3] = 1;

  _valency = 0;

  _mapping = 0;
}


Vertex::~Vertex()
{
}


bool Vertex::isBoundary() const
{
  return _isBoundary;
}


bool Vertex::isNonmanifold() const
{
  return _isNonmanifold;
}


void Vertex::setBoundary(bool flag)
{
  _isBoundary = flag;
}


bool Vertex::isCorner() const
{
  return _isCorner;
}


void Vertex::setCorner(bool flag)
{
  _isCorner = flag;
}


void Vertex::incrementFaceCount()
{
  _faceCount++;
}


void Vertex::decrementFaceCount()
{
  _faceCount--;
}


int Vertex::getFaceCount() const
{
  return _faceCount;
}


int Vertex::getPetalCount() const
{
  return _petalCount;
}


//void Vertex::incrementEdgeCount()
//{
//  _edgeCount++;
//}


//void Vertex::decrementEdgeCount()
//{
//  _edgeCount--;
//}


//int Vertex::getEdgeCount() const
//{
//  return _edgeCount;
//}


void Vertex::evaluateOffset()
{
  _offsetCoordinates[0] = _coordinates[0];
  _offsetCoordinates[1] = _coordinates[1];
  _offsetCoordinates[2] = _coordinates[2];
  _offsetCoordinates[3] = 1;

  _offsetCoordinates[0] += _offset * _normal[0];
  _offsetCoordinates[1] += _offset * _normal[1];
  _offsetCoordinates[2] += _offset * _normal[2];
}


float* Vertex::getCoordinates()
{
  return _coordinates;
}


void Vertex::setMapping(Vertex& vertex)
{
  _mapping = &vertex;
}


Vertex* Vertex::getMapping()
{
  return _mapping;
}


void Vertex::setValency(int valency)
{
  _valency = valency;
}


int Vertex::getValency() const
{
  return _valency;
}


void Vertex::incrementValency()
{
  _valency++;
}


void Vertex::decrementValency()
{
  _valency--;
}


}


}
