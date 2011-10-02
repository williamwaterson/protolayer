#include "WindowActionListener.h"


namespace protolayer
{

namespace carbon
{


pascal OSStatus windowActionHandler(EventHandlerCallRef callRef,
                                    EventRef event,
                                    void* userData)
{
  WindowActionListener* listener =
    reinterpret_cast <WindowActionListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowCollapse) {
    return listener->windowCollapse(callRef, event);

  } else if (whatHappened == kEventWindowExpand) {
    return listener->windowExpand(callRef, event);

  } else if (whatHappened == kEventWindowClose) {
    return listener->windowClose(callRef, event);

  } else if (whatHappened == kEventWindowZoom) {
    return listener->windowZoom(callRef, event);

  } else if (whatHappened == kEventWindowContextualMenuSelect) {
    return listener->windowContextualMenuSelect(callRef, event);

  } else if (whatHappened == kEventWindowPathSelect) {
    return listener->windowPathSelect(callRef, event);

  } else if (whatHappened == kEventWindowGetIdealSize) {
    return listener->windowGetIdealSize(callRef, event);

  } else if (whatHappened == kEventWindowGetMinimumSize) {
    return listener->windowGetMinimumSize(callRef, event);

  } else if (whatHappened == kEventWindowGetMaximumSize) {
    return listener->windowGetMaximumSize(callRef, event);

  } else if (whatHappened == kEventWindowConstrain) {
    return listener->windowConstrain(callRef, event);

  } else if (whatHappened == kEventWindowHandleContentClick) {
    return listener->windowHandleContentClick(callRef, event);

  } else if (whatHappened == kEventWindowGetDockTileMenu) {
    return listener->windowGetDockTileMenu(callRef, event);

  } else if (whatHappened == kEventWindowProxyBeginDrag) {
    return listener->windowProxyBeginDrag(callRef, event);

  } else if (whatHappened == kEventWindowProxyEndDrag) {
    return listener->windowProxyEndDrag(callRef, event);

  } else if (whatHappened == kEventWindowToolbarSwitchMode) {
    return listener->windowToolbarSwitchMode(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec windowActionListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowCollapse },
  { kEventClassWindow, kEventWindowCollapseAll },
  { kEventClassWindow, kEventWindowExpand },
  { kEventClassWindow, kEventWindowExpandAll },
  { kEventClassWindow, kEventWindowClose },
  { kEventClassWindow, kEventWindowCloseAll },
  { kEventClassWindow, kEventWindowZoom },
  { kEventClassWindow, kEventWindowZoomAll },
  { kEventClassWindow, kEventWindowContextualMenuSelect },
  { kEventClassWindow, kEventWindowPathSelect },
  { kEventClassWindow, kEventWindowGetIdealSize },
  { kEventClassWindow, kEventWindowGetMinimumSize },
  { kEventClassWindow, kEventWindowGetMaximumSize },
  { kEventClassWindow, kEventWindowConstrain },
  { kEventClassWindow, kEventWindowHandleContentClick },
  { kEventClassWindow, kEventWindowGetDockTileMenu },
  { kEventClassWindow, kEventWindowProxyBeginDrag },
  { kEventClassWindow, kEventWindowProxyEndDrag },
  { kEventClassWindow, kEventWindowToolbarSwitchMode }
};


const EventHandlerUPP windowActionListenerEventHandler =
  NewEventHandlerUPP(windowActionHandler);


int WindowActionListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowActionListenerEventTypes);
}


const EventTypeSpec* WindowActionListener::getEventTypes()
{
  return windowActionListenerEventTypes;
}


EventHandlerUPP WindowActionListener::getEventHandlerUPP()
{
  return windowActionListenerEventHandler;
}


OSStatus WindowActionListener::windowCollapse(EventHandlerCallRef callRef,
                                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowExpand(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowClose(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowZoom(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowContextualMenuSelect(EventHandlerCallRef callRef,
                                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowPathSelect(EventHandlerCallRef callRef,
                                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowGetIdealSize(EventHandlerCallRef callRef,
                                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowGetMinimumSize(EventHandlerCallRef callRef,
                                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowGetMaximumSize(EventHandlerCallRef callRef,
                                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowConstrain(EventHandlerCallRef callRef,
                                               EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowHandleContentClick(EventHandlerCallRef callRef,
                                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowGetDockTileMenu(EventHandlerCallRef callRef,
                                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowProxyBeginDrag(EventHandlerCallRef callRef,
                                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowProxyEndDrag(EventHandlerCallRef callRef,
                                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus WindowActionListener::windowToolbarSwitchMode(EventHandlerCallRef callRef,
                                                       EventRef event)
{
  return eventNotHandledErr;
}


}


}
