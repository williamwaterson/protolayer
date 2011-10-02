#include "HalfFace.h"


namespace protolayer
{

namespace nurbs
{

HalfFace::HalfFace(HalfLoop& outerHalfLoop) :
  _outerHalfLoop(outerHalfLoop)
{
}


HalfFace::~HalfFace()
{
}


HalfLoop& HalfFace::getOuterHalfLoop()
{
  return _outerHalfLoop;
}


}


}
