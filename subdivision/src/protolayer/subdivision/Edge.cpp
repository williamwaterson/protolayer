#include "Edge.h"


namespace protolayer
{

namespace subdivision
{


void Edge::evaluateDirections()
{
  _firstHalfEdge->_direction[0] =
    _firstHalfEdge->getToVertex()._coordinates[0] -
    _firstHalfEdge->getFromVertex()._coordinates[0];
  _firstHalfEdge->_direction[1] =
    _firstHalfEdge->getToVertex()._coordinates[1] -
    _firstHalfEdge->getFromVertex()._coordinates[1];
  _firstHalfEdge->_direction[2] =
    _firstHalfEdge->getToVertex()._coordinates[2] -
    _firstHalfEdge->getFromVertex()._coordinates[2];
  _firstHalfEdge->_direction[3] = 1;

  _secondHalfEdge->_direction[0] = -_firstHalfEdge->_direction[0];
  _secondHalfEdge->_direction[1] = -_firstHalfEdge->_direction[1];
  _secondHalfEdge->_direction[2] = -_firstHalfEdge->_direction[2];
  _secondHalfEdge->_direction[3] = 1;
}


Edge::Edge(std::vector <Vertex*>& vertices,
           int fromIndex,
           int toIndex)
{
  _isBoundary = false;

  Vertex* firstVertex = vertices[fromIndex];
  Vertex* secondVertex = vertices[toIndex];

  _firstHalfEdge = new HalfEdge(*firstVertex, *secondVertex);
  _secondHalfEdge = new HalfEdge(*secondVertex, *firstVertex);

  _object = 0;
}


Edge::Edge(Vertex& fromVertex,
           Vertex& toVertex)
{
  _isBoundary = false;

  _firstHalfEdge = new HalfEdge(fromVertex, toVertex);
  _secondHalfEdge = new HalfEdge(toVertex, fromVertex);

  _object = 0;
}


bool Edge::isBoundary() const
{
  return _isBoundary;
}


bool Edge::isNonmanifold()
{
  return getFaceCount() > 2;
}


void Edge::setBoundary(bool flag)
{
  _isBoundary = flag;

  getFirstHalf().setBoundary(flag);
  getSecondHalf().setBoundary(flag);

  getFirstHalf().getFromVertex().setBoundary(flag);
  getFirstHalf().getToVertex().setBoundary(flag);
}


int Edge::getFaceCount()
{
  int count = getFirstHalf().getFaceCount();
  count += getSecondHalf().getFaceCount();
  return count;
}


HalfEdge& Edge::getFirstHalf()
{
  return *_firstHalfEdge;
}


HalfEdge& Edge::getSecondHalf()
{
  return *_secondHalfEdge;
}


HalfEdge* Edge::getOtherHalf(HalfEdge& halfEdge)
{
  HalfEdge* result = 0;
  if (_firstHalfEdge == &halfEdge) {
    result = _secondHalfEdge;
  } else if (_secondHalfEdge == &halfEdge) {
    result = _firstHalfEdge;
  }
  
  return result;
}


bool Edge::isSimilar(const Vertex& first, const Vertex& second) const
{
  return _firstHalfEdge->isEquivalent(first, second) ||
    _secondHalfEdge->isEquivalent(first, second);
}


}


}
