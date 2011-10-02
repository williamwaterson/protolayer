#include "MouseListener.h"


namespace protolayer
{

namespace osx
{

MouseListener::MouseListener(protolayer::carbon::Window& parentWindow,
                             Pane& pane) :
  _window(parentWindow),
  _pane(pane)
{
}


MouseListener::~MouseListener()
{
}


OSStatus
MouseListener::mouseDragged(EventHandlerCallRef callRef,
                                    EventRef event)
{
  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(::Point), NULL, &_mousePosition);
  //  _mousePosition.h -= portRect.left;
  //  _mousePosition.v -= portRect.top;

  //  if (_pane.isWithin(_mousePosition.h, _mousePosition.v)) {
  //  }
  return eventNotHandledErr;
}


OSStatus
MouseListener::mouseMoved(EventHandlerCallRef callRef,
                                  EventRef event)
{
  //  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(::Point), NULL, &_mousePosition);
  //  _pane.getSpace().getMouse()._x = _mousePosition.h;
  //  _pane.getSpace().getMouse()._y = _mousePosition.v;

  //  Rect portRect;
  //  WindowRef windowRef;
  //GetEventParameter(event, kEventParamWindowRef, typeWindowRef, NULL, sizeof(WindowRef), NULL, &windowRef);
  //GetWindowBounds(windowRef, kWindowContentRgn, &portRect);

  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(::Point), NULL, &_mousePosition);
  short x = _mousePosition.h - _window.getContentBounds().left;
  short y = _window.getContentBounds().bottom - _mousePosition.v;

  _pane.getSpace().setMousePosition(x, y);

  //  _pane.getSpace().getMouse()._x = _mousePosition.h - _window.getContentBounds().left;
  //  _pane.getSpace().getMouse()._y = _window.getContentBounds().bottom - _mousePosition.v;

}


}


}
