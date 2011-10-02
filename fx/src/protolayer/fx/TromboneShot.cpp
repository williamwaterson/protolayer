#include "TromboneShot.h"


namespace protolayer
{

namespace fx
{

TromboneShot::TromboneShot(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
TromboneShot::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
TromboneShot::setTarget(Item* target)
{
  _target = target;
}


void
TromboneShot::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
TromboneShot::inProgress()
{
  return _inProgress;
}


void
TromboneShot::increment(long timeCurrent)
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
TromboneShot::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
