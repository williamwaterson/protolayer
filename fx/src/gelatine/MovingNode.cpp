#include "MovingShot.h"


namespace protolayer
{


MovingShot::MovingShot(long timePeriod,
                       Camera* camera,
                       float finalPosition[3]) {
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;
  _camera = camera;

  _oldPosition[0] = camera->getPosition()[0];
  _oldPosition[1] = camera->getPosition()[1];
  _oldPosition[2] = camera->getPosition()[2];

  _targetDirection[0] = camera->_target[0];
  _targetDirection[1] = camera->_target[1];
  _targetDirection[2] = camera->_target[2];

  _targetDirection[0] -= _oldPosition[0];
  _targetDirection[1] -= _oldPosition[1];
  _targetDirection[2] -= _oldPosition[2];

  _finalPosition[0] = finalPosition[0];
  _finalPosition[1] = finalPosition[1];
  _finalPosition[2] = finalPosition[2];

  _direction[0] = finalPosition[0];
  _direction[1] = finalPosition[1];
  _direction[2] = finalPosition[2];

  _direction[0] -= _oldPosition[0];
  _direction[1] -= _oldPosition[1];
  _direction[2] -= _oldPosition[2];
}


void
MovingShot::setTimePeriod(long timePeriod)
{
  _timePeriod = timePeriod;
}


void
MovingShot::setFinalPosition(float finalPosition[3])
{
  _oldPosition[0] = _camera->getPosition()[0];
  _oldPosition[1] = _camera->getPosition()[1];
  _oldPosition[2] = _camera->getPosition()[2];

  _targetDirection[0] = _camera->_target[0];
  _targetDirection[1] = _camera->_target[1];
  _targetDirection[2] = _camera->_target[2];

  _targetDirection[0] -= _oldPosition[0];
  _targetDirection[1] -= _oldPosition[1];
  _targetDirection[2] -= _oldPosition[2];

  _finalPosition[0] = finalPosition[0];
  _finalPosition[1] = finalPosition[1];
  _finalPosition[2] = finalPosition[2];

  _direction[0] = finalPosition[0];
  _direction[1] = finalPosition[1];
  _direction[2] = finalPosition[2];

  _direction[0] -= _oldPosition[0];
  _direction[1] -= _oldPosition[1];
  _direction[2] -= _oldPosition[2];
}


void
MovingShot::commence(long timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool
MovingShot::inProgress()
{
  return _inProgress;
}


void
MovingShot::increment(long timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _camera->setPosition(_finalPosition);

    float target[3];
    target[0] = _finalPosition[0] + _targetDirection[0];
    target[1] = _finalPosition[1] + _targetDirection[1];
    target[2] = _finalPosition[2] + _targetDirection[2];
    _camera->setTarget(target);

    _inProgress = false;

  } else {
    _camera->_position[0] = _oldPosition[0];
    _camera->_position[1] = _oldPosition[1];
    _camera->_position[2] = _oldPosition[2];

    _camera->_position[0] += _fraction * _direction[0];
    _camera->_position[1] += _fraction * _direction[1];
    _camera->_position[2] += _fraction * _direction[2];

    _camera->_target[0] = _camera->_position[0];
    _camera->_target[1] = _camera->_position[1];
    _camera->_target[2] = _camera->_position[2];

    _camera->_target[0] += _targetDirection[0];
    _camera->_target[1] += _targetDirection[1];
    _camera->_target[2] += _targetDirection[2];
  }
}


void
MovingShot::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}
