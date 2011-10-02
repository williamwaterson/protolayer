#include "SweepShot.h"


namespace protolayer
{


SweepShot::SweepShot(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
SweepShot::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
SweepShot::setTarget(Item* target)
{
  _target = target;
}


void
SweepShot::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
SweepShot::inProgress()
{
  return _inProgress;
}


void
SweepShot::increment(long timeCurrent)
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
SweepShot::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}
