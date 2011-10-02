#include "PanCamera.h"
#include <iostream.h>

namespace protolayer
{ 

namespace proto
{

namespace interaction
{

namespace
{

  void rotateX(float vector[3], float angle)
  {
    float y = (float) cos(angle) * vector[1] +
      (float) sin(angle) * vector[2];
    float z = - (float) sin(angle) * vector[1] +
      (float) cos(angle) * vector[2];

    vector[1] = y;
    vector[2] = z;
  }


  void rotateY(float vector[3], float angle)
  {
    float x = (float) cos(angle) * vector[0] -
      (float) sin(angle) * vector[2];
    float z = (float) sin(angle) * vector[0] +
      (float) cos(angle) * vector[2];

    vector[0] = x;
    vector[2] = z;
  }

  void rotateZ(float vector[3], float angle)
  {
    float x = (float) cos(angle) * vector[0] +
      (float) sin(angle) * vector[1];
    float y = - (float) sin(angle) * vector[0] +
      (float) cos(angle) * vector[1];

    vector[0] = x;
    vector[1] = y;
  }

}


PanCamera::PanCamera(StateLayer& stateLayer) :
  protolayer::proto::GraphInteraction(stateLayer)
{
  _oldMouseX = 0;
  _oldMouseY = 0;

  _mouseX = 0;
  _mouseY = 0;
}


PanCamera::~PanCamera()
{
}


void PanCamera::mouseDown(float x, float y, int clickCount)
{
  protolayer::proto::GraphInteraction::mouseDown(x, y, clickCount);
  _oldMouseX = x;
  _oldMouseY = y;
}


void PanCamera::mouseMoved(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseMoved(x, y);
}


void PanCamera::mouseDragged(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseDragged(x, y);
  _mouseX = x;
  _mouseY = y;

  // Access width and height
  Rect bounds;
  GetControlBounds(getStateLayer().getViewLayer().getRenderPane(), &bounds);
  short width = bounds.right - bounds.left;
  short height = bounds.bottom - bounds.top;

  // Estimate the angles of rotation
  float thetaY = _mouseX - _oldMouseX;
  float thetaX = _mouseY - _oldMouseY;

  thetaY /= (float) width;
  thetaX /= (float) height;

  // Translate camera position relative to the target
  scenegraph::Camera& camera = getStateLayer().getViewLayer().getCurrentShot().getCamera();

  float temp[3];
  temp[0] = camera.getPosition().getLocalPoint().getCoordinates()[0] -
    camera.getTarget().getLocalPoint().getCoordinates()[0];
  temp[1] = camera.getPosition().getLocalPoint().getCoordinates()[1] -
    camera.getTarget().getLocalPoint().getCoordinates()[1];
  temp[2] = camera.getPosition().getLocalPoint().getCoordinates()[2] -
    camera.getTarget().getLocalPoint().getCoordinates()[2];
  camera.setPosition(temp);

  // Perform the rotation around the y-axis into the xy-plane
  float beta = camera.getPosition().getLocalPoint().getCoordinates()[0];
  beta /= (float) sqrt(camera.getPosition().getLocalPoint().getCoordinates()[0] *
                       camera.getPosition().getLocalPoint().getCoordinates()[0] +
                       camera.getPosition().getLocalPoint().getCoordinates()[2] *
                       camera.getPosition().getLocalPoint().getCoordinates()[2]);
  beta = (float) acos(beta);
  float alpha = beta - thetaY;

  temp[0] = camera.getPosition().getLocalPoint().getCoordinates()[0];
  temp[1] = camera.getPosition().getLocalPoint().getCoordinates()[1];
  temp[2] = camera.getPosition().getLocalPoint().getCoordinates()[2];
  rotateY(temp, beta);
  rotateZ(temp, thetaX);
  rotateY(temp, -alpha);
  camera.setPosition(temp);

  // Translate camera position relative to the origin
  temp[0] = camera.getPosition().getLocalPoint().getCoordinates()[0] +
    camera.getTarget().getLocalPoint().getCoordinates()[0];
  temp[1] = camera.getPosition().getLocalPoint().getCoordinates()[1] +
    camera.getTarget().getLocalPoint().getCoordinates()[1];
  temp[2] = camera.getPosition().getLocalPoint().getCoordinates()[2] +
    camera.getTarget().getLocalPoint().getCoordinates()[2];

  camera.setPosition(temp);
  camera.update();

  // Record the new mouse position
  _oldMouseX = _mouseX;
  _oldMouseY = _mouseY;

  getStateLayer().getViewLayer().swapRendererPortsAndDisplay();
}


void PanCamera::mouseUp(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseUp(x, y);

  scenegraph::Camera& camera = getStateLayer().getViewLayer().getCurrentShot().getCamera();
}


void PanCamera::keyDown()
{
}


void PanCamera::keyUp()
{
}


}


}


}
