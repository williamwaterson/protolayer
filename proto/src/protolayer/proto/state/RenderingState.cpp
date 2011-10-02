#include "RenderingState.h"


namespace protolayer
{

namespace proto
{

RenderingState::RenderingState(scenegraph::Shot& shot)
{
  _activeShot = &shot;
}


RenderingState::~RenderingState()
{
}


void RenderingState::setActiveShot(scenegraph::Shot& shot)
{
  _activeShot = &shot;
}


scenegraph::Shot& RenderingState::getActiveShot()
{
  return *_activeShot;
}


}


}
