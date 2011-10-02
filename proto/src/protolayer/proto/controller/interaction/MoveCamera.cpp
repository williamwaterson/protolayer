#include "MoveCamera.h"
#include <iostream.h>

namespace protolayer
{ 

namespace proto
{

namespace interaction
{

namespace
{
/**
 * TODO: Documentation
 * <p>
 */
void crossProduct3D(float a[3], float b[3], float result[3])
{
  result[0] = a[1] * b[2] - b[1] * a[2];
  result[1] = a[2] * b[0] - b[2] * a[0];
  result[2] = a[0] * b[1] - b[0] * a[1];
}


/**
 * TODO: Documentation
 * <p>
 */
float magnitude(float vector[3])
{
  return (float) sqrt(vector[0] * vector[0] +
                      vector[1] * vector[1] +
                      vector[2] * vector[2]);
}

void normalise(float vector[3])
{
  float length = magnitude(vector);
  vector[0] /= length;
  vector[1] /= length;
  vector[2] /= length;
}


void unitNormal(float a[3], float b[3], float result[3])
{
  renderer::crossProduct(a, b, result);
  normalise(result);
}


}


MoveCamera::MoveCamera(StateLayer& stateLayer) :
  protolayer::proto::GraphInteraction(stateLayer)
{
}


MoveCamera::~MoveCamera()
{
}


void MoveCamera::mouseDown(float x, float y, int clickCount)
{
  protolayer::proto::GraphInteraction::mouseDown(x, y, clickCount);

  _oldMouseX = x;
  _oldMouseY = y;
}


void MoveCamera::mouseMoved(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseMoved(x, y);
}


void MoveCamera::mouseDragged(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseDragged(x, y);

  _mouseX = x;
  _mouseY = y;

  float diffX = - (float) (_mouseX - _oldMouseX);
  float diffY = (float) (_mouseY - _oldMouseY);

  diffX /= 100.0f;
  diffY /= 100.0f;

  scenegraph::Camera& camera = getStateLayer().getViewLayer().getCurrentShot().getCamera();  

  float unitVectorY[3];
  float viewVector[3];
  float sideVector[3];

  unitVectorY[0] = 0.0f;
  unitVectorY[1] = 1.0f;
  unitVectorY[2] = 0.0f;

  sideVector[0] = 0.0f;
  sideVector[1] = 0.0f;
  sideVector[2] = 0.0f;

  viewVector[0] = camera.getTarget().getCoordinates()[0] - camera.getPosition().getCoordinates()[0];
  viewVector[1] = camera.getTarget().getCoordinates()[1] - camera.getPosition().getCoordinates()[1];
  viewVector[2] = camera.getTarget().getCoordinates()[2] - camera.getPosition().getCoordinates()[2];

  unitNormal(viewVector, unitVectorY, sideVector);
  unitNormal(unitVectorY, sideVector, viewVector);

  // Translate camera position relative to the target
  float temp[3];
  temp[0] = camera.getPosition().getLocalPoint().getCoordinates()[0] + diffY * viewVector[0] + diffX * sideVector[0];
  temp[1] = camera.getPosition().getLocalPoint().getCoordinates()[1];
  temp[2] = camera.getPosition().getLocalPoint().getCoordinates()[2] + diffY * viewVector[2] + diffX * sideVector[2];
  camera.setPosition(temp);

  temp[0] = camera.getTarget().getLocalPoint().getCoordinates()[0] + diffY * viewVector[0] + diffX * sideVector[0];
  temp[1] = camera.getTarget().getLocalPoint().getCoordinates()[1];
  temp[2] = camera.getTarget().getLocalPoint().getCoordinates()[2] + diffY * viewVector[2] + diffX * sideVector[2];

  camera.setTarget(temp);
  camera.update();

  // Record the new mouse position
  _oldMouseX = _mouseX;
  _oldMouseY = _mouseY;

  getStateLayer().getViewLayer().swapRendererPortsAndDisplay();
}


void MoveCamera::mouseUp(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseUp(x, y);
}


void MoveCamera::keyDown()
{
}


void MoveCamera::keyUp()
{
}


}


}


}
