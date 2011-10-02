#include "Camera.h"


namespace protolayer
{

namespace renderer
{

Camera::Camera(float x, float y, float z)
{
  _localPosition[0] = x;
  _localPosition[1] = y;
  _localPosition[2] = z;
  _localPosition[3] = 1;

  _position[0] = x;
  _position[1] = y;
  _position[2] = z;
  _position[3] = 1;

  _localTarget[0] = 0;
  _localTarget[1] = 0;
  _localTarget[2] = 0;
  _localTarget[3] = 1;

  _target[0] = 0;
  _target[1] = 0;
  _target[2] = 0;
  _target[3] = 1;

  _orient[0] = 0;
  _orient[1] = 1.0f;
  _orient[2] = 0;

  _fieldOfView = 1.0f;
  _zoom = 1.0f;
  _alpha = 1.0f;

  _positionPoint = new Point(_localPosition, _position);
  _targetPoint = new Point(_localTarget, _target);
  addPoint(*_positionPoint);
  addPoint(*_targetPoint);

  update();
}


Camera::Camera(float x,
               float y,
               float z,
               float targetX,
               float targetY,
               float targetZ)
{
  _localPosition[0] = x;
  _localPosition[1] = y;
  _localPosition[2] = z;
  _localPosition[3] = 1;

  _position[0] = x;
  _position[1] = y;
  _position[2] = z;
  _position[3] = 1;

  _localTarget[0] = targetX;
  _localTarget[1] = targetY;
  _localTarget[2] = targetZ;
  _localTarget[3] = 1;

  _target[0] = targetX;
  _target[1] = targetY;
  _target[2] = targetZ;
  _target[3] = 1;

  _orient[0] = 0;
  _orient[1] = 1.0f;
  _orient[2] = 0;

  _fieldOfView = 1.0f;
  _zoom = 1.0f;
  _alpha = 1.0f;

  _positionPoint = new Point(_localPosition, _position);
  _targetPoint = new Point(_localTarget, _target);
  addPoint(*_positionPoint);
  addPoint(*_targetPoint);

  update();
}


Camera::~Camera()
{
}


void Camera::targetCamera()
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(_positionPoint->getGlobalCoordinates()[0],
            _positionPoint->getGlobalCoordinates()[1],
            _positionPoint->getGlobalCoordinates()[2],
            _targetPoint->getGlobalCoordinates()[0],
            _targetPoint->getGlobalCoordinates()[1],
            _targetPoint->getGlobalCoordinates()[2],
            _orient[0],
            _orient[1],
            _orient[2]);
}


float Camera::getZoom() const
{
  return _zoom;
}


Point& Camera::getPosition()
{
  return *_positionPoint;
}


Point& Camera::getTarget()
{
  return *_targetPoint;
}


float Camera::getAlpha() const
{
  return _alpha;
}


const float* Camera::getOrient() const
{
  return _orient;
}


void Camera::setAlpha(float alpha)
{
  _alpha = alpha;
}


void Camera::setZoom(float zoom)
{
  _zoom = zoom;
}


void Camera::setTarget(float target[3])
{
  _targetPoint->getLocalCoordinates()[0] = target[0];
  _targetPoint->getLocalCoordinates()[1] = target[1]; 
  _targetPoint->getLocalCoordinates()[2] = target[2];
  update();
}


void Camera::setPosition(float position[3])
{  
  _positionPoint->getLocalCoordinates()[0] = position[0];
  _positionPoint->getLocalCoordinates()[1] = position[1]; 
  _positionPoint->getLocalCoordinates()[2] = position[2];
  update();
}


}


}
