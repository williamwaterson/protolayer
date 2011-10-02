#include "GraphInteractionState.h"


namespace protolayer
{

namespace proto
{

GraphInteractionState::GraphInteractionState(osx::Pane& pane) :
  _pane(pane),
  _enabled(true)
{
}


GraphInteractionState::~GraphInteractionState()
{
}


osx::Pane&
GraphInteractionState::getRenderPane()
{
  return _pane;
}


bool GraphInteractionState::isEnabled() const
{
  return _enabled;
}


void GraphInteractionState::enable()
{
  _enabled = true;
}


void GraphInteractionState::disable()
{
  _enabled = false;
}


OSStatus
GraphInteractionState::mouseDown(EventHandlerCallRef callRef,
                                 EventRef event)
{
  Rect portRect;
  WindowRef windowRef;
  GetEventParameter(event, kEventParamWindowRef, typeWindowRef, NULL, sizeof(WindowRef), NULL, &windowRef);
  GetWindowBounds(windowRef, kWindowContentRgn, &portRect);

  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &_mousePosition);

  _mousePosition.h -= portRect.left;
  _mousePosition.v -= portRect.top;

  if (_pane.isWithin(_mousePosition.h, _mousePosition.v)) {
  }

  return eventNotHandledErr;
}


OSStatus
GraphInteractionState::mouseUp(EventHandlerCallRef callRef,
                               EventRef event)
{
  return noErr;
}


OSStatus
GraphInteractionState::mouseMoved(EventHandlerCallRef callRef,
                                  EventRef event)
{
  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &_mousePosition);
  //  _pane.getSpace().getMouse()._x = _mousePosition.h;
  //  _pane.getSpace().getMouse()._y = _mousePosition.v;
  _pane.getSpace().setMousePosition(_mousePosition.h, _mousePosition.v);

  Rect portRect;
  WindowRef windowRef;
  GetEventParameter(event, kEventParamWindowRef, typeWindowRef, NULL, sizeof(WindowRef), NULL, &windowRef);
  GetWindowBounds(windowRef, kWindowContentRgn, &portRect);

  //  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &_mousePosition);
  //_pane.getSpace().getMouse()._x = _mousePosition.h - portRect.left;
  //_pane.getSpace().getMouse()._y = portRect.bottom - _mousePosition.v;

  //  printf("window: l=%d b=%d \n", portRect.left, portRect.bottom);
  //  printf("mouse: x=%d y=%d \n", _mousePosition.h, _mousePosition.v);
  //  printf("opengl: x=%d y=%d \n", _pane.getSpace().getMouse()._x, _pane.getSpace().getMouse()._y);

  return eventNotHandledErr;
}


OSStatus
GraphInteractionState::mouseDragged(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return noErr;
}


OSStatus
GraphInteractionState::mouseWheelMoved(EventHandlerCallRef callRef,
                                       EventRef event)
{
  return noErr;
}


}


}
