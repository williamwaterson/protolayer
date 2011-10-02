#include "Edge.h"


namespace protolayer
{

namespace nurbs
{

Edge::Edge(Curve& curve, Vertex& firstVertex, Vertex& secondVertex) :
  _curve(curve),
  _firstHalfEdge(firstVertex),
  _secondHalfEdge(secondVertex)
{
}


Edge::~Edge()
{
}


Curve& Edge::getCurve()
{
  return _curve;
}


HalfEdge& Edge::getFirstHalfEdge()
{
  return _firstHalfEdge;
}


HalfEdge& Edge::getSecondHalfEdge()
{
  return _secondHalfEdge;
}


}


}
