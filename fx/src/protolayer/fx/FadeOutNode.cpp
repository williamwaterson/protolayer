#include "FadeOutNode.h"


namespace protolayer
{

namespace fx
{

FadeOutNode::FadeOutNode(long timePeriod, style::Appearance* target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = target;
}


void
FadeOutNode::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
FadeOutNode::setTarget(style::Appearance* target)
{
  _target = target;
}


void
FadeOutNode::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
FadeOutNode::inProgress()
{
  return _inProgress;
}


void
FadeOutNode::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _inProgress = false;
    _target->setModifierAlpha(ZERO);
  } else {
    _target->setModifierAlpha(UNITY - _fraction);
  }
}


void
FadeOutNode::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
