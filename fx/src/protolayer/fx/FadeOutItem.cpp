#include "FadeOutItem.h"


namespace protolayer
{

namespace fx
{

FadeOutItem::FadeOutItem(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
FadeOutItem::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
FadeOutItem::setTarget(Item* target)
{
  _target = target;
}


void
FadeOutItem::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
FadeOutItem::inProgress()
{
  return _inProgress;
}


void
FadeOutItem::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _inProgress = false;
    _target->getModel().setModifierAlpha(ZERO);
  } else {
    _target->getModel().setModifierAlpha(UNITY - _fraction);
  }
}


void
FadeOutItem::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}

