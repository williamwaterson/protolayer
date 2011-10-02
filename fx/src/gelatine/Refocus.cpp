#include "Refocus.h"


namespace protolayer
{


Refocus::Refocus(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
Refocus::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
Refocus::setTarget(Item* target)
{
  _target = target;
}


void
Refocus::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
Refocus::inProgress()
{
  return _inProgress;
}


void
Refocus::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _inProgress = false;
  } else {      
    _target->getModel().setModifierAlpha( (float) (UNITY - _fraction) );
  }
}


void
Refocus::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}
