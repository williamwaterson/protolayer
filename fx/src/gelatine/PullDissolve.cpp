#include "PullDissolve.h"


namespace protolayer
{


PullDissolve::PullDissolve(float timePeriod)
{
  _inProgress = false;
  _timePeriod = timePeriod;
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


void
PullDissolve::setTargetPoint(float x, float y, float z)
{
  _targetPosition[0] = x;
  _targetPosition[1] = y;
  _targetPosition[2] = z;
}


bool
PullDissolve::inProgress()
{
  return _inProgress;
}


void
PullDissolve::commence(Shot& initialShot, Shot& finalShot)
{
  Microseconds(&_tick);
  _timeStarted = (float) UnsignedWideToUInt64(_tick);

  // Estimate the camera transition direction for the initial shot
  _startPosition[0] = initialShot.getCamera().getPosition()[0];
  _startPosition[1] = initialShot.getCamera().getPosition()[1];
  _startPosition[2] = initialShot.getCamera().getPosition()[2];

  _startTarget[0] = initialShot.getCamera().getTarget()[0];
  _startTarget[1] = initialShot.getCamera().getTarget()[1];
  _startTarget[2] = initialShot.getCamera().getTarget()[2];

  _transitionDirection[0] = _targetPosition[0];
  _transitionDirection[1] = _targetPosition[1];
  _transitionDirection[2] = _targetPosition[2];

  _transitionDirection[0] -= _startPosition[0];
  _transitionDirection[1] -= _startPosition[1];
  _transitionDirection[2] -= _startPosition[2];

  // Obtain orthonormal basis of first camera
  float orthoBasis[3][3];
  //  orthoBasis[0] = new float[3];
  //orthoBasis[1] = new float[3];
  //orthoBasis[2] = new float[3];

  orthoBasis[0][0] = initialShot.getCamera().getTarget()[0];
  orthoBasis[0][1] = initialShot.getCamera().getTarget()[1];
  orthoBasis[0][2] = initialShot.getCamera().getTarget()[2];

  orthoBasis[0][0] -= initialShot.getCamera().getPosition()[0];
  orthoBasis[0][1] -= initialShot.getCamera().getPosition()[1];
  orthoBasis[0][2] -= initialShot.getCamera().getPosition()[2];
  normalise(orthoBasis[0]);

  const float* orient = initialShot.getCamera().getOrient();
  crossProduct(orthoBasis[0], orient, orthoBasis[1]);
  orthoBasis[1][0] = -orthoBasis[1][0];
  orthoBasis[1][1] = -orthoBasis[1][1];
  orthoBasis[1][2] = -orthoBasis[1][2];
  normalise(orthoBasis[1]);

  crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

  // Determine the direction vector relative to the camera orthonormal basis
  float transpose[3][3];

  transpose[0][0] = orthoBasis[0][0];
  transpose[0][1] = orthoBasis[1][0];
  transpose[0][2] = orthoBasis[2][0];

  transpose[1][0] = orthoBasis[0][1];
  transpose[1][1] = orthoBasis[1][1];
  transpose[1][2] = orthoBasis[2][1];

  transpose[2][0] = orthoBasis[0][2];
  transpose[2][1] = orthoBasis[1][2];
  transpose[2][2] = orthoBasis[2][2];

  inverse(transpose, orthoBasis);

  float result[3];
  multiply(orthoBasis, _transitionDirection, result);

  // Obtain orthonormal basis of second camera
  orthoBasis[0][0] = finalShot.getCamera().getTarget()[0];
  orthoBasis[0][1] = finalShot.getCamera().getTarget()[1];
  orthoBasis[0][2] = finalShot.getCamera().getTarget()[2];

  orthoBasis[0][0] -= finalShot.getCamera().getPosition()[0];
  orthoBasis[0][1] -= finalShot.getCamera().getPosition()[1];
  orthoBasis[0][2] -= finalShot.getCamera().getPosition()[2];
  normalise(orthoBasis[0]);

  orient = finalShot.getCamera().getOrient();
  crossProduct(orthoBasis[0], orient, orthoBasis[1]);
  orthoBasis[1][0] = -orthoBasis[1][0];
  orthoBasis[1][1] = -orthoBasis[1][1];
  orthoBasis[1][2] = -orthoBasis[1][2];
  normalise(orthoBasis[1]);

  crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

  transpose[0][0] = orthoBasis[0][0];
  transpose[0][1] = orthoBasis[1][0];
  transpose[0][2] = orthoBasis[2][0];

  transpose[1][0] = orthoBasis[0][1];
  transpose[1][1] = orthoBasis[1][1];
  transpose[1][2] = orthoBasis[2][1];

  transpose[2][0] = orthoBasis[0][2];
  transpose[2][1] = orthoBasis[1][2];
  transpose[2][2] = orthoBasis[2][2];

  // Determine the start point for the final shot's camera
  multiply(transpose, result, _finalStartPosition);

  _transitionDirection2[0] = _finalStartPosition[0];
  _transitionDirection2[1] = _finalStartPosition[1];
  _transitionDirection2[2] = _finalStartPosition[2];

  _finalStartPosition[0] = -_finalStartPosition[0];
  _finalStartPosition[1] = -_finalStartPosition[1];
  _finalStartPosition[2] = -_finalStartPosition[2];

  _finalStartPosition[0] += finalShot.getCamera().getPosition()[0];
  _finalStartPosition[1] += finalShot.getCamera().getPosition()[1];
  _finalStartPosition[2] += finalShot.getCamera().getPosition()[2];

  _finalStartTarget[0] = finalShot.getCamera().getTarget()[0];
  _finalStartTarget[1] = finalShot.getCamera().getTarget()[1];
  _finalStartTarget[2] = finalShot.getCamera().getTarget()[2];

  _finalStartTarget[0] -= finalShot.getCamera().getPosition()[0];
  _finalStartTarget[1] -= finalShot.getCamera().getPosition()[1];
  _finalStartTarget[2] -= finalShot.getCamera().getPosition()[2];

  _finalStartTarget[0] += _finalStartPosition[0];
  _finalStartTarget[1] += _finalStartPosition[0];
  _finalStartTarget[2] += _finalStartPosition[0];

    // Estimate the camera start point for the final shot
    //    _finalStartPosition[0] = finalShot.getCamera()._position[0];
    //_finalStartPosition[1] = finalShot.getCamera()._position[1];
    //_finalStartPosition[2] = finalShot.getCamera()._position[2];

    //_finalStartPosition[0] -= _transitionDirection[0];
    //_finalStartPosition[1] -= _transitionDirection[1];
    //_finalStartPosition[2] -= _transitionDirection[2];

  // Trigger starting of the transition
  _inProgress = true;

}


void
PullDissolve::increment(Shot& initialShot, Shot& finalShot)
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

    _displacement[0] = _transitionDirection[0];
    _displacement[1] = _transitionDirection[1];
    _displacement[2] = _transitionDirection[2];

    _displacement[0] *= fraction;
    _displacement[1] *= fraction;
    _displacement[2] *= fraction;

    float temp[3];

    temp[0] = _startPosition[0];
    temp[1] = _startPosition[1];
    temp[2] = _startPosition[2]; 

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2]; 

    initialShot.getCamera().setPosition(temp);

    temp[0] = _startTarget[0];
    temp[1] = _startTarget[1];
    temp[2] = _startTarget[2]; 

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2]; 

    initialShot.getCamera().setTarget(temp);

    _displacement[0] = _transitionDirection2[0];
    _displacement[1] = _transitionDirection2[1];
    _displacement[2] = _transitionDirection2[2];

    _displacement[0] *= fraction;
    _displacement[1] *= fraction;
    _displacement[2] *= fraction;

    temp[0] = _finalStartPosition[0];
    temp[1] = _finalStartPosition[1];
    temp[2] = _finalStartPosition[2];

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2];

    finalShot.getCamera().setPosition(temp);

    temp[0] = _finalStartTarget[0];
    temp[1] = _finalStartTarget[1];
    temp[2] = _finalStartTarget[2];

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2]; 

    finalShot.getCamera().setTarget(temp);
  }

}


void
PullDissolve::postComplete(Shot& initialShot, Shot& finalShot)
{
    initialShot.getCamera().setAlpha(UNITY);
    finalShot.getCamera().setAlpha(UNITY);

    initialShot.getCamera().setPosition(_startPosition);

    float temp[3];

    temp[0] = _finalStartPosition[0];
    temp[1] = _finalStartPosition[1];
    temp[2] = _finalStartPosition[2];

    temp[0] += _transitionDirection2[0];
    temp[1] += _transitionDirection2[1];
    temp[2] += _transitionDirection2[2];

    finalShot.getCamera().setPosition(temp);

    _timeElapsed = ZERO;
    _timeStarted = ZERO;
}


}
