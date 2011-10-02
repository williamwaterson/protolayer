#include "GraphInteraction.h"


namespace protolayer
{ 

namespace proto
{

GraphInteraction::GraphInteraction(StateLayer& stateLayer)
{
  _stateLayer = &stateLayer;
}


GraphInteraction::~GraphInteraction()
{
}


StateLayer& GraphInteraction::getStateLayer()
{
  return *_stateLayer;
}


void GraphInteraction::updateProjectedMouse(float x, float y)
{
  ViewLayer& view = _stateLayer->getViewLayer();
  WindowRef window = view.getWindow();

  Rect portRect;
  GetWindowBounds(window, kWindowContentRgn, &portRect);

  Rect bounds;
  GetControlBounds(view.getRenderPane(), &bounds);

  renderer::Space& space = view.getSpace();

  // Note the inversion of the y-ordinate according to OpenGL's basis
  space.setMousePosition(x - portRect.left - bounds.left,
			 portRect.top + bounds.bottom - y);

  space.display();
}


void GraphInteraction::mouseDown(float x, float y, int clickCount)
{
  updateProjectedMouse(x, y);
}


void GraphInteraction::mouseMoved(float x, float y)
{
  updateProjectedMouse(x, y);
}


void GraphInteraction::mouseDragged(float x, float y)
{
  updateProjectedMouse(x, y);
}


void GraphInteraction::mouseUp(float x, float y)
{
  updateProjectedMouse(x, y);
}


void GraphInteraction::keyDown()
{
}


void GraphInteraction::keyUp()
{
}


}


}
