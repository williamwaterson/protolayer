#include "Loop.h"


namespace protolayer
{

namespace nurbs
{

Loop::Loop()
{
}


Loop::~Loop()
{
}


HalfLoop& Loop::getFirstHalfLoop()
{
  return _firstHalfLoop;
}


HalfLoop& Loop::getSecondHalfLoop()
{
  return _secondHalfLoop;
}


}


}

