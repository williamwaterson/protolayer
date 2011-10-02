#include "RetargetShot.h"


namespace protolayer
{

namespace fx
{

RetargetShot::RetargetShot(long timePeriod,
                           Camera* camera,
                           float newTarget[3]) {
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _camera = camera;

  _oldTarget[0] = camera->_target[0];
  _oldTarget[1] = camera->_target[1];
  _oldTarget[2] = camera->_target[2];

  _newTarget[0] = newTarget[0];
  _newTarget[1] = newTarget[1];
  _newTarget[2] = newTarget[2];

  _direction[0] = newTarget[0];
  _direction[1] = newTarget[1];
  _direction[2] = newTarget[2];

  _direction[0] -= _oldTarget[0];
  _direction[1] -= _oldTarget[1];
  _direction[2] -= _oldTarget[2];
}


void
RetargetShot::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
RetargetShot::setTarget(float newTarget[3])
{
  _oldTarget[0] = _camera->_target[0];
  _oldTarget[1] = _camera->_target[1];
  _oldTarget[2] = _camera->_target[2];

  _newTarget[0] = newTarget[0];
  _newTarget[1] = newTarget[1];
  _newTarget[2] = newTarget[2];

  _direction[0] = newTarget[0];
  _direction[1] = newTarget[1];
  _direction[2] = newTarget[2];

  _direction[0] -= _oldTarget[0];
  _direction[1] -= _oldTarget[1];
  _direction[2] -= _oldTarget[2];
}


void
RetargetShot::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
RetargetShot::inProgress()
{
  return _inProgress;
}


void
RetargetShot::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _camera->_target[0] = _newTarget[0];
    _camera->_target[1] = _newTarget[1];
    _camera->_target[2] = _newTarget[2];

    _inProgress = false;

  } else {
    _camera->_target[0] = _oldTarget[0];
    _camera->_target[1] = _oldTarget[1];
    _camera->_target[2] = _oldTarget[2];

    _camera->_target[0] += _fraction * _direction[0];
    _camera->_target[1] += _fraction * _direction[1];
    _camera->_target[2] += _fraction * _direction[2];
  }
}


void
RetargetShot::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}


}
