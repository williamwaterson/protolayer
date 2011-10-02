#include "AlphaShift.h"


namespace protolayer
{

namespace fx
{

AlphaShift::AlphaShift(float timePeriod, style::Appearance& target, float finalAlpha)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _inProgress = false;
  _target = &target;
  _finalAlpha = finalAlpha;
}


void
AlphaShift::setTimePeriod(float timePeriod)
{
  _timePeriod = timePeriod;
}


void
AlphaShift::setTarget(style::Appearance& target)
{
  _target = &target;
}


void
AlphaShift::setFinalAlpha(float alpha)
{
  _finalAlpha = alpha;
}


void
AlphaShift::commence(float timeStarted)
{
  _timeStarted = timeStarted;
  _initialAlpha =  _target->getModifierAlpha();
  _alphaRate = _finalAlpha - _initialAlpha;
  _alphaRate /= _timePeriod;
  _inProgress = true;
}


bool
AlphaShift::inProgress()
{
  return _inProgress;
}


void
AlphaShift::increment(float timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  if (_timeElapsed > _timePeriod) {
    _target->setModifierAlpha(_finalAlpha);
    _inProgress = false;
  } else {
    _target->setModifierAlpha(_alphaRate * _timeElapsed + _initialAlpha);
  }
}


void
AlphaShift::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
}


}


}
