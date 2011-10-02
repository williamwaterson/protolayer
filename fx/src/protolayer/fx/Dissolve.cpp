#include "Dissolve.h"


namespace protolayer
{

namespace fx
{

Dissolve::Dissolve(float timePeriod)
{
  _inProgress = false;
  _timePeriod = timePeriod;
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


bool
Dissolve::inProgress()
{
  return _inProgress;
}


void
Dissolve::commence(scenegraph::Shot& initialShot, scenegraph::Shot& finalShot)
{
  //  Microseconds(&_tick);
  //  _timeStarted = (float) UnsignedWideToUInt64(_tick);
  // printf("%9.2f\n", (float) UnsignedWideToUInt64(_tick));

  gettimeofday(&_tick, NULL);    

  double doubleTime = _tick.tv_usec;
  doubleTime += _tick.tv_sec * 1000000;
  _timeStarted = (float) doubleTime;

  _inProgress = true;
}


void
Dissolve::increment(scenegraph::Shot& initialShot, scenegraph::Shot& finalShot)
{
  //  Microseconds(&_tick);
  //  _timeCurrent = (float) UnsignedWideToUInt64(_tick);

  gettimeofday(&_tick, NULL);    

  double doubleTime = _tick.tv_usec;
  doubleTime += _tick.tv_sec * 1000000;
  _timeCurrent = (float) doubleTime;

  _timeElapsed = _timeCurrent - _timeStarted;
  float fraction = _timeElapsed / _timePeriod;

  if (fraction > UNITY) {
    _inProgress = false;
  } else {
    initialShot.getCamera().setAlpha(UNITY - fraction);
    finalShot.getCamera().setAlpha(fraction);
  }
}


void
Dissolve::postComplete(scenegraph::Shot& initialShot, scenegraph::Shot& finalShot)
{
  initialShot.getCamera().setAlpha(UNITY);
  finalShot.getCamera().setAlpha(UNITY);
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


}


}
