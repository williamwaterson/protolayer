#include "TransitionAction.h"


namespace protolayer
{

namespace renderer
{

TransitionAction::TransitionAction(Space& space, Shot& initialShot, Shot& finalShot)
{
  _space = &space;
  _initialShot = &initialShot;
  _finalShot = &finalShot;
}


TransitionAction::~TransitionAction()
{
}


void TransitionAction::setSpace(Space& space)
{
  _space = &space;
}


void TransitionAction::setInitialShot(Shot& initialShot)
{
  _initialShot = &initialShot;
}


void TransitionAction::setFinalShot(Shot& finalShot)
{
  _finalShot = &finalShot;
}


Space& TransitionAction::getSpace()
{
  return *_space;
}


Shot& TransitionAction::getFinalShot()
{
  return *_finalShot;
}


Shot& TransitionAction::getInitialShot()
{
  return *_initialShot;
}


}


}
