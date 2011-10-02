#include "ZoomShot.h"


namespace protolayer
{

namespace fx
{

ZoomShot::ZoomShot(long timePeriod,
                   renderer::Camera* camera,
                   float finalZoom) {
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _camera = camera;

  _initialZoom = camera->getZoom();
  _finalZoom = finalZoom;
  _differenceZoom = _finalZoom - _initialZoom;
}


void
ZoomShot::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
ZoomShot::setFinalPosition(float finalZoom)
{
  _initialZoom = _camera->getZoom();
  _finalZoom = finalZoom;
  _differenceZoom = _finalZoom - _initialZoom;
}


void
ZoomShot::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
ZoomShot::inProgress()
{
  return _inProgress;
}


void
ZoomShot::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _camera->setZoom(_finalZoom);
    _inProgress = false;

  } else {
    _camera->setZoom(_initialZoom + _fraction * _differenceZoom);
  }
}


void
ZoomShot::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
