#include "DefaultTransition.h"


namespace gelatine
{


DefaultTransition::DefaultTransition()
{
  _inProgress = false;
}


bool
DefaultTransition::inProgress()
{
  return _inProgress;
}


void
DefaultTransition::commence(Shot& initialView, Shot& finalShot)
{
  _inProgress = true;
}


void
DefaultTransition::increment(Shot& initialShot, Shot& finalShot)
{
  _inProgress = false;
}


void
DefaultTransition::postComplete(Shot& initialShot, Shot& finalShot)
{
}


}
