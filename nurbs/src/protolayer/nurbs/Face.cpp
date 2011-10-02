#include "Face.h"


namespace protolayer
{

namespace nurbs
{

Face::Face(Surface& surface, Loop& outerLoop) :
  _surface(surface),
  _outerLoop(outerLoop),
  _firstHalfFace(outerLoop.getFirstHalfLoop()),
  _secondHalfFace(outerLoop.getSecondHalfLoop())
{
}


Face::~Face()
{
}


Surface& Face::getSurface()
{
  return _surface;
}


HalfFace& Face::getFirstHalfFace()
{
  return _firstHalfFace;
}


HalfFace& Face::getSecondHalfFace()
{
  return _secondHalfFace;
}


Loop& Face::getOuterLoop()
{
  return _outerLoop;
}


void Face::addLoop(Loop& loop)
{
}


void Face::removeLoop(Loop& loop)
{
}


}


}
