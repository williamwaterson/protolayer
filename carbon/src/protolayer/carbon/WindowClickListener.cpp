#include "WindowClickListener.h"


namespace protolayer
{

namespace carbon
{


pascal OSStatus windowClickHandler(EventHandlerCallRef callRef,
                                   EventRef event,
                                   void* userData)
{
  WindowClickListener* listener =
    reinterpret_cast <WindowClickListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowClickDragRgn) {
    return listener->windowClickDragRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickCollapseRgn) {
    return listener->windowClickCollapseRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickResizeRgn) {
    return listener->windowClickResizeRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickCloseRgn) {
    return listener->windowClickCloseRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickResizeRgn) {
    return listener->windowClickResizeRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickZoomRgn) {
    return listener->windowClickZoomRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickContentRgn) {
    return listener->windowClickContentRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickProxyIconRgn) {
    return listener->windowClickProxyIconRgn(callRef, event);

  } else  if (whatHappened == kEventWindowClickToolbarButtonRgn) {
    return listener->windowClickToolbarButtonRgn(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec windowClickListenerEventTypes[] =
  {
    { kEventClassWindow, kEventWindowClickDragRgn },
    { kEventClassWindow, kEventWindowClickResizeRgn },
    { kEventClassWindow, kEventWindowClickCollapseRgn },
    { kEventClassWindow, kEventWindowClickCloseRgn },
    { kEventClassWindow, kEventWindowClickZoomRgn },
    { kEventClassWindow, kEventWindowClickContentRgn },
    { kEventClassWindow, kEventWindowClickProxyIconRgn },
    { kEventClassWindow, kEventWindowClickToolbarButtonRgn },
    { kEventClassWindow, kEventWindowClickStructureRgn }
  };


const EventHandlerUPP windowClickListenerEventHandlerUPP =
  NewEventHandlerUPP(windowClickHandler);


int WindowClickListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowClickListenerEventTypes);
}


const EventTypeSpec* WindowClickListener::getEventTypes()
{
  return windowClickListenerEventTypes;
}


EventHandlerUPP WindowClickListener::getEventHandlerUPP()
{
  return windowClickListenerEventHandlerUPP;
}


OSStatus
WindowClickListener::windowClickDragRgn(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickResizeRgn(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickCollapseRgn(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickCloseRgn(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickZoomRgn(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickContentRgn(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickProxyIconRgn(EventHandlerCallRef callRef,
                                             EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickToolbarButtonRgn(EventHandlerCallRef callRef,
                                                 EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowClickListener::windowClickStructureRgn(EventHandlerCallRef callRef,
                                             EventRef event)
{
  return eventNotHandledErr;
}


}


}
