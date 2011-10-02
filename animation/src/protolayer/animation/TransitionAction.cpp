#include "TransitionAction.h"


namespace protolayer
{

namespace animation
{

TransitionAction::TransitionAction(scenegraph::Shot& initialShot, scenegraph::Shot& finalShot)
{
  _initialShot = &initialShot;
  _finalShot = &finalShot;
}


TransitionAction::~TransitionAction()
{
}


void TransitionAction::setInitialShot(scenegraph::Shot& initialShot)
{
  _initialShot = &initialShot;
}


void TransitionAction::setFinalShot(scenegraph::Shot& finalShot)
{
  _finalShot = &finalShot;
}


scenegraph::Shot& TransitionAction::getFinalShot()
{
  return *_finalShot;
}


scenegraph::Shot& TransitionAction::getInitialShot()
{
  return *_initialShot;
}


}


}
