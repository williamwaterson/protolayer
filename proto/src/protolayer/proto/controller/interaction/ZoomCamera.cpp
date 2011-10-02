#include "ZoomCamera.h"
#include <iostream.h>

namespace protolayer
{ 

namespace proto
{

namespace interaction
{

ZoomCamera::ZoomCamera(StateLayer& stateLayer) :
  protolayer::proto::GraphInteraction(stateLayer)
{
  _oldMouseY = 0;
}


ZoomCamera::~ZoomCamera()
{
}


void ZoomCamera::mouseDown(float x, float y, int clickCount)
{
  protolayer::proto::GraphInteraction::mouseDown(x, y, clickCount);
  _oldMouseY = y;
}


void ZoomCamera::mouseDragged(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseDragged(x, y);

  float diffY = (float) (y - _oldMouseY);
  diffY /= 100.0f;

  getStateLayer().getViewLayer().getCurrentShot().getCamera().setZoom(diffY);
  getStateLayer().getViewLayer().getCurrentShot().getCamera().update();

  getStateLayer().getViewLayer().swapRendererPortsAndDisplay();
}


void ZoomCamera::mouseUp(float x, float y)
{
  protolayer::proto::GraphInteraction::mouseUp(x, y);
}


}


}


}
