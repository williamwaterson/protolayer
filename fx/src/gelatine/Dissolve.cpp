#include "Dissolve.h"


namespace protolayer
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
Dissolve::commence(Shot& initialShot, Shot& finalShot)
{
  Microseconds(&_tick);
  _timeStarted = (float) UnsignedWideToUInt64(_tick);
  // printf("%9.2f\n", (float) UnsignedWideToUInt64(_tick));
  _inProgress = true;
}


void
Dissolve::increment(Shot& initialShot, Shot& finalShot)
{
  Microseconds(&_tick);
  _timeCurrent = (float) UnsignedWideToUInt64(_tick);
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
Dissolve::postComplete(Shot& initialShot, Shot& finalShot)
{
  initialShot.getCamera().setAlpha(UNITY);
  finalShot.getCamera().setAlpha(UNITY);
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


}
