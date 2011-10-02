#include "FadeInItem.h"


namespace protolayer
{


FadeInItem::FadeInItem(long timePeriod, Item* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
FadeInItem::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
FadeInItem::setTarget(Item* target)
{
  _target = target;
}


void
FadeInItem::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
FadeInItem::inProgress()
{
  return _inProgress;
}


void
FadeInItem::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _target->getModel().setModifierAlpha(1);
    _inProgress = false;
  } else {      
    _target->getModel().setModifierAlpha( (float) (_fraction) );
  }
}


void
FadeInItem::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}
