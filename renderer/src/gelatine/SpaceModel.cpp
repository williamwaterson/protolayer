#include "SpaceModel.h"


namespace gelatine
{


SpaceModel::SpaceModel(Shot& initialShot)
{
  _currentShot = &initialShot;
  _nextShot = 0;
  _defaultTransition = new DefaultTransition();
  _transition = _defaultTransition;
  initialiseBuffer();
}


SpaceModel::SpaceModel(Shot& initialShot,
                       Transition& transition)
{
  _currentShot = &initialShot;
  _nextShot = 0;
  _transition = &transition;
  initialiseBuffer();
}


SpaceModel::~SpaceModel()
{
}


HitModel& SpaceModel::getHitModel()
{
  return _hitModel;
}


Shot&
SpaceModel::getCurrentShot()
{
  return *_currentShot;
}


Shot*
SpaceModel::getNextShot()
{
  return _nextShot;
}


Mouse&
SpaceModel::getMouse()
{
  return _mouse;
}


Transition&
SpaceModel::getTransition()
{
  return *_transition;
}


Dimensions&
SpaceModel::getDimensions()
{
  return _renderingDimensions;
}


void
SpaceModel::setTransition(Transition& transition)
{
  _transition = &transition;
}


bool
SpaceModel::hasNextShot()
{
  return _nextShot != 0;
}


GLuint*
SpaceModel::getSelectBuffer()
{
  return _selectBuffer;
}


void
SpaceModel::setNextShot(Shot& shot)
{
  if (_currentShot != &shot) {
    _nextShot = &shot;
  }
}


void
SpaceModel::makeNextShotCurrent()
{
  if (_nextShot != 0) {
    _currentShot = _nextShot;
    _nextShot = 0;
  }
}


void
SpaceModel::initialiseBuffer()
{
  for (int i = 0; i < BUFFER_SIZE; i++) {
    _selectBuffer[i] = 0;
  }
}


}
