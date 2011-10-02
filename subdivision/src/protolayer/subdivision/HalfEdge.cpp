#include "HalfEdge.h"


namespace protolayer
{

namespace subdivision
{

bool HalfEdge::isBoundary() const
{
  return _isBoundary;
}


void HalfEdge::setBoundary(bool flag)
{
  _isBoundary = flag;
}


void HalfEdge::setMidpoint(Vertex& midpoint)
{
  _midpoint = &midpoint;
}


Vertex* HalfEdge::getMidpoint()
{
  return _midpoint;
}


HalfEdge::HalfEdge(Vertex& fromVertex, Vertex& toVertex)
{
  _fromVertex = &fromVertex;
  _toVertex = &toVertex;
  _isBoundary = false;
  _faceCount = 0;
}

Vertex& HalfEdge::getFromVertex()
{
  return *_fromVertex;
}

Vertex& HalfEdge::getToVertex()
{
  return *_toVertex;
}

bool HalfEdge::isFrom(const Vertex& vertex) const
{
  return _fromVertex == &vertex;
}

bool HalfEdge::isTo(const Vertex& vertex) const
{
  return _toVertex == &vertex;
}

bool HalfEdge::isEquivalent(const Vertex& first, const Vertex& second) const
{
  return isFrom(first) && isTo(second);
}


void HalfEdge::setObject(void* object)
{
  _object = object;
}


void HalfEdge::incrementFaceCount()
{
  _faceCount++;
}


void HalfEdge::decrementFaceCount()
{
  _faceCount--;
}


int HalfEdge::getFaceCount() const
{
  return _faceCount;
}


}


}
