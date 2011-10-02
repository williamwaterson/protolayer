#include "HalfEdge.h"


namespace protolayer
{

namespace nurbs
{

HalfEdge::HalfEdge(Vertex& fromVertex) :
  _fromVertex(fromVertex)
{
}


HalfEdge::~HalfEdge()
{
}


Vertex& HalfEdge::getFromVertex()
{
  return _fromVertex;
}


}


}
