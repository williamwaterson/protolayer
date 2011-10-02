#include "FadeInNode.h"


namespace protolayer
{

namespace fx
{

FadeInNode::FadeInNode(long timePeriod, style::Appearance& target)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _target = &target;
}


void
FadeInNode::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
FadeInNode::setTarget(style::Appearance& target)
{
  _target = &target;
}


void
FadeInNode::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
FadeInNode::inProgress()
{
  return _inProgress;
}


void
FadeInNode::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _target->setModifierAlpha(1);
    _inProgress = false;
  } else {      
    _target->setModifierAlpha(_fraction);
  }
}


void
FadeInNode::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
