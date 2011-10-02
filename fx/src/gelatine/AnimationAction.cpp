#include "AnimationAction.h"


namespace protolayer
{


AnimationAction::AnimationAction(long timePeriod,
                                 Group& target,
                                 float displace[3],
                                 float rotate,
                                 float scale)
{
  _timePeriod = timePeriod;
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
  _inProgress = false;

  _target = &target;
  _displace[0] = displace[0];
  _displace[1] = displace[1];
  _displace[2] = displace[2];
  _rotate = rotate;
  _scale = scale;

  _target->getLocalTransform(_originalTransform);
}


void
AnimationAction::setTimePeriod(float timePeriod)
{
  _timePeriod = timePeriod;
}


void
AnimationAction::setDisplacement(float displace[3])
{
  _displace[0] = displace[0];
  _displace[1] = displace[1];
  _displace[2] = displace[2];
}


void
AnimationAction::commence(float timeStarted)
{
  _timeStarted = timeStarted;
  _target->getLocalTransform(_originalTransform);
  _inProgress = true;
}


bool
AnimationAction::inProgress()
{
  return _inProgress;
}


void
AnimationAction::increment(float timeCurrent)
{
  _timeElapsed = timeCurrent;
  _timeElapsed -= _timeStarted;

  _fraction = (float) _timeElapsed;
  _fraction /= (float) _timePeriod;

  if (_fraction > UNITY) {
    _multiplier[0][3] = _displace[0];
    _multiplier[1][3] = _displace[1];
    _multiplier[2][3] = _displace[2];

    _multiplier[0][0] = cos(_rotate);
    _multiplier[0][1] = 0;
    _multiplier[0][2] = -sin(_rotate);

    _multiplier[1][0] = 0;
    _multiplier[1][1] = 1;
    _multiplier[1][2] = 0;

    _multiplier[2][0] = sin(_rotate);
    _multiplier[2][1] = 0;
    _multiplier[2][2] = cos(_rotate);

    _multiplier[3][3] = 1; // _scale;

    _inProgress = false;

  } else {
    _multiplier[0][3] = _fraction * _displace[0];
    _multiplier[1][3] = _fraction * _displace[1];
    _multiplier[2][3] = _fraction * _displace[2];

    float rotate = _fraction * _rotate;

    _multiplier[0][0] = cos(rotate);
    _multiplier[0][1] = 0;
    _multiplier[0][2] = -sin(rotate);

    _multiplier[1][0] = 0;
    _multiplier[1][1] = 1;
    _multiplier[1][2] = 0;

    _multiplier[2][0] = sin(rotate);
    _multiplier[2][1] = 0;
    _multiplier[2][2] = cos(rotate);

    _multiplier[3][3] = 1; // _fraction * _scale;
  }

  _currentTransform[0][0] =  _multiplier[0][0] * _originalTransform[0][0];
  _currentTransform[0][0] += _multiplier[0][1] * _originalTransform[1][0];
  _currentTransform[0][0] += _multiplier[0][2] * _originalTransform[2][0];
  _currentTransform[0][0] += _multiplier[0][3] * _originalTransform[3][0];

  _currentTransform[0][1] =  _multiplier[0][0] * _originalTransform[0][1];
  _currentTransform[0][1] += _multiplier[0][1] * _originalTransform[1][1];
  _currentTransform[0][1] += _multiplier[0][2] * _originalTransform[2][1];
  _currentTransform[0][1] += _multiplier[0][3] * _originalTransform[3][1];

  _currentTransform[0][2] =  _multiplier[0][0] * _originalTransform[0][2];
  _currentTransform[0][2] += _multiplier[0][1] * _originalTransform[1][2];
  _currentTransform[0][2] += _multiplier[0][2] * _originalTransform[2][2];
  _currentTransform[0][2] += _multiplier[0][3] * _originalTransform[3][2];

  _currentTransform[0][3] =  _multiplier[0][0] * _originalTransform[0][3];
  _currentTransform[0][3] += _multiplier[0][1] * _originalTransform[1][3];
  _currentTransform[0][3] += _multiplier[0][2] * _originalTransform[2][3];
  _currentTransform[0][3] += _multiplier[0][3] * _originalTransform[3][3];

  _currentTransform[1][0] =  _multiplier[1][0] * _originalTransform[0][0];
  _currentTransform[1][0] += _multiplier[1][1] * _originalTransform[1][0];
  _currentTransform[1][0] += _multiplier[1][2] * _originalTransform[2][0];
  _currentTransform[1][0] += _multiplier[1][3] * _originalTransform[3][0];

  _currentTransform[1][1] =  _multiplier[1][0] * _originalTransform[0][1];
  _currentTransform[1][1] += _multiplier[1][1] * _originalTransform[1][1];
  _currentTransform[1][1] += _multiplier[1][2] * _originalTransform[2][1];
  _currentTransform[1][1] += _multiplier[1][3] * _originalTransform[3][1];

  _currentTransform[1][2] =  _multiplier[1][0] * _originalTransform[0][2];
  _currentTransform[1][2] += _multiplier[1][1] * _originalTransform[1][2];
  _currentTransform[1][2] += _multiplier[1][2] * _originalTransform[2][2];
  _currentTransform[1][2] += _multiplier[1][3] * _originalTransform[3][2];

  _currentTransform[1][3] =  _multiplier[1][0] * _originalTransform[0][3];
  _currentTransform[1][3] += _multiplier[1][1] * _originalTransform[1][3];
  _currentTransform[1][3] += _multiplier[1][2] * _originalTransform[2][3];
  _currentTransform[1][3] += _multiplier[1][3] * _originalTransform[3][3];


  _currentTransform[2][0] =  _multiplier[2][0] * _originalTransform[0][0];
  _currentTransform[2][0] += _multiplier[2][1] * _originalTransform[1][0];
  _currentTransform[2][0] += _multiplier[2][2] * _originalTransform[2][0];
  _currentTransform[2][0] += _multiplier[2][3] * _originalTransform[3][0];

  _currentTransform[2][1] =  _multiplier[2][0] * _originalTransform[0][1];
  _currentTransform[2][1] += _multiplier[2][1] * _originalTransform[1][1];
  _currentTransform[2][1] += _multiplier[2][2] * _originalTransform[2][1];
  _currentTransform[2][1] += _multiplier[2][3] * _originalTransform[3][1];

  _currentTransform[2][2] =  _multiplier[2][0] * _originalTransform[0][2];
  _currentTransform[2][2] += _multiplier[2][1] * _originalTransform[1][2];
  _currentTransform[2][2] += _multiplier[2][2] * _originalTransform[2][2];
  _currentTransform[2][2] += _multiplier[2][3] * _originalTransform[3][2];

  _currentTransform[2][3] =  _multiplier[2][0] * _originalTransform[0][3];
  _currentTransform[2][3] += _multiplier[2][1] * _originalTransform[1][3];
  _currentTransform[2][3] += _multiplier[2][2] * _originalTransform[2][3];
  _currentTransform[2][3] += _multiplier[2][3] * _originalTransform[3][3];


  _currentTransform[3][0] =  _multiplier[3][0] * _originalTransform[0][0];
  _currentTransform[3][0] += _multiplier[3][1] * _originalTransform[1][0];
  _currentTransform[3][0] += _multiplier[3][2] * _originalTransform[2][0];
  _currentTransform[3][0] += _multiplier[3][3] * _originalTransform[3][0];

  _currentTransform[3][1] =  _multiplier[3][0] * _originalTransform[0][1];
  _currentTransform[3][1] += _multiplier[3][1] * _originalTransform[1][1];
  _currentTransform[3][1] += _multiplier[3][2] * _originalTransform[2][1];
  _currentTransform[3][1] += _multiplier[3][3] * _originalTransform[3][1];

  _currentTransform[3][2] =  _multiplier[3][0] * _originalTransform[0][2];
  _currentTransform[3][2] += _multiplier[3][1] * _originalTransform[1][2];
  _currentTransform[3][2] += _multiplier[3][2] * _originalTransform[2][2];
  _currentTransform[3][2] += _multiplier[3][3] * _originalTransform[3][2];

  _currentTransform[3][3] =  _multiplier[3][0] * _originalTransform[0][3];
  _currentTransform[3][3] += _multiplier[3][1] * _originalTransform[1][3];
  _currentTransform[3][3] += _multiplier[3][2] * _originalTransform[2][3];
  _currentTransform[3][3] += _multiplier[3][3] * _originalTransform[3][3];

  _target->setLocalTransform(_currentTransform);
  //  _target->setLocalTransform(_multiplier);
}


void
AnimationAction::postComplete()
{
  _timeStarted = ZERO;
  _timeElapsed = ZERO;
  _fraction = ZERO;
}


}
