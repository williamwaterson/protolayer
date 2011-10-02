#include "Transition.h"


namespace protolayer
{

namespace fx
{

Transition::Transition(float timePeriod,
                       scenegraph::Shot& initialShot,
		       scenegraph::Shot& finalShot) :
  animation::TransitionAction(initialShot, finalShot)
{
  _inProgress = false;
  _timePeriod = timePeriod;
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


void
Transition::setTargetPoint(float x, float y, float z)
{
  _targetPosition[0] = x;
  _targetPosition[1] = y;
  _targetPosition[2] = z;
}


bool
Transition::inProgress()
{
  return _inProgress;
}


void
Transition::commence(float timeStarted)
{
  getInitialShot().getCamera().setAlpha(UNITY);
  getInitialShot().setRenderable(true);
  getInitialShot().setSelectable(false);

  getFinalShot().getCamera().setAlpha(ZERO);
  getFinalShot().setRenderable(true);
  getFinalShot().setSelectable(false);

  //  gettimeofday(&_tick, NULL);    

  //  double doubleTime = _tick.tv_usec;
  //  doubleTime += _tick.tv_sec * 1000000;
  //  _timeStarted = (float) doubleTime;
  _timeStarted = timeStarted;

    //    float temp[3];

    //    temp[0] = _finalStartPosition[0];
    //    temp[1] = _finalStartPosition[1];
    //    temp[2] = _finalStartPosition[2];

    //    temp[0] += _transitionDirection2[0];
    //    temp[1] += _transitionDirection2[1];
    //    temp[2] += _transitionDirection2[2];

  //  getFinalShot().getCamera().setPosition(_secondShotStartPosition);
  //  getFinalShot().getCamera().setTarget(_secondShotStartTarget);

  //  _timeElapsed = ZERO;
  //  _timeStarted = ZERO;

  _secondShotStartPosition[0] = getFinalShot().getCamera().getPosition().getCoordinates()[0];
  _secondShotStartPosition[1] = getFinalShot().getCamera().getPosition().getCoordinates()[1];
  _secondShotStartPosition[2] = getFinalShot().getCamera().getPosition().getCoordinates()[2];

  _secondShotStartTarget[0] = getFinalShot().getCamera().getTarget().getCoordinates()[0];
  _secondShotStartTarget[1] = getFinalShot().getCamera().getTarget().getCoordinates()[1];
  _secondShotStartTarget[2] = getFinalShot().getCamera().getTarget().getCoordinates()[2];

  // Estimate the camera transition direction for the initial shot
  _startPosition[0] = getInitialShot().getCamera().getPosition().getCoordinates()[0];
  _startPosition[1] = getInitialShot().getCamera().getPosition().getCoordinates()[1];
  _startPosition[2] = getInitialShot().getCamera().getPosition().getCoordinates()[2];

  _startTarget[0] = getInitialShot().getCamera().getTarget().getCoordinates()[0];
  _startTarget[1] = getInitialShot().getCamera().getTarget().getCoordinates()[1];
  _startTarget[2] = getInitialShot().getCamera().getTarget().getCoordinates()[2];

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

  orthoBasis[0][0] = getInitialShot().getCamera().getTarget().getCoordinates()[0];
  orthoBasis[0][1] = getInitialShot().getCamera().getTarget().getCoordinates()[1];
  orthoBasis[0][2] = getInitialShot().getCamera().getTarget().getCoordinates()[2];

  orthoBasis[0][0] -= getInitialShot().getCamera().getPosition().getCoordinates()[0];
  orthoBasis[0][1] -= getInitialShot().getCamera().getPosition().getCoordinates()[1];
  orthoBasis[0][2] -= getInitialShot().getCamera().getPosition().getCoordinates()[2];
  renderer::normalise(orthoBasis[0]);

  const float* orient = getInitialShot().getCamera().getOrient();
  renderer::crossProduct(orthoBasis[0], orient, orthoBasis[1]);
  orthoBasis[1][0] = -orthoBasis[1][0];
  orthoBasis[1][1] = -orthoBasis[1][1];
  orthoBasis[1][2] = -orthoBasis[1][2];
  renderer::normalise(orthoBasis[1]);

  renderer::crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

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

  renderer::inverse(transpose, orthoBasis);

  float result[3];
  renderer::multiply(orthoBasis, _transitionDirection, result);

  // Obtain orthonormal basis of second camera
  orthoBasis[0][0] = getFinalShot().getCamera().getTarget().getCoordinates()[0];
  orthoBasis[0][1] = getFinalShot().getCamera().getTarget().getCoordinates()[1];
  orthoBasis[0][2] = getFinalShot().getCamera().getTarget().getCoordinates()[2];

  orthoBasis[0][0] -= getFinalShot().getCamera().getPosition().getCoordinates()[0];
  orthoBasis[0][1] -= getFinalShot().getCamera().getPosition().getCoordinates()[1];
  orthoBasis[0][2] -= getFinalShot().getCamera().getPosition().getCoordinates()[2];
  renderer::normalise(orthoBasis[0]);

  orient = getFinalShot().getCamera().getOrient();
  renderer::crossProduct(orthoBasis[0], orient, orthoBasis[1]);
  orthoBasis[1][0] = -orthoBasis[1][0];
  orthoBasis[1][1] = -orthoBasis[1][1];
  orthoBasis[1][2] = -orthoBasis[1][2];
  renderer::normalise(orthoBasis[1]);

  renderer::crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

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
  renderer::multiply(transpose, result, _finalStartPosition);

  _transitionDirection2[0] = _finalStartPosition[0];
  _transitionDirection2[1] = _finalStartPosition[1];
  _transitionDirection2[2] = _finalStartPosition[2];

  _finalStartPosition[0] = -_finalStartPosition[0];
  _finalStartPosition[1] = -_finalStartPosition[1];
  _finalStartPosition[2] = -_finalStartPosition[2];

  _finalStartPosition[0] += getFinalShot().getCamera().getPosition().getCoordinates()[0];
  _finalStartPosition[1] += getFinalShot().getCamera().getPosition().getCoordinates()[1];
  _finalStartPosition[2] += getFinalShot().getCamera().getPosition().getCoordinates()[2];

  _finalStartTarget[0] = getFinalShot().getCamera().getTarget().getCoordinates()[0];
  _finalStartTarget[1] = getFinalShot().getCamera().getTarget().getCoordinates()[1];
  _finalStartTarget[2] = getFinalShot().getCamera().getTarget().getCoordinates()[2];

  _finalStartTarget[0] -= getFinalShot().getCamera().getPosition().getCoordinates()[0];
  _finalStartTarget[1] -= getFinalShot().getCamera().getPosition().getCoordinates()[1];
  _finalStartTarget[2] -= getFinalShot().getCamera().getPosition().getCoordinates()[2];

  _finalStartTarget[0] += _finalStartPosition[0];
  _finalStartTarget[1] += _finalStartPosition[0];
  _finalStartTarget[2] += _finalStartPosition[0];

    // Estimate the camera start point for the final shot
    //    _finalStartPosition[0] = getFinalShot().getCamera().getPosition().getCoordinates()[0];
    //_finalStartPosition[1] = getFinalShot().getCamera().getPosition().getCoordinates()[1];
    //_finalStartPosition[2] = getFinalShot().getCamera().getPosition().getCoordinates()[2];

    //_finalStartPosition[0] -= _transitionDirection[0];
    //_finalStartPosition[1] -= _transitionDirection[1];
    //_finalStartPosition[2] -= _transitionDirection[2];

  // Estimate the corrected local coordinates for the camera
  scenegraph::Camera& initialCamera = getInitialShot().getCamera();
  scenegraph::Camera& finalCamera = getFinalShot().getCamera();

  scenegraph::Scene& initialScene = getInitialShot().getScene();
  scenegraph::Scene& finalScene = getFinalShot().getScene();

  scenegraph::Group* initialGroup = initialScene.getRoot().getParent(initialCamera);
  scenegraph::Group* finalGroup = finalScene.getRoot().getParent(finalCamera);

  float transform[4][4];
  float inverse[4][4];

  initialGroup->getGlobalTransform(transform);
  renderer::inverse(transform, inverse);

  float position4[4];
  float result4[4];
  position4[0] = _startPosition[0];
  position4[1] = _startPosition[1];
  position4[2] = _startPosition[2];
  position4[3] = 1;
  renderer::multiply(inverse, position4, result4);
  _startPosition[0] = result4[0];
  _startPosition[1] = result4[1];
  _startPosition[2] = result4[2];

  position4[0] = _startTarget[0];
  position4[1] = _startTarget[1];
  position4[2] = _startTarget[2];
  position4[3] = 1;
  renderer::multiply(inverse, position4, result4);
  _startTarget[0] = result4[0];
  _startTarget[1] = result4[1];
  _startTarget[2] = result4[2];

  finalGroup->getGlobalTransform(transform);
  renderer::inverse(transform, inverse);

  position4[0] = _finalStartPosition[0];
  position4[1] = _finalStartPosition[1];
  position4[2] = _finalStartPosition[2];
  position4[3] = 1;
  renderer::multiply(inverse, position4, result4);
  _finalStartPosition[0] = result4[0];
  _finalStartPosition[1] = result4[1];
  _finalStartPosition[2] = result4[2];

  position4[0] = _finalStartTarget[0];
  position4[1] = _finalStartTarget[1];
  position4[2] = _finalStartTarget[2];
  position4[3] = 1;
  renderer::multiply(inverse, position4, result4);
  _finalStartTarget[0] = result4[0];
  _finalStartTarget[1] = result4[1];
  _finalStartTarget[2] = result4[2];

  _secondShotStartPosition[0] = getFinalShot().getCamera().getPosition().getCoordinates()[0];
  _secondShotStartPosition[1] = getFinalShot().getCamera().getPosition().getCoordinates()[1];
  _secondShotStartPosition[2] = getFinalShot().getCamera().getPosition().getCoordinates()[2];

  _secondShotStartTarget[0] = getFinalShot().getCamera().getTarget().getCoordinates()[0];
  _secondShotStartTarget[1] = getFinalShot().getCamera().getTarget().getCoordinates()[1];
  _secondShotStartTarget[2] = getFinalShot().getCamera().getTarget().getCoordinates()[2];

  _inProgress = true;
}


void
Transition::increment(float timeCurrent)
{
  //  gettimeofday(&_tick, NULL);

  //  double doubleTime = _tick.tv_usec;
  //  doubleTime += _tick.tv_sec * 1000000;
  //  _timeCurrent = (float) doubleTime;
  _timeCurrent = timeCurrent;

  _timeElapsed = _timeCurrent - _timeStarted;
  float fraction = _timeElapsed / _timePeriod;

  if (fraction > UNITY) {
    _inProgress = false;
  } else {
    getInitialShot().getCamera().setAlpha(UNITY - fraction);
    getFinalShot().getCamera().setAlpha(fraction);

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

    //    getInitialShot().getCamera().setPosition(temp);
    getInitialShot().getCamera().getPosition().getCoordinates()[0] = temp[0];
    getInitialShot().getCamera().getPosition().getCoordinates()[1] = temp[1];
    getInitialShot().getCamera().getPosition().getCoordinates()[2] = temp[2];

    temp[0] = _startTarget[0];
    temp[1] = _startTarget[1];
    temp[2] = _startTarget[2];

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2];

    //    getInitialShot().getCamera().setTarget(temp);
    getInitialShot().getCamera().getTarget().getCoordinates()[0] = temp[0];
    getInitialShot().getCamera().getTarget().getCoordinates()[1] = temp[1];
    getInitialShot().getCamera().getTarget().getCoordinates()[2] = temp[2];

    getInitialShot().getCamera().update();

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

    //    getFinalShot().getCamera().setPosition(temp);
    getFinalShot().getCamera().getPosition().getCoordinates()[0] = temp[0];
    getFinalShot().getCamera().getPosition().getCoordinates()[1] = temp[1];
    getFinalShot().getCamera().getPosition().getCoordinates()[2] = temp[2];

    temp[0] = _finalStartTarget[0];
    temp[1] = _finalStartTarget[1];
    temp[2] = _finalStartTarget[2];

    temp[0] += _displacement[0];
    temp[1] += _displacement[1];
    temp[2] += _displacement[2];

    //    getFinalShot().getCamera().setTarget(temp);
    getFinalShot().getCamera().getTarget().getCoordinates()[0] = temp[0];
    getFinalShot().getCamera().getTarget().getCoordinates()[1] = temp[1];
    getFinalShot().getCamera().getTarget().getCoordinates()[2] = temp[2];

    getFinalShot().getCamera().update();
  }
}


void
Transition::postComplete()
{
  getInitialShot().setRenderable(false);
  getInitialShot().setSelectable(true);
  getInitialShot().getCamera().setAlpha(UNITY);

  getFinalShot().setRenderable(true);
  getFinalShot().setSelectable(true);
  getFinalShot().getCamera().setAlpha(UNITY);

  //  getInitialShot().getCamera().setPosition(_startPosition);
  getInitialShot().getCamera().getPosition().getCoordinates()[0] = _startPosition[0];
  getInitialShot().getCamera().getPosition().getCoordinates()[1] = _startPosition[1];
  getInitialShot().getCamera().getPosition().getCoordinates()[2] = _startPosition[2];

  //  getInitialShot().getCamera().setTarget(_startTarget);
  getInitialShot().getCamera().getTarget().getCoordinates()[0] = _startTarget[0];
  getInitialShot().getCamera().getTarget().getCoordinates()[1] = _startTarget[1];
  getInitialShot().getCamera().getTarget().getCoordinates()[2] = _startTarget[2];

  //  getFinalShot().getCamera().setPosition(_secondShotStartPosition);
  getFinalShot().getCamera().getPosition().getCoordinates()[0] = _secondShotStartPosition[0];
  getFinalShot().getCamera().getPosition().getCoordinates()[1] = _secondShotStartPosition[1];
  getFinalShot().getCamera().getPosition().getCoordinates()[2] = _secondShotStartPosition[2];

  //  getFinalShot().getCamera().setTarget(_secondShotStartTarget);
  getFinalShot().getCamera().getTarget().getCoordinates()[0] = _secondShotStartTarget[0];
  getFinalShot().getCamera().getTarget().getCoordinates()[1] = _secondShotStartTarget[1];
  getFinalShot().getCamera().getTarget().getCoordinates()[2] = _secondShotStartTarget[2];

  getInitialShot().getCamera().update();
  getFinalShot().getCamera().update();

  _timeElapsed = ZERO;
  _timeStarted = ZERO;
}


}


}
