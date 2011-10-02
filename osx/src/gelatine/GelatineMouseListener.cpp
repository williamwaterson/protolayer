#include "GelatineMouseListener.h"


namespace gelatine
{


GelatineMouseListener::GelatineMouseListener(protolayer::carbon::Window& parentWindow,
                                             GelatinePane& pane) :
  _window(parentWindow),
  _pane(pane)
{
}


GelatineMouseListener::~GelatineMouseListener()
{
}


OSStatus
GelatineMouseListener::mouseDragged(EventHandlerCallRef callRef,
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
GelatineMouseListener::mouseMoved(EventHandlerCallRef callRef,
                                  EventRef event)
{
  //  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(::Point), NULL, &_mousePosition);
  //  _pane.getSpace().getModel().getMouse()._x = _mousePosition.h;
  //  _pane.getSpace().getModel().getMouse()._y = _mousePosition.v;

  //  Rect portRect;
  //  WindowRef windowRef;
  //GetEventParameter(event, kEventParamWindowRef, typeWindowRef, NULL, sizeof(WindowRef), NULL, &windowRef);
  //GetWindowBounds(windowRef, kWindowContentRgn, &portRect);

  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(::Point), NULL, &_mousePosition);
  _pane.getSpace().getModel().getMouse()._x = _mousePosition.h - _window.getContentBounds().left;
  _pane.getSpace().getModel().getMouse()._y = _window.getContentBounds().bottom - _mousePosition.v;
}


}
