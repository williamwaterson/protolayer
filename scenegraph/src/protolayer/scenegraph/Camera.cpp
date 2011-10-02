#include "Camera.h"


namespace protolayer
{

namespace scenegraph
{

Camera::Camera(float x, float y, float z)
{
  _localPosition = new Point(x, y, z);
  _localTarget = new Point(0, 0, 0);

  _globalPosition = &(addPoint(*_localPosition));
  _globalTarget = &(addPoint(*_localTarget));

  _orient[0] = 0;
  _orient[1] = 1.0f;
  _orient[2] = 0;

  _fieldOfView = 1.0f;
  _zoom = 1.0f;
  _alpha = 1.0f;

  update();
}


Camera::Camera(float x,
               float y,
               float z,
               float targetX,
               float targetY,
               float targetZ)
{
  _localPosition = new Point(x, y, z);
  _localTarget = new Point(targetX, targetY, targetZ);

  _globalPosition = &(addPoint(*_localPosition));
  _globalTarget = &(addPoint(*_localTarget));

  _orient[0] = 0;
  _orient[1] = 1.0f;
  _orient[2] = 0;

  _fieldOfView = 1.0f;
  _zoom = 1.0f;
  _alpha = 1.0f;

  update();
}


Camera::~Camera()
{
}


void Camera::targetCamera()
{
  //  glMatrixMode(GL_MODELVIEW);
  //glLoadIdentity();
  //gluLookAt(_positionPoint->getGlobalCoordinates()[0],
  //        _positionPoint->getGlobalCoordinates()[1],
  //        _positionPoint->getGlobalCoordinates()[2],
  //        _targetPoint->getGlobalCoordinates()[0],
  //        _targetPoint->getGlobalCoordinates()[1],
  //        _targetPoint->getGlobalCoordinates()[2],
  //        _orient[0],
  //        _orient[1],
  //        _orient[2]);
}


float Camera::getZoom() const
{
  return _zoom;
}


TransformedPoint& Camera::getPosition()
{
  return *_globalPosition;
}


TransformedPoint& Camera::getTarget()
{
  return *_globalTarget;
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
  //  _targetPoint->getLocalCoordinates()[0] = target[0];
  //  _targetPoint->getLocalCoordinates()[1] = target[1]; 
  //  _targetPoint->getLocalCoordinates()[2] = target[2];
  update();
}


void Camera::setPosition(float position[3])
{  
  //  _positionPoint->getLocalCoordinates()[0] = position[0];
  //  _positionPoint->getLocalCoordinates()[1] = position[1]; 
  //  _positionPoint->getLocalCoordinates()[2] = position[2];
  update();
}


}


}
